class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        // 1. IDENTIFY PEAKS
        // 2. TRAVERSE BACKWARDS WHILE PREVIOUS ELEMENT -
        // - IS SMALLER THAT CURRENT (i.e. GO TO THE START ROOT OF THE MOUNTAIN)
        // 3. TRAVERSE FORWARD WHILE NEXT ELEMENT IS SMALLER THAN CURRENT 
        // (i.e. GO TO THE END ROOT OF THE MOUNTAIN)
        // 4 . ADD THEM TO CALCULATE THE MOUNTAIN LENGTH
        int max_length = 0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])) //PEAK CONDITION
            {
                int start_root = i;
                int end_root = i;
                while( start_root>0 && arr[start_root] > arr[start_root-1])
                {
                    start_root--; //getting start root
                    
                }
                while( end_root<n-1 && arr[end_root] > arr[end_root+1] )
                {
                    end_root++; //getting end root
                }
                max_length = max(max_length,(end_root-start_root+1));
                i = end_root;
            }
        }
        return max_length;
    }
};

class Solution {
public:
    int longestMountain(vector<int> A) {
        int N = A.size(), res = 0;
        vector<int> up(N, 0), down(N, 0);
        for (int i = N - 2; i >= 0; --i) if (A[i] > A[i + 1]) down[i] = down[i + 1] + 1;
        for (int i = 0; i < N; ++i) {
            if (i > 0 && A[i] > A[i - 1]) up[i] = up[i - 1] + 1;
            if (up[i] && down[i]) res = max(res, up[i] + down[i] + 1);
        }
        return res;
    }
};


class Solution {
public:
    int longestMountain(vector<int> A) {
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
            up += A[i - 1] < A[i];
            down += A[i - 1] > A[i];
            if (up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};


