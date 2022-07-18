class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int buyState=-prices[0];
        int sellState=0;
        int waitState=0;
        for(int i=1;i<prices.size();i++)
        {
            int nb=max(-prices[i]+waitState,buyState);
            int nw=max(sellState,waitState);
            int ns=max(sellState,buyState+prices[i]);
            buyState=nb;
            sellState=ns;
            waitState=nw;            
        }
        return sellState;
    }
};
class Solution {
public:
    
    int solve(vector<int>& price,int i,int n,int b,vector<vector<int>> &out){
        if(i>=n) return 0;
        if(out[i][b]!=INT_MIN) return out[i][b];
        if(b==0)
        {
           int x=solve(price,i+1,n,b,out);// go ahead
           int y=-price[i]+solve(price,i+1,n,1,out);//buy now
           return out[i][b]=max(x,y);
        }
        //when you have already bought
        int x=solve(price,i+1,n,b,out); //continue
        int y=solve(price,i+2,n,0,out)+price[i];//sell buy go 2 steps ahead 
        return out[i][b]=max(x,y);   
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> out(prices.size()+1,vector<int>(2,INT_MIN));
        return solve(prices,0,prices.size(),0,out);
    }
};
