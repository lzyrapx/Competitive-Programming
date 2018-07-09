class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string>ans;
        int n = cpdomains.size();
        if(n == 0) return ans;
        unordered_map<string,int>mp;
        for(auto cur : cpdomains)
        {
            int num = 0;
            int i = 0;
            while(cur[i] != ' ') {
                num = num * 10 + cur[i] - '0';
                i++;
            }
            while(i < cur.size()) {
                if(cur[i - 1] == '.' || cur[i - 1] == ' ') {
                    mp[cur.substr(i, cur.size() - i)] += num;
                }
                i++;
            }
        }
        for(auto x : mp) {
            ans.push_back(to_string(x.second) + " " + x.first);
        }
        return ans;
    }
};