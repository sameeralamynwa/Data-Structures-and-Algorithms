bool comparator(string &a, string &b){
    return a + b == b + a ? false : a + b > b + a;
}

class Solution {
public:    
    string largestNumber(vector<int>& nums) {
        vector <string> numsString;
        for(int &x : nums){
            numsString.push_back(to_string(x));
        }
        
        sort(numsString.begin(), numsString.end(), comparator);
        
        string largestNumber;
        for(string &s : numsString){
            largestNumber += s;
        }
        
        reverse(largestNumber.begin(), largestNumber.end());
        while(largestNumber.size() > 1 and largestNumber.back() == '0'){
            largestNumber.pop_back();
        }
        reverse(largestNumber.begin(), largestNumber.end());
        
        return largestNumber;
    }
};
