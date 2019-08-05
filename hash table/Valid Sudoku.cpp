/*
https://leetcode.com/problems/valid-sudoku/

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> ss;
        for(int i=0;i<9;i++){
            string si=to_string(i);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                string b="("+string(1,board[i][j])+")";
                string r=b+si;
                string c=to_string(j)+b;
                string h=to_string(int(i/3))+b+to_string(int(j/3));
                if(ss.count(r)||ss.count(c)||ss.count(h)) return false;
                ss.insert(r);
                ss.insert(c);
                ss.insert(h);
            }
        }
        return true;
    }
};
