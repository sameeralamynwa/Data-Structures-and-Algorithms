class Solution {
public:
    bool dfs(int u, vector <vector <int> > &graph, vector <int> &color){
        for(int x : graph[u]){
            if(color[x] == -1){
                color[x] = 1 - color[u];
                if(dfs(x, graph, color) == false){
                    return false;
                }
            }
            else if(color[x] != 1 - color[u]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> color((int) graph.size(), -1);
        bool bipartite = true;
        for(int i = 0; i < (int) graph.size(); ++i){
            if(color[i] == -1){
                color[i]++;
                bipartite &= dfs(i, graph, color);
            }
        }
        return bipartite;
    }
};
