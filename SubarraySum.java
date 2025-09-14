import java.util.*;

public class SubarraySum {
    public static void main(String[] args) {
        Solution s = new Solution();
        int [] nums = {1,1,1};
        int k = 2;
        System.out.println(s.subarraySum(nums, k));
    }    
}


class Solution {
    public int subarraySum(int[] nums, int k) {
        Queue<Integer> q = new LinkedList<>();


        int sum = 0;
        int count = 0;
        for (int i = 0;i < nums.length;i++) {
            q.add(nums[i]);
            sum += nums[i];
            // if (sum > k) {
            //     sum -= q.remove();                
            // }


            // removing process

            if (sum > k) {
                while (sum > k) {
                    sum -= q.remove();
                }
            }

            if (sum < 0) {
                while (sum < 0) {
                    sum += q.remove();
                }
            }

            if (sum == k) {
                count++;

            }
        }
        return count;
    }
}

