/*
https://leetcode.com/problems/shortest-completing-word/

*/
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        std::transform(licensePlate.begin(),licensePlate.end(),licensePlate.begin(),::tolower);
        unordered_map<char,int> counts;
        int total=0;
        for(char& c:licensePlate){
            if(isalpha(c)){
                counts[c]++;
                total++;
            }
        }
        string res="";
        for(string w:words){
            int n=total;
            unordered_map<char,int> cnts=counts;
            for(int i=0;i<w.size()&&n;i++) n-=cnts[w[i]]-- > 0;
            if(n==0 &&(res.empty() || w.size()<res.size())) res=w;
        }
        return res;
    }
};
