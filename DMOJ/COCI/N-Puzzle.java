import java.util.Scanner;

public class COCI06C3P2 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		char puzzle[][] = new char [4][4];
		int ans = 0;
		for (int line = 0;line<4;line++) {
			puzzle[line] = input.nextLine().toCharArray();
		}
		
		for (int row = 0;row<4;row++) {
			for (int col = 0; col<4; col++) {
				if (puzzle[row][col]!='.') {
					int dif = puzzle [row][col] - 'A';
					int r = dif/4;
					int c = dif%4;
					ans+=Math.abs(r-row)+Math.abs(c-col);
				}
			}
		}
		System.out.print(ans);
		
	}

}

