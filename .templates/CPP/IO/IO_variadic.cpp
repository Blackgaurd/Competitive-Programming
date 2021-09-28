#ifdef __linux__
#define getchar getchar_unlocked
#endif
template <typename T>
void sc(T &x) {
    x = 0;
    bool _ = 0;
    T c = getchar();
    _ = c == 45;
    c = _ ? getchar() : c;
    while (c < 48 || c > 57) c = getchar();
    for (; c < 48 || c > 57; c = getchar())
        ;
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    x = _ ? -x : x;
}
template <typename T, typename... A>
void scan(T &t, A &...a) {
    sc(t);
    sc(a...);
}

/* USAGE

int main(){
    int a, b, c;
    scan(a, b, c); // signed ints
}

*/