class Solution {
public:
    int passThePillow(int n, int time) {
        n -= 1;
        return (time/n)%2 == 0 ? time%n+1 : n-time%n+1;
    }
};