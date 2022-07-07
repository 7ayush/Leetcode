//Backtracking we are just initialising a and b with different string size lelength

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
    bool util(int i,int j,string num){
        // cout<<i<<" "<<num.substr(0,i)<<" "<<j<<" "<<num.substr(i,j)<<endl;
        int n=num.size();
        string a=num.substr(0,i);
        string b=num.substr(i,j);
        if(num.size()<=2||(a.size()>1&&a[0]=='0')||(b.size()>1&&b[0]=='0'))return false;
        int k=i+j;
        if(k>=n)return false;
        while(k<n)
        {
            string sum=addString(a,b);
            string cut=num.substr(k,sum.size());
            if(sum!=cut||(cut.size()>1&&cut[0]=='0'))return false;
            a=b;
            b=cut;
            k+=cut.size();
            
        }
        return true;
    }
    bool isAdditiveNumber(string num) {
        int n=num.size();
        for(int i=1;i<=n/2;i++)
        {
            int idx=0;
            for(int j=1;2*max(j,i)<=n;j++)
            {
                if(util(i,j,num)){
                    // cout<<i<<" "<<j<<endl;
                    return true;   
                }
            }
        }
  
        return false;
    }
};

