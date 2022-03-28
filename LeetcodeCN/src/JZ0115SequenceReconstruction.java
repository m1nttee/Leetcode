import java.util.*;

/**
 * @author aiinirii
 * 拓扑排序
 */
public class JZ0115SequenceReconstruction {
    public static void main(String[] args) {
        System.out.println(new JZ0115SequenceReconstruction().sequenceReconstruction(
                new int[]{4, 1, 5, 2, 6, 3},
                List.of(
                        List.of(5, 2, 6, 3),
                        List.of(4, 1, 5, 2)
                )
        ));
    }

    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        int N = org.length;
        int[] in = new int[N + 1];
        HashMap<Integer, Set<Integer>> graph = new HashMap<>();
        LinkedList<Integer> genList = new LinkedList<>();
        boolean ans;

        // special case
        boolean[] numShowUps = new boolean[N];
        for (List<Integer> seq : seqs) {
            for (Integer num : seq) {
                if (num < 1 || num > N) {
                    return false;
                } else {
                    numShowUps[num - 1] = true;
                }
            }
        }
        for (boolean numShowUp : numShowUps) {
            if (!numShowUp) {
                return false;
            }
        }

        // initialize graph
        for (int i = 1; i < N + 1; i++) {
            graph.put(i, new HashSet<>());
        }

        // create graph
        for (List<Integer> seq : seqs) {
            for (int i = 0; i < seq.size() - 1; i++) {
                Set<Integer> edges = graph.get(seq.get(i));
                if (!edges.contains(seq.get(i + 1))) {
                    edges.add(seq.get(i + 1));
                    in[seq.get(i + 1)]++;
                }
            }
        }

        Stack<Integer> inZeroStack = new Stack<>();
        for (int i = 1; i < N + 1; i++) {
            if (in[i] == 0) {
                inZeroStack.push(i);
                genList.add(i);
            }
        }

        if (inZeroStack.size() != 1) {
            ans = false;
        } else {
            while (inZeroStack.size() == 1) {
                Integer cur = inZeroStack.pop();
                Set<Integer> edges = graph.get(cur);
                for (Integer edge : edges) {
                    in[edge]--;
                    if (in[edge] == 0) {
                        genList.add(edge);
                        inZeroStack.push(edge);
                    }
                }
            }
            if (inZeroStack.isEmpty() && genList.size() == org.length) {
                ans = true;
                for (int i = 0; i < genList.size(); i++) {
                    if (org[i] != genList.poll()) {
                        ans = false;
                    }
                }
            } else {
                ans = false;
            }
        }

        return ans;
    }
}
