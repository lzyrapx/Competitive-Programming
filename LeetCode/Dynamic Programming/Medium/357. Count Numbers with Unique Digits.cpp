int countNumbersWithUniqueDigits(int n) { //计算各位都不相同的数字个数
       if(n==0)return 1;
       int ans = 10;
       int unique = 9;
       int avail = 9;
       while(n > 1 && avail > 0) 
       {
         unique = unique * avail;
         ans += unique;
         avail--;
         n--;
       }
       return ans;
   }