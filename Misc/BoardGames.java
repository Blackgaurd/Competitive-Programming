import java.util.*;
import java.io.*;
public class BoardGames {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), m = readInt();
		int dis[] = new int[1000000];
		boolean vis[] = new boolean[1000000];
		vis[n] = true;
		Queue<Integer> q = new LinkedList<>();
		q.add(n);
		while (!q.isEmpty()) {
			int cur = q.poll();
			if (cur==m) break;
			if (cur*3<1000000) {
				if (!vis[cur*3]) {
					vis[cur*3] = true;
					q.add(cur*3);
					dis[cur*3] = dis[cur]+1;
				}
			}
			if (cur>=1) {
				if (!vis[cur-1]) {
					vis[cur-1] = true;
					q.add(cur-1);
					dis[cur-1] = dis[cur]+1;
				}
			}
			if (cur>=3) {
				if (!vis[cur-3]) {
					vis[cur-3] = true;
					q.add(cur-3);
					dis[cur-3] = dis[cur]+1;
				}
			}
			if (cur%2==0) {
				if (!vis[cur/2]) {
					vis[cur/2] = true;
					q.add(cur/2);
					dis[cur/2] = dis[cur]+1;
				}
			}
		}
		System.out.println(dis[m]);
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