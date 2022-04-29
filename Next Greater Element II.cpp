class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            nums.push_back(nums[i]);
        }
        vector <int> nextGreater(2 * n), nextGreaterValue;
        stack <int> rightElement;
        for(int i = 2 * n - 1; i >= 0; --i){
            if(i == 2 * n - 1){
                nextGreater[i] = -1;
                rightElement.push(i - n);
            }
            else{
                while(rightElement.size() and nums[i] >= nums[rightElement.top()]){
                    rightElement.pop();
                }
                if(rightElement.empty() == false){
                    nextGreater[i] = rightElement.top() - i >= n ? -1 : rightElement.top();
                }
                else{
                    nextGreater[i] = -1;
                }
                rightElement.push(i);
            }
            if(i < n){
                nextGreaterValue.push_back(nextGreater[i] == -1 ? -1 : nums[nextGreater[i] % n]);
            }
        }
        reverse(nextGreaterValue.begin(), nextGreaterValue.end());
        return nextGreaterValue;
    }
};
