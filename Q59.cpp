class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>vec(n,vector<int>(n,0));
        int left=0,right=n-1;
        int up=0,down=n-1;
        int dir=0;
        int i=0,j=0;
        int k=1;
        while(k<=n*n)
        {
            if(dir==0){                
                i=up;
                j=left;
                while(j<=right)
                {
                    vec[i][j++]=k++;                
                }
                j--;                
                up++;
                
            }
            
            else if(dir==1)
            {
                i=up;
                j=right;
                while(i<=down)
                {
                    vec[i++][j]=k++;                    
                }    
                i--;
                right--;
            }
            else if(dir==2)
            {
                i=down;
                j=right;
                while(j>=left)
                {
                    vec[i][j--]=k++;                    
                }   
                j++;
                down--;
            }
            else
            {
                i=down;
                j=left;
                while(i>=up)
                {
                    vec[i--][j]=k++;                    
                }   
                i++;
                left++;
            }
            dir=(dir+1)%4;
        }
        return vec;
    }
};
