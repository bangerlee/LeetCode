/*
https://leetcode.com/problems/monotone-increasing-digits/

*/
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string n_str=to_string(N);
        int mark=n_str.length();
        for(int i=n_str.length()-1;i>0;i--){
            if(n_str[i]<n_str[i-1]){
                mark=i;
                n_str[i-1]=n_str[i-1]-1;
            }
        }
        for(int i=mark;i<n_str.length();i++){
            n_str[i]='9';
        }
        return stoi(n_str);
    }
};
