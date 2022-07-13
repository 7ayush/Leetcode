class Solution {
public:
    int getMaxLen(vector<int>& nums) 
    {
        int start=0,end=0;
        int firstMinus=-1,lastMinus=-1;
        int ans=0,maxAns=0,count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                end--;
                if(count%2==0)ans=end-start+1;
                else
                {
                    ans=max(end-firstMinus,lastMinus-start);
                }
                maxAns=max(ans,maxAns);
                start=i+1;
                end=i+1;
                firstMinus=-1;
                lastMinus=-1;
                count=0;
            }
            else
            {
                if(nums[i]<0)
                {
                    if(firstMinus==-1)firstMinus=i;
                    lastMinus=i;
                    count++;
                }
                end++;                
            }
        }
        end--;
        if(count%2==0)ans=end-start+1;
        else
        {
            ans=max(end-firstMinus,lastMinus-start);
        }
        maxAns=max(ans,maxAns);
        return maxAns;        
    }
};


