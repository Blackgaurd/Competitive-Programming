import java.util.*;
import java.io.*;
public class Binary {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt();
		String space[] = {"","",""," "};
		for (int i=0; i<n; i++) {
			int a = readInt();
			for (int j=0; j<convert(a).size(); j++) {
				System.out.print(convert(a).get(j)+space[j%4]);
			}
			System.out.println();
		}
	}
	static ArrayList<Integer> convert(int x) {
		ArrayList<Integer> binary = new ArrayList<>();
		if (x==0) binary.add(0);
		while (x>0) {
			binary.add(0,(x%2));
			x/=2;
		}
		while (binary.size()%4!=0) {
			binary.add(0,0);
		}
		return binary;
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