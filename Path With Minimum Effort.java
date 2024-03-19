class Solution {
    class UnionFind {
        int[] parent;
        int[] rank;

        public UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        public boolean union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX == rootY) {
                return false;
            }

            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }

            return true;
        }
    }

    public int minimumEffortPath(int[][] heights) {
        int rows = heights.length;
        int cols = heights[0].length;

        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int[][] edges = new int[rows * cols * 4][3];
        int totalEdges = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int currentIndex = r * cols + c;
                for (int[] dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                        int nextIndex = nr * cols + nc;
                        edges[totalEdges++] = new int[]{Math.abs(heights[r][c] - heights[nr][nc]), currentIndex, nextIndex};
                    }
                }
            }
        }

        Arrays.sort(edges, 0, totalEdges, (a, b) -> a[0] - b[0]);

        UnionFind uf = new UnionFind(rows * cols);

        for (int i = 0; i < totalEdges; i++) {
            int[] edge = edges[i];
            int weight = edge[0];
            int x = edge[1];
            int y = edge[2];
            if (uf.union(x, y)) {
                if (uf.find(0) == uf.find(rows * cols - 1)) {
                    return weight;
                }
            }
        }

        return 0;
    }
}
