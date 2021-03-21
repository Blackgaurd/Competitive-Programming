import java.util.*;
import java.io.*;
public class BlueBookPrime {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		boolean p[] = new boolean[70001];
		p[1] = true;
		for (int i=4; i<=70000; i+=2) {
			p[i] = true;
		}
		for (int i=3; i<70000; i+=2) {
			if (!p[i]) {
				for (int j=i+i; j<70000; j+=i) {
					p[j] = true;
				}
			}
		}
		int n = readInt();
		for (int i=0; i<n; i++) {
			if (p[readInt()]) System.out.println(0);
			else System.out.println(1);
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