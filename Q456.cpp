class Solution {
public:
    bool find132pattern(vector<int> n) {
        stack<int> s;
        int last=INT_MIN;
        for(int i=n.size()-1;i>=0;i--){
            if(last>n[i]) return true;
            while(s.size() && s.top()<n[i]){
                last=s.top();
                s.pop();
            }
            s.push(n[i]);
        }
        return false;
    }
};
