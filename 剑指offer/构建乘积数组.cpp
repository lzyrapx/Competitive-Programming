class Solution {
public:
    // B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1], A[i] = 1
    // 题解： B[i]的值可以看成矩阵中每行的乘积
    vector<int> multiply(const vector<int>& A) {
        if(A.size() == 0) return vector<int>();
        vector<int>B(A.size(),0);
        B[0] = 1;
        // //计算下三角连乘
        for(int i = 1; i < A.size(); i++) {
            B[i] = B[i - 1] * A[i - 1];
        }
        // 计算上三角
        int tmp = 1;
        for(int j = A.size() - 2; j >= 0; --j) {
            tmp *= A[j + 1];
            B[j] *= tmp;
        }
        return B;
    }
};