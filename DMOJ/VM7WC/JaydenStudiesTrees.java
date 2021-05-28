import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
public class JaydenStudiesTrees {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	public static void main(String[] args) throws IOException{
		n = readInt();;
		ArrayList<Integer> adj[] = new ArrayList[n+1];
		for (int i=1; i<=n; i++) {
			adj[i] = new ArrayList<>();
		}
		int t = 0;
		for (int i=0; i<n-1; i++) {
			int a = readInt(), b = readInt();
			adj[a].add(b);
			adj[b].add(a);
			t=a;
		}
		int m = bfs(t,adj)[0];
		//System.out.println(m);
		System.out.println(bfs(m,adj)[1]);
	}
	static int[] bfs(int x, ArrayList<Integer> adj[]) {
		Queue<Integer> q = new LinkedList<>();
		boolean v[] = new boolean[n+1];
		int dis[] = new int[n+1];
		q.add(x); v[x] = true; dis[x] = 0;
		while (!q.isEmpty()) {
			int cur = q.poll();
			for (int nxt: adj[cur]) {
				if (!v[nxt]) {
					v[nxt] = true;
					q.add(nxt);
					dis[nxt] = dis[cur]+1;
				}
			}
		}
		int max = 0;
		for (int i=0; i<dis.length; i++) {
			max = dis[i] > dis[max] ? i:max;
		}
		int[] s = {max, dis[max]};
		return s;
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