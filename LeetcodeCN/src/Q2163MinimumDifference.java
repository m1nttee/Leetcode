import java.util.PriorityQueue;

/**
 * @author aiinirii
 */
public class Q2163MinimumDifference {
    public static void main(String[] args) {
        PriorityQueue<Integer> left = new PriorityQueue<>((o1, o2) -> o1 - o2);
        left.add(3);
        left.add(9);
        left.add(5);
        left.add(1);

        System.out.println(left.poll());
        System.out.println(left.poll());
        System.out.println(left.poll());
        System.out.println(left.poll());
    }

    public long minimumDifference(int[] nums) {
        int n = nums.length / 3;

        long leftSum = 0;
        long rightSum = 0;

        PriorityQueue<Integer> left = new PriorityQueue<>((o1, o2) -> o2 - o1);
        PriorityQueue<Integer> right = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {

            leftSum += nums[i];
            left.add(nums[i]);

            rightSum += nums[3 * n - i - 1];
            right.add(nums[3 * n - i - 1]);
        }

        long[] leftSums = new long[n + 1];
        long[] rightSums = new long[n + 1];

        leftSums[0] = leftSum;
        rightSums[0] = rightSum;

        for (int i = 1; i <= n; i++) {
            int leftPollValue = left.poll();
            int rightPollValue = right.poll();

            int leftReplaceValue = Math.min(leftPollValue, nums[n + i - 1]);
            int rightReplaceValue = Math.max(rightPollValue, nums[2 * n - i]);

            left.add(leftReplaceValue);
            right.add(rightReplaceValue);

            leftSum = leftSum + leftReplaceValue - leftPollValue;
            rightSum = rightSum + rightReplaceValue - rightPollValue;

            leftSums[i] = leftSum;
            rightSums[i] = rightSum;
        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            long diff = leftSums[i] - rightSums[n - i];
            if (diff < ans) {
                ans = diff;
            }
        }
        return ans;
    }
}
