import java.util.Scanner;
public class AnArithmeticProblem {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String[] t = in.nextLine().split(" ");
		if (Integer.parseInt(t[0])+Integer.parseInt(t[2])==Integer.parseInt(t[4])) System.out.println("True");
		else System.out.println("False");
	}

}
