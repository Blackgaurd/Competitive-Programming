import java.util.*;
import java.io.*;
public class KnightHop {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int fx = readInt()-1, fy = readInt()-1;
		int tx = readInt()-1, ty = readInt()-1;
		
		boolean visited[][] = new boolean[8][8];
		int distance[][] = new int[8][8];
		
		ArrayList<Integer> qx = new ArrayList<>();
		ArrayList<Integer> qy = new ArrayList<>();
		
		int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
		int dy[] = {-2, -2, -1, 1, 2, 2, 1, -1};
		
		qx.add(fx); qy.add(fy);
		visited[fy][fx] = true;
		distance[fy][fx] = 0;
		while (!qx.isEmpty()) {
			int curx = qx.get(0), cury = qy.get(0);
			qx.remove(0); qy.remove(0);
			
			for (int i=0; i<8; i++) {
				try {
					if (!visited[cury+dy[i]][curx+dx[i]]) {
						visited[cury+dy[i]][curx+dx[i]]  = true;
						qx.add(curx+dx[i]);
						qy.add(cury+dy[i]);
						distance[cury+dy[i]][curx+dx[i]] = distance[cury][curx]+1;
					}
				} catch (Exception ignore) {};
			}
		}
		System.out.println(distance[ty][tx]);
		
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