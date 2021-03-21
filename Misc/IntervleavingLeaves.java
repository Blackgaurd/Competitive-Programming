import java.util.Arrays;
import java.util.Scanner;
public final class IntervleavingLeaves {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int t = Integer.parseInt(in.nextLine());
		for (int i=0; i<t; i++) {
			int n = Integer.parseInt(in.nextLine());
			char[] p1 = in.nextLine().toCharArray(), p2 = in.nextLine().toCharArray();
			for (int j=n-1;j>=0;j--) {
				System.out.print(p2[j]);
				System.out.print(p1[j]);
			}
			System.out.println();
		}
	}

}
