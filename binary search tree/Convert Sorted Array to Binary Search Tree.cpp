/*
https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* buildBST(vector<int>& nums,int begin,int end){
        if(begin>end) return NULL;
        int mid=(begin+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=buildBST(nums,begin,mid-1);
        root->right=buildBST(nums,mid+1,end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums,0,nums.size()-1);
    }
};
