class Solution {
public:
    int dsu_find(int u, vector <int> &parent){
        return u == parent[u] ? u : parent[u] = dsu_find(parent[u], parent);
    }
    
    void dsu_union(int u, int v, vector <int> &parent){
        u = dsu_find(u, parent);
        v = dsu_find(v, parent);
        if(u != v){
            parent[u] = v;
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector <int> parent((int) s.size());
        for(int i = 0; i < (int) parent.size(); ++i){
            parent[i] = i;
        }
        
        for(vector <int> canSwap : pairs){
            dsu_union(canSwap[0], canSwap[1], parent);
        }
        
        map <int, vector <int> > disjointSets;
        for(int i = 0; i < (int) s.size(); ++i){
            disjointSets[dsu_find(i, parent)].push_back(i);
        }
        
        for(map <int, vector <int> > :: iterator it = disjointSets.begin(); it != disjointSets.end(); ++it){
            vector <int> alphabet(26, 0);
            auto &v = it -> second;
            for(int x : v){
                alphabet[s[x] - 'a']++;
            }
            reverse(v.begin(), v.end());
            for(int i = 0; i < 26; ++i){
                while(alphabet[i]--){
                    s[v.back()] = (char) (i + 'a');
                    v.pop_back();
                }
            }
        }
        return s;
    }
};
