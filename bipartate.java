
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;

public class bipartate {
    class Solution{
        public boolean isBipartite(int[][] graph) {
            Queue<BipartitePair> q = new LinkedList<>();
            HashMap<Integer, Integer> visited = new HashMap<>();
            for (int i=0;i<graph.length;i++) {
                if (visited.containsKey(i)) {
                    continue;
                }
                q.add(new BipartitePair(i,0));
                while(!q.isEmpty()) {
                    // remove
                    BipartitePair rp = q.poll();
                    // ignore if already visited
                    if (visited.containsKey(rp.vtx)){
                        if (visited.get(rp.vtx)!=rp.dis) {
                            return false;
                        }
                        continue;
                    }
                    // marked visited
                    visited.put(rp.vtx, rp.dis);

                    for (int nbrs:graph[rp.vtx]) {
                        if (!visited.containsKey(nbrs)) {
                            q.add(new BipartitePair(nbrs, rp.dis+1));
                        }
                    }
                }
            }

            return true;
        }
    }

    class BipartitePair{
        int vtx;
        int dis;

        public BipartitePair(int vtx, int dis) {
            this.vtx=vtx;
            this.dis=dis;
        }
    }
}
