import java.util.*;
import java.io.*;
public class TortureChamber {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> primes = new ArrayList<>();
	static final int MM = 100005;
	public static void main(String[] args) throws IOException{
		sieve(MM);
		long n = readLong(), m = readLong();
		System.out.println(countPrimes(n, m)-1);
	}
	static void sieve(int ceiling) {
        BitSet primality = new BitSet(MM);
        
        //Set initial primality
        for (int i = 2; i < MM; i++) primality.set(i);
        
        //Only need to check up to sqrt(int)
        int sr = (int) Math.sqrt(ceiling);
        //Populate primeNumbers and factors if i is prime
        for (int i = 2; i <= sr; i++) {
            if (primality.get(i)) {
                primes.add(i);
                for (int j = i * i; j <= ceiling; j += i) primality.clear(j);
            }
        }
        //Add remaining primes
        for (int i = sr + 1; i < MM; i++) if (primality.get(i)) primes.add(i);
        
        //System.out.println(primeNumbers.size());
    }
	static long countPrimes(long n, long m) {
		BitSet isPrime = new BitSet((int) (m-n+5));
		for (int i=0; i<(int)(m-n+1); i++) isPrime.set(i);
		for (int p: primes) {
			long start = 0;
			if (p==n) start = p;
			else start = (long)(Math.ceil(((double)n/p)))*p-n;
			if (start+n==p) start+=p;
			for (; start<m-n; start+=p) isPrime.clear((int) (start));
		}
		return (n==1)?isPrime.cardinality()-1:isPrime.cardinality();
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