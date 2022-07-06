// Bulls are no of digits that in their correct place.

// Cows are digits that could be rearranged in guess so that they are in their correct place in secret. 
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])bull++;
            else {
                mp1[secret[i]]++;
                mp2[guess[i]]++;
            }
        }
        int cow=0;
        for(auto it1: mp1)
        {
            auto it2=mp2.find(it1.first);
            if(it2!=mp2.end())
            {
                cow+=min(it2->second,it1.second);
            }
        }
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};
