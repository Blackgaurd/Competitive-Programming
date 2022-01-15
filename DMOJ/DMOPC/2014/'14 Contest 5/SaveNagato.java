// DMOPC '14 Contest 5 P6 - Save Nagato!

import java.util.*;
import java.io.*;
public class SaveNagato {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n, last;
	static ArrayList<Integer> adj[];
	public static void main(String[] args) throws IOException{
		n = readInt();
		adj = new ArrayList[n+1];
		for (int i=1; i<=n; i++) adj[i] = new ArrayList<>();
		for (int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		int[] dis1 = new int[n+1], dis2 = new int[n+1];
		bfs(1, dis1); bfs(last, dis1); bfs(last, dis2);
		for (int i=1; i<=n; i++) {
			System.out.println(Math.max(dis1[i], dis2[i]));
		}
	}
	static void bfs(int start, int dis[]) {
		boolean vis[] = new boolean[n+1];
		Queue<Integer> q = new LinkedList<>();
		q.add(start);
		vis[start] = true;
		dis[start] = 1;
		while (!q.isEmpty()) {
			int cur = q.poll(); last = cur;
			for (int nxt: adj[cur]) {
				if (!vis[nxt]) {
					vis[nxt] = true;
					q.add(nxt);
					dis[nxt] = dis[cur]+1;
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