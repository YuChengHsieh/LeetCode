#include <vector>
#include <algorithm>
class Solution {
public:
    int distributeCookies(std::vector<int>& cookies, int k) {
        std::vector<int> kids(k, 0);
        int ans = std::accumulate(cookies.begin(), cookies.end(), 0);

        distribute(cookies, kids, 0, ans);

        return ans;
    }

private:
    void distribute(const std::vector<int>& cookies, std::vector<int>& kids, int cookie_cnt, int& ans) {
        if (cookie_cnt == cookies.size()) {
            ans = std::min(*std::max_element(kids.begin(), kids.end()), ans);
            return;
        }

        if (*std::max_element(kids.begin(), kids.end()) >= ans) {
            return;
        }

        for (int i = 0; i < kids.size(); i++) {
            kids[i] += cookies[cookie_cnt];
            distribute(cookies, kids, cookie_cnt + 1, ans);
            kids[i] -= cookies[cookie_cnt];
        }
    }
};