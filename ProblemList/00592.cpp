#include <vector>
#include <string>
using namespace std;

class Solution {
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
public:
    string fractionAddition(string expression) {
        vector<int> no, deno;
        bool negative = false, nominate = true;
        string number;
        expression += "/";
        for(int i=0; i<expression.size(); i++){
            if(expression[i] == '-'){
                if(i != 0){ 
                    if(nominate) no.push_back(negative ? -stoi(number) : stoi(number));
                    else deno.push_back(negative ? -stoi(number) : stoi(number));
                    nominate = !nominate;
                    number = "";
                } 
                negative = true;
            }else if(expression[i] == '+' || expression[i] == '/'){
                if(nominate) no.push_back(negative ? -stoi(number) : stoi(number));
                else deno.push_back(negative ? -stoi(number) : stoi(number));
                negative = false;
                nominate = !nominate;
                number = "";
            }
            else{
                number += expression[i];
            }
        }

        int LCM = 1;
        for(auto& num: deno){
            LCM = LCM*num/abs(gcd(LCM,num));
        }

        int ans = 0;
        for(int i=0; i<deno.size(); i++){
            ans += LCM/deno[i]*no[i];
        }
        
        int GCD = abs(gcd(ans,LCM));
        ans /= GCD;
        LCM /= GCD;
        
        return to_string(ans) + '/' + to_string(LCM);
    }
};