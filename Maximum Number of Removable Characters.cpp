class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size() - 1, canTakeTill = 0;
        while(low <= high){
            int mid = (low + high) >> 1;
            vector <bool> canTake((int) s.size(), true);
            for(int i = 0; i <= mid; ++i){
                canTake[removable[i]] = false;
            }
            int i = 0, j = 0;
            while(j < (int) p.size()){
                while(i < (int) s.size() and (canTake[i] == false or s[i] != p[j])){
                    ++i;
                }
                if(i < (int) s.size()){
                    ++j;
                    ++i;
                }
                else{
                    break;
                }
            }
            if(j == (int) p.size()){
                low = ++mid;
                canTakeTill = mid;
            }
            else{
                high = --mid;
            }
        }
        return canTakeTill;
    }
};
