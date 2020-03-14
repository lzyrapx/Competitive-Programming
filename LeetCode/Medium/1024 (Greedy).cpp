/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-14 17:48:48
 */
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end());
        int cur = 0;
        int nxt = 0;
        int cnt = 1;
        for(auto clip: clips) {
            if(clip[0] > nxt) {
                return -1;
            }
            if(clip[0] > cur) {
                cur = nxt;
                cnt++;
            }
            nxt = max(clip[1], nxt);
            if(nxt >= T) {
                return cnt;
            }
        }
        return -1;
    }
};