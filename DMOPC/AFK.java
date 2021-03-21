import java.util.*;
import java.io.*;
public class AFK {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int p=0; p<n; p++) {
			int l = readInt(), w = readInt(), fx=0, fy=0, tx=0, ty=0;
			char room[][] = new char[w][l];
			boolean v[][] = new boolean[w][l];
			int dis[][] = new int[w][l];
			
			for (int x=0; x<w; x++) {
				char[] t = readLine().toCharArray();

				for (int y=0; y<l; y++) {
					char c = t[y];
					room[x][y] = c;
					if (c=='X') {
						v[x][y] = true;
					} else if (c=='C') {
						fx = x; fy = y;
					} else if (c=='W') {
						tx = x; ty = y;
					} 
				}
			}
			int dx[] = {1, -1, 0, 0};
			int dy[] = {0, 0, 1, -1};
			
			ArrayList<Integer> qx = new ArrayList<>(), qy = new ArrayList<>();
			qx.add(fx); qy.add(fy);
			v[fx][fy] = true;
			dis[fx][fy] = 0;
			while (!qx.isEmpty()) {
				int curx = qx.get(0), cury = qy.get(0);
				qx.remove(0); qy.remove(0);
				for (int i=0; i<4; i++) {
					try {
						if (!v[curx+dx[i]][cury+dy[i]]) {
							v[curx+dx[i]][cury+dy[i]] = true;
							qx.add(curx+dx[i]);
							qy.add(cury+dy[i]);
							dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
						}
					} catch (Exception ignore) {};
				}
			}
			if (dis[tx][ty]>=60 || dis[tx][ty]==0) System.out.println("#notworth");
			else System.out.println(dis[tx][ty]);
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