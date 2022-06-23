class Solution {
public:
    static bool compare(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        sort(courses.begin(),courses.end(),compare);
        int currentTime=0;
        priority_queue<int> q;
        for(int i=0;i<courses.size();i++)
        {
            if(currentTime+courses[i][0]<=courses[i][1])
            {
                currentTime+=courses[i][0];
                q.push(courses[i][0]);
            }
            else
            {
                if(!q.empty() && q.top() > courses[i][0]) {
                    // current course is actually of 
                    //less duration and can be taken
                    int x = q.top();
                    q.pop();
                    currentTime-=x;
                    currentTime+=courses[i][0];
                    q.push(courses[i][0]);
                }
            }
        }
        return q.size();
    }
};
