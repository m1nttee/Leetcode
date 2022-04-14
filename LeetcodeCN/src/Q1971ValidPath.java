/**
 * @author aiinirii
 */
public class Q1971ValidPath {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        MFSet mfSet = new MFSet(n);
        for (int i = 0; i < edges.length; i++) {
            mfSet.merge(edges[i][0], edges[i][1]);
        }
        return mfSet.find(source) == mfSet.find(destination);
    }

    static class MFSet {
        int[] fa;

        MFSet(int n) {
            fa = new int[n];
            for (int i = 0; i < n; i++) {
                fa[i] = i;
            }
        }

        int find(int p) {
            if (fa[p] == p) {
                return p;
            } else  {
                fa[p] = find(fa[p]);
                return fa[p];
            }
        }

        void merge(int p1, int p2) {
            fa[find(p2)] = find(p1);
        }
    }
}
