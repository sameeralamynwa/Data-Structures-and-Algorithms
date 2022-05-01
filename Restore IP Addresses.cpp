class Solution {
public:
    void solve(int pos, int currentNumber, string &s, vector <string> &addresses, string validIP){
        int numbersTakenSoFar = count(validIP.begin(), validIP.end(), '.');
        
        if(currentNumber > 255 or numbersTakenSoFar > 4){
            return;
        }
                
        if(pos == s.size() and numbersTakenSoFar == 4 and validIP.size() == s.size() + 4){
            validIP.pop_back();
            addresses.push_back(validIP);
            return;
        }
        
        if(pos == s.size()){
            return;
        }
        
        currentNumber *= 10;
        currentNumber += s[pos] - '0';
        
        if(currentNumber <= 255){
            solve(pos + 1, 0, s, addresses, validIP + to_string(currentNumber) + ".");
        }
        
        solve(pos + 1, currentNumber, s, addresses, validIP);
    }
    vector<string> restoreIpAddresses(string s) {
        vector <string> allValidAddresses;
        solve(0, 0, s, allValidAddresses, "");
        return allValidAddresses;
    }
};
