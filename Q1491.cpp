class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        sum-=*max_element(salary.begin(),salary.end());
        sum-=*min_element(salary.begin(),salary.end());
        for(auto i:salary)sum+=(double)i;
        return sum/(salary.size()-2);
    }
};
