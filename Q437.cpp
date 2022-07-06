class Solution {
public:
    map<long long,int>util(TreeNode* root,int &count,int targetSum)
    {
        map<long long,int>mp;
        if(!root)return mp;
        if(!root->left&&!root->right)
        {
            mp[root->val]++;
            if(root->val==targetSum)count++;
            return mp;
        }
        map<long long,int>l=util(root->left,count,targetSum);
        map<long long,int>r=util(root->right,count,targetSum);
        for(auto it:l)
        {      
            long long x=root->val+it.first;
            mp[x]+=it.second;
            if(x==targetSum)count+=it.second;
        }
        for(auto it:r)
        {
            long long x=root->val+it.first;
            mp[x]+=it.second;
            if(x==targetSum)count+=it.second;
        }
        mp[root->val]++;
        if(root->val==targetSum)count++;
        return mp;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        util(root,count,targetSum);
        return count;
    }
};

//Another approach
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int sumUp(TreeNode* root, long long pre, int& sum){
        if(!root) return 0;
        long long current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
