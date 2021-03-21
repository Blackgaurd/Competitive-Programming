import java.util.*;
import java.io.*;
public class War {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		int war = 0;
		for (int i=0; i<n; i++) {a[i] = in.nextInt();}
		for (int i=0; i<n; i++) {b[i] = in.nextInt();}
		boolean active = false;
		for (int i=0; i<n; i++) {
			if (!active && a[i]==b[i]) {
				active = true;
				war+=1;
			}
			if (active && a[i]!=b[i]) {
				active=false;
			}
		}
		System.out.println(war);
	}

}
