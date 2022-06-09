class Solution {
public:
    long long maximumImportance(int n, vector <vector <int> > &roads) {
        vector <int> degree(n);
        for(vector <int> &edges : roads){
            for(int &nodes : edges){
                ++degree[nodes];
            }
        }
        sort(degree.begin(), degree.end());
        long long importance = 0;
        for(int i = 0; i < (int) degree.size(); ++i){
            importance += (long long) (i + 1) * degree[i];
        }
        return importance;
    }
};
