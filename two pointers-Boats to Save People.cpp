/*
https://leetcode.com/problems/boats-to-save-people/

Runtime: 152 ms
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i=0,j=people.size()-1;
        sort(people.rbegin(),people.rend());
        for(;i<=j;i++){
            if(people[i]+people[j]<=limit) j--;
        }
        return i;
    }
};
