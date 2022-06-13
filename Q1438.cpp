class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int start=0,end=0;
        deque<int>minQueue;
        deque<int>maxQueue;
        int ans=0;
        while(end<nums.size())
        {
            int x=nums[end];
            
            while(!minQueue.empty()&&nums[minQueue.back()]>=x)minQueue.pop_back();
            minQueue.push_back(end);
            
            while(!maxQueue.empty()&&nums[maxQueue.back()]<=x)maxQueue.pop_back();
            maxQueue.push_back(end);
            
            int mini=nums[minQueue.front()];
            int maxi=nums[maxQueue.front()];
            
            if(maxi-mini>limit)
            {
                start++;
                if(start>minQueue.front())minQueue.pop_front();
                if(start>maxQueue.front())maxQueue.pop_front();
            }
            else
            {
                ans=max(ans,end-start+1);
                end++;
            }
        }
        return ans;
    }
};
