import java.util.*;
import java.io.*;
public class BridgesInAGraph {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, low[], tin[], t, bridges;
	static boolean vis[];
	public static void main(String[] args) throws IOException{
		for (int e=0; e<5; e++) {
			bridges = 0; t = 0;
			n = readInt();
			int m = readInt();
			vis = new boolean[n+1];
			low = new int[n+1]; tin = new int[n+1];
			Arrays.fill(low, -1); Arrays.fill(tin, -1);
			ArrayList<Integer> adj[] = new ArrayList[n+1];
			for (int i=1; i<=n; i++) adj[i] = new ArrayList();
			for (int i=0; i<m; i++) {
				int a = readInt(), b = readInt();
				adj[a].add(b); adj[b].add(a);
			}
			dfs (adj, 1, -1);
			System.out.println(bridges);
			
		}
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