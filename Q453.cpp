//Using maxHeap
class Solution {
public:
    
    int minMoves(vector<int>& nums) 
    {
        priority_queue<int>maxHeap(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        int count=0;
        while(maxHeap.top()!=mini)
        {
            int x=maxHeap.top();
            maxHeap.pop();
            maxHeap.push(x-1);
            count++;
        }
        return count;        
    }
};

//Method 2
class Solution {
public:
    
    int minMoves(vector<int>& nums) 
    {
        int mini=*min_element(nums.begin(),nums.end());
        int count=0;
        for(auto i:nums)count+=i-mini;
        return count;        
    }
};
