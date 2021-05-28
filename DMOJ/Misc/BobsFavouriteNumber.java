import java.util.*;
public class BobsFavouriteNumber {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int count = 0;
		for (int i=2; i<n+1; i++) {
			if (i%2==1) {
				double s = Math.sqrt(i);
				if (s-Math.floor(s)!=0) {
					count+=1;
				}
			}
		}
		System.out.print(count);
	}

}
