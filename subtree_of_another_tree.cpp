class Solution {
public:
    bool isidentical(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }

        if(root1 == NULL || root2 == NULL){
            return false;
        }

        if(root1->val != root2->val){
            return false;
        }

        return isidentical(root1->left, root2->left) &&
               isidentical(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL){
            return false;
        }

        if(isidentical(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};