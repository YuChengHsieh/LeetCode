#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


// int main(){
//     int t;
//     cin >> t;
//     for(int i=0; i<t; i++){
//         int n,q;
//         cin >> n >> q;
//         vector<int> sections(n+1,0);
//         vector<pair<int,int>> soldiers(q);
//         vector<int> prefix1(n+1,0), prefix2(n+1,0);
//         for(int j=0; j<q; j++){
//             pair<int,int> val;
//             cin >> val.first >> val.second;
//             soldiers[j] = val;
//             for(int l=val.first; l<=val.second; l++){
//                 sections[l] += 1;
//             }
//         }
        
//         for(int i=1; i<=n; i++){
//             prefix2[i] = prefix2[i-1];
//             prefix1[i] = prefix1[i-1];
//             if(sections[i] <= 2) prefix2[i] ++;
//             if(sections[i] <= 1) prefix1[i] ++;
//         }

//         sort(soldiers.begin(), soldiers.end());

//         int sections_cnt = 0;
//         for(int j=1; j<=n; j++){
//             sections_cnt += sections[j] > 0;
//         }

        

//         int max_val = INT_MIN;
//         for(int j=0; j<soldiers.size(); j++){
//             for(int k=j+1; k<soldiers.size(); k++){
//                 int unguard_section = 0;
//                 if(soldiers[j].second < soldiers[k].first){
//                     unguard_section += prefix1[soldiers[k].second] - prefix1[soldiers[k].first-1];
//                     unguard_section += prefix1[soldiers[j].second] - prefix1[soldiers[j].first-1];
//                 }else{
//                     unguard_section += prefix1[soldiers[k].second] - prefix1[soldiers[j].second];
//                     unguard_section += prefix2[soldiers[j].second] - prefix2[soldiers[k].first-1];
//                     unguard_section += prefix1[soldiers[k].first-1] - prefix1[soldiers[j].first-1];
//                 }
//                 max_val = max(max_val,sections_cnt-unguard_section);
//             }
//         }
//         cout << max_val << endl;
//     }
//     return 0;
// }

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n,q;
        cin >> n >> q;
        vector<int> sections(n+1,0);
        vector<pair<int,int>> soldiers(q);
        vector<int> prefix1(n+1,0), prefix2(n+1,0);
        for(int j=0; j<q; j++){
            pair<int,int> val;
            cin >> val.first >> val.second;
            soldiers[j] = val;
            for(int l=val.first; l<=val.second; l++){
                sections[l] += 1;
            }
        }
        
        for(int i=1; i<=n; i++){
            prefix2[i] = prefix2[i-1];
            prefix1[i] = prefix1[i-1];
            if(sections[i] <= 2) prefix2[i] ++;
            if(sections[i] <= 1) prefix1[i] ++;
        }

        sort(soldiers.begin(), soldiers.end());

        int sections_cnt = 0;
        for(int j=1; j<=n; j++){
            sections_cnt += sections[j] > 0;
        }

        int max_val = INT_MIN;
        for(int j=0; j<soldiers.size(); j++){
            for(int k=j+1; k<soldiers.size(); k++){
                int unguard_section = 0;
                if(soldiers[j].second < soldiers[k].first){
                    unguard_section += prefix1[soldiers[k].second] - prefix1[soldiers[k].first-1];
                    unguard_section += prefix1[soldiers[j].second] - prefix1[soldiers[j].first-1];
                }else{
                    unguard_section += prefix1[soldiers[k].second] - prefix1[soldiers[j].second];
                    unguard_section += prefix2[soldiers[j].second] - prefix2[soldiers[k].first-1];
                    unguard_section += prefix1[soldiers[k].first-1] - prefix1[soldiers[j].first-1];
                }
                max_val = max(max_val,sections_cnt-unguard_section);
            }
        }
        cout << max_val << endl;
    }
    return 0;
}