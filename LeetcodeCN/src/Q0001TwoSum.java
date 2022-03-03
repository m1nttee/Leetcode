import java.util.HashMap;

/**
 * @author aiinirii
 */
public class Q0001TwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            map.put(nums[i], i);
        }
        for (int i=0; i<nums.length; i++) {
            Integer n = map.get(target - nums[i]);
            if (n != null && n != i) {
                if (i > n){
                    int k = n;
                    n = i;
                    i = k;
                }
                return new int[]{i, n};
            }
        }
        return null;
    }
}
