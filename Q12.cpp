class Solution {
public:
    string intToRoman(int num) 
    {
        vector<int>digit{1,5,10,50,100,500,1000};
        vector<string>letters{"I","V","X","L","C","D","M"};
        int end=digit.size()-1;
        string ans="";
        while(num>0&&end>=0)
        {
            if(num>=digit[end])
            {
                num-=digit[end];
                ans+=letters[end];
            }
            else 
            {
                int sub=end-1;
                while(sub>=0&&(digit[sub]==5||digit[sub]==50||digit[sub]==500))
                {
                    sub--;
                }
                if(num>=digit[end]-digit[sub])
                {
                    num-=digit[end]-digit[sub];
                    ans+=letters[sub];
                    ans+=letters[end];
                }
                else
                {
                    end--;
                }
            }
        }
        return ans;
    }
};
