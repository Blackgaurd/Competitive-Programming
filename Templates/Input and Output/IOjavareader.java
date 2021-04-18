//

import java.io.*;
import java.util.*;
public class IOjavareader {
    final static Reader rd = new Reader();
    public static void main(String[] args) throws IOException {
    }
    static class Reader {
        int pt, r;
        byte b[] = new byte[1<<10];
        byte nextByte() throws IOException {
            if (pt >= r){
                if ((r = System.in.read(b)) == -1) return -1;
                pt = 0;
            }
            if (b[pt] == ' ' || b[pt] == '\n'){
                ++pt;
                return -1;
            }
            return b[pt++];
        }
        int readInt() throws IOException {
            byte nxt = nextByte();
            while (nxt == -1) nxt = nextByte();
            int ans = 0; boolean neg = false;
            if (nxt == '-'){
                nxt = nextByte();
                neg = true;
            }
            while (nxt != -1){
                ans *= 10; ans += nxt - '0';
                nxt = nextByte();
            }
            return neg ? -ans : ans;
        }
        long readLong() throws IOException {
            byte nxt = nextByte();
            while (nxt == -1) nxt = nextByte();
            long ans = 0; boolean neg = false;
            if (nxt == '-'){
                nxt = nextByte();
                neg = true;
            }
            while (nxt != -1){
                ans *= 10; ans += nxt - '0';
                nxt = nextByte();
            }
            return neg ? -ans : ans;
        }
        double readDouble() throws IOException {
            byte nxt = nextByte();
            while (nxt == -1) nxt = nextByte();
            double ans = 0; boolean neg = false;
            if (nxt == '-'){
                nxt = nextByte();
                neg = true;
            }
            while (nxt != -1){
                if (nxt != '.') {
                    ans *= 10; ans += nxt - '0';
                    nxt = nextByte();
                } else {
                    nxt = nextByte();
                    for (double pow = 0.1; nxt != -1; pow *= 0.1){
                        ans += pow*(nxt - '0');
                        nxt = nextByte();
                    }
                }
            }
            return neg ? -ans : ans;
        }
        byte readChar() throws IOException {
            byte nxt = nextByte();
            while (nxt == -1) nxt = nextByte();
            return nxt;
        }
    }
}