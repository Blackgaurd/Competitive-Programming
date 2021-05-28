import java.util.*;
import java.io.*;
public class TombRobbing
 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean vis[][];
	static int r, c, t = 0, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
	public static void main(String[] args) throws IOException{
		r = readInt(); c = readInt();
		vis = new boolean [r][c];
		for (int i=0; i<r; i++) {
			char p[] = readLine().toCharArray();
			for (int j=0; j<c; j++) {
				if (p[j]=='X') vis[i][j] = true;
			}
		}
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (!vis[i][j]) {
					dfs(i,j);
					t++;
				}
			}
		}
		System.out.println(t);
	}
	static void dfs(int x, int y) {
		vis[x][y] = true;
		for (int i=0; i<4; i++) {
			try {
				if (!vis[x+dx[i]][y+dy[i]]) {
					dfs(x+dx[i], y+dy[i]);
				}
			} catch (Exception ignore) {};
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