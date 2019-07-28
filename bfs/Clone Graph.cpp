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
    unordered_map<Node*, Node*> copies;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* res=new Node(node->val, {});
        copies[node]=res;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* cur=q.front();q.pop();
            for(Node* neighbor:cur->neighbors){
                if(!copies.count(neighbor)){
                    copies[neighbor]=new Node(neighbor->val,{});
                    q.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return res;
    }
};
