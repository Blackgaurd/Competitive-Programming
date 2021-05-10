import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class Zeroes {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), zeroes = 0;
		BigInteger fac = factorial(BigInteger.valueOf(n));
		for (char c: fac.toString().toCharArray()) {
			if (c=='0') zeroes++;
		}
		System.out.println(zeroes);
	}
	static BigInteger factorial(BigInteger n) {
	    BigInteger out = BigInteger.ONE;
	    while (!n.equals(BigInteger.ZERO)) {
	    	out = out.multiply(n);
	    	n = n.subtract(BigInteger.ONE);
	    }
	    return out;
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