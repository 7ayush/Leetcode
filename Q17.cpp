// In this we are repeatedly appending the same vector ans to ans so as to generate new permutations with next number
class Solution {
public:
  
    vector<string> letterCombinations(string digits) {
        vector<string>details{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        vector<string>temp{""};
        
        int x,currSize,j;
        int prod=1;
        
        for(int i=0;i<digits.size();i++)
        {
            int x=digits[i]-'2';
            currSize=details[x].size();
            if(i!=0)
            {
                temp=ans;
                j=1;
            }
            else
                j=0;
            
            prod=prod*currSize;
            for(;j<currSize;j++)
            {
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
            int idx=0;
            for(int j=0;j<currSize;j++)
            {
                char c=details[x][j];
                for(int k=0;k<prod/currSize;k++)
                {
                    ans[idx]+=c;
                    idx++;
                }
            }
        }
        return ans;
    }
};
