// DMOPC '17 Contest 2 P3 - Bad Bunnies

import java.util.*;
import java.io.*;
public class BadBunnies {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), r = readInt();
		ArrayList<Integer> adj[] = new ArrayList[n+1];
		for (int i=1; i<=n; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for (int i=1; i<n; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v); adj[v].add(u);
		}
		Queue<Integer> q = new LinkedList<>();
		boolean v[] = new boolean[n+1];
		int dis[] = new int[n+1];
		for (int i=1; i<=r; i++) {
			int a = readInt();
			q.add(a);
			v[a] = true;
			dis[a] = 0;
		}
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt: adj[cur]) {
				if (!v[nxt]) {
					q.add(nxt);
					v[nxt] = true;
					dis[nxt] = dis[cur]+1;
				}
			}
		}
		int start = readInt(), end = readInt(), prev[] = new int[n+1];
		Arrays.fill(v, false);
		q.add(start);
		v[start] = true;
		prev[start] = -1;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt: adj[cur]) {
				if (!v[nxt]) {
					q.add(nxt);
					v[nxt] = true;
					prev[nxt] = cur;
				}
			}
		}
		int ans = Integer.MAX_VALUE;
		for (int i=end; i!=-1; i=prev[i]) {
			ans = Math.min(ans, dis[i]);
		}
		System.out.println(ans);
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