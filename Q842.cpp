class Solution {
public:
    string addString(string a,string b)
    {
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0&&j>=0)
        {
            int x=a[i]-'0'+b[j]-'0'+carry;            
            carry=x/10;
            x%=10;
            ans=to_string(x)+ans;
            i--;j--;
        }
        while(i>=0)
        {
            int x=a[i]-'0'+carry;            
            carry=x/10;
            x%=10;
            ans=to_string(x)+ans;
            i--;
        }
        while(j>=0)
        {
            int x=b[j]-'0'+carry;            
            carry=x/10;
            x%=10;
            ans=to_string(x)+ans;
            j--;
        }
        if(carry!=0)
            ans='1'+ans;
        return ans;
    }
    vector<string> util(int i,int j,string num){
        int n=num.size();
        string a=num.substr(0,i);
        string b=num.substr(i,j);
        if(num.size()<=2||(a.size()>1&&a[0]=='0')||(b.size()>1&&b[0]=='0'))return {};
        
        int k=i+j;
        if(k>=n)return {};
        vector<string>ans{a,b};
        while(k<n)
        {
            string sum=addString(a,b);
            string cut=num.substr(k,sum.size());
            if(sum!=cut||(cut.size()>1&&cut[0]=='0'))return {};
            a=b;
            b=cut;
            ans.push_back(cut);
            if(cut.size()>10)return {};
            if(cut.size()==10&&cut>"2147483648")return {};
            k+=cut.size();
        }
        return ans;
    }
    vector<int> splitIntoFibonacci(string num) {
        int n=num.size();
        for(int i=1;i<9&&i<n;i++)
        {
            int idx=0;
            for(int j=1;2*max(j,i)<=n&&2*max(j,i)<=18;j++)
            {
                vector<string>ans=util(i,j,num);
                if(ans.size()>0){
                    vector<int>ans1;
                    for(string i:ans)ans1.push_back(stoi(i));
                    return ans1;   
                }
            }
        }
        return {};
    }
};
