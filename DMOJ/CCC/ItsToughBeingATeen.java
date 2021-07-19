// CCC '06 J4 - It's tough being a teen!

import java.util.*;
import java.io.*;

public class ItsToughBeingATeen {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static boolean adj[][] = new boolean[8][8];
	static boolean cycle = false;

	public static void main(String[] args) throws IOException {
		adj[1][7] = true;
		adj[1][4] = true;
		adj[2][1] = true;
		adj[3][4] = true;
		adj[3][5] = true;
		while (true) {
			int a = readInt(), b = readInt();
			if (a == 0)
				break;
			adj[a][b] = true;
		}
		for (int i = 1; i <= 7; i++) {
			int vis[] = new int[8];
			dfs(i, vis);
		}
		if (cycle)
			System.out.println("Cannot complete these tasks. Going to bed.");
		else {
			boolean done[] = new boolean[8];
			for (int t = 1; t <= 7; t++) {
				int pre[] = new int[8];
				for (int i = 1; i <= 7; i++) {
					for (int j = 1; j <= 7; j++) {
						if (adj[i][j])
							pre[j] += 1;
					}
				}
				for (int i = 1; i <= 7; i++) {
					if (pre[i] == 0 && !done[i]) {
						done[i] = true;
						System.out.print(i + " ");
						Arrays.fill(adj[i], false);
						break;
					}
				}
			}
		}
	}

	static void dfs(int i, int vis[]) {
		vis[i] = 1;
		for (int v = 1; v <= 7; v++) {
			if (adj[i][v]) {
				if (vis[v] == 1) {
					cycle = true;
					return;
				} else if (vis[v] == 0)
					dfs(v, vis);
			}
		}
		vis[i] = 2;
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