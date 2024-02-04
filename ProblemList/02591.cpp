class Solution {
public:
    int distMoney(int money, int children) {
        int num_eight = money/8;
        int i;
        for(i=num_eight; i>=0; i--){
            int left_money = money-i*8, left_children = children-i;
            if( left_children < 0 || left_money < left_children || (left_money > 0 && left_children == 0) || (left_money == 4 && left_children == 1)) continue;
            break;
        }
        return i;
    }
};