class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans=0;
        int n=arr.size();
        int x=pow(2,n);
        for(int i=1;i<x;i++)
        {
            int a=i;
            vector<int>vec(26,0);
            int j=0;
            int count=0;
            while(a>0)
            {
                int t=a&1;
                if(t==1)
                {
                    for(int k=0;k<arr[j].size();k++)
                    {
                        vec[arr[j][k]-'a']++;
                    }
                }
                j++;
                a=a>>1;
            }
            for(auto x:vec){
                if(x>1){
                    count=0;
                    break;
                }
                else if(x==1)
                    count++;
            }
            ans=max(ans,count);
        }
        return ans;
    }
};
