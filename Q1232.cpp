class Solution {
public:
    bool isCollinear(int x1, int y1, int x2, int y2, int x3, int y3) {
        int res = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
        if(res == 0) return true;
        return false;
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) return true;
        for(int i = 2; i < n; i++) {
            int x1 = coordinates[i - 2][0];
            int y1 = coordinates[i - 2][1];

            int x2 = coordinates[i - 1][0];
            int y2 = coordinates[i - 1][1];

            int x3 = coordinates[i][0];
            int y3 = coordinates[i][1];
            if(isCollinear(x1, y1, x2, y2, x3, y3) == 0) return false;
        }
        return true;
    }
};
