import java.util.*;
import java.io.*;
public class MooBuzz {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), q = n/8, r = n%8, arr[] = {1,2,4,7,8,11,13,14};
		//System.out.println("q"+q+" r"+r);
		if (r==0) q--;
		r--;
		if (r==-1) r=7;
		int i = arr[r]+15*q;
		System.out.println(i);
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