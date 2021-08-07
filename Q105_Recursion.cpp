/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int binarySearch(vector<int>inOrder,int target,int i,int j)
    {
        int mid=(i+j)/2;
        if(inOrder[mid]==target)return mid;
        else if(inOrder[mid]<target)
        {
            return binarySearch(inOrder,target,mid+1,j);
        }
        else
        {
            return binarySearch(inOrder,target,i,mid-1);
        }
        
    }
    TreeNode* build(vector<int>preorder,vector<int>inorder,int ps,int pe,int is,int ie)
    {
        if(is>ie)return NULL;
        
        TreeNode *temp=new TreeNode(preorder[ps]);
        int idx=-1;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==preorder[ps])
            {
                idx=i;
                break;
            }
        }
        int lps=ps+1;                
        int rpe=pe;
        int lis=is;
        int lie=idx-1;
        int ris=idx+1;
        int rie=ie;
        int lpe=lie-lis+lps;
        int rps=lpe+1;
        // temp->left=build(preorder,inorder,lps,lpe,lis,lie);   
        // temp->right=build(preorder,inorder,rps,rpe,ris,rie);
        temp->left=build(preorder,inorder,ps+1,idx-is+ps,is,idx-1);           
        temp->right=build(preorder,inorder,idx-is+ps+1,pe,idx+1,ie);
        return temp;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int n=preorder.size();
        TreeNode* ans=build(preorder,inorder,0,n-1,0,n-1);
        return ans;
    }
};
