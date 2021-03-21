import java.util.*;
import java.io.*;
public class DirectedAcyclicGraph {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, vis[];
	static boolean adj[][], cycle = false;
	public static void main(String[] args) throws IOException{
		n = readInt(); vis = new int[n]; adj = new boolean[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				adj[i][j] = readInt()==1? true:false;
			}
		}
		for (int i=0; i<n; i++) {
			if (vis[i]==0) dfs(i);
		}
		if (cycle) System.out.println("NO");
		else System.out.println("YES");
	}
	static void dfs(int i) {
		vis[i] = 1;
		for (int v=0; v<n; v++) {
			if (adj[i][v]) {
				if (vis[v]==1) {
					cycle = true;
					return;
				} else if (vis[v]==0) dfs(v);
			}
		}
		vis[i] = 2;
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