#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <regex.h>
#include <sys/types.h>
char regx[233], str[233];
int main(){
  while(~scanf("%s %s", regx, str)){
    regex_t reg;
    regcomp(&reg, regx, REG_EXTENDED);
    regmatch_t mm[1];
    if(regexec(&reg, str, 1, mm, 0) != REG_NOMATCH){
      if(mm[0].rm_eo-mm[0].rm_so == strlen(str))
        puts("Yes");
      else puts("No");
    }
    else puts("No");
    regfree(&reg);
  }
  return 0;
}