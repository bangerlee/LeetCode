/*
https://leetcode.com/problems/stream-of-characters/
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
    void insert(string& word){
        TrieNode* p=root;
        for(auto& c:word){
            if(p->children[c-'a']==NULL)
                p->children[c-'a']=new TrieNode;
            p=p->children[c-'a'];
        }
        p->isWord=true;
    }
    bool searchPrefix(string& str){
        if(str.length()==0) return false;
        TrieNode* p=root;
        for(char& c:str){
            if(p->children[c-'a']==NULL) return false;
            p=p->children[c-'a'];
            if(p->isWord) return true;
        }
        return p->isWord;
    }
};
class StreamChecker {
private:
    Trie* ttree;
    string str="";
    int mlen=0;
public:
    StreamChecker(vector<string>& words) {
        ttree=new Trie;
        for(string word:words){
            reverse(word.begin(),word.end());
            ttree->insert(word);
            mlen=max(mlen,(int)word.length());
        }
    }
    
    bool query(char letter) {
        str=string(1,letter)+str;
        if(str.length()>mlen) str.pop_back();
        return ttree->searchPrefix(str);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
