/*
https://leetcode.com/problems/flood-fill/

*/
class Solution {
private:
     void fill(vector<vector<int>>& res,int sr,int sc,int color,int newColor){
         if(sr<0||sc<0||sr>=res.size()||sc>=res[0].size()) return;
         if(res[sr][sc]!=color) return;
         res[sr][sc]=newColor;
         fill(res,sr-1,sc,color,newColor);
         fill(res,sr,sc-1,color,newColor);
         fill(res,sr+1,sc,color,newColor);
         fill(res,sr,sc+1,color,newColor);
     }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        fill(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
