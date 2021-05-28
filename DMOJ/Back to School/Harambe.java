import java.util.*;
public class Harambe {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String t = in.nextLine();
		int up = 0, low = 0;
		for (char c: t.toCharArray()) {
			if (c == ' ') continue;
			else if(c==Character.toLowerCase(c)) low++;
			else if (c==Character.toUpperCase(c)) up++;
		}
		if (low>up) System.out.println(t.toLowerCase());
		else if (low<up) System.out.println(t.toUpperCase());
		else System.out.println(t);
	}

}
