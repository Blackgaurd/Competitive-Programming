import java.util.*;
import java.io.*;
public class FreeShirts {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for (int t=0; t<10; t++) {
			int n = readInt(), m = readInt(), d = readInt(), clean = n, total = n, count = 0;
			int arr[] = new int[d];
			for (int i=0; i<m; i++) {
				int e = readInt()-1;
				arr[e]++;
			}
			for (int i=0; i<d; i++) {
				if (clean==0) {
					count++;
					clean = total;
				}
				clean--;
				if (arr[i]!=0) {
					clean+=arr[i];
					total+=arr[i];
				}
			}
			System.out.println(count);
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