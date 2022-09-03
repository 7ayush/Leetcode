class Solution {
public:
    void generate(int i,int n,vector<int>temp,vector<vector<int>>&comb)
    {
        if(n==0){
            comb.push_back(temp);
            return;
        }
        if(i<0)return;
        generate(i-1,n,temp,comb);
        temp.push_back(i);
        generate(i-1,n-1,temp,comb);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int maxi=0;
        vector<vector<int>>comb;
        int m=mat.size();
        int n=mat[0].size();
        generate(n-1,cols,{},comb);
        for(int i=0;i<comb.size();i++)
        {
            int count=0;
            unordered_map<int,int>mp;
            for(auto l:comb[i])mp[l]++;
            for(int j=0;j<m;j++)
            {
                bool found=true;
                for(int k=0;k<n;k++)
                {
                    if(mat[j][k]==1&&mp.find(k)==mp.end()){
                        found=false;
                        break;
                    }
                }
                count+=found;
            }
            maxi=max(maxi,count);
            
        }
        return maxi;
    }
};
