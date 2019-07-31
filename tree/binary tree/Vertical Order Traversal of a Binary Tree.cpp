/*
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    void dfs(TreeNode* root,int x,int y,map<int,map<int,set<int>>>& m){
        if(root!=NULL){
            m[x][y].insert(root->val);
            dfs(root->left,x-1,y+1,m);
            dfs(root->right,x+1,y+1,m);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,set<int>>> m;
        dfs(root,0,0,m);
        vector<vector<int>> res;
        for(auto itx=m.begin();itx!=m.end();itx++){
            res.push_back(vector<int>());
            for(auto ity=itx->second.begin();ity!=itx->second.end();ity++)
                res.back().insert(end(res.back()),begin(ity->second),end(ity->second));
        }
        return res;
    }
};
