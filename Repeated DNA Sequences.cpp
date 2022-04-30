class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map <string, int> sequences;
        for(int i = 0; i + 9 < (int) s.size(); ++i){
            sequences[s.substr(i, 10)]++;
        }
        vector <string> repeatedSequences;
        for(auto it = sequences.begin(); it != sequences.end(); ++it){
            if(it -> second > 1){
                repeatedSequences.push_back(it -> first);
            }
        }
        return repeatedSequences;
    }
};
