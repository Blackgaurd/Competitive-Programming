import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class FibonacciSequence {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int mod = 1000000007;
	static Map<BigInteger, Integer> nums = new HashMap<>();;
	public static void main(String[] args) throws IOException{
	}
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static int fib(BigInteger n) {
		BigInteger one = new BigInteger("1"), two = new BigInteger("2");
		if (n.compareTo(two)==-1) return 1;
		if ()
		nums.put(n, (fib((n.subtract(one)).divide(two))*fib((n.subtract(two)).divide(two))+fib(n.divide(two))*fib((n.add(one)).divide(two)))%mod);
		return nums.get(n);
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