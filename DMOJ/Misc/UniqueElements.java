import java.util.*;
public class UniqueElements {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int n = in.nextInt();
    Set<Integer> nums = new HashSet<Integer>();
    for (int i=0; i<n; i++){
      nums.add(in.nextInt());
    }
    System.out.println(nums.size());
  }
}