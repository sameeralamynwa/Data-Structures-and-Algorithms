class Solution{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector <int> nextGreater(n);
        vector <long long> nextGreaterValue;
        stack <int> rightElement;
        for(int i = n - 1; i >= 0; --i){
            if(i == n - 1){
                nextGreater[i] = -1;
                rightElement.push(i);
            }
            else{
                while(rightElement.size() and arr[i] > arr[rightElement.top()]){
                    rightElement.pop();
                }
                if(rightElement.empty() == false){
                    nextGreater[i] = rightElement.top();
                }
                else{
                    nextGreater[i] = -1;
                }
                rightElement.push(i);
            }
            nextGreaterValue.push_back(nextGreater[i] == -1 ? -1 : arr[nextGreater[i]]);
        }
        reverse(nextGreaterValue.begin(), nextGreaterValue.end());
        return nextGreaterValue;
    }
};
