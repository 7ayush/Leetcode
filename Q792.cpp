//TLE
class Solution {
public:
    void util(string s,int i,string temp,unordered_map<string,int>&mp,int &count,unordered_map<string,int>&mp1)
    {
        if(i==s.size())return;        
        util(s,i+1,temp,mp,count,mp1);//move ahead
        temp+=s[i];
        if(mp.find(temp)!=mp.end()&&mp1.find(temp)==mp1.end()){
            count+=mp[temp];            
            mp1[temp]=1;
        }
        util(s,i+1,temp,mp,count,mp1);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        unordered_map<string,int>mp1;
        for(auto word:words)mp[word]++;
        int count=0;
        util(s,0,"",mp,count,mp1);
        return count;
    }
};

class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
		//Here I am simply traversing through strings recursively and checking the last characters
		//resulting in TLE as it will take a lot of time to process all the subsequences.
		
		//if end of s2 then our goal is fulfilled as we have traversed s2 completely.
        if(n == 0) return true;
		
		//else return false, as we reached end of s1 without reaching end of s2
        if(m == 0) return false;
		
		//if matched call recursively for next characters in both strings
        if(s1[m - 1] == s2[n - 1]) return isSubsequence(s1, s2, m - 1, n - 1);
		
		//if not simply reduce s1 by 1 and call again
        else return isSubsequence(s1, s2, m - 1, n);
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(auto x: words){
            count += (isSubsequence(s, x, s.size(), x.size()) == true);
        }
        return count;
    }
};


class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
		//Here we have simplified the process in finding whether the subsequence is there or not in O(n)
		// Variable for s2 string
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
			// if matched increment both variables, else just increment i
            if(s1[i] == s2[j]) j++;
        }
		//if we reached end of s2 that means all the characters of s2 have occurred in s1, so return true;
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for(auto x: words){
            count += (isSubsequence(s, x, s.size(), x.size()) == true);
        }
        return count;
    }
};


class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
		
		// Storing whether a string is subsequence or not!
        map<string, bool> mp;
        for(auto x: words)
        {
		
			//if the string has already occurred then don't compute again
            if(mp.find(x) != mp.end()) {
				// if that string has value true that means it is subsequence, count++
                if(mp[x] == true) {
                    count++;
                }
				//if not, go for next string
                continue;
            }
			
			// if not calculated previously, compute the value and assign to x(current string from words)
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == true);
        }
		// return the final count of number of subsequences.
        return count;
    }
};
