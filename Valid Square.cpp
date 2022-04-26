class Solution {
public:
    int distance(vector <int> a, vector <int> b){
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector <vector <int> > adj {p1, p2, p3, p4};
        sort(adj.begin(), adj.end());
        
        p1 = adj[0];
        p2 = adj[1];
        p3 = adj[2];
        p4 = adj[3];
        
        bool isValid = distance(p1, p2) == distance(p3, p4);
        isValid &= distance(p1, p2) == distance(p1, p3);
        isValid &= p1 != p2 and p1 != p3 and p1 != p4 and p2 != p3 and p2 != p4 and p3 != p4;
        isValid &= (p2[1] - p1[1]) * (p4[0] - p3[0]) == (p4[1] - p3[1]) * (p2[0] - p1[0]);
        isValid &= (p2[1] - p1[1]) * (p3[1] - p1[1]) == -1 * (p2[0] - p1[0]) * (p3[0] - p1[0]);
        
        return isValid;
    }
};
