class Solution {
private:
    vector <int> dx {-1, 1, 0, 0}, dy {0, 0, 1, -1};
public:
    bool isValid(int row, int col, int n, int m){
        return row >= 0 and row < n and col >= 0 and col < m;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e6, minEffort;
        while(low <= high){
            int mid = (low + high) >> 1;
            queue <pair <int, int> > q;
            vector <vector <bool> > visited(heights.size(), vector <bool> (heights[0].size(), false));
            q.push({0, 0});
            visited[0][0] = true;
            while(q.empty() == false){
                auto currentCell = q.front();
                q.pop();
                for(int d = 0; d < 4; ++d){
                    int newX = currentCell.first + dx[d], newY = currentCell.second + dy[d];
                    if(isValid(newX, newY, heights.size(), heights[0].size())){
                        if(visited[newX][newY] == false){
                            if(abs(heights[newX][newY] - heights[currentCell.first][currentCell.second]) <= mid){
                                q.push({newX, newY});
                                visited[newX][newY] = true;
                            }
                        }
                    }
                }
            }
            if(visited[heights.size() - 1][heights[0].size() - 1] == true){
                minEffort = mid;
                high = --mid;
            }
            else{
                low = ++mid;
            }
        }
        return minEffort;
    }
};
