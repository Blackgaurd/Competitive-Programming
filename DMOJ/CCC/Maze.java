import java.util.*;
import java.io.*;
public class Maze {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		for (int p=0; p<n; p++) {
			int w = readInt(), l = readInt();
			char town[][] = new char[w][l];
			boolean v[][] = new boolean[w][l];
			int dis[][] = new int[w][l];

			for (int x=0; x<w; x++) {
				char[] t = readLine().toCharArray();

				for (int y=0; y<l; y++) {
					char c = t[y];
					town[x][y] = c;
					if (c=='*') {
						v[x][y] = true;
					}
				}
			}
			int px[] = {-1,1,0,0}, py[] = {0,0,-1,1};
			int h[] = {-1,1};

			ArrayList<Integer> qx = new ArrayList<>(), qy = new ArrayList<>();
			qx.add(0); qy.add(0);
			v[0][0] = true;
			dis[0][0] = 1;
			while (!qx.isEmpty()) {
				int curx = qx.get(0), cury = qy.get(0);
				qx.remove(0); qy.remove(0);
				if (town[curx][cury]=='+') {
					for (int i=0; i<4; i++) {
						try {
							if (!v[curx+px[i]][cury+py[i]]) {
								v[curx+px[i]][cury+py[i]] = true;
								qx.add(curx+px[i]);
								qy.add(cury+py[i]);
								dis[curx+px[i]][cury+py[i]] = dis[curx][cury]+1;
							}
						} catch (Exception ignore) {};
					}
				} else if (town[curx][cury]=='|') {
					for (int i=0; i<2; i++) {
						try {
							if (!v[curx+h[i]][cury]) {
								v[curx+h[i]][cury] = true;
								qx.add(curx+h[i]);
								qy.add(cury);
								dis[curx+h[i]][cury] = dis[curx][cury]+1;
							}
						} catch (Exception ignore) {};
					}
				} else if (town[curx][cury]=='-') {
					for (int i=0; i<2; i++) {
						try {
							if (!v[curx][cury+h[i]]) {
								v[curx][cury+h[i]] = true;
								qx.add(curx);
								qy.add(cury+h[i]);
								dis[curx][cury+h[i]] = dis[curx][cury]+1;
							}
						} catch (Exception ignore) {};
					}
				}
			}
			if (dis[w-1][l-1]==0) System.out.println(-1);
			else System.out.println(dis[w-1][l-1]);
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