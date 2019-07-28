/*
https://leetcode.com/problems/word-ladder/

*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        dict.erase(beginWord);
        int res=1;
        while(!todo.empty()){
            int m=todo.size();
            for(int i=0;i<m;i++){
                string word=todo.front();todo.pop();
                if(word==endWord) return res;
                for(int j=0;j<word.size();j++){
                    char c=word[j];
                    for(int k=0;k<26;k++){
                        word[j]='a'+k;
                        if(dict.count(word)!=0){
                            todo.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j]=c;
                }
            }
            res++;
        }
        return 0;
    }
};
