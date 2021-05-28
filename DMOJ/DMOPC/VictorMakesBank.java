import java.util.*;
import java.io.*;
public class VictorMakesBank {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		long months = readLong();
		int births = readInt(), grow = readInt(), adults = readInt(), babies = 0;
		for (int i=0; i<months-1; i++) {
			int temp = babies;
			babies=adults*grow*births;
			adults+=temp;
		}
		babies+=births*(months%grow);
		System.out.println(adults*2+babies);
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