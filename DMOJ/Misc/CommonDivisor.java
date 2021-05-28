import java.util.*;
import java.io.*;
public class CommonDivis {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		long a = readLong(), b = readLong();
		int n = readInt();
		if (n==1) System.out.println(n);
		else {
			TreeSet<Long> af = fac(a), bf = fac(b), com = new TreeSet<>();
			//System.out.println(af);
			//System.out.println(bf);
			if (af.size()<bf.size()) {
				bf.retainAll(af);
				com.addAll(bf);
			} else {
				af.retainAll(bf); 
				com.addAll(af);
			}
			//System.out.println(com);
			NavigableSet<Long> revcom = com.descendingSet();
			if (n<=com.size()) {
				Iterator<Long> iterator = revcom.iterator(); 
				for (int i=0; i<n-1; i++) {
					iterator.next();
				}
				System.out.println(iterator.next());
			} else System.out.println(-1);
		}
	}
	static TreeSet<Long> fac(long x){
		TreeSet<Long> f = new TreeSet<>();
		for (int i=1; i<=Math.sqrt(x); i++) {
			if (x%i==0) {
			f.add((long) i); 
			f.add(x/i);
			}
		}
		return f;
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