import java.util.*;
import java.io.*;
public class RunningInCircles {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		for (int l=0; l<5; l++) {
			int n = readInt();
			ArrayList<Integer> adj[] = new ArrayList[101];
			int vis[] = new int[101];
			for (int i=1; i<=100; i++) {
				adj[i] = new ArrayList<>();
			}
			int x = readInt(), y = readInt();
			adj[x].add(y);
			for (int i=0; i<n-1; i++) {
				int a = readInt(), b = readInt();
				adj[a].add(b);
			}
			dfs(x, adj, vis);
		}
	}
	static void dfs(int v, ArrayList<Integer> adj[], int vis[]) {
		vis[v] = 1;
		System.out.println(v);
		for (int nxt:adj[v]) {
			if (vis[nxt]==0) {
				dfs(vis[nxt],adj,vis);
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