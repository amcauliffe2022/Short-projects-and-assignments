import java.util.*;
public class Kruskal {

    static class Edgelist implements Comparable<Kruskal.Edgelist> {
        int source;
        int destination;
        int weight;

        @Override
        public int compareTo(Kruskal.Edgelist o) {
            return this.weight - o.weight;
        }
    }

    int Vnum;
    int Enum;
    int totalweight = 0;
    Edgelist[] Edgelist;

    Kruskal(int vertexnum, int edgenum) {
        this.Vnum = vertexnum;
        this.Enum = edgenum;
        this.Edgelist = new Edgelist[edgenum];
        for (int x = 0; x < edgenum; x++) {
            Edgelist[x] = new Edgelist();
        }
    }

    class set {
        int parent;
        int rank;
    }

    public int findRoot(set[] subset, int a) {
        if (subset[a].parent != a) {
            subset[a].parent = findRoot(subset, subset[a].parent);
        }
        return subset[a].parent;
    }

    public void Union(set[] subsets, int x, int y) {
        int subset1root = findRoot(subsets, x);
        int subset2root = findRoot(subsets, y);

        if (subsets[subset1root].rank < subsets[subset2root].rank) {
            subsets[subset1root].parent = subset2root;
        } else if (subsets[subset1root].rank > subsets[subset2root].rank) {
            subsets[subset2root].parent = subset1root;
        } else {
            subsets[subset2root].parent = subset1root;
            subsets[subset1root].rank++;
        }
    }

    public void MST() {
        Kruskal.Edgelist[] MST = new Edgelist[Vnum];
        int mstindex = 0;
        int storedindex = 0;

        for (int x = 0; x < Vnum; x++) {
            MST[x] = new Edgelist();
        }

        Arrays.sort(Edgelist);

        set[] subsets = new set[Vnum];
        for (int x = 0; x < Vnum; x++) {
            subsets[x] = new set();
            subsets[x].parent = x;
            subsets[x].rank = 0;
        }

        while (mstindex < Vnum - 1 && storedindex < Enum - 1) {
            Kruskal.Edgelist nextEdge = new Edgelist();
            nextEdge = Edgelist[storedindex];
            storedindex++;

            int sourceRoot = findRoot(subsets, nextEdge.source);
            int destinationRoot = findRoot(subsets, nextEdge.destination);

            if (sourceRoot != destinationRoot) {
                MST[mstindex] = nextEdge;
                mstindex++;
                totalweight = totalweight + nextEdge.weight;
                Union(subsets, sourceRoot, destinationRoot);
            }
        }
        System.out.println("Following are the edges in " + "the constructed MST");
        for (int i = 0; i < mstindex; ++i) {
            System.out.println(MST[i].source + " -- " +
                    MST[i].destination + " == " + MST[i].weight);
        }
        System.out.println( "Total Weight: " + totalweight);

    }


    public static void main(String[] args) {

            int V = 100;  // Number of vertices in graph
            ArrayList<Kruskal.Edgelist> edges = new ArrayList<Kruskal.Edgelist>();
            for (int x = 0; x < 100; x++) {
                Kruskal.Edgelist temp = new Kruskal.Edgelist();
                int edgeNum = (int) (Math.random() * 4 + 2);
                while (edgeNum != 0) {
                    temp.source = x;
                    temp.destination = (int) (Math.random() * 100);
                    temp.weight = (int) (Math.random() * 4 + 2);
                    edges.add(temp);
                    edgeNum--;
                }
            }
            int E = edges.size();
            Kruskal graph = new Kruskal(V, E);
            for (int x = 0; x < E - 1; x++) {
                graph.Edgelist[x].source = edges.get(x).source;
                graph.Edgelist[x].destination = edges.get(x).destination;
                graph.Edgelist[x].weight = edges.get(x).weight;
            }
            int time = (int) System.nanoTime();
            graph.MST();
            System.out.println("Time to complete: " + ((int)System.nanoTime() - time));

    }
}


