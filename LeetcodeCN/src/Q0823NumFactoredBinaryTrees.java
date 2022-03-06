import java.util.Arrays;

/**
 * @author aiinirii
 */
public class Q0823NumFactoredBinaryTrees {

    public static void main(String[] args) {
        new Q0823NumFactoredBinaryTrees().numFactoredBinaryTrees(new int[]{18865777,36451879,36878647});
    }

    public int numFactoredBinaryTrees(int[] arr) {
        // 如果 c = a * b，且 a 有 k_a 种组合，b 有 k_b 种组合，那么 k_c = 1 + k_a * k_b。
        // -> 找每个数的因子。

        long sum = 0;

        // 1. 排序
        Arrays.sort(arr);

        // 2. 新建计数数组
        long[] count = new long[arr.length];

        // 3. 初始化数据
        count[0] = 1;

        sum += 1;

        // 4. 开始 dp
        for (int i = 1; i < arr.length; i++) {
            count[i] = 1;
            int a = 0;
            int b = i - 1;
            while (a <= b) {
                // tip: 注意 int 溢出问题。
                if ((long) arr[a] * arr[b] == arr[i]) {
                    if (a == b) {
                        count[i] += count[a] * count[b];
                    } else {
                        count[i] += 2 * count[a] * count[b];
                    }
                    count[i] %= 1000000007;
                    a += 1;
                    b -= 1;
                } else if ((long) arr[a] * arr[b] < arr[i]) {
                    a += 1;
                } else {
                    b -= 1;
                }
            }
            sum = sum + count[i];
            sum %= 1000000007;
        }

        return (int) sum;
    }

}
