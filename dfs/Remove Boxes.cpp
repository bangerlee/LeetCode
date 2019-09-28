/*
https://leetcode.com/problems/remove-boxes/

*/
class Solution {
private:
    int mem[100][100][100];
    int helper(vector<int>& boxes,int l,int r,int k){
        if(l>r) return 0;
        if(mem[l][r][k]) return mem[l][r][k];
        mem[l][r][k]=helper(boxes,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;i++)
            if(boxes[i]==boxes[r])
                mem[l][r][k]=max(mem[l][r][k],helper(boxes,l,i,k+1)+helper(boxes,i+1,r-1,0));
        return mem[l][r][k];
    }
public:
    int removeBoxes(vector<int>& boxes) {
        return helper(boxes,0,boxes.size()-1,0);
    }
};
