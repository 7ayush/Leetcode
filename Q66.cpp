class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int i=digits.size()-1;
        while(carry>0&&i>=0)
        {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]=digits[i]%10;
            i--;            
        }
        if(carry==1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
