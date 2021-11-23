class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans(n);
        
        for(int i=1;i<=n;i++)
        {
            string answ;
            if(i%15==0)answ="FizzBuzz";
            else if(i%5==0)answ="Buzz";
            else if(i%3==0)answ="Fizz";
            else answ=to_string(i);
            ans[i-1]=answ;
        }
        return ans;
    }
};
