class Solution {
private:
    const int mod = 1e9 + 7;
public:
    void solve(int pos, string &s, set <int> &taken, int &maxUnique){
        if(pos == (int) s.size()){
            maxUnique = max(maxUnique, (int) taken.size());
            return;
        }
        int hashValue = 0;
        for(int j = pos; j < (int) s.size(); ++j){
            hashValue = (long long) hashValue * 10 % mod;
            hashValue += s[j] - '0';
            if(taken.find(hashValue) == taken.end()){
                taken.insert(hashValue);
                solve(j + 1, s, taken, maxUnique);
                taken.erase(hashValue);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        int maxUnique = 0;
        set <int> taken;
        solve(0, s, taken, maxUnique);
        return maxUnique;
    }
};
