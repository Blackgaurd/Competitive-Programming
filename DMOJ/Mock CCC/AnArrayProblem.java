import java.util.*;
public class AnArrayProblem {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[n];
		long sum = 0;
		for (int i=0; i<n; i++) {
			arr[i] = in.nextInt();
			sum+=arr[i];
		}
		Arrays.sort(arr);
		int max = arr[arr.length-1];
		if (max>=sum-max) {
			System.out.println(sum-max);
		}
		else {
			System.out.println(sum/2);
		}
	}
}
