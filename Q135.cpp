class Solution {
public:
    void util(vector<int>&ratings,vector<int>&candy)
    {
        for(int i=1;i<candy.size();i++)
        {
            if(ratings[i]>ratings[i-1]){
                int newVal=candy[i-1]+1;               
                candy[i]=max(candy[i],newVal);
            }
        }
    }
    int candy(vector<int>& ratings) {
        if(ratings.size()==1)return 1;
        vector<int>candy(ratings.size(),1);
        util(ratings,candy);
        reverse(candy.begin(),candy.end());
        reverse(ratings.begin(),ratings.end());
        util(ratings,candy);        
        int sum=0;
        for(auto i:candy)sum+=i;
        return sum;
        
        
    }
};
