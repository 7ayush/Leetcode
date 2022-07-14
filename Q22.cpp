class Solution {
public:
    void util(vector<string>&ans,int start,int end,string curr)
    {
        if(start==0&&end==0){
            ans.push_back(curr);
            return;
        }
        if(start==end)
        {
            util(ans,start-1,end,curr+'(');
            return;
        }
        if(start>0)util(ans,start-1,end,curr+'(');
        if(end>0)util(ans,start,end-1,curr+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        util(ans,n,n,"");
        return ans;
    }
};

