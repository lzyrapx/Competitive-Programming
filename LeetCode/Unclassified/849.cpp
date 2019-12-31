/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 22:42:24
 */
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = -1;
        int maxdis = 0;
        for(int i = 0; i < seats.size(); i++) {
            if(seats[i] == 0) continue;
            if(l == -1) {
                maxdis = max(maxdis, i);
            }
            else {
                maxdis = max(maxdis, (i - l) / 2);
            }
            l = i;
        }
        if(seats[seats.size() - 1] == 0) {
            maxdis = max(maxdis, int((seats.size() - 1) - l));
        }
        return maxdis;
    }
};