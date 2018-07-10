class Solution {
public:
    /*
    假设一个森林里有若干只小兔子，每只兔子都有颜色。现在这群兔子里的其中几只兔子会告诉你除它自己以外与它颜色相同的兔子有多少个，
    现在要求根据几只兔子的回答求出森林里最少有几只兔子(有些兔子并未回答)。
    */
    int numRabbits(vector<int>& answers) {
        int n = answers.size();
        if(n == 0) return 0;
        map<int,int>mp;
        int ans = 0;
        for(auto x : answers) {
            if(mp[x] == 0) { // new color
                mp[x]++;
                ans += (x + 1);
            }
            else mp[x]++;
            
            if(mp[x] > x) { // color is full
                mp[x] = 0;
            }
        }
        return ans;
    }
};