// CCC '05 S4 - Pyramid Message Scheme

import java.util.*;
import java.io.*;
public class PyramidMessageScheme {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int e=0; e<n; e++) {
			int m = readInt(), dis = 0, max = 0;
			String names[] = new String[m+1];
			//names[0] = "Home";
			for (int i=1; i<=m; i++) {
				names[i] = readLine();
			}
			names[0] = names[m];
			HashSet<String> vis = new HashSet<>();
			for (String str: names) {
				if (vis.contains(str)) dis--;
				else {
					vis.add(str);
					max = Math.max(max, dis++);
				}
			}
			System.out.println((m-max*2)*10);
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