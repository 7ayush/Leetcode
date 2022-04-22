class Solution {
public:
    static bool compare(vector<int> &a,vector<int>&b)
    {
        if(a[1]<b[1])return true;
        else if(a[1]==b[1])return a[0]<b[0];
        return false;
        
    }
    int countOnes(int x)
    {
        int count=0;
        while(x>0)
        {
            count+=x&1;
            x=x>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>>vec;
        
        for(int i:arr)vec.push_back({i,countOnes(i)});
        sort(vec.begin(),vec.end(),compare);
        for(int i=0;i<arr.size();i++)arr[i]=vec[i][0];
        return arr;
    }
};
