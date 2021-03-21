import java.util.*;
import java.io.*;
public class Shahir {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int h = readInt(), r = readInt(), s = readInt()-1, d = readInt()-1;
		List<Integer> adj[] = new ArrayList[h];
		for (int i=0; i<h; i++) {
			adj[i] = new ArrayList();
		}
		for (int i=0; i<r; i++) {
			int a = readInt()-1, b = readInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		List<Integer> queue = new ArrayList<>();
		boolean visited[] = new boolean[h];
		queue.add(s);
		visited[s] = true;
		while (!queue.isEmpty()) {
			int cur = queue.get(0);
			queue.remove(0);
			for (int next:adj[cur]) {
				if (!visited[next]) {
					queue.add(next);
					visited[next] = true;
				}
			}
		}
		if (visited[d]) System.out.println("GO SHAHIR!");
		else System.out.println("NO SHAHIR!");
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