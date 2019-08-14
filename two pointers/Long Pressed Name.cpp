/*
https://leetcode.com/problems/long-pressed-name/

*/
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0,j=0;
        while(i<name.length()&&j<typed.length()){
            if(name[i]!=typed[j]) return false;
            while(i<name.length()&&j<typed.length()&&name[i]==typed[j]){
                i++;
                j++;
            }
            while(j>0&&j<typed.length()&&typed[j]==typed[j-1])
                j++;
        }
        if(i==name.length()&&j==typed.length())
            return true;
        return false;
    }
};
