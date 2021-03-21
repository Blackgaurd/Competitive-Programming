import java.util.*;
import java.io.*;
public class Sentences {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int e = readInt();
		for (int t=0; t<e; t++) {
			int n = readInt(), v = readInt(), o = readInt();
			String nouns[] = new String[n], verbs[] = new String[v], objects[] = new String[o];
			for (int i=0; i<n; i++) nouns[i] = readLine();
			for (int i=0; i<v; i++) verbs[i] = readLine();
			for (int i=0; i<o; i++) objects[i] = readLine();
			for (String a: nouns) {
				System.out.print(a+" ");
				for (String b: verbs) {
					System.out.print(b+" ");
					for (String c: objects) {
						System.out.println
					}
				}
			}
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