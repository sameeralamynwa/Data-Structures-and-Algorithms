class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string maybe;
        do{
            maybe = "";
            for(int i = 0; i < (int) nums.size(); ++i){
                maybe += to_string(rand() % 2);
            }
        }while(find(nums.begin(), nums.end(), maybe) != nums.end());
        
        return maybe;
    }
};
