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

 /************************************************************ C++ ************************************************************/
//Approach : store the nodes in a vector using inorder traversal(sorted fashion ) and then build the tree using the vector(using concept of merge sort)
//T.C : O(2n)
//S.C : O(2n)

// https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2026-02-22
class Solution {
public:
    void inorder(vector<TreeNode*>&nodes,TreeNode* root){
        if(root==NULL)return ;
        inorder(nodes,root->left);
        nodes.push_back(root);
        inorder(nodes,root->right);
    }
    TreeNode* build(vector<TreeNode*>&nodes,int l,int r){
        if(l>r)return NULL;
        int mid=(l+r)/2;

        TreeNode *root=nodes[mid];
        int n=nodes.size();
        root->left=build(nodes,l,mid-1);
        root->right=build(nodes,mid+1,r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(nodes,root);
        int n=nodes.size();
        return build(nodes,0,n-1);
    }
};