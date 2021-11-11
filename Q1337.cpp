// We will create a aux vec containing the number of 1s and index of the vector for every row and the sorting it and returning k weakest rows
class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        if(v1[0]<v2[0])return true;
        else if(v1[0]==v2[0])
        {
            return v1[1]<v2[1];
        }
        else
        {
            return false;
        }
    }
    int binarySearch(vector<int>vec)
    {
        int start=0,end=vec.size()-1;
        int mid;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(vec[mid]==0)
            {
                if(mid==start||vec[mid-1]==1)
                {
                    return mid;
                }
                else
                {
                    end=mid-1;
                }
            }
            else
            {
                start=mid+1;
            }
        }
        return vec.size();
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>>ans;
        for(int i=0;i<mat.size();i++)
        {
            int x=binarySearch(mat[i]);
            ans.push_back({x,i});
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>finalVector;
        for(int i=0;i<k;i++)
        {
            finalVector.push_back(ans[i][1]);
        }
        return finalVector;
    }
};
