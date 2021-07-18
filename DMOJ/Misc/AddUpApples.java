// Add Up Apples

import java.util.*;
import java.io.*;
public class AddUpApples {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, count=0;
	public static void main(String[] args) throws IOException{
		n = readInt();
		for (int i=1; i<=n/2; i++) {
			sums(i,i,n+"="+i);
		}
		System.out.println("total="+count);
	}
	static void sums(int prev, int sum, String ans) {
		if (sum==n) {
			count++;
			System.out.println(ans);
		}
		for (int i=prev; i+sum<=n; i++) {
			sums(i, sum+i, ans+"+"+i);
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