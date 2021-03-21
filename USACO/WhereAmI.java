import java.util.*;
import java.io.*;
public class WhereAmI {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		String t = readLine();
		char arr[] = new char[n];
		for (int i=0; i<n; i++) {
			arr[i] = t.charAt(i);
		}
		
		for (int i=1; i<=n; i++) { //length of subset
			ArrayList<String> sub = new ArrayList<String>();
			for (int j=0; j<n-i+1; j++) { //begin index of subset
				String subset = new String(Arrays.copyOfRange(arr, j, i+j));
				if (sub.contains(subset)){
					break;
				}
				sub.add(subset);
				if (j==n-i) {
					System.out.println(i);
					System.exit(0);
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