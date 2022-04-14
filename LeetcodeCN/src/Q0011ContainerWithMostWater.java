/**
 * @author aiinirii
 */
public class Q0011ContainerWithMostWater {
    public static void main(String[] args) {
        System.out.println(new Q0011ContainerWithMostWater().maxArea(new int[]{1, 2, 4, 3}));
    }

    public int maxArea(int[] height) {
        int n = height.length;
        int ans = (n - 1) * Math.min(height[0], height[n - 1]);

        int leftIndex = 0;
        int rightIndex = n - 1;

        while (leftIndex < rightIndex) {
            if (height[leftIndex] < height[rightIndex]) {
                leftIndex += 1;
            } else {
                rightIndex -= 1;
            }

            ans = Math.max(ans, (rightIndex - leftIndex) * Math.min(height[leftIndex], height[rightIndex]));
        }

        return ans;
    }
}
