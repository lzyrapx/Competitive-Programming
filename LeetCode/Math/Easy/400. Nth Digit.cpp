class Solution {
public:
    int findNthDigit(int n) {
        if(n <= 9) return n;
        int bits = 1; // 当前位数
        
        long long num = 9; // 注意：long long
        
        // 几位数
        while(n > bits * num)
        {
            n -= bits * num;
            bits++;
            num *= 10;
        }
        int nth = (n - 1) / bits; // 第几个
        int wei = (n - 1) % bits; // 第几位
        
        //  还原数字
        int number = pow(10, bits - 1) + nth;
        
        string s =  to_string(number);
        // cout << s << endl;
        // cout << wei << endl;
        int ans = s[wei] - '0';
        return ans;
    }
};
/*
分析一下位数和规律
* 个位数：1-9，一共9个,共计9个数字
* 2位数：10-99,一共90个，共计180个数字
* 3位数：100-999，一共900个，共计2700个数字
* 4位数，1000-9999，一共9000个，共计36000个数字
* 以此类推，
* 这样就可以首先定位到是几位数，再找到其对应的数字.
*/