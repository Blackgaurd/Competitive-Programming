import java.util.*;
import java.io.*;
public class TripleFatLadies {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		// ends in 192, 442, 692, 942
		int n = readInt();
		for (int i=0; i<n; i++) {
			int a = readInt();
			int r = a%1000;
			if (a>999) {int q = a/1000;}
			String rs = Integer.toString(r);
			if (r<=192) System.out.println(q+"192");
			else if (r<=442) System.out.println(q+442);
			else if (r<=692) System.out.println(q+692);
			else if (r<=942) System.out.println(q+942);
			else System.out.println(Integer.parseInt(q)+1)
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