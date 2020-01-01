/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-01 22:30:06
 */
class Solution {
public:
    // 不能有相邻的花
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for(int i = 1; i < flowerbed.size() - 1; i++) {
            if(n == 0) return true;
            if(flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0) {
                n--;
                i++;
            }
        }
        if(n <= 0) return true;
        else return false;
    }
};