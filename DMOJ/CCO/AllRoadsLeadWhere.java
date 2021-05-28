import java.util.*;
import java.io.*;
public class AllRoadsLeadWhere {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		ArrayList<Integer> adj[] = new ArrayList[27];
		for (int i=1; i<=26; i++) {
			adj[i] = new ArrayList<>();
		}
		
		for (int i=0; i<n; i++) { 
			String t[] = readLine().split(" ");
			int c1 = t[0].charAt(0)-'@', c2 = t[1].charAt(0)-'@'; 
			adj[c1].add(c2);
			adj[c2].add(c1);
		}
		
		for (int i=0; i<m; i++) {
			String t[] = readLine().split(" ");
			int start = t[0].charAt(0)-'@', end = t[1].charAt(0)-'@';
			
			Queue<Integer> q = new LinkedList<>();
			boolean v[] = new boolean[27];
			int prev[] = new int[27];
			q.add(end); v[end] = true; prev[end] = -1;
			while (!q.isEmpty()) {
				int cur = q.poll();
				for (int nxt: adj[cur]) {
					if (!v[nxt]) {
						v[cur] = true;
						q.add(nxt);
						prev[nxt] = cur;
					}
				}
			}
			
			for (int x=start; x!=-1; x=prev[x]) {
				System.out.print((char) (x+'@'));
			} System.out.println();
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