class Solution {
public:
    string countAndSay(int n) {
        string currentSequence;
        for(int i = 0; i < n; ++i){
            string newSequence;
            if(i == 0){
                newSequence = "1";
            }
            else{
                for(int i = 0; i < (int) currentSequence.size();){
                    int j = i;
                    while(j < (int) currentSequence.size() and currentSequence[j] == currentSequence[i] and ++j);
                    newSequence += to_string(j - i);
                    newSequence.push_back(currentSequence[i]);
                    i = j;
                }
            }
            currentSequence = newSequence;
        }
        return currentSequence;
    }
};
