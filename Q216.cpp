class Solution {
public:
    void util(vector<vector<int>>&ans,int k,int n,vector<int>temp,vector<int>visited)
    {
        if(n<0)return;
        if(n==0&&k==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=1;i<=9;i++)
        {
            vector<int>temp1=temp;
            if(visited[i]==false)
            {
                temp1.push_back(i);
                visited[i]=true;
                util(ans,k-1,n-i,temp1,visited);                                
            }
            
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>visited(10,false);
        util(ans,k,n,{},visited);
        return ans;
    }
};



class Solution {
public:
    vector<vector<int>> ans;
    
    void f(vector<int>& cur, int cnum, int k, int n) {
        if(n < 0 || cur.size() > k) return;
        if(n == 0 && cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        
        for(int i=cnum; i<=9; ++i) {
            cur.push_back(i);
            f(cur, i+1, k, n-i);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        f(cur, 1, k, n);
        return ans;
    }
};
