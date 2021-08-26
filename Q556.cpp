/*
Following are few observations about the next greater number.

If all digits sorted in descending order, then output is always “Not Possible”. For example, 4321.
If all digits are sorted in ascending order, then we need to swap last two digits. For example, 1234.
For other cases, we need to process the number from rightmost side (why? because we need to find the smallest of all greater numbers)
You can now try developing an algorithm yourself.

Following is the algorithm for finding the next greater number.
I) Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit. For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9. If we do not find such a digit, then output is “Not Possible”.

II) Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output. For above example, we sort digits in bold 536974. We get “536479” which is the next greater number for input 534976.
*/

class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s="";
        while(n){
            s=s+to_string(n%10);
            n/=10;
        }
        reverse(s.begin(),s.end());
        int i;
        for(i=s.length()-1;i>0;i--)
        {
           if(s[i]>s[i-1])
               break;
        }
       
        if(i==0)return -1;
        char p=s[i-1];
        int small=i;
        for(int j=i+1;j<s.length();j++)
        {
            if(s[j]>p&&s[j]<s[small])
                small=j;
        }
        char temp=s[small];
        s[small]=s[i-1];
        s[i-1]=temp;
        sort(s.begin()+i,s.end());
        if(stol(s)<=pow(2,31)-1)return stol(s);
        return -1;
    
    }
}; 
