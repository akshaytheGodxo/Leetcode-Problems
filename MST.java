import java.util.*;

public class MST {
    static HashMap<Integer, List<Integer>> map = new HashMap<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        for (int i=1;i<=n;i++) {
            map.put(i, new ArrayList<>());
        }

        for (int i=1;i<=m;i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            map.get(a).add(b);
            map.get(b).get(a);
        }
        System.out.println(prims());
    }

    public static int prims() {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b)->a.cost-b.cost);
        pq.add(new Pair(1, 0));
        HashSet<Integer> visited = new HashSet<>();
        int sum=0;
        while (!pq.isEmpty()) {
            // 1. remove
            Pair rp = pq.poll();
            // 2. ignore if already
            if (visited.contains(rp.vtx)) {
                continue;
            }
            visited.add(rp.vtx);
            sum += rp.cost;
            for (int nbrs = 1;nbrs<=map.size();nbrs++) {
                if (!visited.contains(nbrs)) {
                    int cost = 0;
                    if (map.get(rp.vtx).contains(nbrs)) {
                        cost++;                       
                    }
                    pq.add(new Pair(nbrs, cost));
                }
            }
        }

        return sum;
    }

    static class Pair{
        int vtx;
        int cost;
        public Pair(int vtx, int cost) {
            this.cost = cost;
            this.vtx = vtx;
        }
    }
}