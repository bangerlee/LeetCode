/*
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

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
    unordered_map<TreeNode*, vector<TreeNode*>> m;
    void buildMap(TreeNode* node,TreeNode* parent){
        if(node==NULL) return;
        if(!m.count(node)){
            if(parent!=NULL){
                m[node].push_back(parent);
                m[parent].push_back(node);
            }
            buildMap(node->left,node);
            buildMap(node->right,node);
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        if(root==NULL) return res;
        buildMap(root, NULL);
        if(!m.count(target)) return res;
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            int size=q.size();
            if(K==0){
                for(int i=0;i<size;i++){
                    res.push_back(q.front()->val);
                    q.pop();
                }
                return res;
            }
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();q.pop();
                for(TreeNode* next:m[cur]){
                    if(visited.count(next)) continue;
                    visited.insert(next);
                    q.push(next);
                }
            }
            K--;
        }
        return res;
    }
};
