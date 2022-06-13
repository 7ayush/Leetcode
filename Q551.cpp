class Solution {
public:
    bool checkRecord(string s) {
        int late=0,absent=0;
        for(int i=0;i<s.size();i++)               
        {
            int c=s[i];
            if(c=='A'){
                absent++;
                if(absent>=2)return false;
            }
            
            if(i>=2&&s[i-1]=='L'&&s[i-2]=='L'&&c=='L')return false;
        }
        return true;
    }
};
