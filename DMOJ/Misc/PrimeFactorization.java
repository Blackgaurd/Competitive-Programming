import java.util.*;
import java.io.*;
public class PrimeFactorization {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int i=0; i<n; i++) {
			int a = readInt();
			for (int x: pf(a)) {
				System.out.print(x+" ");
			} System.out.println();
		}
	}
	static ArrayList<Integer> pf(int a){
		ArrayList<Integer> f = new ArrayList<>();
		while (a%2==0) {
			f.add(2);
			a/=2;
		}
		for (int i=3; i<=Math.sqrt(a); i+=2) {
			while (a%i==0) {
				f.add(i);
				a/=i;
			}
		}
		if (a>2) f.add(a);
		return f;
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