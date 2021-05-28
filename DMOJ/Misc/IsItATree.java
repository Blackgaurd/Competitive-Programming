import java.util.*;
import java.io.*;
public class IsItATree {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int arr[][] = new int[4][4], edges = 0;
		HashSet<Integer> nodes = new HashSet<Integer>();
		
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				arr[i][j] = readInt();
			}
		}
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (arr[i][j]==1) {
					nodes.add(i); nodes.add(j);
					edges++;
				}
			}
		}
		edges/=2;
		if (edges+1==nodes.size()) {
			System.out.println("Yes");
		} else System.out.println("No");
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