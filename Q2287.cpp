class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        map<char,int> mp1,mp2;
        for(auto& ch:target) mp1[ch]++; // mp1 is to store the letter count of target string
        for(auto& ch: s) mp2[ch]++; // // mp2 is to store the letter count of s string
        int res=INT_MAX;
        for(auto x:mp1){
            char ch=x.first;
            int count1=x.second; // count of ch character in target string
            int count2=mp2[ch]; // count of ch character in s string
            res=min(res,count2/count1);
        }
        return res;
    }
};
