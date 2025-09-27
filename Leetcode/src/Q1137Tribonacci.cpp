class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;
        int a[] = {0, 1, 1};
        int ai = 0;
        for (int i = 2; i < n; i++) {
            a[ai] = a[0] + a[1] + a[2];
            ai = (ai + 1) % 3;
        }
        return a[n % 3];
    }
};