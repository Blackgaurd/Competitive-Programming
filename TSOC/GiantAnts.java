import java.util.*;
import java.io.*;
public class GiantAnts {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		List<Integer> adj[] = new ArrayList[n+1];
		for (int i=1; i<=n; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for (int i=1; i<=m; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v);
			adj[v].add(u);
		}
		int w = readInt(), ants[] = new int[n+1], dis[] = new int[n+1];
		List<Integer> q = new ArrayList<>();
		boolean v[] = new boolean[n+1];
		for (int i=1; i<=w; i++) {
			int x = readInt();
			q.add(x);
			v[x] = true;
		}
		while (!q.isEmpty()) {
			int cur = q.get(0);
			q.remove(0);
			for (int nxt:adj[cur]) {
				if (!v[nxt]) {
					q.add(nxt);
					v[nxt] = true;
					ants[nxt] = ants[cur]+4;
				}
			}
		}
		Arrays.fill(v, false);
		q.add(1);
		v[1] = true;
		dis[1] = 0;
		while (!q.isEmpty()) {
			int cur = q.get(0);
			q.remove(0);
			for (int nxt:adj[cur]) {
				if (!v[nxt] && dis[cur]+1<ants[nxt]) {
					q.add(nxt);
					v[nxt] = true;
					dis[nxt] = dis[cur]+1;
				}
			}
		}
		if (v[n]) System.out.println(dis[n]);
		else System.out.println("sacrifice bobhob314");
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