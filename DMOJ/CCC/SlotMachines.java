// CCC '00 S1 - Slot Machines

import java.util.*;
import java.io.*;

public class SlotMachines {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) throws IOException {
		int n = readInt(), a = readInt(), b = readInt(), c = readInt(), count = 0;
		while (true) {
			n--;
			a++;
			count++;
			if (a == 35) {
				n += 30;
				a = 0;
			}
			if (n == 0)
				break;
			n--;
			b++;
			count++;
			if (b == 100) {
				n += 60;
				b = 0;
			}
			if (n == 0)
				break;
			n--;
			c++;
			count++;
			if (c == 10) {
				n += 9;
				c = 0;
			}
			if (n == 0)
				break;
		}
		System.out.println("Martha plays " + count + " times before going broke.");
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}