class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int left=0;
        int right=n-1;
        int up=0;
        int down=m-1;
        while(head)
        {
            for(int j=left;j<=right&&head;j++)
            {
                mat[up][j]=head->val;
                head=head->next;
            }
            up++;
            for(int i=up;i<=down&&head;i++)
            {
                mat[i][right]=head->val;
                head=head->next;
            }
            right--;
            for(int j=right;j>=left&&head;j--)
            {
                mat[down][j]=head->val;
                head=head->next;
            }
            down--;
            for(int i=down;i>=up&&head;i--)
            {
                mat[i][left]=head->val;
                head=head->next;
            }   
            left++;
            
        }
        return mat;
    }
};
