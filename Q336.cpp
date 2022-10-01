//TLE
class Solution {
public:
    bool isPalindrome(string word)
    {
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]!=word[n-i-1])return false;
        }
        return true;        
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words.size();j++)
            {
                if(i==j)continue;
                string word=words[i]+words[j];
                if(isPalindrome(word)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
