//题目链接https://ac.nowcoder.com/acm/contest/120712/B
#include<bits/stdc++.h>
// #define ll long long
// #define int long long
using namespace std;
const int N = 1e3 + 5;
int n, m;
bool check(int x, int y){
    return x <= n && x > 0 && y <= m && y > 0;
}
//对于每一个点来讲有8个搜索方向，为了避免重复，删除4个方向
//下， 右上， 右，右下
int dir[4][2] = {{1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int mp[N][N];
void solve(){
    cin >> n >> m;
    char c;
    getchar();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            mp[i][j] = getchar() - '0';
            // cout << mp[i][j] << " ";
        }
        getchar();
    }

    int ans[3] = {0};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 0; k < 4; k++){
                if(mp[i][j] == 0) continue;
                int x = dir[k][0], y = dir[k][1];
                int cnt = 0;
                for(int t = 0; t < 5; t++){
                    int xx = x*t + i, yy = y*t + j;
                    if(check(xx, yy) && mp[i][j] == mp[xx][yy]){
                        cnt++;
                    }else{
                        break;
                    }
                }
                if(cnt == 5) ans[mp[i][j]]++;
                // printf("point:(%d, %d), dir:%d, cnt:%d\n", i, j, k, cnt);
            }
        }
    }

    cout << ans[1] << " " << ans[2] << endl;
}   
signed main(){
    // std::ios::sync_with_stdio(false);
    solve();
    return 0;
}
