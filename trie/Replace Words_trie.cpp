/*
https://leetcode.com/problems/replace-words/

*/
class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode(){
        memset(children,0,sizeof(children));
        isWord=false;
    }
    
};
class Trie{
public:
    TrieNode* root=NULL;
    Trie(){
        root=new TrieNode;
    }
    void insert(string word){
        TrieNode* p=root;
        for(auto& w:word){
            if(p->children[w-'a']==NULL) p->children[w-'a']=new TrieNode;
            p=p->children[w-'a'];
        }
        p->isWord=true;
    }
    string startsWith(string& s){
        TrieNode* p=root;
        string res="";
        for(auto& w:s){
            p=p->children[w-'a'];
            if(p==NULL) break;
            res+=string(1,w);
            if(p->isWord) return res;
        }
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        stringstream ss(sentence);
        string word="",res="";
        Trie ttree;
        for(auto& d:dict) ttree.insert(d);
        while(ss>>word){
            res+=" "+ttree.startsWith(word);
        }
        return res.substr(1);
    }
};
