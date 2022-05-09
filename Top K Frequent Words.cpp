class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        set <pair <int, string> > candidates;
        map <string, int> count;
        for(string &s : words){
            count[s]++;
            if(candidates.size() < k){
                candidates.erase({count[s] - 1, s});
                candidates.insert({count[s], s});
            }
            else{
                if(candidates.find({count[s] - 1, s}) != candidates.end()){
                    candidates.erase({count[s] - 1, s});
                    candidates.insert({count[s], s});
                }
                else{
                    if(count[s] > candidates.begin() -> first){
                        candidates.erase(candidates.begin());
                        candidates.insert({count[s], s});
                    }
                }
            }
        }
        vector <string> kFrequent;
        int leastCount = candidates.begin() -> first;
        while(candidates.size() and candidates.begin() -> first == leastCount){
            candidates.erase(candidates.begin());
        }
        while(candidates.size()){
            int currentCount = candidates.rbegin() -> first;
            vector <string> store;
            while(candidates.size() and candidates.rbegin() -> first == currentCount){
                store.push_back(candidates.rbegin() -> second);
                candidates.erase(--candidates.end());
            }
            for(int i = store.size() - 1; i >= 0; --i){
                kFrequent.push_back(store[i]);
            }
        }
        for(auto it = count.begin(); it != count.end() and kFrequent.size() < k; ++it){
            if(it -> second == leastCount){
                kFrequent.push_back(it -> first);
            }
        }
        return kFrequent;
    }
};
