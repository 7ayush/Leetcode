class Solution {
public:
    vector<double> convertTemperature(double c) {
        double f,k;
        k=c+273.15;
        f=(c/5)*9+32;
        return {k,f};
    }
};
