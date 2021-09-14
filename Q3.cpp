// We take l=0 and r=0 and We are maintaining a set and then we are checking if have the element in the set if we have then we update the l upto a level till we do not have str[l]=c 
// Time complexity O(N) time and O(N) space
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        set<char>s;
        int l=0,r=0;
        int mx=0;
        for(int i=0;i<str.size();i++)
        {
            char c=str[i];
            
            if(s.find(c)!=s.end())
            {
                while(str[l]!=c)    
                {
                    s.erase(str[l]);
                    l++;
                }
                s.erase(c);
                l++;
            }
            mx=max(mx,r-l+1);            
            s.insert(c);                
            r++;            
        }
        return mx;
        
        
    }
};


// We are using a map to jump to a level upto which the element is present
// Time complexity O(N) time and O(N) space
class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        map<char,int>m;
        int l=0,r=0;
        int mx=0;
        for(int i=0;i<str.size();i++)
        {
            char c=str[i];            
            if(m.find(c)!=m.end()&&m[c]>=l)
            {
                l=m[c]+1;
                m[c]=i;
            }
            mx=max(mx,r-l+1);            
            m[c]=i;                
            r++;            
        }
        return mx;
        
        
    }
};
