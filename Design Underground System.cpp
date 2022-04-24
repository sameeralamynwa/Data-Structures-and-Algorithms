class UndergroundSystem {
public:
    map <pair <string, string>, vector <int> > intervals;
    map <int, pair <string, int> > checkInStation;
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        intervals[{checkInStation[id].first, stationName}].push_back(t - checkInStation[id].second);
        checkInStation.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        vector <int> &allIntervals = intervals[{startStation, endStation}];
        return (double) accumulate(allIntervals.begin(), allIntervals.end(), 0LL) / (int) allIntervals.size();
    }
};
