class Solution {
public:
    // 只输出一个,  least list index sum
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n = list1.size();
        int m = list2.size();
        map<string,int>mp;
        vector<string>ans;
        int minn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mp[list1[i]] = i;
        }
        for(int i = 0; i < m; i++) {
            if(mp.find(list2[i]) != mp.end()) {
                minn = min(minn,mp[list2[i]] + i);
            }
        }
        for(int i = 0;i < m; i++)
        {
            if(mp.find(list2[i]) != mp.end())
            {
                if(mp[list2[i]] + i == minn) {
                    ans.push_back(list2[i]);
                }   
            }
        }
        return ans;
    }
};