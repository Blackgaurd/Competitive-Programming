import java.util.*;
import java.io.*;
public class MostPopularNum {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int n = readInt(), max = 0, mode = 10001;
		HashMap<Integer, Integer> nums = new HashMap<>();
		for (int i=0; i<n; i++) {
			int a = readInt();
			try {
				nums.put(a, nums.get(a)+1);
			} catch (Exception e) {
				nums.put(a, 1);
			}
		}
		for (int i:nums.values()) {
			if (i>max) max=i;
		}
		for (int i:nums.keySet()) {
			if (nums.get(i)==max) {
				if (i<mode) mode=i;
			}
		}
		//System.out.println(nums);
		System.out.println(mode);
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