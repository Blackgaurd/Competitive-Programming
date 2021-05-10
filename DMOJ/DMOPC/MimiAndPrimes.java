import java.util.*;
import java.io.*;
public class MimiAndPrimes {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		long gcd = readLong();
		for (int i=0; i<n-1; i++) {
			long x = readLong();
			gcd = gcd(x,gcd);
		}
		if (lpf(gcd)!=0) {
			System.out.println(lpf(gcd));
		} else System.out.println("DNE");
	}
	static long lpf(long a) {
		long mp = 0;
		while (a%2==0) {
			mp=2;
			a/=2;
		}
		for (int i=3; i<=Math.sqrt(a); i+=2) {
			while (a%i==0) {
				mp=i;
				a/=i;
			}
		}
		if (a>2) mp = a;
		return mp;
	}
	static long gcd(long a, long b) {
		if (a%b==0) return b;
		return gcd(b, a%b);
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}