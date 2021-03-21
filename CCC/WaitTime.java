import java.util.*;
import java.io.*;
public class WaitTime {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		ArrayList<Integer> arr[] = new ArrayList[101];
		int time = 0, m = readInt();
		for (int i=1; i<=100; i++) arr[i] = new ArrayList<>();
		for (int i=0; i<m; i++) {
			char c = readCharacter();
			int p = readInt();
			if (c=='R'||c=='S') {arr[p].add(time); time++;}
			else time+=p-1;
		}
		for (int i=1; i<=100; i++) {
			if (!arr[i].isEmpty()) {
				System.out.print(i+" ");
				if (arr[i].size()%2==1) System.out.println(-1);
				else {
					int sum = 0;
					for (int j=1; j<arr[i].size(); j+=2) sum+=arr[i].get(j)-arr[i].get(j-1);
					System.out.println(sum);
				}
			}
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