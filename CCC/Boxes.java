import java.util.Arrays;
import java.util.Scanner;
public class Boxes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] sizes = new int[n];
		for (int i=0; i<n; i++) {
			int l = in.nextInt(), w = in.nextInt(), h = in.nextInt();
			sizes[i] = l*w*h;
		}
		Arrays.sort(sizes);
		int m = in.nextInt();
		for (int i=0; i<m; i++) {
			int l = in.nextInt(), w = in.nextInt(), h = in.nextInt();
			int v = l*w*h;
			for (int box:sizes) {
				
			}
		}
	}

}
