/*
https://leetcode.com/problems/asteroid-collision/
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0;i<asteroids.size();i++){
            if(res.empty()||asteroids[i]>0||res.back()<0)
                res.push_back(asteroids[i]);
            else if(!res.empty()&&res.back()<=-asteroids[i]){
                if(res.back()<-asteroids[i]) i--;
                res.pop_back();
            }
        }
        return res;
    }
};
