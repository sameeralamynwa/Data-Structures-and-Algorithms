bool comparator(string x, string y){
    return x.size() < y.size();
}

class Solution {
public:
    int minimumLengthEncoding(vector <string> words) {
        int n = words.size();
        unordered_map <string, bool> occured;
        for(string &s : words){
            occured.insert({s, true});
        }
        int minLength = 0;
        sort(words.begin(), words.end(), comparator);
        for(int i = n - 1; i >= 0; --i){
            if(occured.find(words[i]) == occured.end()){
                continue;
            }
            for(int j = 0; j < (int) words[i].size(); ++j){
                string current = words[i].substr(j);
                occured.erase(current);
            }
            minLength += (int) words[i].size() + 1;
        }
        return minLength;
    }
    
};
