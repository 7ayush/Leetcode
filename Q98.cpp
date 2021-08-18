// In this question we are setting limits that an element will be in a limit for being a BST
class Solution {
public:
  bool isValidNode ( TreeNode* node, double minVal, double maxVal ) {

	if(node==NULL)
		return true;
	if( !( node->val > minVal && node->val < maxVal ) ) 
		return false;
	
	return ( isValidNode( node->left, minVal, node->val ) && isValidNode( node->right, node->val, maxVal ) );

    }

    bool isValidBST (TreeNode* root) {
            double infinity = numeric_limits<double>::infinity();
            double minusInfinity = -numeric_limits<double>::infinity();
           
            return isValidNode( root, minusInfinity, infinity  );
    }
};
