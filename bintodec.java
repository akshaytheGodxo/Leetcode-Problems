import java.util.*;

public class Main{ 
	public static void main(String[] args) {
		int n = 11;

		int ans = 0;
		int place = 0;
		while (n != 0) {
			int rem = n % 10;
			if (rem == 1) {
				ans += Math.pow(2, place);
			}
			place++;
			n = n / 10;
		}

		System.out.print(ans);
	}

}