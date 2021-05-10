import java.util.*;
import java.io.*;
public class Rimuru {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		long n = readLong();
		ArrayList<Long> nums = new ArrayList<Long>();
		nums.add(0L);
		int ind = 0, count = 0;
		while (true) {
			long a = nums.get(ind)*10+2;
			if (a<=n) {
				nums.add(a);
				count++;
			} else break;
			a = nums.get(ind)*10+3;
			if (a<=n) {
				nums.add(a);
				count++;
			} else break;
			ind++;
		}
		System.out.print(count);
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