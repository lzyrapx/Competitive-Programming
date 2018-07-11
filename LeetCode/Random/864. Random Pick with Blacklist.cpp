class Solution {
public:
    map<int,int>mp;
    set<int>se;
    int M;
    //将前面的数字重新re-map到后面，然后随机后面那段连续数字
    Solution(int N, vector<int> blacklist) {
        mp.clear();
        
        for(int i = 0; i < (int)blacklist.size(); i++) {
            mp[blacklist[i]] = 1;
        }
        M = N - blacklist.size();
        for(auto b : blacklist) 
        {
            if(b < M) // re-mapping
            {
                while(mp.count(N - 1)) N--;
                mp[b] = N - 1;
                N--;
            }
        }
        
    }
    
    int pick() {
        int x = rand() % M;
        if(mp.count(x) == 1) return mp[x];
        else return x;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
