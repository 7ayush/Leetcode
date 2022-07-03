class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m; 
        m[0] = -1; 
        int sum = 0; 
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i]; 
            int res = sum % k; 
            if (m.find(res)!= m.end() && m[res]+ 1 < i) return true; 
            
            if (m.find (res) == m.end()) m[res] = i; 
        }
        return false; 
        
    }
};
