class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxConsecutive = 0;
        unordered_set <int> elements(nums.begin(), nums.end());
        for(int x : nums){
            if(elements.find(x) != elements.end()){
                elements.erase(x);
                int previous = x - 1;
                while(elements.find(previous) != elements.end()){
                    elements.erase(previous);
                    previous--;
                }
                int next = x + 1;
                while(elements.find(next) != elements.end()){
                    elements.erase(next);
                    ++next;
                }
                maxConsecutive = max(maxConsecutive, next - previous - 1);
            }
        }
        return maxConsecutive;
    }
};
