class Solution {
public:
    int minDeletions(string s) {
        vector<int>vec(26,0);
        for(char c:s)vec[c-'a']++;
        sort(vec.begin(),vec.end(),greater<int>());
        int count=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==0)break;
            for(int j=i+1;j<vec.size();j++)
            {
                if(vec[i]==vec[j])
                {
                    int n=vec[i]-1;
                    count+=vec[j]-n;
                    vec[j]=n;
                }
                else break;
            }
        }
        return count;
        
    }
};


//Using heap 
class Solution {
public:
    int minDeletions(string s) {
        vector<int>vec(26,0);
        for(char c:s)vec[c-'a']++;
        priority_queue<int>pq;
        for(auto i:vec)if(i>0)pq.push(i);
        int count=0;
        while(!pq.empty())
        {
            int x=pq.top();
            pq.pop();
            while(!pq.empty()&&pq.top()==x)
            {
                int y=pq.top();
                pq.pop();
                if(y-1>0) pq.push(y-1);
                count++;
            }
            
        }
        return count;
    }
};
