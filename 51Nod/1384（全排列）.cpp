#include <bits/stdc++.h>
using namespace std;
int main()  
{  
    char s[10];  
    scanf("%s", s);  
    int length = strlen(s);  
    sort(s, s + length);  
    do  
    {  
        printf("%s\n", s);  
    }while(next_permutation(s, s+length));  
    return 0;  
}