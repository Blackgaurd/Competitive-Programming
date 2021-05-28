// CCC '13 S4 - Who is Taller?

import java.util.*;
import java.io.*;
public class WhoIsTaller {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static int n;
	public static void main(String[] args) throws IOException{
		n = readInt(); 
		int m = readInt();
		ArrayList<Integer> p[] = new ArrayList[n+1];
		for (int i=1; i<=n; i++) {
			p[i] = new ArrayList<>();
		}
		for (int i=0; i<m; i++) {
			int a = readInt(), b = readInt();
			p[a].add(b);
		}
		int x = readInt(), y = readInt();
		if (taller(p, x, y)) System.out.println("yes");
		else if (taller(p, y, x)) System.out.println("no");
		else System.out.println("unknown");
		//System.out.println(taller(p, x, y));
		//System.out.println(taller(p, y, x));
	}
	static boolean taller(ArrayList<Integer> p[], int x, int y) {
		ArrayList<Integer> q = new ArrayList<>();
		boolean v[] = new boolean[n+1];
		q.add(x);
		v[x] = true;
		while (!q.isEmpty()) {
			int cur = q.get(0);
			q.remove(0);
			for (int person: p[cur]) {
				if (!v[person]) {
					v[person] = true;
					q.add(person);
				}
			}
		}
		if (v[y]) return true;
		return false;
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