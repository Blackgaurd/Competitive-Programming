import java.util.Scanner;
public class Pink {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int pink = 0;
		for (int i=0;i<n;i++) {
			int r = in.nextInt();
			int g = in.nextInt();
			int b = in.nextInt();
			if (240<=r && r<=255 && 0<=g && g<=200 && 95<=b && b<=220) {
				pink++;
			}
		}
		System.out.println(pink);
	}

}

//240≤R≤255, 0≤G≤200, 95≤B≤220.