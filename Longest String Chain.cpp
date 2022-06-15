class Solution {
public:
    int longestStrChain(vector <string> &words) {
        map <string, int> indexOf;
        for(int i = 0; i < (int) words.size(); ++i){
            indexOf.insert({words[i], i});
        }
        vector <int> chainLength((int) words.size(), 1);
        for(int length = 16; length >= 1; length--){
            for(int i = 0; i < (int) words.size(); ++i){
                if(words[i].size() == length){
                    for(int split = 0; split < (int) words[i].size(); ++split){
                        string predecessor = words[i].substr(0, split) + words[i].substr(split + 1);
                        if(indexOf.find(predecessor) != indexOf.end()){
                            chainLength[indexOf[predecessor]] = max(chainLength[indexOf[predecessor]], chainLength[i] + 1);
                        }
                    }
                }
            }
        }
        return *max_element(chainLength.begin(), chainLength.end());
    }
};

    
