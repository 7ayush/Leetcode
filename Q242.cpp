// Storing frequencies in an array and checking if it is equal O(N) time and O(N) space
class Solution {
public:
    bool isAnagram(string s, string t) {
        int l1=s.size();
        int l2=t.size();
        if(l1!=l2)return false;
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        for(int i=0;i<l1;i++)
        {
            h1[s[i]-'a']++;
            h2[t[i]-'a']++;
        }
        return h1==h2;
    }
};

// Sorting the strings if they are equal then they are anagrams O(NLogN) time and sorting space
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
