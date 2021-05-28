import java.util.*;
import java.io.*;
public class LilJami {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), k = readInt(), cups[] = new int[n], psa[] = new int[n+1];
		for (int i=0; i<k; i++) {
			int a = readInt();
			cups[a]++;
		}
		psa[0]=0;
		for (int i=1; i<=n; i++) {
			psa[i] = psa[i-1]+cups[i-1];
		}
		int q = readInt();
		for (int i=0; i<q; i++) {
			int a = readInt(), b = readInt();
			int sum = psa[b+1]-psa[a];
			System.out.println(sum);
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