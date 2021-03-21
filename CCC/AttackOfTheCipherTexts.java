import java.util.*;
public class AttackOfTheCipherTexts {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String a = in.nextLine(), b = in.nextLine(), c = in.nextLine();
		for (char t: c.toCharArray()) {
			int index = b.indexOf(t);
			if (index!=-1) {
				System.out.print(a.charAt(index));
			} else {
				System.out.print('.');
			}
		}
	}

}
