class Solution {
public:
    //  beats 94.89 %
    string shortestPalindrome(string s) {
      int len = s.size();
      if(len == 0) return ""; 
      if(len == 1) return s;
      if(len == 2) {
          if(s[0] == s[1]) return s;
          else return s.substr(1) + s;
      }
      string str(s.size() * 2 + 3, 'c');
      std::vector<int> p(len*2+2,0);
      p.resize(len*2+2);
      str[0] = '$';
      str[1] = '#';
      str[len-1] = '$';
      int k = 2;
      for(auto c : s){
        str[k++] = c;
        str[k++] = '#';
      }
      //
      // for(int i=0;i<=len*2+1;i++) {
      //   std::cout << str[i] ;
      // }
      // std::cout  << '\n';
      int id = 1,mx =1;
      p[1] = p[0] = 1;
      int n = len * 2 + 2;
      for(int i=2;i<n;i++) {
        p[i] = 1;
        if(mx > i) {
          p[i] = min(p[(id<<1)-i],mx-i);
        }
        // $#a#a#a#
        while(str[i+p[i]] == str[i-p[i]]) p[i]++; //p[i]为str[]第i个字符为中心的回文串长度+1
        if(i + p[i] > mx){
          id = i;
          mx = i + p[i];
        }
      }

      int max_len = 0;
      int idx = -1;
      for(int i = 0; i < k;i++) {
       // std::cout << i <<" " << p[i] - 1 <<endl;
       if(p[i] == i) {
           idx = i;
         }
       }
       string ans;
       int av = p[idx] - 1;
       ans = s.substr(av);
       reverse(ans.begin(), ans.end());
       // cout<< av << " "<< ans <<endl;
	   return ans + s;
    }
};