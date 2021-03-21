import java.util.*;
import java.io.*;
public class PursuitofKnowledge {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> adj[];
	static int n, m, t;
	public static void main(String[] args) throws IOException{
		n = readInt(); m = readInt(); t = readInt();
		adj = new ArrayList[n+1];
		for (int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		for (int i=0; i<m; i++) {
			int a = readInt(), b = readInt();
			adj[a].add(b); 
		}
		int ans[][] = new int[n+1][n+1];
		for (int i=1; i<=n; i++) {
			int dis[] = new int[n+1];
			bfs(dis, i);
			ans[i] = dis;
		}
		int q = readInt();
		for (int i=0; i<q; i++) {
			int a = readInt(), b = readInt();
			if (ans[a][b]==0) System.out.println("Not enough hallways!");
			else System.out.println(ans[a][b]);
		}
	}

	static void bfs(int dis[], int v) {
		boolean vis[] = new boolean[n+1];
		Queue<Integer> q = new LinkedList<>();
		q.add(v);
		vis[v] = true;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt:adj[cur]) {
				if (!vis[nxt]) {
					vis[nxt] = true;
					q.add(nxt);
					dis[nxt] = dis[cur]+t;
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