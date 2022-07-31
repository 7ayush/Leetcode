class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int i=0;
        int n=grades.size();
        int count=1;
        int ans=0;
        int sum=0,prevSum=0;
        while(i<n)
        {
            sum=0;
            int j=0;
            for(;j<count&&i<n;j++){
                sum+=grades[i++];
            }           
            if(sum<=prevSum||j<count)continue;
            count++; 
            prevSum=sum;
        }
        return count-1;
        
    }
};
