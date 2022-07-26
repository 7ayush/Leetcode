class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(auto i:asteroids){
            bool flag=false;
            if(s.empty())s.push(i);
            else
            {
                if(i<0&&s.top()<0)s.push(i);
                else if(i>0&&s.top()>0)s.push(i);
                else if(i<0)
                {
                    while(!s.empty()&&s.top()>0&&s.top()<=abs(i))
                    {
                        if(s.top()==abs(i)){
                            flag=true;
                            s.pop();
                            break;
                        }
                        s.pop();
                    }
                    if(flag)continue;
                    if(s.empty()||s.top()<0)s.push(i);
                }
                else s.push(i);
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
