/**
 * @author aiinirii
 *
 * TODO: not done yet
 */
public class Q1575CountRoutes {
    public static void main(String[] args) {
        new Q1575CountRoutes().countRoutes(
                new int[]{2, 3, 6, 8, 4},
                1,
                3,
                5);
    }

    public int countRoutes(int[] locations, int start, int finish, int fuel) {
        if (Math.abs(locations[start] - locations[finish]) > fuel) {
            return 0;
        } else {
            int[][] dp = new int[fuel + 1][locations.length];
            if (0 != finish) {
                int temp = locations[start];
                locations[start] = locations[0];
                locations[0] = temp;
                temp = locations[finish];
                locations[finish] = locations[locations.length - 1];
                locations[locations.length - 1] = temp;
            } else {
                int temp = locations[finish];
                locations[finish] = locations[locations.length - 1];
                locations[locations.length - 1] = temp;
                temp = locations[start];
                locations[start] = locations[0];
                locations[0] = temp;
            }
            for (int i = 0; i < fuel; i++) {
                dp[i][0] = 0;
            }
            dp[fuel][0] = 1;
            for (int endPosition = 1; endPosition < locations.length; endPosition++) {
                boolean isLoop = true;
                while (isLoop) {
                    isLoop = false;
                    for (int lastPosition = 0; lastPosition < endPosition; lastPosition++) {
                        int costFuel = Math.abs(locations[endPosition] - locations[lastPosition]);
                        for (int lastRestFuel = costFuel; lastRestFuel <= fuel - Math.abs(locations[lastPosition] - locations[0]); lastRestFuel++) {
                            dp[lastRestFuel - costFuel][endPosition] += dp[lastRestFuel][lastPosition];
                            dp[lastRestFuel - costFuel][endPosition] %= 1e9 + 7;
                        }
                    }

                    for (int updateEndPosition = 0; updateEndPosition < endPosition; updateEndPosition++) {
                        int costFuel = Math.abs(locations[endPosition] - locations[updateEndPosition]);
                        for (int lastRestFuel = costFuel; lastRestFuel <= fuel - Math.abs(locations[updateEndPosition] - locations[0]); lastRestFuel++) {
                            if (dp[lastRestFuel][endPosition] >= 1) {
                                isLoop = true;
                                dp[lastRestFuel - costFuel][updateEndPosition] += dp[lastRestFuel][endPosition];
                                dp[lastRestFuel - costFuel][updateEndPosition] %= 1e9 + 7;
                            }
                        }
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i < fuel + 1; i++) {
                sum += dp[i][locations.length - 1];
                sum %= 1e9 + 7;
            }
            return sum;
        }
    }
}
