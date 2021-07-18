// Sleigh Ride

import java.util.*;
import java.io.*;
public class SleighRide {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt()+1, sum = 0, max = 0;
		ArrayList<Edge> adj[] = new ArrayList[n];
		for (int i=0; i<n; i++) adj[i] = new ArrayList<>();
		for (int i=1; i<n; i++) {
			int u = readInt(), v = readInt(), w = readInt();
			sum+=w;
			adj[u].add(new Edge(v,w));
			adj[v].add(new Edge(u,w));
		}
		Queue<Integer> q = new LinkedList<>();
		int dis[] = new int[n];
		boolean vis[] = new boolean[n];
		q.add(0); vis[0] = true;
		while (!q.isEmpty()) {
			int u = q.poll();
			max = Math.max(max,  dis[u]);
			for (Edge e: adj[u]) {
				int v = e.v, w = e.w;
				if (!vis[v]) {
					q.add(v);
					vis[v] = true;
					dis[v] = dis[u]+w;
				}
			}
		}
		System.out.println(2*sum-max);
	}
	static class Edge {
		public int v, w;
		Edge (int v0, int w0) {v = v0; w = w0;}
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