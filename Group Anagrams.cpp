class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <string, vector <string> > groupedAnagrams;
        for(string &s : strs){
            string sortedString = s;
            sort(sortedString.begin(), sortedString.end());
            groupedAnagrams[sortedString].push_back(s);
        }
        
        vector <vector <string> > combined;
        for(map <string, vector <string> > :: iterator it = groupedAnagrams.begin(); it != groupedAnagrams.end(); ++it){
            combined.push_back(it -> second);
        }
        
        return combined;
    }
};
