class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0;
        while(true)
        {
            int i=0;
            bool found=0;
            while(i+1<s.size())
            {
                if(s.substr(i,2)=="01")
                {
                    s[i]='1';
                    s[i+1]='0';
                    i+=2;
                    found=true;
                }
                else
                {
                    i++;
                }
            }
            ans++;
            if(!found)break;
        }
        return ans-1;
    }
};

int secondsToRemoveOccurrences(string s) {
    int zeros = 0, seconds = 0;
    for (int i = 0; i < s.size(); ++i) {
        zeros += s[i] == '0';
        if (s[i] == '1' && zeros)
            seconds = max(seconds + 1, zeros);
    }
    return seconds;
}
