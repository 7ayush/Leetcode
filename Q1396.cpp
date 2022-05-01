class UndergroundSystem {
public:
   map<int,pair<string,double>> customer;
	//customer is storing customer id as key and station name and time as value
    map<pair<string, string>, pair<double, int>> total;
	//total is storing startstation and endstation as key and totaltime and count as value
    UndergroundSystem() {
        customer.clear();
        total.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        customer[id]={stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        total[{customer[id].first, stationName}]={total[{customer[id].first, stationName}].first+(t-customer[id].second),total[{customer[id].first, stationName}].second+1};
    }
    
    double getAverageTime(string startStation, string endStation) {
        return total[{startStation,endStation}].first/total[{startStation,endStation}].second;
    }

};
