class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        unordered_map<char,int>mp1;
        for(int i=0;i<ranks.size();i++)
        {
            mp1[suits[i]]++;
        }
        for(auto i:mp1)if(i.second==5)return "Flush";
        unordered_map<int,int>mp;        
        for(int i=0;i<ranks.size();i++)
        {
            mp[ranks[i]]++;
        }
        for(auto i:mp)if(i.second>=3)return "Three of a Kind";
        for(auto i:mp)if(i.second>=2)return "Pair";
        return "High Card";
    }
};
