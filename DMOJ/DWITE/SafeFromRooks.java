import java.util.*;
import java.io.*;
public class SafeFromRooks {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for (int e=0; e<1; e++) {
			int r = readInt(), c = readInt(), m = readInt(), xcount = 0, ycount = 0;
			boolean row[] = new boolean[r], col[] = new boolean[c];
			for (int i=0; i<r; i++) {row[i] = true;}
			for (int i=0; i<c; i++) {col[i] = true;}
			for (int i=0; i<m; i++) {
				int x = readInt()-1, y = readInt()-1;
				row[x] = false;
				col[y] = false;
			}
			for (boolean val:row) {if (val) {xcount++;}}
			for (boolean val:col) {if (val) {ycount++;}}
			System.out.println(xcount*ycount);
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