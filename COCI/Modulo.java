import java.util.*;
public class COCI06C1P1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Set<Integer> set= new HashSet<Integer>();
		for (int i=0;i<10;i++) {
			int num=in.nextInt();
			set.add(num%42);
		}
		System.out.println(set.size());
	}
}
