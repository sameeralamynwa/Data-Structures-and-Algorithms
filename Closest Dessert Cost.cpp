class Solution {
public:
    void solve(int pos, bool baseTaken, int top, vector<int>& baseCosts, vector<int>& toppingCosts, int target, int currentCost, int &closestCost){
        if(baseTaken and abs(currentCost - target) <= abs(closestCost - target)){
            if(abs(currentCost - target) == abs(closestCost - target)){
                closestCost = min(closestCost, currentCost);
            }
            else{
                closestCost = currentCost;
            }
        }
        if(baseTaken){
            if(top + 1 <= toppingCosts.size()){
                solve(pos, baseTaken, top + 1, baseCosts, toppingCosts, target, currentCost, closestCost);
                solve(pos, baseTaken, top + 1, baseCosts, toppingCosts, target, currentCost + toppingCosts[top], closestCost);
            }
        }
        else{
            if(pos + 1 <= baseCosts.size()){
                solve(pos + 1, baseTaken, top, baseCosts, toppingCosts, target, currentCost, closestCost);
                solve(pos + 1, !baseTaken, top, baseCosts, toppingCosts, target, currentCost + baseCosts[pos], closestCost);
            }
        }
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int numberOfToppings = toppingCosts.size();
        for(int i = 0; i < numberOfToppings; ++i){
            toppingCosts.push_back(toppingCosts[i]);
        }
        int closestCost = baseCosts.back();
        solve(0, false, 0, baseCosts, toppingCosts, target, 0, closestCost);
        return closestCost;
    }
};
