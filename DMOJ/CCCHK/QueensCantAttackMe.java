// CCCHK '15 J3 - Queens can't attack me!


import java.util.*;
import java.io.*;
public class QueensCantAttackMe {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		boolean row[] = new boolean[n], col[] = new boolean[n], ldag[] = new boolean[2*n-1], rdag[] = new boolean[2*n-1];
		for (int i=0; i<n; i++) {row[i] = true; col[i] = true;}
		for (int i=0; i<2*n-1; i++) {ldag[i] = true; rdag[i] = true;}
		for (int i=0; i<m; i++) {
			int x = readInt()-1, y = readInt()-1;
			row[x] = false;
			col[y] = false;
			rdag[x+y] = false;
			ldag[n-y+x-1] = false;
			//System.out.println(x);
			//System.out.println(y);
			//System.out.println(x+y);
			//System.out.println(n-y+x-1);
		}
		int count = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (row[i]==true && col[j]==true) {
					if (rdag[i+j]==true && ldag[n-j+i-1]==true) {
						count++;
					}
				}
			}
		}
		System.out.println(count);
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