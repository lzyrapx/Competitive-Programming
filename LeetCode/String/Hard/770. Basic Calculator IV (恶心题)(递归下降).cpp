class Solution {
public:
    // 递归下降
    string token;
    string str;
    int index;
    vector<string> g_evalvars;
    vector<int> g_evalints;
 
    //找出下一个符号 + - * ( ) 数字或者变量
    string get_token() {
        while(str[index]==' ') index++;  //去除空格
        string token = "";
        if(index == str.length()) return token;
        //数字
        if(str[index]>='0' && str[index]<='9') {
            while(str[index]>='0' && str[index]<='9') {
                token += str[index];
                index++;
            }
        }else if(str[index]>='a' && str[index]<='z') {  //变量
            while(str[index]>='a' && str[index]<='z') {
                token += str[index];
                index++;
            }
        }else
        switch(str[index]) {
            case '+':
                token += "+";
                index++;
                break;
            case '-':
                token += "-";
                index++;
                break;
            case '*':
                token += "*";
                index++;
                break;
            case '/':
                token += "/";
                index++;
                break;
            case '(':
                token += '(';
                index++;
                break;
            case ')':
                token += ')';
                index++;
                break;
            default:  //不可识别的记号
                break;
        }
        return token;
    }
    //判断是否为num
    bool is_num(string &tk) {
        for(int i=0; i<tk.length(); i++)
            if(tk[i]>='a' && tk[i]<='z') return false;
        return true;
    }
    string int2str(const int int_temp)
    {
        string string_temp;
        stringstream stream;
        stream<<int_temp;
        string_temp=stream.str();   //此处也可以用 stream>>string_temp
        return string_temp;
    }
    //使用c分割字符串s
    void split_string(const string& s, const string& c, vector<string> &v){
        string::size_type pos1, pos2;
        pos2 = s.find(c);
        pos1 = 0;
        while(string::npos != pos2){
            v.push_back(s.substr(pos1, pos2-pos1));
 
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }
    //分离因子的系数和变量
    void split(const string &fac1, string &num1, string &vars1) {
        int i = 0;
        while(i<fac1.length() && fac1[i]!='*') i++;
        num1 = fac1.substr(0, i);
        if(i != fac1.length())
            vars1 = fac1.substr(i+1, fac1.length()-i-1);
    }
    //处理两个因子相乘 1*a*b*c * 2*c*d
    string multi(string fac1, string fac2) {
        string res = "";
        string num1, vars1, num2, vars2;
        int coff;
        split(fac1, num1, vars1);
        split(fac2, num2, vars2);
        coff = atoi(num1.c_str()) * atoi(num2.c_str());
 
        vector<string> vvars1, vvars2;
        split_string(vars1, "*", vvars1);
        split_string(vars2, "*", vvars2);
        sort(vvars1.begin(), vvars1.end());
        sort(vvars2.begin(), vvars2.end());
 
        res += int2str(coff);
        int s1 = 0, s2 = 0;
        while(s1<vvars1.size() && s2<vvars2.size()) {
            if(vvars1[s1] < vvars2[s2]) {
                res += "*";
                res += vvars1[s1];
                s1++;
            }else {
                res += "*";
                res += vvars2[s2];
                s2++;
            }
        }
        while(s1<vvars1.size()) {
            res += "*";
            res += vvars1[s1++];
        }
        while(s2<vvars2.size()) {
            res += "*";
            res += vvars2[s2++];
        }
        return res;
    }
    //排序辅助函数
    static bool cmp(const string &s1, const string &s2) {
        int nums1 = 0, nums2 = 0;  //两因子的度
        for(int i=0; i<s1.length(); i++) if(s1[i] == '*') nums1++;
        for(int i=0; i<s2.length(); i++) if(s2[i] == '*') nums2++;
        if(nums1 != nums2) return nums1 > nums2; //度大的优先
        else {
            string vars1, vars2;
            int i = 0;
            while(i<s1.length() && s1[i]!='*') i++;
            if(i != s1.length()) vars1 = s1.substr(i+1, s1.length()-i-1);
            i = 0;
            while(i<s2.length() && s2[i]!='*') i++;
            if(i != s2.length()) vars2 = s2.substr(i+1, s2.length()-i-1);
            return vars1 < vars2;   //字典序排序
        }
    }
    //合并同类项
    void merge_factor(vector<string> &res, vector<string> &res1) {
        if(res.size() == 0) return ;
 
        sort(res.begin(), res.end(), cmp);
        int c;
        string num;
        string var;
        for(int i=0; i<res.size(); i++) {
            if(i == 0) {
                split(res[0], num, var);
                c = atoi(num.c_str());
            }else {
                string t_num, t_var;
                split(res[i], t_num, t_var);
                if(t_var == var) c += atoi(t_num.c_str());
                else {
                    if(c != 0) {
                        string tp = int2str(c);
                        if(var != "")   tp += "*"+var;
                        res1.push_back(tp);
                    }
                    num = t_num;
                    var = t_var;
                    c = atoi(num.c_str());
                }
            }
        }
        if(c != 0) { //插入系数非0项
            string tp = int2str(c);
            if(var != "")   tp += "*"+var;
            res1.push_back(tp);
        }
        return ;
    }
 
    vector<string> exp() {
        vector<string> res = additive();
        vector<string> temp;
        while(token=="+" || token=="-") {
            string op = token;
            token = get_token();    //跳过'+' '-'
            temp = additive();
            if(op=="+") {
                for(int i=0; i<temp.size(); i++) res.push_back(temp[i]);
            }else {
                for(int i=0; i<temp.size(); i++) res.push_back(multi(temp[i], "-1"));
            }
        }
        vector<string> res1;
        //合并同类项
        merge_factor(res, res1);
        return res1;
    }
    vector<string> additive() {
        vector<string> res = factor();
        while(token=="*") {
            token = get_token();   //跳过'*'
            vector<string> fac= factor();
            vector<string> temp;
            //执行相乘运算
            for(int i=0; i<res.size(); i++)
            for(int j=0; j<fac.size(); j++) {
                temp.push_back(multi(res[i], fac[j]));
            }
            res = temp;
        }
        return res;
    }
    vector<string> factor() {
        vector<string> res;
        if(token == "(") {
            token = get_token();
            res = exp();
            token = get_token();  //跳过')'
        }else {
            if(is_num(token)) {
                res.push_back(token);
            }else {
                for(int i=0; i<g_evalvars.size(); i++)
                    if(token == g_evalvars[i])
                        res.push_back(int2str(g_evalints[i]));
                if(res.size() == 0) {
                    string t = "";
                    t += "1*";
                    t += token;
                    res.push_back(t);
                }
            }
            token = get_token();  //跳过num
        }
        return res;
    }
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        vector<string> res;
        str = expression;
        g_evalvars = evalvars;
        g_evalints = evalints;
        index = 0;
        token = get_token();
        res = exp();
        return res;
    }
};
/*
给定一个表达式（包含+ – * ( ) 变量 数字）,符号之间用一个空格隔开，变量集合和赋值集合，给出结果。
例如expression = "e + 8 – a + 5"，evalvars = ["e"] evalints = [1] ( 即e = 1)，结果为["-1*a", "14"]， 
变量只包含小写字母，不会有系数，输出格式如下：

1.每个因子的包含的变量应该按照字典序排序，比如"b*a*c"，只能表示为"a*b*c"。
2.每个因子有一个度，即变量的个数，输出的时候度大的优先，度相同的情况下，按照字典序输出（不包含系数）。
3.系数总是被输出到最左边，系数1也应该输出。
4.系数为0的项不输出。比如表达式"0"的输出为[]。
*/