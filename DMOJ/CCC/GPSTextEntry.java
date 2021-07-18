import java.util.Scanner;

public class GPSTextEntry {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String line = input.nextLine().replaceAll(" ", "[").replaceAll("-", "\\").replaceAll(".","]");
		System.out.println(line);

		int row = 11/6;
		int col = 11%6;
		System.out.println(row);
		System.out.println(col);

		input.close();
	}

}
