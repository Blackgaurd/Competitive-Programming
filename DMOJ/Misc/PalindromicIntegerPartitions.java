import java.util.*;
import java.io.*;
public class PalidromeIntPartitions {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static long memo[] = new long[100];
	static long fun(int n) {
		if(memo[n]!=0) return memo[n];
		if (n==0||n==1) return memo[n] = 1;
		long count = 1;
		for(int i=n-2; i>=0; i-=2) {
			count+=fun(i);
		}
		return memo[n] = count;
	}
	public static void main(String[] args) throws IOException{
		int n = readInt();
		System.out.println(fun(n));
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