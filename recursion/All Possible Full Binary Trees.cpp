/*
https://leetcode.com/problems/all-possible-full-binary-trees/

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
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> res;
        if(N==1){
            TreeNode* a=new TreeNode(0);
            res.push_back(a);
            return res;
        }
        if(N<1||N%2==0) return res;
        for(int i=1;i<N;i+=2){
            vector<TreeNode*> lres=allPossibleFBT(i);
            vector<TreeNode*> rres=allPossibleFBT(N-i-1);
            for(int j=0;j<lres.size();j++){
                for(int k=0;k<rres.size();k++){
                    TreeNode* p=new TreeNode(0);
                    p->left=lres[j];
                    p->right=rres[k];
                    res.push_back(p);
                }
            }
        }
        return res;
    }
};
