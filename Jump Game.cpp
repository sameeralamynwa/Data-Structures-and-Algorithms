class Solution {
public:
    bool canJump(vector <int> &nums) {
        int maxIndexReachable = 0;
        for(int i = 0; max(maxIndexReachable, i) < (int) nums.size(); ++i){
            if(i > maxIndexReachable){
                return false;
            }
            else{
                maxIndexReachable = max(maxIndexReachable, i + nums[i]);
            }
        }
        return true;
    }
};
