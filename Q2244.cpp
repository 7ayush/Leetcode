class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        
        for(auto i:tasks) mp[i]++;        
        int ans=0;

        for(auto i:mp)
        {
            if(i.second==1) 
                return -1;
            else
                ans+=(i.second-1)/3+1;            
        }
        return ans;
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        vector<int>rounds(1e5);
        rounds[0]=-1;
        rounds[1]=1;
        rounds[2]=1;
        rounds[3]=2;
        for(int i=4;i<1e5;i++)
        {
            rounds[i]=min(rounds[i-2],rounds[i-3])+1;
        }
        unordered_map<int,int>mp;
        for(auto i:tasks)
        {
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp)
        {
            if(rounds[i.second-1]==-1)
            {
                return -1;
            }
            else
            {
                ans+=rounds[i.second-1];
            }
        }
        return ans;

    }
};

