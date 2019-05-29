/*
https://leetcode.com/problems/implement-trie-prefix-tree/

*/
class TrieNode{
public:
    TrieNode(){
        memset(children,0,sizeof(children));
    };
    TrieNode* children[26];
    bool isWord=false;
};
class Trie {
private:
    TrieNode* root=NULL;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p=root;
        for(auto w:word){
            if(p->children[w-'a']==NULL) p->children[w-'a']=new TrieNode;
            p=p->children[w-'a'];
        }
        p->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p=root;
        for(auto w:word){
            if(p->children[w-'a']==NULL) return false;
            p=p->children[w-'a'];
        }
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p=root;
        for(auto w:prefix){
            if(p->children[w-'a']==NULL) return false;
            p=p->children[w-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
