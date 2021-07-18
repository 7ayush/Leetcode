class Solution {
public:
    int sumChar(char a,char b,char c)
    {
        int count=0;
        if(a=='1')count++;
        if(b=='1')count++;
        if(c=='1')count++;
        return count;
    }
    string addBinary(string a, string b) 
    {
        int i=a.size()-1;
        int j=b.size()-1;
        char carry='0';
        string result="";
        string temp,ans="";
        
        char x,y,z;
        while(i>=0||j>=0||carry=='1')
        {
            temp="";
            y=j>=0?b[j]:0;
            x=i>=0?a[i]:0;
            int sum=sumChar(x,y,carry);
            temp=sum%2==1?"1":"0";
            carry=sum>1?'1':'0';
            temp+=ans;
            ans=temp;
            i--;j--;
        }
        return ans;
    }
};
