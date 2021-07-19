// CCC '03 S3 - Floor Plan


import java.util.*;
import java.io.*;

public class FloorPlan {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean vis[][];
	static int r, c, t = 0, dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 };
	public static void main(String[] args) throws IOException {
		int m = readInt(), rooms = 0;
		r = readInt();
		c = readInt();
		vis = new boolean[r][c];
		for (int i = 0; i < r; i++) {
			char p[] = readLine().toCharArray();
			for (int j = 0; j < c; j++) {
				if (p[j] == 'I')
					vis[i][j] = true;
			}
		}
		ArrayList<Integer> sizes = new ArrayList<>();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (!vis[i][j]) {
					dfs(i, j);
					sizes.add(t);
					t = 0;
				}
			}
		}
		Collections.sort(sizes, Collections.reverseOrder());
		// System.out.println(sizes);
		for (int i = 0; i < sizes.size(); i++) {
			if (m >= sizes.get(i)) {
				rooms++;
				m -= sizes.get(i);
			} else
				break;
		}
		if (rooms != 1)
			System.out.println(rooms + " rooms, " + m + " square metre(s) left over");
		else
			System.out.println(rooms + " room, " + m + " square metre(s) left over");
	}
	static void dfs(int x, int y) {
		t++;
		vis[x][y] = true;
		for (int i = 0; i < 4; i++) {
			try {
				if (!vis[x + dx[i]][y + dy[i]]) {
					dfs(x + dx[i], y + dy[i]);
				}
			} catch (Exception ignore) {
			}
			;
		}
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}