import java.util.*;
import java.io.*;
public class VictorGetsQuizzed {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int i=0; i<n; i++) {
			char test[] = readLine().toCharArray();
			boolean M = false, C = false;
			for (char t:test) {
				if (t=='M') M = true;
				if (t=='C') C = true;
			}
			if (M != C) System.out.println("FAIL");
			else if (M && C) System.out.println("NEGATIVE MARKS");
			else System.out.println("PASS");
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