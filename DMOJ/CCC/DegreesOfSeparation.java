// CCC '09 S3 - Degrees Of Separation

import java.util.*;
import java.io.*;

public class DegreesOfSeparation {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		HashSet<Integer> p[] = new HashSet[50];
		for (int i = 0; i < 50; i++) {
			p[i] = new HashSet<Integer>();
		}
		ap(p, 2, 6);
		ap(p, 1, 6);
		ap(p, 6, 3);
		ap(p, 6, 4);
		ap(p, 6, 5);
		ap(p, 6, 7);
		ap(p, 3, 4);
		ap(p, 4, 5);
		ap(p, 7, 8);
		ap(p, 3, 5);
		ap(p, 8, 9);
		ap(p, 9, 10);
		ap(p, 9, 12);
		ap(p, 11, 10);
		ap(p, 11, 12);
		ap(p, 3, 15);
		ap(p, 13, 15);
		ap(p, 12, 13);
		ap(p, 13, 14);
		ap(p, 16, 17);
		ap(p, 17, 18);
		ap(p, 16, 18);
		while (true) {
			char c = readCharacter();
			if (c == 'i') {
				int x = readInt(), y = readInt();
				ap(p, x, y);
			} else if (c == 'd') {
				int x = readInt(), y = readInt();
				p[x].remove(y);
				p[y].remove(x);
			} else if (c == 'n') {
				int x = readInt();
				System.out.println(p[x].size());
			} else if (c == 'f') {
				int x = readInt();
				System.out.println(bfs(p, x, 0, 'f'));
			} else if (c == 's') {
				int x = readInt(), y = readInt();
				int a = bfs(p, x, y, 's');
				if (a == 0)
					System.out.println("Not connected");
				else
					System.out.println(a);
			} else
				break;
		}
	}
	static void ap(Set<Integer>[] p, int a, int b) {
		p[a].add(b);
		p[b].add(a);
	}
	static int bfs(Set<Integer> p[], int a, int b, char c) {
		ArrayList<Integer> q = new ArrayList<>();
		boolean v[] = new boolean[50];
		int d[] = new int[50];
		q.add(a);
		v[a] = true;
		d[a] = 0;
		while (!q.isEmpty()) {
			int cur = q.get(0);
			q.remove(0);
			for (int i : p[cur]) {
				if (!v[i]) {
					v[i] = true;
					q.add(i);
					d[i] = d[cur] + 1;
				}
			}
		}
		if (c == 'f') {
			int count = 0;
			for (int i : d) {
				if (i == 2)
					count++;
			}
			return count;
		} else {
			return d[b];
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