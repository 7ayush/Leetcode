//Brute Force TLE
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int sum=0;
        int exp=1e9+7;
        for(int i=0;i<arr.size();i++)
        {
            int mini=arr[i];
            for(int j=i;j<arr.size();j++)
            {
                mini=min(mini,arr[j]);
                sum=(sum+mini)%exp;
            }
        }
        return sum;
    }
};


//using NSL
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int>s;
        vector<int>nsl(arr.size());
        for(int i=0;i<arr.size();i++)
        {
            while(!s.empty()&&arr[s.top()]>=arr[i])
            {
                s.pop();
            }
            if(s.empty())nsl[i]=-1;
            else nsl[i]=s.top();
            s.push(i);
        }
        for(int i=0;i<nsl.size();i++)
        {
            if(nsl[i]==-1)nsl[i]=arr[i]*(i+1);
            else
            {
                int j=nsl[i];
                nsl[i]=arr[i]*(i-j)+nsl[j];
            }
        }
        long long int sum=0;
        int mod=1e9+7;
        for(auto i:nsl)sum=(sum+i)%mod;
        
        
        return sum;
    }
};



