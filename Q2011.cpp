class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans=0;
        for(string i:operations)
        {
            if(i=="--X"||i=="X--")ans--;
            else ans++;
        }
        return ans;
    }
};
