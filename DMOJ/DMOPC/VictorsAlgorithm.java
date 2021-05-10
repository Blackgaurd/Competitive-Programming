import java.util.*;
import java.io.*;
public class VictorsAlgorithm {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), arr[] = new int[n], max = Integer.MIN_VALUE, ind = 0;
		for (int i=0; i<n; i++) {
			int a = readInt();
			if (a>max) {
				max = a;
				ind = i;
			}
			arr[i] = a;
		}
		int x = Integer.MIN_VALUE, sum = 0;
		for (int i=0; i<=ind; i++) {
			if (arr[i]>x) {
				x = arr[i];
			} else sum+=x-arr[i];
			System.out.println(arr[i]+" "+sum);
		}
		x = Integer.MIN_VALUE;
		for (int i=n-1; i>ind; i--) {
			if (arr[i]>x) {
				x = arr[i];
			} else sum+=x-arr[i];
			System.out.println(arr[i]+" "+sum);
		}
		System.out.println(sum);
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