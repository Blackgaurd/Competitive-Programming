//----- MIT IO -----//
#include <bits/stdc++.h>
#include <unistd.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#ifdef __MINGW32__
#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#endif
#define ll long long
#define ld long double
static struct IO {
#define _i inline void
#define __t template<typename T>
#define __c unsigned char
#define __1(x,y,z) inline IO &operator x (y &s){z; return*this;}
#define __2 val=0;int c=gc();while(c<=' ')c=gc();bool n=(c=='-');if(n)c=gc();do{val=val*10+c-'0';}while((c=gc())>='0'&&c<='9');
#define p_str(x) for (char i: x)pc(i);
#define likely(x) __builtin_expect(x,true)
#define unlikely(x) __builtin_expect(x,false)
const unsigned int bfz=1<<15;const static bool line_buf; __c *_rb=new __c[bfz]; __c *_wb=new __c[bfz];unsigned int rl=0,ri=0,wi=0;bool eof=false;
#ifdef _getchar_nolock
#else
#define ugc getchar
#endif
inline __c gc(){if(line_buf){return ugc();}else{if(unlikely(ri>=rl)){if(unlikely(eof))return EOF;fill_buffer();}
return _rb[ri++];}} _i pc(char x){if(unlikely(wi>=bfz))flush_buffer();_wb[wi++]=x;} _i fill_buffer(){auto x=fread(_rb,sizeof(char),bfz,stdin);
if(unlikely(x!=0&&x<bfz)){eof=true;}rl=x;ri= 0;} _i flush_buffer(){fwrite(_wb,sizeof(char),wi,stdout);fflush(stdout);wi=0;}~IO(){flush_buffer();}
__t _i _ni(T &val){__2 if(n)val=-val;} __t _i _nd(T &val){__2 T div=1;if(c=='.'){while((c=gc())>='0'&&c<='9')val+=(c-'0')/(div*=10);}if(n)val=-val;}
_i _nt(string &s,char token=' '){ostringstream oss;int c=gc();while(c==token||c<' ')c=gc();do{oss<<static_cast<char>(c);}while((c=gc())!=token&&c>=' ');
s=oss.str();} _i _nln(string &s){_nt(s,'\n');}static inline int fast_log10(const unsigned ll& val){return val<=9?0:val<=99?1:val<=999?2:val<=
9999?3:val<=99999?4:val<=999999?5:val<=9999999?6:val<=99999999?7:val<=999999999?8:val<=9999999999?9:val<=99999999999?10:val<=999999999999?11:val<=
9999999999999?12:val<=99999999999999?13:val<=999999999999999?14:val<=9999999999999999?15:val<=99999999999999999?16:val<=999999999999999999?17:val<=
9999999999999999999ull?18:val<=ULLONG_MAX?19:-1;}char buf[20]; __t _i write_int(T data){if(data==0)pc('0');else{int len;if(data<0){pc('-');data
=-data;}len=fast_log10(data)+1;for(int i=len-1;i>=0;i--){buf[i]=data%10+'0';data/=10;}for(int i=0;i<len;i++){pc(buf[i]);}}} __1(>,char,s=gc())
__1(>=,char,s=' ';while(s<=' ')s=gc()) __1(>,string,_nt(s)) __1(>,ld,_nd(s)) __1(>,ll,_ni(s)) __1(>,int,_ni(s)) __1(>=,string,_nln(s))
__1(<,const int,write_int(s)) __1(<,const ll,write_int(s)) __1(<,const ld,p_str(to_string(s));) __1(<,const string,p_str(s);)
__1(<,const char,pc(s);)IO(){if(line_buf){std::istream::sync_with_stdio(false);cin.tie(nullptr);}
else{setvbuf(stdin,nullptr,_IONBF,0);}setvbuf(stdout, nullptr, _IONBF, 0);}}io;
#ifdef __MINGW32__ 
#pragma clang diagnostic pop
const bool IO::line_buf = true;
#else
const bool IO::line_buf = false;
#endif

// > read
// < write
// >= readline (for string with spaces)
// can be used with any signed integer type
// example:
// int a;
// io > a;
// io < a;

//!NOTE: io may not work on usaco or other contests

//----- MIT IO -----//


//----- default fast IO -----//
#define sc(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
char _;

// default fast io instructions
// sc(x)
// x has to be unsigned integer

//----- default fast IO -----//


//----- buffed fast IO -----//
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

// buffed fast io instructions
// scan(x)
// x has to be unsigned integer
// can not be used alongside default fast io

//----- buffed fast IO -----//


//----- multi fast IO -----//
#define gc getchar_unlocked()
template<typename T> void sc2(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T, typename...A> void sc2(T&t, A&...a){sc2(t);sc2(a...);}

// multi fast io instructions
// sc2(a, b, c ...)
// can be used with multiple unsigned integers
// can not be used alongside any other io

//----- multi fast IO -----//


//----- cin fast IO -----//
// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// add to top of main()
// use cin and cout as normal
// do not use scanf 

//----- cin fast IO -----//


// remeber: only use one io template, dont mix and match
int main(){
    int a; 
    io > a;
    io < a;
    
    return 0;
}