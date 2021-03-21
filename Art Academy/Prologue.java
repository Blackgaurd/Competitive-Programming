import java.util.*;
public class Prologue {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for (int i=0;i<n+1;i++) {
			String t = in.nextLine();
			t.toLowerCase();
			for (char c: t.toCharArray()) {
				if (c=='a') {
					System.out.print("Hi! ");
				} else if (c=='e') {
					System.out.print("Bye! ");
				} else if (c=='i') {
					System.out.print("How are you? ");
				} else if (c=='o') {
					System.out.print("Follow me! ");
				} else if (c=='u') {
					System.out.print("Help! ");
				} else if (c>='0' && c<='9') {
					System.out.print("Yes! ");
				}
			}
		}
	}

}
