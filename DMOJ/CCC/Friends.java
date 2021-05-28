import java.util.*;
import java.io.*;
public class Friends {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> adj[] = new ArrayList[10000];
	public static void main(String[] args) throws IOException{
		for (int i=1; i<10000; i++) adj[i] = new ArrayList<>();
		int n = readInt();
		for (int i=0; i<n; i++) {
			int a = readInt(), b = readInt();
			adj[a].add(b);
		}
		while (true) {
			int a = readInt(), b = readInt();
			if (a==0) break;
			if (bfs(a,b)==-1) System.out.println("No");
			else System.out.println("Yes "+bfs(a,b));
		}
	}
	static int bfs(int u, int v) {
		boolean vis[] = new boolean[10000];
		int dis[] = new int[10000];
		Queue<Integer> q = new LinkedList<>();
		q.add(u);
		vis[u] = true;
		dis[u] = 1;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt: adj[cur]) {
				if (!vis[nxt]) {
					vis[nxt] = true;
					q.add(nxt);
					dis[nxt] = dis[cur]+1;
				}
			}
		}
		if (dis[v]==0) return -1;
		else return dis[v]-dis[u]-1;
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