// CCC '15 J2 - Happy or Sad

import java.util.Scanner;
public class HappyOrSad {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		String line = input.nextLine();
		int happy = 0;
		int sad = 0;
		for (int letter=0; letter<line.length()-2; letter++){
			if (line.charAt(letter)==':' && line.charAt(letter+1)=='-'){
				if (line.charAt(letter+2)=='(') {
					sad++;
				}
				else if (line.charAt(letter+2)==')') {
					happy++;
				}
			}

		}
		if (happy>sad) {
			System.out.println("happy");
		}
		else if (sad>happy) {
			System.out.println("sad");
		}
		else if (sad==0 && happy==0) {
			System.out.println("none");
		}
		else {
			System.out.println("unsure");
		}

		input.close();
	}

}