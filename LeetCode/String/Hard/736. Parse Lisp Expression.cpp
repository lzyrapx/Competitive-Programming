class Solution {
public:
    int evaluate(string expression) {
        map<string,int>mp;
        return solve(expression,mp);
    }
    int solve(string expression, map<string,int> mp)
    {
         if ((expression[0] == '-') || (expression[0] >= '0' && expression[0] <= '9')) {
             return stoi(expression);
         }
         else if (expression[0] != '(') {
              return mp[expression];
         }
         // 除了第一个的 "(" 和最后一个")"
        string s = expression.substr(1, expression.size()- 1 - 1);
        int start = 0;
        string word = parse(s,start);
        if(word == "let") 
        {
            while(true)
            {
                
                string variable = parse(s,start);
                // 没有更多的表达式，分析变量
                if(start > s.size()) return solve(variable,mp);
                string tmp = parse(s,start);
                mp[variable] = solve(tmp, mp);
            }
        }
        else if(word == "add")
        {
            return solve(parse(s,start), mp) + solve(parse(s,start), mp);
        }
        else if(word == "mult")
        {
            return solve(parse(s,start), mp) * solve(parse(s,start), mp);
        }
    }
    //function : to seperate each expression
    string parse(string &s,int &start) 
    {
        int id = start + 1;
        int temp = start;
        int count = 1;
        if (s[start] == '(')
        {
            while (count != 0)
            {
                if (s[id] == '(') { 
                    count++;
                }
                else if (s[id] == ')') {
                    count--;
                }
                id++;
            }
        }
        else 
        {
            while (id < (int)s.size() && s[id] != ' ') {
                id++;
            }    
        }
        start = id + 1;
        return s.substr(temp,id - temp);
    }
};