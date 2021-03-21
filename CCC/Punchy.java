import java.util.*;
import java.io.*;
public class Punchy {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int a = 0, b = 0;
		while (true) {
			int n = readInt();
			if (n==1) {
				char c = readCharacter();
				int x = readInt();
				if (c=='A') a=x;
				else b=x;
			} else if (n==2) {
				char c = readCharacter();
				if (c=='A') System.out.println(a);
				else System.out.println(b);
			} else if (n==3) {
				char c = readCharacter(), t = readCharacter();
				if (c=='A' && t=='A') a+=2;
				else if (c=='A' && t=='B') a+=b;
				else if (c=='B' && t=='A') b+=a;
				else b+=2;
			} else if (n==4) {
				char c = readCharacter(), t = readCharacter();
				if (c=='A' && t=='A') a*=a;
				else if (c=='A' && t=='B') a*=b;
				else if (c=='B' && t=='A') b*=a;
				else b*=b;
			} else if (n==5) {
				char c = readCharacter(), t = readCharacter();
				if (c=='A' && t=='A') a=0;
				else if (c=='A' && t=='B') a-=b;
				else if (c=='B' && t=='A') b-=a;
				else b=0;
			} else if (n==6) {
				char c = readCharacter(), t = readCharacter();
				if (c=='A' && t=='A') a=1;
				else if (c=='A' && t=='B') a/=b;
				else if (c=='B' && t=='A') b/=a;
				else b=1;
			} else break;
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