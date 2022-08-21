class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int countWhites=0;
        for(int i=0;i<k;i++)
        {
            if(blocks[i]=='W')countWhites++;            
        }
        int ans=countWhites;
        // cout<<countWhites<<endl;
        for(int i=1;i+k-1<blocks.size();i++)
        {
            if(blocks[i-1]=='W')countWhites--;
            if(blocks[i+k-1]=='W')countWhites++;
            ans=min(ans,countWhites);
        }
        return ans;
        
    }
};
