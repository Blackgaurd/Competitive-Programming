import java.util.*;
public class BubbleSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] arr = new int[n];
		int[] sorted = new int[n];
		for (int i=0; i<n; i++) {
			arr[i] = in.nextInt();
			sorted[i] = i+1;
		}
		while (true) {
			if (Arrays.equals(arr,sorted)) {
				break;
			}
			for (int num=1; num<n; num++) {
				if (arr[num]<arr[num-1]){
					int temp = arr[num-1];
					arr[num-1]=arr[num];
					arr[num]=temp;
					for (int i: arr) {
						System.out.print(i+" ");
					} System.out.println("");
				}
			}
		}
	}

}
