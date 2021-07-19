// CCC '06 J2 - Roll the Dice

import java.util.*;

public class RollTheDice {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int d1 = in.nextInt();
		int d2 = in.nextInt();
		int small = Math.min(d1, d2);
		int big = Math.max(d1, d2);
		int way = 0;
		if (big > 9 && small < 10) {
			way = small;
		} else if (big < 10 && small < 10) {
			way = big + small - 9;
		} else {
			way = 9;
		}
		if (way == 1) {
			System.out.println("There is 1 way to get the sum 10.");
		} else if (way > 0) {
			System.out.println("There are " + way + " ways to get the sum 10.");
		} else {
			System.out.println("There are 0 ways to get the sum 10.");
		}
		in.close();
	}
}
