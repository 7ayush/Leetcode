class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int ans=0;
        queue<string>q;
        unordered_set<string>s;
        q.push(startGene);
        for(auto c:bank){
            s.insert(c);
        }
        while(!q.empty())
        {
            int x=q.size();
            while(x--)
            {
                auto str=q.front();
                q.pop();
                if(str==endGene){
                    return ans;
                }
                for(auto &c:str)
                {
                    char temp=c;
                    for(auto i:"ATCG")
                    {
                        c=i;
                        if(s.find(str)!=s.end())
                        {
                            q.push(str);
                            s.erase(str);
                        }
                    }
                    c=temp;
                }
            }
            ans++;
        }
        return -1;
    }
};
