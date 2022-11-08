class Solution {
public:
    int maximum69Number (int num) {
        vector<int>digits;
        while(num>0)
        {
            digits.push_back(num%10);
            num=num/10;
        }
        reverse(digits.begin(),digits.end());
        int ans=0;
        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]==6)
            {
                digits[i]=9;
                break;
            }
        }
        for(auto i:digits)
        {
            ans=ans*10+i;
        }
        return ans;
    }
};
