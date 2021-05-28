import java.util.*;
import java.io.*;
public class GoodWriting {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String base = "Good writing is good writing is good writing.";
	static String pre = "Good writing is good ", mid = " writing is good ", suf = " is good writing.";
	static long len[] = new long[31];
	static char fun(int lvl, int ind) {
		if (lvl==0)return base.charAt(ind);
		int size = pre.length();
		if (ind<size) return pre.charAt(ind);
		if (ind<size+len[lvl-1]) return fun(lvl-1, ind-size);
		size+=mid.length();
		if (ind<size+len[lvl-1]) return fun(lvl-1, ind-size);
		size+=len[lvl-1];
		if (ind<size+len[lvl-1]) return fun(lvl-1, ind-size);
		size+=len[lvl-1];
		return suf.charAt(ind-size);
	}
	public static void main(String[] args) throws IOException{
		len[0] = base.length();
		for (int i=1; i<=30; i++) {
			len[i] = pre.length() + len[i-1] +mid.length() + len[i-1] + suf.length();
		}
		int q = readInt();
		for (int i=1; i<=q; i++) {
			int lvl = readInt(), ind = readInt();
			if (ind>=len[lvl]) System.out.println('.');
			else System.out.println(fun(lvl,ind-1));
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