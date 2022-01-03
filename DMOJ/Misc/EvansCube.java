// Evan's Cube
// whys this java only :sadge:

import java.util.*;
import java.io.*;
public class EvansCube {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static char cube[][][];
    public static void main(String[] args) throws IOException {
        /* File file = new File("output.txt");
        FileOutputStream fos = new FileOutputStream(file);
        PrintStream ps = new PrintStream(fos);
        System.setOut(ps); */

        cube = new char[7][3][3];
        for (int f = 1; f <= 6; f++) {
            for (int i = 0; i < 3; i++) {
                String cur = readLine();
                for (int j = 0; j < 3; j++) {
                    cube[f][i][j] = cur.charAt(j);
                }
            }
        }

        int q = readInt();
        for (int i = 0; i < q; i++) {
            String tmp = readLine();
            int face = Character.getNumericValue(tmp.charAt(0));
            char dir = tmp.charAt(1);
            for (int r = 0; r < (dir == 'C' ? 1 : 3); r++) {
                rotateFace(face);
                switch (face) {
                    case 1:
                        rotate1();
                        break;
                    case 2:
                        rotate2();
                        break;
                    case 3:
                        rotate3();
                        break;
                    case 4:
                        rotate4();
                        break;
                    case 5:
                        rotate5();
                        break;
                    case 6:
                        rotate6();
                        break;
                }
            }
        }
        // check solved
        for (int f = 1; f <= 6; f++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (cube[f][i][j] != cube[f][1][1]) {
                        System.out.println("Boo!");
                        return;
                    }
                }
            }
        }
        System.out.println("Solved!");
    }
    static void print() {
        for (int f = 1; f <= 6; f++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    System.out.print(cube[f][i][j]);
                }
                System.out.println();
            }
            System.out.println();
        }
    }
    static void printSpread() {
        rotateFace(6);
        rotateFace(6);
        for (int i = 0; i <= 2; i++) {
            System.out.println("         " + Arrays.toString(cube[6][i]));
        }
        rotateFace(6);
        rotateFace(6);
        for (int i = 0; i < 3; i++) {
            System.out.println(Arrays.toString(cube[2][i]) + Arrays.toString(cube[1][i]) + Arrays.toString(cube[4][i]) + Arrays.toString(cube[3][i]));
        }
        for (int i = 0; i < 3; i++) {
            System.out.println("         " + Arrays.toString(cube[5][i]));
        }
    }
    // all rotations are clockwise
    static void rotateFace(int face) {
        char tmp = cube[face][0][0];
        cube[face][0][0] = cube[face][2][0];
        cube[face][2][0] = cube[face][2][2];
        cube[face][2][2] = cube[face][0][2];
        cube[face][0][2] = tmp;

        tmp = cube[face][0][1];
        cube[face][0][1] = cube[face][1][0];
        cube[face][1][0] = cube[face][2][1];
        cube[face][2][1] = cube[face][1][2];
        cube[face][1][2] = tmp;
    }
    static void rotate1() {
        char tmp[] = new char[3];
        tmp[0] = cube[6][0][0];
        tmp[1] = cube[6][0][1];
        tmp[2] = cube[6][0][2];

        cube[6][0][0] = cube[2][0][2];
        cube[6][0][1] = cube[2][1][2];
        cube[6][0][2] = cube[2][2][2];

        cube[2][0][2] = cube[5][0][0];
        cube[2][1][2] = cube[5][0][1];
        cube[2][2][2] = cube[5][0][2];

        cube[5][0][2] = cube[4][0][0];
        cube[5][0][1] = cube[4][1][0];
        cube[5][0][0] = cube[4][2][0];

        cube[4][0][0] = tmp[2];
        cube[4][1][0] = tmp[1];
        cube[4][2][0] = tmp[0];
    }
    static void rotate2() {
        char tmp[] = new char[3];
        tmp[0] = cube[6][0][2];
        tmp[1] = cube[6][1][2];
        tmp[2] = cube[6][2][2];

        cube[6][0][2] = cube[3][0][2];
        cube[6][1][2] = cube[3][1][2];
        cube[6][2][2] = cube[3][2][2];

        cube[3][0][2] = cube[5][2][0];
        cube[3][1][2] = cube[5][1][0];
        cube[3][2][2] = cube[5][0][0];

        cube[5][2][0] = cube[1][2][0];
        cube[5][1][0] = cube[1][1][0];
        cube[5][0][0] = cube[1][0][0];

        cube[1][0][0] = tmp[2];
        cube[1][1][0] = tmp[1];
        cube[1][2][0] = tmp[0];
    }
    static void rotate3() {
        char tmp[] = new char[3];
        tmp[0] = cube[6][2][0];
        tmp[1] = cube[6][2][1];
        tmp[2] = cube[6][2][2];

        cube[6][2][0] = cube[4][2][2];
        cube[6][2][1] = cube[4][1][2];
        cube[6][2][2] = cube[4][0][2];

        cube[4][2][2] = cube[5][2][0];
        cube[4][1][2] = cube[5][2][1];
        cube[4][0][2] = cube[5][2][2];

        cube[5][2][0] = cube[2][0][0];
        cube[5][2][1] = cube[2][1][0];
        cube[5][2][2] = cube[2][2][0];

        cube[2][0][0] = tmp[0];
        cube[2][1][0] = tmp[1];
        cube[2][2][0] = tmp[2];
    }
    static void rotate4() {
        char tmp[] = new char[3];
        tmp[0] = cube[6][0][0];
        tmp[1] = cube[6][1][0];
        tmp[2] = cube[6][2][0];

        cube[6][0][0] = cube[1][2][2];
        cube[6][1][0] = cube[1][1][2];
        cube[6][2][0] = cube[1][0][2];

        cube[1][2][2] = cube[5][2][2];
        cube[1][1][2] = cube[5][1][2];
        cube[1][0][2] = cube[5][0][2];

        cube[5][2][2] = cube[3][0][0];
        cube[5][1][2] = cube[3][1][0];
        cube[5][0][2] = cube[3][2][0];

        cube[3][0][0] = tmp[0];
        cube[3][1][0] = tmp[1];
        cube[3][2][0] = tmp[2];
    }
    static void rotate5() {
        char tmp;
        for (int i = 0; i < 3; i++) {
            tmp = cube[1][2][i];
            cube[1][2][i] = cube[2][2][i];
            cube[2][2][i] = cube[3][2][i];
            cube[3][2][i] = cube[4][2][i];
            cube[4][2][i] = tmp;
        }
    }
    static void rotate6() {
        char tmp;
        for (int i = 0; i < 3; i++) {
            tmp = cube[4][0][i];
            cube[4][0][i] = cube[3][0][i];
            cube[3][0][i] = cube[2][0][i];
            cube[2][0][i] = cube[1][0][i];
            cube[1][0][i] = tmp;
        }
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