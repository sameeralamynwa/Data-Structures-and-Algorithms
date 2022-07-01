class StockSpanner {
private:
    vector <int> pricesSoFar;
    stack <int> justGreater;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        pricesSoFar.push_back(price);
        while(justGreater.empty() == false and price >= pricesSoFar[justGreater.top()]){
            justGreater.pop();
        }
        int span = justGreater.empty() ? pricesSoFar.size() : pricesSoFar.size() - justGreater.top() - 1;
        justGreater.push((int) pricesSoFar.size() - 1);
        return span;
    }
};
