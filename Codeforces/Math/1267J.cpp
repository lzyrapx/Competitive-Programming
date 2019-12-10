/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-10 22:22:16
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>ve;
        ve.clear();
        map<int,int>cnt;
        int minn = INT_MAX;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        for(auto x: cnt) {
            ve.push_back(x.second);
            minn = min(minn, x.second + 1);
        }
        int ans = INT_MAX;
        for(int s = 2; s <= minn; s++) { //  screen sizes
            int cur = 0;
            int f = 0;
            for(auto x : ve) {
                int num = (x - 1) / s + 1;
                if(num * (s - 1) > x) {
                    f = 1;
                    break;
                }
                cur += num;
            }
            if(f == 0) {
                ans = min(ans, cur);
            } 
        }
        cout << ans << endl;
    }
    return 0;
}
