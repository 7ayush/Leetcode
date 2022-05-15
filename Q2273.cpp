class Solution {
public:
    bool map_compare (map<char,int>&lhs, map<char,int>&rhs) 
    {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()&& std::equal(lhs.begin(), lhs.end(),rhs.begin());
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        for(int i=0;i<words.size()-1;i++)
        {
            if(words[i]=="")continue;
            map<char,int>m1;
            for(char c:words[i])
            {
                m1[c]++;
            }
            for(int j=i+1;j<words.size();j++)
            {
                map<char,int>m2;
                for(char c:words[j])
                {
                    m2[c]++;
                }    
                if(map_compare(m1,m2)){
                    words[j]="";                    
                } 
                else
                {
                    break;
                }
            }
        }
        for(string word:words)
        {
            if(word!="")ans.push_back(word);
        }

        
        return ans;
    }
};

