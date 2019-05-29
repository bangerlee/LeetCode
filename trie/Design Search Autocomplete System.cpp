/*
https://leetcode.com/problems/design-search-autocomplete-system/
*/
class TrieNode{
public:
    map<char,TrieNode*> children;
    map<string,int> counts;
    bool isWord;
    TrieNode(){
        isWord=false;
    }
};
class Trie{
public:
    TrieNode* root;
    Trie(){
        root=new TrieNode;
    }
    void insert(string& s,int count){
        TrieNode* p=root;
        for(char c:s){
            if(p->children[c]==NULL) p->children[c]=new TrieNode;
            p=p->children[c];
            p->counts[s]+=count;
        }
        p->isWord=true;
    }
    void searchTop3(vector<string>& res,string& s){
        TrieNode* p=root;
        for(char c:s){
            if(p->children[c]==NULL) return;
            p=p->children[c];
        }
        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second || a.second == b.second && a.first < b.first;
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(cmp)> pq(cmp);
        auto it=p->counts.begin();
        while(it!=p->counts.end()){
            pq.push({it->first,it->second});
            if(pq.size()>3) pq.pop();
            ++it;
        }
        res.resize(pq.size());
        for(int i=pq.size()-1;i>=0;i--){
            res[i]=pq.top().first;
            pq.pop();
        }
    }
};
class AutocompleteSystem {
public:
    Trie* ttree=NULL;
    string str="";
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        ttree=new Trie;
        for(int i=0;i<sentences.size();i++){
            ttree->insert(sentences[i],times[i]);
        }
    }
    
    vector<string> input(char c) {
        vector<string> res;
        if(c=='#'){
            ttree->insert(str,1);
            str="";
            return res;
        }
        str+=string(1,c);
        ttree->searchTop3(res,str);
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
