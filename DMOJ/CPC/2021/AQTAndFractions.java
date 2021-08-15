// CPC '21 Contest 1 P1 - AQT and Fractions

import java.math.BigDecimal;
import java.util.*;
import java.io.*;
public class AQTAndFractions {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException{
        int t = readInt();
        for (int i=0; i<t; i++){
            long a = readLong(), b = readLong();
            long gcd = __gcd(a, b);
            a /= gcd; b /= gcd;
            long cop = b;
            while (cop % 2 == 0) cop /= 2;
            while (cop % 5 == 0) cop /= 5;
            if (cop != 1) System.out.println(-1);
            else {
                BigDecimal x = new BigDecimal(a), y = new BigDecimal(b);
                BigDecimal ans = x.divide(y);
                System.out.println(decimalPlaces(ans));
            }
        }
	}
    static long __gcd(long a, long b){
        if (b == 0) return a;
        return __gcd(b, a%b);
    }
    static int decimalPlaces(BigDecimal bigDecimal) {
        String string = bigDecimal.stripTrailingZeros().toPlainString();
        int index = string.indexOf(".");
        return index < 0 ? 0 : string.length() - index - 1;
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