import java.util.*;
import java.io.*;
public class Mispelling {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int i=1; i<=n; i++) {
			String t[] = readLine().split(" ", 2);
			
			char c[] = t[1].toCharArray();
			System.out.print(i+" ");
			for (int j=0; j<c.length; j++) {
				if (j!=Integer.parseInt(t[0])-1) System.out.print(c[j]);
			}
			System.out.println();
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