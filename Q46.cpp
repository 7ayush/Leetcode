class Solution {
public:
    void swapString(int i,int j,vector<int>x,vector<vector<int>>&s)
	{
	        int n=x.size();
	       if(n==1)
	       {
		     s.push_back(x);
		     return;
		   }
		   if(j==n-1){
		       s.push_back(x);
		       return;
		   }
		   for(;i<n-1;i++)
		   {
		       for(;j<n;j++)
		       {
		           swap(x[i],x[j]);
		           swapString(i+1,i+1,x,s);
		           swap(x[i],x[j]);
		       }
		   }
	}
    vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>x;
		    swapString(0,0,nums,x);
		    sort(x.begin(),x.end());
		    return x;
    }
};

//Recursive solution
class Solution {
public:
    void util(vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums,vector<int>&visited)
    {
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i]=1;
                util(temp,ans,nums,visited);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>visited(nums.size(),0);
        vector<int>temp;
        util(temp,ans,nums,visited);
        return ans;
    }
};

//Recursive swaps
class Solution {
public:
    void util(vector<vector<int>>&ans,vector<int>&nums,int i)
    {
        if(i==nums.size()){
            ans.push_back(nums);   
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            util(ans,nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        util(ans,nums,0);
        return ans;
    }
};
