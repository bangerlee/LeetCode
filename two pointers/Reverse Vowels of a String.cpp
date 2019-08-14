/*
https://leetcode.com/problems/reverse-vowels-of-a-string/

*/
class Solution {
public:
    string reverseVowels(string s) {
        string vowels="aeiouAEIOU";
        auto b=s.begin();
        auto e=s.end()-1;
        while(b<e){
            while(vowels.find(*b)==string::npos) b++;
            while(vowels.find(*e)==string::npos) e--;
            if(b<e) swap(*b,*e);
            b++;
            e--;
        }
        return s;
    }
};
