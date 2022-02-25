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
