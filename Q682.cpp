class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s;
        for(string i:ops)
        {
            if(i=="C")
            {
                if(s.empty()) continue;
                else s.pop();                    
            }
            else if(i=="D")
            {
                int x=2*s.top();
                s.push(x);
            }
            else if(i=="+")
            {
                int x=s.top();                
                s.pop();
                int y=s.top(); 
                s.push(x);
                s.push(x+y);
            }
            else
            {
                s.push(stoi(i));
            }
        }
        int score=0;
        while(!s.empty()){
            score+=s.top();
            s.pop();
        }
        return score;
    }
};
