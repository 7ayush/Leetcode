class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int, int> vals;
        for (int i = 0 ; i < arr.size() ;i ++ ){
            vals[arr[i]]++;
        }
        for (int i =0 ; i <  arr.size() ;i++){
            if (arr[i] == 0 && vals[0]%2==0) return true;
            if (vals.count(arr[i]*2) && arr[i]!=0) return true;
        }
        return false;
    }
};
