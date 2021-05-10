import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class FibonacciSequenceHarder {
	static final long MOD = 1000000007;
	static final BigInteger pisano = new BigInteger("2000000016");
	static HashMap<Long, Long> nums = new HashMap<>();
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(System.in);
		// pisano period = 2000000016
		BigInteger n = in.nextBigInteger();
		n = n.mod(pisano);
		System.out.println(fib(n.intValue()-1));
	}
	static long fib(long n) {
		if (n<=1) return 1L;
		if (nums.containsKey(n)) return nums.get(n);
		nums.put(n, (fib((n-1)/2)*fib((n-2)/2)+fib(n/2)*fib((n+1)/2))%MOD);
		return nums.get(n);
		
	}
}