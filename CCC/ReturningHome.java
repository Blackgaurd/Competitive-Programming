import java.util.*;
import java.io.*;
public class ReturningHome {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		ArrayList<String> l = new ArrayList<>();
		while (true) {
			String a = readLine();
			if (a.equals("SCHOOL")) break;
			if (a.equals("R")) l.add(0, "LEFT");
			else if (a.equals("L")) l.add(0, "RIGHT");
			else l.add(0, a);
		}
		//System.out.println(l);
		int x = l.size()/2;
		for (int i=0; i<x; i++) {
			System.out.println("Turn "+l.get(0)+" onto "+l.get(1)+" street.");
			l.remove(0); l.remove(0);
		}
		System.out.println("Turn "+l.get(0)+" into your HOME.");
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