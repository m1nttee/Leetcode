import java.util.*;

/**
 * @author aiinirii
 * todo
 */
public class Q1610VisiblePoints {
    public static void main(String[] args) {
        System.out.println(new Q1610VisiblePoints().visiblePoints(List.of(List.of(2, 1), List.of(2, 2), List.of(3, 3)), 90, List.of(1, 1)));
        System.out.println(new Q1610VisiblePoints().visiblePoints(List.of(List.of(1, 0), List.of(2, 1)), 13, List.of(1, 1)));
        System.out.println(new Q1610VisiblePoints().visiblePoints(List.of(List.of(1, 1), List.of(2, 2), List.of(3, 3), List.of(4, 4), List.of(1, 2), List.of(2, 1)), 0, List.of(1, 1)));
    }

    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        int baseNum = 0;
        LinkedList<List<Integer>> pointsList = new LinkedList<>(points);
        ListIterator<List<Integer>> listListIterator = pointsList.listIterator();
        while (listListIterator.hasNext()) {
            List<Integer> point = listListIterator.next();
            if (Objects.equals(point.get(0), location.get(0)) && Objects.equals(point.get(1), location.get(1))) {
                baseNum++;
                listListIterator.remove();
            }
        }
        double[] pointAngles = new double[pointsList.size()];
        int i = 0;
        for (List<Integer> point : pointsList) {
            pointAngles[i++] = computeAngle(point, location);
        }
        Arrays.sort(pointAngles);
        int maxPointNum = 0;
        int startIndex = 0;
        int endIndex = 0;
        while (startIndex < pointAngles.length) {
            while (true) {
                if ((pointAngles[(endIndex + 1) % pointAngles.length] - pointAngles[startIndex]) % 360 > angle) {
                    break;
                }
                if ((endIndex + 1) % pointAngles.length == startIndex) {
                    break;
                }
                endIndex++;
                endIndex %= pointAngles.length;
            }
            maxPointNum = Math.max(maxPointNum, endIndex - startIndex + 1);
            startIndex++;
        }
        return maxPointNum + baseNum;
    }

    private double computeAngle(List<Integer> point, List<Integer> location) {
        double anglePi = Math.atan2((float) (point.get(1) - location.get(1)), (float) (point.get(0) - location.get(0)));
        return ((anglePi + Math.PI) * 360f) / (2 * Math.PI);
    }
}
