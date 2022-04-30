class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        while(s != "1" and ++steps){
            if(s.back() == '1'){
                if(count(s.begin(), s.end(), '0') == 0){
                    for(int i = 0; i < (int) s.size(); ++i){
                        s[i]  = '0';
                    }
                    s.insert(s.begin(), '1');
                }
                else{
                    for(int i = (int) s.size() - 1; i >= 0; --i){
                        if(s[i] == '0'){
                            s[i] = '1';
                            break;
                        }
                    }
                }
            }
            else{
                s.pop_back();
            }
        }
        return steps;
    }
};
