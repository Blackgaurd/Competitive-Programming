import java.util.*;
public class COCI08C4P1 {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int[] nums = new int[5];
		int[] sorted = {1,2,3,4,5};
		for (int i=0;i<5;i++) {
			nums[i] = in.nextInt();
		}
		while (!(Arrays.equals(nums,sorted))) {
			for (int i=0;i<4;i++) {
				if (nums[i]>nums[i+1]) {
					int temp = nums[i];
					nums[i]=nums[i+1];
					nums[i+1]=temp;
					for (int j=0;j<5;j++) {
						System.out.print(nums[j]+" ");
					}	
					System.out.println("");		
				}		
			}
		}
	}

}
