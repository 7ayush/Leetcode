class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<vector<string>>events={event1,event2};
        sort(events.begin(),events.end());
        return events[0][1]>=events[1][0];    
    }
};
