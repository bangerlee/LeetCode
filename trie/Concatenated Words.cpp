/*
https://leetcode.com/problems/concatenated-words/
*/
class TrieNode{
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode(){
        isWord=false;
        memset(children,0,sizeof(children));
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode;
    }
    void insert(string& s){
        TrieNode* p=root;
        for(char c:s){
            if(p->children[c-'a']==NULL) p->children[c-'a']=new TrieNode;
            p=p->children[c-'a'];
        }
        p->isWord=true;
    }
    bool testWord(string& word,int idx,int count){
        TrieNode* p=root;
        int n=word.length();
        for(int i=idx;i<n;i++){
            if(p->children[word[i]-'a']==NULL) return false;
            if(p->children[word[i]-'a']->isWord){
                if(i==n-1) return count>=1;
                if(testWord(word,i+1,count+1)) return true;
            }
            p=p->children[word[i]-'a'];
        }
        return false;
    }
};
class Solution {
private:
    Trie* ttree;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        ttree=new Trie;
        for(auto& word:words){
            ttree->insert(word);
        }
        for(auto& word:words){
            if(ttree->testWord(word,0,0)) res.push_back(word);
        }
        return res;
    }
};
