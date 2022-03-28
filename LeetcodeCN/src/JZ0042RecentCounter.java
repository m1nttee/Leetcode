import java.util.LinkedList;

/**
 * @author aiinirii
 */
public class JZ0042RecentCounter {
    public static void main(String[] args) {
        RecentCounter obj = new RecentCounter();
        int param_1 = obj.ping(1);
    }

    static class RecentCounter {
        LinkedList<Integer> pingList;

        public RecentCounter() {
            pingList = new LinkedList<>();
        }

        public int ping(int t) {
            pingList.add(t);
            while (pingList.peekFirst() < t - 3000) {
                pingList.poll();
            }
            return pingList.size();
        }
    }
}
