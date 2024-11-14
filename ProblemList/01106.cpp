#include <string>
using namespace std;

class Solution {
private:
    int idx = 0;
    bool check(char opt, bool r1, bool r2){
        if(opt == '&') return r1 & r2;
        else if(opt == '|') return r1 | r2;
        else return !r2;
    }
    bool rec(char oper, string& expression){
        bool ret = oper == '&' ? true : false;
        idx++;
        for(; idx < expression.size(); idx++){
            if(expression[idx] == '|' || expression[idx] == '&' || expression[idx] == '!')
                ret = check(oper,ret,rec(expression[idx],expression));
            else if(expression[idx] == 'f') ret = check(oper,ret,false);
            else if(expression[idx] == 't') ret = check(oper,ret,true);
            else if(expression[idx] == ')') break;
        }
        return ret;
    }
public:
    bool parseBoolExpr(string expression) {
        return rec(expression[0],expression);
    }
};