class Solution {
public:
    // 大模拟
    static vector<string> split(const string& s, char c) {
		vector<string> ans;
		int i = 0, n = s.size();
		while (i < n) {
			int j = i;
			i = s.find(c, i);
			if (i == -1) i = n;
			ans.push_back(s.substr(j, i - j));
			i++;
		}
		return ans;
	}
	static bool mycompare(pair<string, int>& a, pair<string, int>& b) {
		string s1 = a.first, s2 = b.first;
		vector<string> left = split(s1, '*');
		vector<string> right = split(s2, '*');
		return left.size() > right.size() || (left.size() == right.size() && left < right);
	}
	string combine(const string& a, const string& b) {
		if (a == "") return b;
		if (b == "") return a;
		vector<string> strs = split(a, '*');
		for (auto& s : split(b, '*')) strs.push_back(s);
		sort(strs.begin(), strs.end());
		string s;
		for (auto& t : strs) s += t + '*';
		s.pop_back();
		return s;
	}
	map<string, int> multi(map<string, int>& lhs, map<string, int>& rhs) {
		map<string, int> ans;
		int m = lhs.size(), n = rhs.size();
		for (auto& p : lhs) {
			for (auto& q : rhs) {
				// combine and sort the product of variables
				string t = combine(p.first, q.first);
				ans[t] += p.second*q.second;
			}
		}
		return ans;
	}
	map<string, int> calculate(vector<map<string, int>>& operands, vector<char>& ops) {
		map<string, int> ans;
		int n = ops.size();
		for (int i = n - 1; i >= 0; --i) {
			map<string, int> tmp = operands[i];
			while (i >= 0 && ops[i] == '*')
				tmp = multi(tmp, operands[--i]);
			int sign = ops[i] == '+' ? 1 : -1;
			for (auto& p : tmp) ans[p.first] += sign*p.second;
		}
		return ans;
	}
	map<string, int> helper(string& s, map<string, int>& mp, int& pos) {
		// every operand is an map, including single variable or nested (a * b + a * c); 
		// if the operand is a number, use pair("", number)
		vector<map<string, int>> operands;
		vector<char> ops;
		ops.push_back('+');
		int n = s.size();
		while (pos < n && s[pos] != ')') {
			if (s[pos] == '(') {
				pos++;
				operands.push_back(helper(s, mp, pos));
			}
			else {
				int k = pos;
				while (pos < n && s[pos] != ' ' && s[pos] != ')') pos++;
				string t = s.substr(k, pos - k);
				bool isNum = true;
				for (char c : t) {
					if (!isdigit(c)) isNum = false;
				}
				map<string, int> tmp;
				if (isNum)
					tmp[""] = stoi(t);
				else if (mp.count(t))
					tmp[""] = mp[t];
				else
					tmp[t] = 1;
				operands.push_back(tmp);
			}
			if (pos < n && s[pos] == ' ') {
				ops.push_back(s[++pos]);
				pos += 2;
			}
		}
		pos++;
		return calculate(operands, ops);
	}
	vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
		map<string, int> mp;
		int n = evalvars.size();
		for (int i = 0; i < n; ++i) mp[evalvars[i]] = evalints[i];
		int pos = 0;
		map<string, int> output = helper(expression, mp, pos);
		vector<pair<string, int>> ans(output.begin(), output.end());
		sort(ans.begin(), ans.end(), mycompare);
		vector<string> res;
		for (auto& p : ans) {
			if (p.second == 0) continue;
			res.push_back(to_string(p.second));
			if (p.first != "") res.back() += "*" + p.first;
		}
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