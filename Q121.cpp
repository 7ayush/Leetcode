// Method 1 using stack O(N) time O(N) space stack
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        stack<int>s;
        int maxProfit=0;
        for(int i=prices.size()-1;i>0;i--)
        {
            if(s.empty())
            {
                s.push(prices[i]);
            }
            else
            {
                if(s.top()<prices[i])
                {
                    s.push(prices[i]);
                }
                else
                {
                    s.push(s.top());
                }
            }
            
        }
        for(int i=0;i<prices.size()-1;i++)
        {
            int profit=s.top()-prices[i];
            s.pop();
            if(profit>maxProfit)
            {
                maxProfit=profit;
            }
        }
        return maxProfit;
    }
};


//By calculating minimum before the current element at every step and calculating the subsequent maxProfit

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int maxProfit=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(mini>prices[i])mini=prices[i];
            int profit=prices[i]-mini;
            if(maxProfit<profit)maxProfit=profit;
        }
        return maxProfit;
    }
};
