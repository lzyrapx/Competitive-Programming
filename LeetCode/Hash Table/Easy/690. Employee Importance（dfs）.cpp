/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    // 满足树的结构, 直接dfs.
    int dfs(vector<Employee*> employees, int id)
    {
        int sum = 0;
        for(auto employee : employees) 
        {
            if(employee -> id == id) 
            {
                for(auto sub_id : employee -> subordinates)
                {
                    sum += dfs(employees, sub_id);
                }
                sum += employee -> importance;
            }
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees, id);
    }
};