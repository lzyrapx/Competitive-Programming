class Solution {
public:
    char str[1234<<1];
   int countSubstrings(string s) {

      int len = s.size();
      if(len==1)return 1;
      if(len==2) {
        if(s[0]==s[1])return 3;
        else return 2;
      }
      std::vector<int> p(len*2+2,0);
      int cnt = 0;
      str[0] = '$';
      str[1] = '#';
      str[len-1] = '$';
      int k = 2;
      for(auto c : s){
        str[k++] = c;
        str[k++] = '#';
      }

      for(int i=0;i<=len*2+1;i++) {
        std::cout << str[i] ;
      }
      std::cout  << '\n';
      int id = 1,mx =1;
      p[1] = p[0] = 1;
      int n = len * 2 + 2;
      for(int i=2;i<n;i++) {
        p[i] = 1;
        if(mx > i) {
          p[i] = min(p[(id<<1)-i],mx-i);
        }
        while(str[i+p[i]] == str[i-p[i]]) p[i]++;
        if(i + p[i] > mx){
          id = i;
          mx = i + p[i];
        }
      }
      // for(int i=0;i<3;i++) {
      //   std::cout << p[i] << " ";
      // }
      int ans = 0;
      for(auto x: p){
        // std::cout << "x=" << x << '\n';
        ans += (x / 2 );
      }
      return ans;
    }
};