#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n, tmp;
    vector<int> arr, ans, ans_idx;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        arr.push_back(tmp);
        if(ans.empty() or ans.back() < tmp){
            ans.push_back(tmp);
            ans_idx.push_back(i);
        } else {
            auto it = lower_bound(all(ans), tmp);
            *it = tmp;
            ans_idx[it-ans.begin()] = i;
        }
    }
    // for(int i=0; i<ans.size(); i++){
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    int s, e;
    s = e = ans.size() - 1;
    cout << ans.size() << endl;
    while(s!=0){
        if(ans_idx[s-1] > ans_idx[e]) s--;
        else if (s < e) { 
            // [s, e)
            // cout << s << " " << e << endl;
            int tmp, x;
            tmp = ans_idx[e];
            while(x = arr[--tmp]){
                // cout << tmp << endl;
                if(ans[e] > x and ans[s] <= x){
                    ans[e-1] = x;
                    ans_idx[e-1] = tmp;
                    break;
                }
            }
            e--; 
        }
        else {s--; e--;}
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}