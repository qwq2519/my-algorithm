#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
vector<int> v[N];
int n;
bool a[N],goal[N];
int fa[N],dep[N];
void dfs(int x,int F,int D){
    fa[x]=F;
    dep[x]=D;
    for(auto &to:v[x]){
        if(to==F) continue;
        dfs(to,x,D+1);
    }
}
set<pair<int,int> >op;
void bfs(int p){
    queue<int> q;
    q.push(p);
    a[p]=!a[p];
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto &to:v[x]){
            if(to==fa[x]) continue;
            if( (dep[to]-dep[p])%2==0 ){
                a[to]=!a[to];
            }
            q.push(to);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=goal[i]){
            op.insert({dep[i],i});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>goal[i];
    dfs(1,-1,1);

    for(int i=1;i<=n;i++){
        if(a[i]!=goal[i]){
            op.insert({dep[i],i});
        }
    }
    // //按照深度排序，自顶向下操作节点
    // sort(op.begin(),op.end());
    int ans=0;

    while(!op.empty()){
        auto it=op.begin();
        op.erase(it);

        if(a[it->second]==goal[it->second]) continue;
        bfs(it->second);
        ++ans;
    }

    for(auto& [DEP,X]:op){
        if(a[X]==goal[X]) continue;
        bfs(X);
        ans++;
    }

    cout<<ans<<'\n';
    return 0;
}