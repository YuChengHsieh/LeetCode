class Solution {
public:
    int totalMoney(int n) {
        int week_cnt = n/7;
        int left_days = n%7;
        int first_week_money = 7+6+5+4+3+2+1;
        int ans = 0;
        for(int i=0; i<week_cnt; i++){
            ans += first_week_money+i*7;
        }
        for(int i=0; i<left_days; i++){
            ans += week_cnt + i + 1;
        }
        return ans;
    }
};