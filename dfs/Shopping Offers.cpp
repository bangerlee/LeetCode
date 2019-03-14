/*
https://leetcode.com/problems/shopping-offers/

*/
class Solution {
private:
    int buydirect(vector<int>& price,vector<int>& needs){
        int res=0;
        for(int i=0;i<price.size();i++) res+=price[i]*needs[i];
        return res;
    }
    int helper(vector<int>& price,vector<vector<int>>& special,vector<int>& needs,int pos){
        int res=buydirect(price,needs);
        for(int i=pos;i<special.size();i++){
            vector<int> tmp;
            vector<int> offer=special[i];
            for(int j=0;j<needs.size();j++){
                if(offer[j]>needs[j]){
                    tmp.clear();
                    break;
                }
                tmp.push_back(needs[j]-offer[j]);
            }
            if(tmp.size()>0)
                res=min(res,offer.back()+helper(price,special,tmp,i));
        }
        return res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price,special,needs,0);
    }
};
