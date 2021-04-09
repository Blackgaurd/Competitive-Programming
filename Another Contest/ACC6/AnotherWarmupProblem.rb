require "openssl"

K = [0x5a827999, 0x6ed9eba1, 0x8f1bbcdc, 0xca62c1d6];

def rotate_left(value, shift)
    return ( ((value << shift) | (value >> (32 - shift))) & 0xffffffff)
end

module SHA0
    class Digest
        def initialize()
        @data = ''
        @data_length = 0
        @hash = [
            0x67452301,
            0xefcdab89,
            0x98badcfe,
            0x10325476,
            0xc3d2e1f0
        ]
        @rounds = 80
        @tmp = []
        @unit_size = 4
        @block_size = 16
        @block_byte_size = @block_size * @unit_size
    end

    def update(data)
        @data += data
        @data_length += data.size

        while @data.size >= @block_byte_size
            block = @data[0, @block_byte_size].unpack('N*')
            @hash = process_block(block)
            @data = @data[@block_byte_size, @data.size - @block_byte_size]
        end

        self
    end

    def digest
        current_hash.pack('N*')
    end

    def hexdigest()
        current_hash.each_with_object('') do |partial, hash|
            hash << '0' * (8 - partial.to_s(16).length) + partial.to_s(16)
        end
    end

    private
        def padding(message)
            bit_string = message.unpack('B*')[0]
            bit_string += '1'
            while ((448 % 512) != (bit_string.length % 512)) do
                bit_string += '0'
        end

        data_length_bit = (@data_length * 8).to_s(2)
        bit_string += '0' * (64 - data_length_bit.length) + data_length_bit

        [bit_string].pack('B*').unpack('N*')
    end

    def current_hash()
        pad_string = padding(@data)
        process_block(pad_string)
    end

    def process_block(block)
        working_vars = Array.new(@hash)

        @rounds.times.each do |i|
        if i < 16
            @tmp[i] = block[i]
        else
            @tmp[i] = (@tmp[i - 3] ^ @tmp[i - 8] ^ @tmp[i - 14] ^ @tmp[i - 16])
        end

        if i < 20
            f = (working_vars[1] & working_vars[2]) | (~working_vars[1] & working_vars[3])
        elsif i < 40
            f = working_vars[1] ^ working_vars[2] ^ working_vars[3]
        elsif i < 60
            f = (working_vars[1] & working_vars[2]) | (working_vars[1] & working_vars[3]) | (working_vars[2] & working_vars[3])
        else
            f = working_vars[1] ^ working_vars[2] ^ working_vars[3]
        end
        t = (rotate_left(working_vars[0], 5) + working_vars[4] + @tmp[i] + K[i / 20] + f) & 0xffffffff

        working_vars = [
            t,
            working_vars[0],
            rotate_left(working_vars[1], 30),
            working_vars[2],
            working_vars[3]
        ]
    end

        working_vars.map.with_index { |var, i|
            (@hash[i] + var) & 0xffffffff
        }
        end
    end
end

word = gets
puts SHA0::Digest.new().update(word.strip).hexdigest