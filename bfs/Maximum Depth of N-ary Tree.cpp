/*
https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        int res=0;
        if(root==NULL) return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            res++;
            int level=q.size();
            for(int i=0;i<level;i++){
                Node* p=q.front();q.pop();
                for(Node* child:p->children)
                    if(child) q.push(child);
            }
        }
        return res;
    }
};
