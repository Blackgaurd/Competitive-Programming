import java.util.*;
import java.io.*;
public class DirectedGraphConnectivity {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int t, low[], tin[];
	static boolean vis[];
	public static void main(String[] args) throws IOException{
		int n = readInt();
	}
	static void dfs(ArrayList<Integer> adj[], int v, int p) {
		t++;
		vis[v] = true;
		tin[v] = t;
		low[v] = t;
		for (int nxt: adj[v]) {
			if (nxt==p) continue;
			if (vis[nxt]) low[v] = Math.min(low[v], tin[nxt]);
			else {
				dfs(adj, nxt, v);
				low[v] = Math.min(low[v],  low[nxt]);
				if (low[nxt]>tin[v]) bridges++;
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