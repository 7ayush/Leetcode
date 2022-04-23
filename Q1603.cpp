class ParkingSystem {
public:
    vector<int>ans;
    ParkingSystem(int big, int medium, int small) {
        ans.push_back(big);
        ans.push_back(medium);
        ans.push_back(small);        
    }
    
    bool addCar(int carType) {
        if(ans[carType-1]==0)return false;
        ans[carType-1]-=1;
        return true;
    }
};

