import java.util.*;
public class maxSixNine {
    public static void main(String[] args) {
        Solution s = new Solution();
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int ans = s.maximum69Number(x);
        System.out.print(ans);       
    }
}

class Solution {
    public int maximum69Number (int num) {
        String myNum = Integer.toString(num);
        int idx = -1;
        for (int i = 0;i < myNum.length();i++) {
            if (myNum.charAt(i) == '6') {
                idx = i;
                break;
            }
        }
        int ans = num;
        if (idx != -1) {
            StringBuilder sb = new StringBuilder(myNum);
            sb.setCharAt(idx, '9');
            String newNum = sb.toString();
            ans = Integer.parseInt(newNum);
        }
        return ans;
    }
}