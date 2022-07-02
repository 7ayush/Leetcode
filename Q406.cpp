class Solution {
public:
    static bool compare(vector<int>& a, vector<int> & b)
    {
        if(a[0] == b[0])
            return a[1] < b[1];
        
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);

        //insertion sort
        for(int i=1;i<people.size();i++)
        {
            int k=i;
            for(int j=i-1;j>=0;j--)
            {
                if(people[k][1]<k){
                    swap(people[k],people[j]);      
                    k=j;
                }
                else break;
            }
        }
        return people;
    }
};

