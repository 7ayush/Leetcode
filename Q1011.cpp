class Solution {
public:
    bool isPossible(vector<int>arr,int wt,int days)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<arr.size();i++)        
        {
            if(sum+arr[i]<wt)
            {
                sum+=arr[i];
            }
            else if(sum+arr[i]==wt)
            {
                sum=0;
                if(i!=arr.size()-1)
                    count++;                
            }
            else
            {
                sum=arr[i];
                count++;
            }
        }
        if(count>days)return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        vector<int>temp;
        int n=weights.size();
        
        for(int i=0;i<n;i++)temp.push_back(weights[i]);
        
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        cout<<low<<" "<<high<<endl;
        int ans;        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(temp,mid,days))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }            
        }
        
        return ans;
    }
};
// 1 2 2 3 3 4
// 4 15
// 12
    

