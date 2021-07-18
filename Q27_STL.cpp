// Using STL to remove a particular element in vector and returning the size
class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        vector<int>::iterator it=std::find(nums.begin(),nums.end(),val);
        while(it!=nums.end())
        {
            nums.erase(it);
            it=std::find(nums.begin(),nums.end(),val);
        }
        return nums.size();
        
    }
};
