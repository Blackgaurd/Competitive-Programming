// CCC '96 S1 - Deficient, Perfect, and Abundant

import java.util.*;
import java.io.*;

public class DeficientPerfectAndAbundant {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt();
		for (int i = 0; i < n; i++) {
			int t = readInt();
			System.out.println(t + " is a" + fun(t) + " number.");
		}
	}
	static String fun(int num) {
		int sum = 0;
		for (int i = 1; i <= Math.sqrt(num); i++) {
			if (num % i == 0) {
				int mul = num / i;
				sum += i;
				if (mul != i)
					sum += mul;
			}
		}
		sum -= num;
		// System.out.println(sum);
		if (sum > num)
			return "n abundant";
		else if (num > sum)
			return " deficient";
		else
			return " perfect";
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}