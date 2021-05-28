import java.util.*;
import java.io.*;
public class EEECCCOOO {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int i=0; i<n; i++) {
			char[] t= readLine().toCharArray();
			for (int j=0; j<t.length; j++) {
				if (t[i]=='E') System.out.print("Educational ");
				else if (t[i]=='C') System.out.print("Computing ");
				else if (t[i]=='O') {
					System.out.print("Organization of Ontario ");
					j++;
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