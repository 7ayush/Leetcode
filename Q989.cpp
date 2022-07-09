class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        reverse(num.begin(),num.end());
        for(int i=0;i<num.size();i++)
        {
            num[i]=num[i]+carry+k%10;
            carry=num[i]/10;
            num[i]=num[i]%10;
            k=k/10;
        }
        while(k>0)
        {
            int sum=k%10+carry;
            num.push_back(sum%10);
            carry=sum/10;
            k=k/10;
        }
        if(carry)num.push_back(carry);
        reverse(num.begin(),num.end());
        return num;
        
    }
};
