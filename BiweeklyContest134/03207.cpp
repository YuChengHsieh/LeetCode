#include <vector>
using namespace std;
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long points = 0, cur_energy = currentEnergy;
        int n = enemyEnergies.size();
        sort(enemyEnergies.begin(),enemyEnergies.end());

        if(cur_energy >= enemyEnergies[0]){
            cur_energy -= enemyEnergies[0];
            points += 1;
            for(int i=1; i<enemyEnergies.size(); i++){
                cur_energy += enemyEnergies[i];
            }
        }
        points += cur_energy/enemyEnergies[0];
        return points;
    }
};