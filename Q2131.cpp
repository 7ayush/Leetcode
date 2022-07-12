class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(string word:words)mp[word]++;
        int count=0;
         bool flag=0;
        for(auto &i:mp)
        {
            string a=i.first;
            string b=a;
            reverse(b.begin(),b.end());
            if(a==b){
                if(!flag&&i.second%2)flag=true;
                count+=(i.second/2)*4;
                continue;
            } 
            auto it=mp.find(b);
            if(it!=mp.end())
            {
                count+=min(i.second,it->second)*4;
                it->second=0;
                i.second=0;
            } 
        }
        if(flag)count+=2;
        return count;
    }
};
