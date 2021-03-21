import java.util.Scanner;
public class CCC10J4 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		while (true) {
			int n = in.nextInt();
			if (n==0) break;
			int nums[] = new int[n], op[] = new int[n-1];
			for (int i=0; i<n; i++) {
				nums[i]=in.nextInt();
			}
			if (n==1) {
				System.out.println(0);
				continue;
			}
			for (int i=0; i<n-1; i++) {
				op[i]=nums[i+1]-nums[i];
			}
			int cycle=1;
			for (cycle=1;cycle<n-1;cycle++) {
				boolean test = true;
				for (int i=0; i<n-1; i++) {
					if(op[i] != op[i%cycle]) test = false;
				}
				if (test) break;
			}
			System.out.println(cycle);
		}
	}

}
