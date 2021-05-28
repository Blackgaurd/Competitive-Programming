import java.util.*;
public class SharingIsCaring {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		int[] mine = new int[m];
		String[] docs = new String[m];
		for (int i=0; i<m; i++) {
			int a = in.nextInt(), b = in.nextInt();
			String doc = in.nextLine();
			mine[i] = b;
			docs[i] = doc;
		}
		int num = in.nextInt();
		for (int j=0; j<m; j++) {
			if (mine[j]==num) {
				System.out.println(docs[j]);
			}
		}
		
	}

}
