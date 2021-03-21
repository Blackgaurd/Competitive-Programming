import java.util.*;
public class LoveGuru {
	static int pow(int base, int exp) {
		if (exp==0) {
			return 1;
		}
		return base*pow(base,exp-1);
	}
	static int lastdigit(int base, int exp) {
		base%=10;
		if (base%5==0||base%5==1) {
			return base;
		}
		exp%=4;
		return pow(base,exp)%10; 
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		String a = in.nextLine().toUpperCase(), b = in.nextLine().toUpperCase();
		char[] name1 = a.toCharArray(), name2 = b.toCharArray();
		int amod = 0, bmod = 0;
		for (int i=0; i<a.length(); i++) {
			amod+=lastdigit(name1[i]-'A'+1,i+1);
			}
		for (int i=0;i<b.length();i++) {
			bmod+=lastdigit(name2[i]-'A'+1,i+1);
		}
		amod%=10;
		bmod%=10;
		if (amod==0) amod=10;
		if (bmod==0) bmod=10;
		System.out.println(amod+bmod);
	}

}
