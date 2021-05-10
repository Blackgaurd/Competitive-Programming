import java.util.*;
public class COCI07C3P1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int[] nums = {in.nextInt(), in.nextInt(), in.nextInt()};
		Arrays.sort(nums);
		int dif1 = nums[1]-nums[0], dif2 = nums[2]-nums[1];
		if (dif1==dif2) System.out.println(nums[2]+dif1);
		else if (dif1>dif2) System.out.println(nums[0]+dif2);
		else System.out.println(nums[1]+dif1);
	}

}
