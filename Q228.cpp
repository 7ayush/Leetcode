class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        if(nums.size()==0)return {};
        sort(nums.begin(),nums.end());
        vector<string>vec;
        int i=1;
        string start=to_string(nums[0]);
        string end="";
        string temp="";
        int n=nums.size();
        while(i<n)
        {
            
            if(nums[i]==1+nums[i-1]){
                end=to_string(nums[i]);                
            }
            else
            {
                if(end!="")
                {
                    temp=start+"->"+end;
                }
                else
                {
                    temp=start;
                }
                vec.push_back(temp);
                end="";
                start=to_string(nums[i]);
            }            
            i++;
        }
        if(end!="")
        {
            temp=start+"->"+end;
        }
        else
        {
            temp=start;
        }
        vec.push_back(temp);
            
        return vec;
    }
};
