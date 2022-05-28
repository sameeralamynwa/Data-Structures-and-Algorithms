class Solution {
public:
    int xorTillN(int n){
        if(n % 4 == 0){
            return n;
        }
        else if(n % 4 == 1){
            return 1;
        }
        else if(n % 4 == 2){
            return n + 1;
        }
        else{
            return 0;
        }
    }
    
    int missingNumber(vector<int>& nums) {
        for(int i = 1; i < (int) nums.size(); ++i){
            nums[i] = nums[i] ^ nums[i - 1];
        }
        return nums.back() ^ xorTillN((int) nums.size());
    }
};
