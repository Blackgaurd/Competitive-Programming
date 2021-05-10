import java.util.*;
import java.io.*;
public class NewStudent {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		double n = readDouble();
		long sum = 0L;
		for (int i=0; i<n; i++) {
			sum+=readInt();
		}
		int m = readInt();
		for (double i=1d; i<=m; i++) {
			sum+=readInt();
			double mean = sum/(n+i);
			//mean = (double) Math.round(mean*1000d)/1000d;
			System.out.printf("%.3f %n", mean);
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