// CCC '12 J4 - Big Bang Secrets

import java.util.*;
import java.io.*;
public class BigBangSecrets {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int k = readInt();
		char t[] = readLine().toCharArray();
		for (int p=0; p<t.length; p++){
			int c = t[p] - 'A' + 1;
			c -= (p+1)*3+k;
			while (c <= 0) c += 26;
			System.out.print((char)(c+'A'-1));
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