import java.util.*;
import java.io.*;
public class Rectangles {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), x[] = new int[n], y[] = new int[n], M = (int) 1e5;
		Set<Long> set = new HashSet<>();
		for (int i=0; i<n; i++) {
			x[i] = readInt(); y[i] = readInt();
			set.add((long) x[i]*M + y[i]);
		}
		int ans = 0;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				if (set.contains(1L*x[i]*M+y[j]) && set.contains(1L*x[j]*M+y[i])) {
					ans = Math.max(ans, Math.abs(x[i]-x[j])*Math.abs(y[i]-y[j]));
				}
			}
		}
		System.out.println(ans);
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