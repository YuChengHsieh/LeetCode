#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();
        for(int i=1; i<=n/2; i++){
            if( n%i != 0 ) continue;
            vector<int> vec_a(26,0);
            vector<int> vec_b(26,0);
            for(int j=0; j<n; j += i){
                vec_a = vector<int>(26,0);
                for(int k=0; k<i; k++){
                    vec_a[s[j+k]-'a'] += 1;
                }
                if(j >= 1 && vec_a != vec_b) break;
                vec_b = vec_a;
            }
            if(vec_a == vec_b) return i;
        }
        return n;
    }
};