

public class Main {
    //problem specific variables
    static ArrayList<Pair> adj[];
    static int U[], V[];

    //HLD stuff
    static int subtree_size[], chain[], chainHead[], position[], chainId = 0,pos = 0;

    //LCA stuff
    static int parent[][], level[], MAX;

    //Segment tree related stuff
    static int n, arr[], tree[];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while(t-->0) {
            //reset
            chainId = 0;
            pos = 0;

            n = scanner.nextInt();
            MAX = (int)(log(n)/log(2));
            adj = new ArrayList[n+1];
            for(int i=1;i<=n;++i) {
                adj[i] = new ArrayList<>();
            }
            U = new int[n];
            V = new int[n];
            for(int i=1;i<n;++i) {
                int u = scanner.nextInt(), v = scanner.nextInt(), c = scanner.nextInt();
                adj[u].add(new Pair(v, c));
                adj[v].add(new Pair(u, c));
                U[i] = u;
                V[i] = v;
            }
            parent = new int[n+1][MAX+1];
            chain = new int[n+1];
            chainHead = new int[n+1];
            position = new int[n+1];
            subtree_size = new int[n+1];
            arr = new int[n];
            level = new int[n+1];
            int sz = (int)pow(2, ceil(log(n)/log(2)) + 1);
            tree = new int[sz];
            dfs(1,0, 0);
            chainHead[0] = 1;
            HLD(1,0);
            //print the array
            build(1,0, n-1);
            while(true) {
                String s = scanner.next();
                if(s.equals("DONE")) {
                    break;
                }
                if(s.equals("QUERY")) {
                    int u = scanner.nextInt(), v = scanner.nextInt() , LCA = lca(u,v);
                    int max1 = 0;
                    max1 = max(max1, queryUp(u, LCA));
                    max1 = max(max1, queryUp(v, LCA));
                    System.out.println(max1);
                }
                else {
                    int idx = scanner.nextInt(), cost = scanner.nextInt();
                    int u = U[idx], v = V[idx];
                    if(level[u]>level[v]) {
                        update(position[u], cost);
                    }
                    else {
                        update(position[v], cost);
                    }
                }
            }
        }
    }
    static class Pair implements Comparable<Pair>
    {
        int x,y;
        Pair(int x,int y)
        {
            this.x=x;
            this.y=y;
        }
        public int compareTo(Pair other)
        {
            if(this.x!=other.x)
                return this.x-other.x;
            return this.y-other.y;
        }
        public String toString()
        {
            return "("+x+","+y+")";
        }
    }
}
