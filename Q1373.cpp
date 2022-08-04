class obj{
public:
    int sum;
    bool isBST;
    int maxi;
    int mini;
    obj(){
        this->isBST=true;
        this->maxi=INT_MIN;
        this->mini=INT_MAX;
        this->sum=0;
    }
};
class Solution {
public:
    obj util(TreeNode*root,int &ans)
    {
        obj temp;
        if(!root){
            return temp;
        }
        if(!root->left&&!root->right)
        {
            temp.sum=root->val;
            temp.maxi=root->val;
            temp.mini=root->val;
            ans=max(ans,root->val);
            return temp;
        }
        obj l=util(root->left,ans);
        obj r=util(root->right,ans);
        if(l.isBST&&r.isBST)
        {
            if(root->val>l.maxi&&root->val<r.mini)
            {
                int sum=root->val+l.sum+r.sum;
                temp.sum=sum;                
                temp.maxi=max(root->val,r.maxi);
                temp.mini=min(root->val,l.mini);
                ans=max(ans,sum);
            }
            else
            {
                temp.isBST=false;
            }
            return temp;
        }
        else
        {
            obj temp;
            temp.isBST=0;
            return temp;
        }
    }
    int maxSumBST(TreeNode* root) {
        int ans=0;        
        util(root,ans);   
        return ans;
    }
};
