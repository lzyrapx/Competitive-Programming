class Solution {
public:
        int nthUglyNumber(int n) {
              vector<long long>v;
             for(long long  i=1;i<=INT_MAX;i*=2) {
                for(long long j=i;j<=INT_MAX;j*=3) {
                    for(long long k=j;k<=INT_MAX;k*=5) {
                        v.push_back(k);
                    }
                 }
            }
            sort(v.begin(),v.end());
            return v[n-1];
    }
};