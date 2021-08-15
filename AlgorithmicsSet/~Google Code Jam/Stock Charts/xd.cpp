#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

int N,K;
bool cbn[111][111]; // can be next
int prv[111];
bool visited[111];

bool FindNextDfs(int a) {
  if(a<0) return true;
  if(visited[a]) return false;
  visited[a]=true;
  for (int i=0;i<N;i++) if(cbn[a][i]) {
      if(FindNextDfs(prv[i])) {
        prv[i]=a;
        return true;
      }
    }
  return false;
}

int Solve(const vector<vector<int> >& stock) {
  N=stock.size(); K=stock[0].size();
  int i,j,k;
  for(i=0;i<N;i++) {
    for(j=0;j<N;j++) {
      if(i==j) cbn[i][j]=false;
      else {
        cbn[i][j]=true;
        for(k=0;k<K;k++)
          if(stock[i][k]<=stock[j][k]) cbn[i][j]=false;
      }
    }
  }
  memset(prv, -1, sizeof(prv));
  int ret=0;
  for(i=0;i<N;i++) {
    memset(visited, 0, sizeof(visited));
    if(!FindNextDfs(i)) ret++;
  }
  return ret;
}
    
int main(){
    int T, n, k, a;
    cin >> T;
    
    while(T--){
        vector<vector<int> >xd;
        cin >> n >> k;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                cin >> a;
                xd[i].push_back(a);
            }
        }
        
        cout << Solve(xd) << '\n';
    }
    
    return 0;
}