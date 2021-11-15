/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
class Solution {
public:
    
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> result;
        for(int i=1;i<=1000;i++)
        {
            int start=1;
            int end=1000;
            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(customfunction.f(i,mid)==z)
                {
                    result.push_back({i,mid});
                    break;
                }
                else if(customfunction.f(i,mid)<z)
                {
                    start=mid+1;
                }
                else
                {
                    end=mid-1;
                }
            }
        }
        return result;
    }
};
