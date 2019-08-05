/*
https://leetcode.com/problems/shortest-word-distance-ii/

*/
class WordDistance {
private:
    unordered_map<string,vector<int>> m;
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++) m[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        vector<int> v1=m[word1];
        vector<int> v2=m[word2];
        int res=INT_MAX;
        for(int i=0,j=0;i<v1.size()&&j<v2.size();){
            if(v1[i]<v2[j]){
                res=min(res,v2[j]-v1[i]);
                i++;
            }
            else{
                res=min(res,v1[i]-v2[j]);
                j++;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
