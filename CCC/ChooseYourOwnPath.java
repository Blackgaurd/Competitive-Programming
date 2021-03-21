import java.util.*;
import java.io.*;
public class ChooseYourOwnPath {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		boolean end[] = new boolean[n+1];
		ArrayList<Integer> path[] = new ArrayList[n+1];
		for (int i=1; i<n+1; i++) {
			path[i] = new ArrayList<Integer>();
			int m = readInt();
			if (m==0) end[i] = true;
			for (int j=0; j<m; j++) {
				path[i].add(readInt());
			}
		}
		ArrayList<Integer> q = new ArrayList<>();
		boolean visited[] = new boolean[n+1];
		int distance[] = new int[n+1];
		q.add(1);
		visited[1] = true;
		distance[1] = 1;
		while (!q.isEmpty()) {
			int cur = q.get(0);
			q.remove(0);
			for (int i:path[cur]) {
				if (!visited[i]) {
					visited[i] = true;
					q.add(i);
					distance[i] = distance[cur]+1;
				}
			}
		}
		char fin = 'Y';
		int min = Integer.MAX_VALUE;
		for (int i=1; i<n+1; i++) {
			if (!visited[i]) fin = 'N';
			if (end[i] && distance[i]<min && visited[i]) min = distance[i];
		}
		//System.out.println(Arrays.toString(distance));
		//System.out.println(Arrays.toString(end));
		System.out.println(fin);
		System.out.println(min);
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