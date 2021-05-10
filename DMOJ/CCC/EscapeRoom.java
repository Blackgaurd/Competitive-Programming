import java.util.*;
import java.io.*;
public class EscapeRoom {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static ArrayList<Integer> factors[];
	public static void main(String[] args) throws IOException{
		
		int x = readInt(), y = readInt();
		int arr[][] = new int[x+1][y+1];
		for (int i = 1; i<=x; i++) {
			for (int j = 1; j<=y; j++) {
				arr[i][j] = readInt();
			}
		}
		System.out.println(bfs(arr, x, y));
	}
	static String bfs(int arr[][], int x, int y) {
		ArrayList<Integer> factors[] = new ArrayList[1000001];
		for (int i=1; i<=1000000; i++) {
			factors[i] = fac(i);
		}
		Queue<Integer> qx = new LinkedList<>(), qy = new LinkedList<>();
		boolean vis[][] = new boolean[x+1][y+1];
		qx.add(1); qy.add(1);
		vis[1][1] = true;
		while (!qx.isEmpty()) {
			int curx = qx.poll(), cury = qy.poll();
			ArrayList<Integer> nums = factors[arr[curx][cury]];
			for(int i=0; i<nums.size(); i+=2) {
				int a = nums.get(i), b = nums.get(i+1);
				if (a==x && b==y) return "yes";
				if (b==x && a==y) return "yes";
				try {
					if (!vis[a][b]) {
						vis[a][b] = true;
						qx.add(a); qy.add(b);
					}
					if (!vis[b][a]) {
						vis[b][a] = true;
						qx.add(b); qy.add(a);
					}
				} catch (Exception ignore) {};
			}
		}
		if (vis[x][y]) return "yes";
		else return "no";
	}
	static ArrayList<Integer> fac(int x) {
		ArrayList<Integer> nums= new ArrayList<>();
		int p = x%2==0? 1:2;
		for (int i=1; i<=Math.sqrt(x); i+=p) {
			if (x%i==0) {
				nums.add(i);
				nums.add(x/i);
			}
		}
		return nums;
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