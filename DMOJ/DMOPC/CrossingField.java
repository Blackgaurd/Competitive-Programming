import java.util.*;
import java.io.*;
public class CrossingField {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), h = readInt();
		int field[][] = new int[n][n];
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int x = readInt();
				field[i][j] = x;
			}
		}
		
		boolean visited[][] = new boolean[n][n];
		ArrayList<Integer> qx = new ArrayList<>(), qy = new ArrayList<>();
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		
		qx.add(0); qy.add(0);
		visited[0][0] = true;
		while (!qx.isEmpty()) {
			/*for (int i=0; i<n; i++) {
				System.out.println(Arrays.toString(visited[i]));
			}
			System.out.println();*/
			int curx = qx.get(0), cury = qy.get(0);
			qx.remove(0); qy.remove(0);
			for (int i=0; i<4; i++) {
				try {
					if (!visited[cury+dy[i]][curx+dx[i]] && Math.abs(field[cury][curx]-field[cury+dy[i]][curx+dx[i]])<=h) {
						visited[cury+dy[i]][curx+dx[i]] = true;
						qx.add(curx+dx[i]);
						qy.add(cury+dy[i]);
					}
				} catch (Exception ignore) {};
			}
		}
		if (visited[n-1][n-1]) System.out.println("yes");
		else System.out.println("No");
		
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