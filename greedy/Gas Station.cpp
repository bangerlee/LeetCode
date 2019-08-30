/*
https://leetcode.com/problems/gas-station/

*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumCost=0,sumGas=0,tank=0,start=0;
        for(int i=0;i<gas.size();i++){
            sumCost+=cost[i];
            sumGas+=gas[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                tank=0;
                start=i+1;
            }
        }
        if(sumCost>sumGas) return -1;
        return start;
    }
};
