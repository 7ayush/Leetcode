// Using priority queue as subsequence of size k is nothing but sum of k largest elements in the array

class compare{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        return a.first<b.first;        
    }
};
class Solution {
public:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;        
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare>pq;
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i],i});
        }
        while(k--)
        {
            vec.push_back(pq.top());
            pq.pop();            
        }
        sort(vec.begin(),vec.end(),comp);
        vector<int>ans;
        for(int i=0;i<vec.size();i++)
        {
            ans.push_back(vec[i].first);
        }
        return ans;
    }
};
