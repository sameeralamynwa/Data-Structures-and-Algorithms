class Solution {
public:
    int findKthLargest(vector <int> &nums, int k) {
        priority_queue <int, vector <int>, greater<int> > maxElements;
        for(int &x : nums){
            maxElements.push(x);
            if((int) maxElements.size() > k){
                maxElements.pop();
            }
        }
        return maxElements.top();
    }
};
