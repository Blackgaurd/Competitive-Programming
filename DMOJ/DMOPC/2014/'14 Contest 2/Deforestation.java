// DMOPC '14 Contest 2 P4 - Deforestation

import java.util.*;
import java.io.*;
public class Deforestation {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), mass[] = new int[n+1], psa[] = new int[n+1];
		for (int i=1; i<=n; i++) {
			mass[i] = readInt();
		}
		for (int i=1; i<=n; i++) {
			psa[i] = psa[i-1]+mass[i];
		}
		int q = readInt();
		for (int i=0; i<q; i++) {
			int a = readInt(), b = readInt();
			System.out.println(psa[b+1]-psa[a]);
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