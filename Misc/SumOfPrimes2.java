import java.util.*;
import java.io.*;
public class SumOfPrimes2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		boolean primes[] = new boolean[100001];
		primes[0] = true;
		primes[1] = true;
		for (int i=4; i<=100000; i+=2) {
			primes[i] = true;
		}
		for (int i=3; i<=100000; i+=2) {
			if (!primes[i]) {
				for (int j=i+i; j<=100000; j+=i) {
					primes[j] = true;
				}
			}
		}
		// false = prime
		long psa[] = new long[100002];
		psa[0] = 0;
		for (int i=0; i<=100000; i++) {
			if (!primes[i]) {
				psa[i+1] = psa[i]+i;
			} else psa[i+1] = psa[i];
		}
		//System.out.println(Arrays.toString(psa));
		int n = readInt();
		for (int i=0; i<n; i++) {
			int a = readInt(), b = readInt();
			long sum = psa[b+1]-psa[a];
			System.out.println(sum);
		}
		
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
		return next().charAt(00);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}