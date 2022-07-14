class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        stack<string>s1;
        string ans="";
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                if(ans=="..")
                {                    
                    if(!s.empty())s.pop();
                }    
                else if(ans!=""&&ans!=".")
                {
                    s.push(ans);               
                }
                ans="";
            }
            else ans+=path[i];

        }
        if(ans!="")
        {
            if(ans==".."){
                if(!s.empty())s.pop();   
            }
            else if(ans!=".") s.push(ans);
        }
        ans="/";        
        while(!s.empty())
        {
            s1.push(s.top());
            s.pop();
        }
        while(!s1.empty())
        {
            ans+=s1.top();
            s1.pop();
            if(!s1.empty())ans+='/';
        }
        return ans;
    }
};
