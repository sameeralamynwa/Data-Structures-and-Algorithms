class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map <int, int> xorCount, xorIndex;
        int currentXOR = 0, triplets = 0;
        xorCount[currentXOR]++;
        for(int i = 0; i < (int) arr.size(); ++i){
            currentXOR ^= arr[i];
            
            triplets += xorCount[currentXOR] * i;
            triplets -= xorIndex[currentXOR];
            
            xorIndex[currentXOR] += i + 1;
            xorCount[currentXOR]++;
        }
        return triplets;
    }
};
