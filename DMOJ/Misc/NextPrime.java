import java.util.*;
public class NextPrime {
	private static boolean prime(int n) {
		for (int i=2; i<=(int) Math.sqrt(n); i++) {
			if (n%i==0) {
				return false;
			}
		}
		return true;	 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		if (num<3) {
			System.out.println(2);
		} else {
			while (!prime(num)) {
				num++;
			}
			System.out.println(num);
		}
	}

}
