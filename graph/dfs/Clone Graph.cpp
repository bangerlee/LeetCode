/*
https://leetcode.com/problems/clone-graph/

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
private:
    Node* dfs(Node* node,unordered_map<int,Node*>& m){
        if(node==NULL) return NULL;
        if(m.count(node->val)!=0) return m[node->val];
        Node* new_node=new Node;
        new_node->val=node->val;
        m[new_node->val]=new_node;
        for(auto x:node->neighbors)
            new_node->neighbors.push_back(dfs(x,m));
        return new_node;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int,Node*> m;
        return dfs(node,m);
    }
};
