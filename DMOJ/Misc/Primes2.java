import java.util.*;
import java.io.*;
public class Primes2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> primes = new ArrayList<>();
	static final int MM = 100001;
	static long n, m;
	public static void main(String[] args) throws IOException{
		n = readLong(); m = readLong();
		sieve(MM, m<MM);
		if (m>=MM) getPrimes(n, m);
	}
	static void sieve(int ceiling, boolean small) {
		if (small) ceiling = (int) m;
        BitSet primality = new BitSet(ceiling);
        
        //Set initial primality
        for (int i = 2; i < ceiling; i++) primality.set(i);
        
        //Only need to check up to sqrt(int)
        int sr = (int) Math.sqrt(ceiling);
        //Populate primeNumbers and factors if i is prime
        for (int i = 2; i <= sr; i++) {
            if (primality.get(i)) {
            	if (small && i>=n) System.out.println(i);
            	else primes.add(i);
                for (int j = i * i; j <= ceiling; j += i) primality.clear(j);
            }
        }
        //Add remaining primes
        for (int i = sr + 1; i < ceiling; i++) if (primality.get(i)) {
        	if (small && i>=n) System.out.println(i);
        	else primes.add(i);
        }
        
        //System.out.println(primeNumbers.size());
    }
	static void getPrimes(long n, long m) {
		BitSet isPrime = new BitSet((int) (m-n));
		for (int i=0; i<(int)(m-n+1); i++) isPrime.set(i);
		for (int p: primes) {
			long start = 0;
			if (p==n) start = p;
			else start = (long)(Math.ceil(((double)n/p)))*p-n;
			if (start+n==p) start+=p;
			for (; start<m-n; start+=p) isPrime.clear((int) (start));
		}
		//System.out.println(isPrime.cardinality());
		for (int i=1; i<m-n; i++) {
			if (isPrime.get(i)) System.out.println(i+n);
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
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}