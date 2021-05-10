import java.util.*;
import java.io.*;
public class CyclopianPuzzle {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static void hanoi(int n, String from, String mid, String to) {
		if (n==1) {
			System.out.println(from+to);
			return;
		}
		hanoi(n-1, from, to, mid);
		System.out.println(from+to);
		hanoi(n-1, mid, from, to);
	}
	public static void main(String[] args) throws IOException{
		int n = readInt();
		hanoi(n, "A", "B", "C");
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