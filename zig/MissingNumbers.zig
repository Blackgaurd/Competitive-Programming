//
// trying to learn zig

const std = @import("std");

var _i: [2400256]u8 = undefined;
var _i0: u32 = 0;
var _o0: u32 = 0;
var __ = [1]u8{0}**11 ++ [1]u8{'\n'};

inline fn sc()u8{
    _i0+=1;
    return _i[_i0-1];
}
inline fn su32()u32{
    var x:u32=sc()-48;
    var _c=sc();
    while(_c>47){
        x=x*10+_c-48;
        _c=sc();
    }
    return x;
}
inline fn si32()i32{
    if(_i[_i0]=='-'){
        _i0+=1;
        return -@intCast(i32, su32());
    }
    return @intCast(i32, su32());
}
inline fn pc(c:u8)void{
    _i[_o0]=c;
    _o0+=1;
}
inline fn pu32(y:u32)void{
    var i:u8=10;
    __[10]=@intCast(u8,y%10+48);
    var x=y/10;
    while(x>0){
        i-=1;
        __[i]=@intCast(u8,x%10+48);
        x/=10;
    }
    for(__[i..12])|b,j|{
        _i[_o0+j]=b;
        _o0+=12-i;
    }
}
inline fn pi32(y:i32)void{
    if(y<0){
        pc('-');
        pu32(@intCast(u32,-y));
    }
    else pu32(@intCast(u32,y));
}

pub fn main() !void {
    @setRuntimeSafety(false);
    const stdin = std.io.getStdIn().inStream();
    const stdout = std.io.getStdOut().outStream();
    _ = try stdin.readAll(&_i);



    try stdout.writeAll(_i[0.._o0]);
}