class Solution {
public:
    vector<int>util(vector<int>nums,int k)
    {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() and dq.front()==(i-k))
                dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if(i>=(k-1))
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans=0;
        vector<long long>prefix(runningCosts.size()+1,0);
        int n=chargeTimes.size();
        for(int i=1;i<prefix.size();i++)
        {
            prefix[i]=prefix[i-1]+runningCosts[i-1];
        }
        for(int size=1;size<=n;size++)   
        {
            vector<int>maxis=util(chargeTimes,size);
            bool found=true;
            for(int j=0;j+size<runningCosts.size();j++)
            {
                if(maxis[j]+size*(prefix[j+size]-prefix[j])<=budget)
                {
                    ans=max(ans,size);
                    found=false;
                    break;
                }
            }
            if(found)return ans;
            
        }
        return ans;
    }
};

class Solution {
public:
    vector<int>util(vector<int>nums,int k)
    {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() and dq.front()==(i-k))
                dq.pop_front();
            
            while(!dq.empty() and nums[dq.back()]<=nums[i])
                dq.pop_back();
            dq.push_back(i);
            
            if(i>=(k-1))
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        int n = chargeTimes.size();
        int i = 0,j=0,res=0;
        long long sum = 0;
        deque<int> d;
        while(j<n){
            while( !d.empty() && d.back() < chargeTimes[j])
            {
                d.pop_back();   
            }
            
            d.push_back(chargeTimes[j]);
            sum += runningCosts[j];
            
            int windowSize = j - i + 1;
            if(d.front() +  windowSize*sum <= budget){
                res = max(res, windowSize);
                j++;
            }
            
            else{
                if(d.front()==chargeTimes[i])
                {
                    d.pop_front();
                }                
                sum =sum-runningCosts[i];
                i=i+1;
                j=j+1;
            }
            
        }
        
        return res;
    }

};
