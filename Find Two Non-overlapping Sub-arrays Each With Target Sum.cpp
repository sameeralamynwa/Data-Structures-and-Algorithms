class Solution {
public:
    int minSumOfLengths(vector<int>& a, int target) {
        int n = a.size(), sum = 0;
        vector <int> suffMin(n, -1);
        map <int, int> valueAt;
        for(int i = n - 1; i >= 0; --i){
            sum += a[i];
            if(sum == target){
                suffMin[i] = n - i;
            }
            else if(valueAt.find(sum - target) != valueAt.end()){
                if(i + 1 == n or suffMin[i + 1] == -1){
                    suffMin[i] = valueAt[sum - target] - i;
                }
                else{
                    suffMin[i] = min(suffMin[i + 1], valueAt[sum - target] - i);
                }
            }
            else if(i + 1 < n and suffMin[i + 1] != -1){
                suffMin[i] = suffMin[i + 1];
            }
            valueAt[sum] = i;
        }
        
        int leftEnd = 0, rightEnd = 0, len = 0, minLen = -1;
        sum = 0;
        while(leftEnd < n){
            while(rightEnd < n and sum < target){
                sum += a[rightEnd++];
            }
            if(sum == target){
                len = rightEnd - leftEnd;
                if(rightEnd < n and suffMin[rightEnd] != -1){
                    len += suffMin[rightEnd];
                    if(minLen == -1 or len < minLen){
                        minLen = len;
                    }
                }
            }
            sum -= a[leftEnd];
            leftEnd++;
        }
        return minLen;
    }
};
