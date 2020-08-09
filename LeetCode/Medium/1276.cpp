class Solution {
public:
    // 问是否可以让x,y 满足以下条件
    // 1. 4 * x + 2 * y = tomatoSlices
    // 2. x + y = cheeseSlices
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int>ans;
        if(tomatoSlices == 0 || cheeseSlices == 0) {
            return {0, 0};
        }
        if(tomatoSlices % 2 != 0) {
            return {};
        }
        if(tomatoSlices < cheeseSlices * 2) {
            return {};
        }
        if(cheeseSlices * 4 < tomatoSlices) {
            return {};
        }
        return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
    }
};