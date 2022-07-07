class Solution {
public:
    void util(vector<vector<int>>&ans,int i,int size,vector<int>temp,int k)
    {
        if(i+size<k)return;// We have not yet chosen enough elements so we need to break as continuing till the end will not lead to anything
        if(size==k){
            ans.push_back(temp);
            return;
        }
        if(i<1)return;
        //not choose
        util(ans,i-1,size,temp,k);
        //choose
        temp.push_back(i);
        util(ans,i-1,size+1,temp,k);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        util(ans,n,0,{},k);
        return ans;
    }
};


//Recursive method 2
class Solution {
public:
    void findCombination(vector<vector<int>> &res, vector<int> temp, int index, int n, int k){
        if(temp.size() == k){
            res.push_back(temp);
            return;
        }
        for(int itr = index; itr < n; itr++){
            temp.push_back(itr+1);
            findCombination(res, temp, itr+1, n, k);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        findCombination(res, vector<int>(), 0, n, k);
        return res;
    }
};
