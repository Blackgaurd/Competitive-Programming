import java.util.*;
import java.io.*;
public class SurpriseTeleport {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		//read room input
		int r = readInt(), c = readInt(), sr = readInt(), sc = readInt(), er = readInt(), ec = readInt();
		boolean vis[][] = new boolean[1001][1001];
		for (int i=0; i<r; i++) {
			char ch[] = readLine().toCharArray();
			for (int j=0; j<c; j++) {
				if (ch[j]=='X') vis[i][j] = true; // cant walk into wall
			}
		}
		//bfs and label distance for each coordinate
		vis[sr][sc] = true;
		int dis[][] = new int[1001][1001], dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
		Queue<Integer> qx = new LinkedList<>(), qy = new LinkedList<>();
		dis[sr][sc] = 1;
		qx.add(sr); qy.add(sc);
		while (!qx.isEmpty()) {
			int curx = qx.poll(), cury = qy.poll();
			for (int i=0; i<4; i++) {
				try {
					if (!vis[curx+dx[i]][cury+dy[i]]) {
						vis[curx+dx[i]][cury+dy[i]] = true;
						dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
						qx.add(curx+dx[i]); qy.add(cury+dy[i]);
					}
				} catch (Exception ignore) {};
			}
		}
		// read input and find time saved
		int q = readInt(), max = 0;
		for (int i=0; i<q; i++) {
			int a = readInt(), b = readInt();
			if (a<r && b<c) {
				if (dis[a][b]>0) {
					max = Math.max(max, dis[er][ec]-dis[a][b]);
				}
			}
		}
		System.out.println(max);
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