class Solution {
public:
    void solve(int row, int col, vector <vector <int> > &a, vector <vector <bool> > &vis, int soFarGold, int &maxGold){
        int n = a.size(), m = a[0].size();
        maxGold = max(maxGold, soFarGold);
        if(row + 1 < n and !vis[row + 1][col] and a[row + 1][col] > 0){
            vis[row + 1][col] = true;
            solve(row + 1, col, a, vis, soFarGold + a[row + 1][col], maxGold);
            vis[row + 1][col] = false;
        }
        if(row - 1 >= 0 and !vis[row - 1][col] and a[row - 1][col] > 0){
            vis[row - 1][col] = true;
            solve(row - 1, col, a, vis, soFarGold + a[row - 1][col], maxGold);
            vis[row - 1][col] = false;
        }
        if(col + 1 < m and !vis[row][col + 1] and a[row][col + 1] > 0){
            vis[row][col + 1] = true;
            solve(row, col + 1, a, vis, soFarGold + a[row][col + 1], maxGold);
            vis[row][col + 1] = false;
        }
        if(col - 1 >= 0 and !vis[row][col - 1] and a[row][col - 1] > 0){
            vis[row][col - 1] = true;
            solve(row, col - 1, a, vis, soFarGold + a[row][col - 1], maxGold);
            vis[row][col - 1] = false;
        }
    }
    int getMaximumGold(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), maxGold = 0;
        for(int startRow = 0; startRow < n; ++startRow){
            for(int startCol = 0; startCol < m; ++startCol){
                if(a[startRow][startCol] == 0){
                    continue;
                }
                vector <vector <bool> > vis(n, vector <bool> (m, false));
                vis[startRow][startCol] = true;
                solve(startRow, startCol, a, vis, a[startRow][startCol], maxGold);
            }
        }
        return maxGold;
    }
};
