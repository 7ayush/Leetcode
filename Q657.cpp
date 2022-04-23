class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontal=0,vertical=0;
        for(char c:moves)
        {
            if(c=='U')vertical++;
            if(c=='D')vertical--;
            if(c=='R')horizontal++;
            if(c=='L')horizontal--;
        }
        return (horizontal==0&&vertical==0);
    }
};
