class Solution{
    public:
    int tour(petrolPump p[], int n){
        int l = 0, r = 0, currentPetrol = 0;
        while(l < n){
            if(l == r){
                currentPetrol = p[l].petrol - p[l].distance;
                ++r;
                r %= n;
            }
            while(r != l and currentPetrol >= 0 and currentPetrol + p[r].petrol - p[r].distance >= 0){
                currentPetrol += p[r].petrol - p[r].distance;
                ++r;
                r %= n;
            }
            currentPetrol -= p[l].petrol - p[l].distance;
            if(r == l){
                return l;
            }
            ++l;
        }
        return -1;
    }
};
