import java.util.*;
import java.io.*;
public class ChancesOfWinning {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
		int t = readInt(), g = readInt(), s[] = {0,0,0,0}, p[] = {0,0,0,0}, count=0;
		int played[][] = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
		for (int i=0; i<g; i++) {
			int a = readInt(), b = readInt(), sa = readInt(), sb = readInt();
			s[a-1]+=sa; s[b-1]+=sb;
			if (sa>sb) p[a-1]+=2;
			else if (sa<sb) p[b-1]+=2;
			else {p[a-1]+=1; p[b-1]+=1;}
			for (int j=0; j<6; j++) {
				if (played[j][0]==a) {
					if (played[j][1]==b) {
						played[j][0] = 0;
					}
				}
			}
		}
		int points = p[t-1], mp = max(p), ms = max(s);
		if (points == mp) {
			for (int i=0; i<6; i++) {
				if (played[i][0]!=0) {
					if (!(s[played[i][0]-1]+2>=s[t-1])) {
						count++;
					}
					if (!(s[played[i][1]-1]+2>=s[t-1])) {
						count++;
					}
					if (!(s[played[i][1]-1]+1>=s[t-1])&&!(!(s[played[i][0]-1]+1>=s[t-1]))) {
						count++;
					}
				}
			}
		} else {
			for (int i=0; i<6; i++) {
				if (played[i][0]!=0) {
					if (s[t-1]+2>ms) {
						count++;
					}
					if (s[t-1]+1>ms) {
						count++;
					}
				}
			}
		}
		System.out.println(count);
		System.out.println(Arrays.toString(p)+Arrays.toString(s));
	}
	static int max(int[] arr) {
		int temp[] = arr, a = arr.length;
		Arrays.sort(temp);
		return temp[a-1];
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