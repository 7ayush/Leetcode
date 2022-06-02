class Solution {
public:
    string convertToBase7(int num) {
        string ans="";
        bool flag=false;
        if(num<0){
            num*=-1;
            flag=true;
        }
        if(num==0)return "0";
        while(num>0)
        {
            int n=num%7;
            ans+=to_string(n);
            num=num/7;
        }
        if(flag)ans+='-';
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
