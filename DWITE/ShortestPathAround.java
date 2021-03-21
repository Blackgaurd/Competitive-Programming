import java.util.*;
import java.io.*;
public class ShortestPathAround {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int dx[] = {0,1,1,1,0,-1,-1,-1}, dy[] = {1,1,0,-1,-1,-1,0,1};
	public static void main(String[] args) throws IOException{
		fun();
		readLine();
		fun();
		readLine();
		fun();
		readLine();
		fun();
		readLine();
		fun();
	}
	static void fun() throws IOException {
		boolean vis[][] = new boolean[10][10];
		int dis[][] = new int[10][10];
		int sx = -1, sy = -1, ex = -1, ey = -1;
		for (int i=0; i<10; i++) {
			char t[] = readLine().toCharArray();
			for (int j=0; j<10; j++) {
				if (t[j]=='#') vis[i][j] = true;
				else if (t[j]=='X') {
					if (sx==-1) {
						sx = i; sy = j;
					} else {ex = i; ey = j;}
				}
			}
		}
		
		Queue<Integer> qx = new LinkedList<>(), qy = new LinkedList<>();
		qx.add(sx); qy.add(sy);
		vis[sx][sx] = true;
		while (!qx.isEmpty()) {
			int curx = qx.poll(), cury = qy.poll();
			if (curx==ex && cury==ey) break;
			for (int i=0; i<8; i++) {
				try {
					if (!vis[curx+dx[i]][cury+dy[i]]) {
						vis[curx+dx[i]][cury+dy[i]] = true;
						qx.add(curx+dx[i]); qy.add(cury+dy[i]);
						dis[curx+dx[i]][cury+dy[i]] = dis[curx][cury]+1;
					}
				} catch (Exception ignore) {};
			}
		}
		System.out.println(dis[ex][ey]);
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