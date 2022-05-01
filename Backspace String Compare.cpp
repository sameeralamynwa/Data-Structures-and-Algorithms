class Solution {
public:
    string typed(string s) {
        string finalS;
        for(char c : s){
            if(c == '#'){
                if(finalS.empty() == false){
                    finalS.pop_back();
                }
            }
            else{
                finalS.push_back(c);
            }
        }
        return finalS;
    }
    
    bool backspaceCompare(string s, string t) {
        return typed(s) == typed(t);
    }
};
