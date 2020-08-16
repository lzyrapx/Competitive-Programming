class Solution {
public:
    // 0 -> 01, 1 -> 10
    //01排列
    //              0
    //          /        \   
    //      0                1
    //    /   \            /    \
    //  0       1        1       0
    // / \     /  \     /  \    / \ 
    //0   1   1    0   1    0  0   1
    int kthGrammar(int N, int K) {
        if(N == 1) {
            return 0;
        }
        // 上一行的长度
        int preLen = (1 << (N - 1)) / 2;
        if(K <= preLen) {
            // 位于前半段，则等价于上一行同样位置的值
            return kthGrammar(N - 1, K);
        }
        else {
             // 位于后半段，则等价于上一行相应位置的值取反
            return 1 - kthGrammar(N - 1, K - preLen);
        }
    }
};