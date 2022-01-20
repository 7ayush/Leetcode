
//Method 1 
//Run loop i from 0 to n-2
	//Run loop j from i+1 to n-1
//Check if the substring from i to j is valid or not. Find max length of valid substring
// O N3 time ON space


// Method 2 using stack Using ON time and O1 space
// We are using stacks Initialise stack with -1. 
// ( push i
// ) pop and then if s.empty() push i else len=max(i-s.top(),len)
// return length
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        stk.push(-1);
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                if(stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    len=max(i-stk.top(),len);
                }
                
            }
        }
        return len;
    }
};

// Using 2 pointer technique to solve
class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxLength=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                maxLength=max(maxLength,2*right);
            }
            else if(right>=left)
            {
                right=left=0;
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
            {
                left++;
            }
            else
            {
                right++;
            }
            if(left==right)
            {
                maxLength=max(maxLength,2*right);
            }
            else if(left>=right)
            {
                right=left=0;
            }
        }
        return maxLength;
    }
};
