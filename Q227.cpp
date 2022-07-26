class Solution {
public:
    int calculate(string s) {
        stack<char>operators;
        stack<string>nums;
        string temp="";
        map<char,int>mp={{'+',1},{'-',1},{'*',2},{'/',2}};
        for(char c:s)
        {
            if(c==' ')continue;
            if(c>='0'&&c<='9')temp+=c;
            else
            {
                if(temp!="")
                {
                    nums.push(temp);  
                    temp="";
                }
                while(!operators.empty()&&mp[operators.top()]>=mp[c])
                {
                    int b=stoi(nums.top());
                    nums.pop();
                    
                    int a=stoi(nums.top());
                    nums.pop();
                    
                    char op=operators.top();
                    operators.pop();
                    
                    if(op=='+')a=a+b;
                    if(op=='-')a=a-b;
                    if(op=='*')a=a*b;
                    if(op=='/')a=a/b;
                    nums.push(to_string(a));                    
                }
                operators.push(c);
            }
        }
        if(temp!="")nums.push(temp);
        while(!operators.empty())
        {
            int b=stoi(nums.top());
            nums.pop();
            
            int a=stoi(nums.top());
            nums.pop();
            
            char op=operators.top();
            operators.pop();
            
            if(op=='+')a=a+b;
            if(op=='-')a=a-b;
            if(op=='*')a=a*b;
            if(op=='/')a=a/b;
            nums.push(to_string(a));                    
        }
        int ans=stoi(nums.top());
        return ans;        
    }
};
