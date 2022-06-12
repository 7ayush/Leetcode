class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        string special="!@#$%^&*()-+";
        bool flag1=password.size()>=8;
        bool flag2=false;
        bool flag3=false;
        bool flag4=false;
        bool flag5=false;
        if(!flag1)return false;
        for(int i=0;i<password.size();i++)
        {
            char c=password[i];
            if(i>0&&password[i-1]==c)return false;
            
            if(c>='a'&&c<='z')flag2=true;
            if(c>='A'&&c<='Z')flag3=true;
            if(c=='!'||c=='@'||c=='#'||c=='%'||c=='$'||c=='^'||c=='&'||c=='*'||c=='('||c==')'||c=='-'||c=='+')flag4=true;
            if(c>='0'&&c<='9')flag5=true;            
        }
        return flag1&&flag2&&flag3&&flag4&&flag5;
    }
};
