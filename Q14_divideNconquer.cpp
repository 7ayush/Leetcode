// To calculate Longest common prefix we can also use divide and conquer strategy just like merge sort
// Time complexity will be 2T(n/2)+O(m)
// Space complexity will be O(mlogn)
// n strings of length m worst case

class Solution {
public:
    
    string solve1(string s,string t)
    {
        int i=0;
        string a="";
        while(i!=s.size()&&i!=t.size())
        {
            if(s[i]==t[i])
            {
                a+=s[i];
                i++;
            }
            else
            {
                return a;
            }
        }
        return a;
    }
    string solve(vector<string>strs,int l, int r)    
    {
        if(l==r)
        {
            return strs[l];
        }
        int mid=(l+r)/2;
        string s=solve(strs,l,mid);
        string t=solve(strs,mid+1,r);
        return solve1(s,t);
    }
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==0)return "";
        return solve(strs,0,strs.size()-1);        
    }
};