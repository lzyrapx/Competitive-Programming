/*
 * @Descripttion: Prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-09-11 01:38:38
 * @LastEditors: zhaoyang.liang
 * @LastEditTime: 2019-09-11 01:38:38
 */
class Solution {
public:
    int years[2][13]={
            {0,31,28,31,30,31,30,31,31,30,31,30,31},
            {0,31,29,31,30,31,30,31,31,30,31,30,31}
    };
    int calc(int year,int month,int day)
    {
        int i,leap=0;
        if((year%4==0 && year%100!=0) || (year%100==0 && year%400==0) ) {
            leap=1;
        }
        for(i=0;i<month;i++) {
            day+=years[leap][i];
        }
        return day;
    }
    int dayOfYear(string date) {
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,7));
        int day = stoi(date.substr(8,10));
        return calc(year, month, day);
    }
};