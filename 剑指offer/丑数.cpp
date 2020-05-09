class Solution {
public:
    // 丑数p = 2 ^ x * 3 ^ y * 5 ^ z
    int GetUglyNumber_Solution(int index) {
        // 0-6的丑数分别为0-6
        if(index < 7) return index;
        int p2 = 0, p3 = 0, p5 = 0;
        int num = 1;
        vector<int>v;
        v.push_back(num);
        while(v.size() < index)
        {
            // 选取三个可能的丑数中间最小的一个
            num = min(v[p2] * 2, min(v[p3] * 3, v[p5] * 5));
            // 移动下标
            if(v[p2] * 2 == num) p2++;
            if(v[p3] * 3 == num) p3++;
            if(v[p5] * 5 == num) p5++;
            v.push_back(num);
        }
        return num;
    }
};