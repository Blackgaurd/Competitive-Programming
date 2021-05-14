// Fast Bit Duplication

unsigned long long duplicatebits(unsigned long long x){
    x = (x | (x << 16));
    x &= 281470681808895;

    x = (x | (x << 8));
    x &= 71777214294589695;

    x = (x | (x << 4));
    x &= 1085102592571150095;

    x = (x | (x << 2));
    x &= 3689348814741910323;

    x = (x | (x << 1));
    x &= 6148914691236517205;

    x = (x | (x << 1));
    return x;
}