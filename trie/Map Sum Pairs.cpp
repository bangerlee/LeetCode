/*
https://leetcode.com/problems/map-sum-pairs/

*/
class TrieNode{
public:
    map<char,TrieNode*> children;
    int value;
    TrieNode(){
        value=0;
    }
};
class Trie{
private:
    int dfs(TrieNode* p){
        int sum=0;
        if(p==NULL) return sum;
        auto it=p->children.begin();
        while(it!=p->children.end()){
            sum+=dfs(p->children[it->first]);
            ++it;
        }
        return sum+p->value;
    }
public:
    TrieNode* root=NULL;
    Trie(){
        root=new TrieNode;
    }
    void insert(string& key,int value){
        TrieNode* p=root;
        for(char c:key){
            if(p->children[c]==NULL) p->children[c]=new TrieNode;
            p=p->children[c];
        }
        p->value=value;
    }
    int sumsearch(string& prefix){
        TrieNode* p=root;
        for(char& c:prefix){
            if(p->children[c]==NULL) return 0;
            p=p->children[c];
        }
        return dfs(p);
    }
};
class MapSum {
private:
    Trie* root=NULL;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root=new Trie;
    }
    
    void insert(string key, int val) {
        root->insert(key,val);
    }
    
    int sum(string prefix) {
        return root->sumsearch(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
