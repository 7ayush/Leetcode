class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int i=0;
        string ans="";
        int carry=0;
        while(i<num1.size()||i<num2.size())
        {
            int x=i<num1.size()?num1[i]-'0':0;
            int y=i<num2.size()?num2[i]-'0':0;
            int sum=x+y+carry;
            carry=sum/10;
            sum=sum%10;
            ans+=to_string(sum);                
            i++;
        }
        if(carry>0)ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
