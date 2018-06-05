class Solution {
public:
    int not_swap[1234];
    int Swap[1234];
    int minSwap(vector<int>& A, vector<int>& B) {
       int sz = (int)A.size();
       Swap[0] = 1;
       for(int i=1;i<sz;i++) {
         not_swap[i] = sz;
         Swap[i] = sz;
         if(A[i - 1] < A[i] && B[i-1] < B[i]) {
           not_swap[i] = not_swap[i-1];
           Swap[i] = Swap[i-1] + 1;
         }
         if(A[i-1] < B[i] && B[i-1] < A[i]) {
          //If A[i-1] and B[i-1] are swapped, we don’t need to swap A[i] and B[i].
          //Otherwise, we need to swap A[i] and B[i].
           not_swap[i]= min(not_swap[i],Swap[i-1]);
           Swap[i] = min(Swap[i],not_swap[i-1] + 1);
           // 以上语句顺序调转也可以
         }
       }
       return min(not_swap[sz-1],Swap[sz-1]);
   }
};