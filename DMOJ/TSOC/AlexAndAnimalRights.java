import java.util.*;
import java.io.*;
public class AlexAndAnimalRights {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	static boolean vis[][];
	static char room[][];
	public static void main(String[] args) throws IOException{
		int r = readInt(), c = readInt(), sum=0;
		vis = new boolean[r][c];
		room = new char[r][c];
		for (int i=0; i<r; i++) {
			char t[] = readLine().toCharArray();
			room[i] = t;
			for (int j=0; j<c; j++) {
				if (t[j]=='#') vis[i][j] = true;
			}
		}
		
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (!vis[i][j]) {
					if (bfs(i,j)) sum++;
				}
			}
		}
		System.out.println(sum);
	}
	static boolean dfs(int x, int y) {
		boolean m = false;
		if (room[x][y]=='M') m = true;
		vis[x][y] = true;
		for (int i=0; i<4; i++) {
			try {
				if (!vis[x+dx[i]][y+dy[i]]) {
					dfs(x+dx[i], y+dy[i]);
				}
			} catch (Exception ignore) {};
		}
		return m;
	}
	static boolean bfs(int x, int y) {
		boolean m = false;
		Queue<Integer> qx = new LinkedList<>(), qy = new LinkedList<>();
		qx.add(x); qy.add(y);
		while (!qx.isEmpty()) {
			int curx = qx.poll(), cury = qy.poll();
			if (room[curx][cury] == 'M') m = true;
			for (int i=0; i<4; i++) {
				try {
					if (!vis[curx+dx[i]][cury+dy[i]]) {
						vis[curx+dx[i]][cury+dy[i]] = true;
						qx.add(curx+dx[i]); qy.add(cury+dy[i]);
					}
				} catch (Exception ignore) {};
			}
		}
		return m;
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