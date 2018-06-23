class Solution {
public:
    // beats 99.68 %
    // nlog(k)
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int>ans(2);
        if(nums.size() == 0) return ans;
        map<int,vector<int> > mp;
        
        vector<int>pos(nums.size(), 0); // 记录
        
        for(int i = 0; i < nums.size(); i++) 
        {
            int id = nums[i][0];
            mp[id].push_back(i);
        }
        int minn = INT_MAX;
        while(true)
        {
            auto it1 = mp.begin();
            auto it2 = prev(mp.end()); // 取最后一个mp
            int st = (*it1).first;
            int ed = (*it2).first;
            cout << st << " " << ed << endl;
            if(ed - st < minn) 
            {
                ans.clear();
                minn = ed - st;
                ans.push_back(st);
                ans.push_back(ed);
            }
            vector<int> v = (*it1).second;
            mp.erase(it1);
            for(int x : v) //遍历当前左端点所在的nums下标
            {
                // cout << "x = " << x << " ";
                pos[x]++;
                if(pos[x] >= nums[x].size()) return ans;
                int num = nums[x][pos[x]];
                mp[num].push_back(x);
            }
            // cout<<endl;
        }
        return ans;
    }
};