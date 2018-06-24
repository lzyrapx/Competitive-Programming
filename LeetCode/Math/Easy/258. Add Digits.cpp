class Solution {
public:
    // O(1) : answer is (num - 1) % 9 + 1
    int addDigits(int num) {
        if(num <= 9) return num;
        while(num > 0)
        {
            int sum = 0;
            if(num <= 9) return num;
            while(num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
    }
};