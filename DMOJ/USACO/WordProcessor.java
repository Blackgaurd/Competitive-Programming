import java.util.Scanner;
public class WordProcessor {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int len = in.nextInt(), n = in.nextInt();
		String t = in.nextLine();
		String[] arr = t.split(" ");
		int current = 0;
		for (String word:arr) {
			/*int chars = word.length();
			if (current+chars>n) {
				System.out.print("\n");
			}
			current+=chars;*/
			System.out.print(word);
		}
	}

}
