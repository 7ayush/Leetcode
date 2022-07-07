//Recursive
class Solution {
public:
    void util(vector<string>&ans,string s,vector<int>index,int i)
    {
        if(i==index.size()){
            ans.push_back(s);
            return;
        }
        
        s[index[i]]=tolower(s[index[i]]);
        util(ans,s,index,i+1);
        
        s[index[i]]=toupper(s[index[i]]);
        util(ans,s,index,i+1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<int>index;
        vector<string>ans;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                index.push_back(i);   
            }
        }
        util(ans,s,index,0);
        return ans;
    }
};


// Bit Manipulation
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int>index;
        vector<string>ans;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                index.push_back(i);   
            }
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]=s[i]-'A'+'a';
            }
        }
        int n=pow(2,index.size());
        for(int i=0;i<n;i++)
        {
            if(i==0){
                ans.push_back(s);
                continue;
            }
            int j=i;            
            string a=s;
            int idx=0;
            while(j>0)
            {
                int x=j%2;
                if(x==1){
                    a[index[idx]]=toupper(a[index[idx]]);
                }
                j=j/2;
                idx++;
            }
            ans.push_back(a);
        
        }
        return ans;
    }
};
