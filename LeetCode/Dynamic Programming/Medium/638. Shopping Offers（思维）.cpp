class Solution {
public:
    int check(vector<int>&needs,vector<int>&special)
    {
        for(int i=0;i<needs.size();i++) {
            if(needs[i] < special[i] ) return 0;
        }
        return 1;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minprices = 0;
        for(int i=0;i<needs.size();i++) {
            minprices += needs[i] * price[i];
        }
        for(int i=0;i<special.size();i++) 
        {
            if(check(needs,special[i])) 
            {
                vector<int> curneeds;
                for(int j=0;j<needs.size();j++) 
                {
                    curneeds.push_back(needs[j]-special[i][j]);
                }
                int tmpprice = shoppingOffers(price,special,curneeds) + special[i][needs.size()];
                minprices = min(minprices,tmpprice);
            }        
        }
        return minprices;
    }
};