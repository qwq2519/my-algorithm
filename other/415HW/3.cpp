#include<bits/stdc++.h>
using namespace std;
int n,m;
unordered_set<string> Name;

struct windowssss{
    string name;
    int x,y;
    int w,h;
    int cengji;
    int idx;
};

vector<windowssss> v;
int cnt;
windowssss findById(int id){
    for(auto &it:v){
        if(it.idx==id){
            return it;
        }
    }
}

windowssss findByName(string name){
    for(auto &it:v){
        if(it.name==name){
            return it;
        }
    }
}

int pingmu[4007][4007];
void shuaxin(){
    memset(pingmu,0,sizeof pingmu);
    for(auto &it:v){
        for(int i=it.x;i<it.x+it.w;i++)
          for(int j=it.y;j<it.y+it.h;j++){
            if(i<0||j<0||i>n||j>m) continue;
            if(pingmu[i][j]==0){
                pingmu[i][j]=it.idx;
                continue;
            }
            windowssss pre=findById(pingmu[i][j]);
            if(pre.cengji<it.cengji||it.idx>pre.idx)
            pingmu[i][j]=it.idx;
        }
    }
}

void shuaxinone(windowssss it){
for(int i=it.x;i<it.x+it.w;i++)
          for(int j=it.y;j<it.y+it.h;j++){
            if(i<0||j<0||i>n||j>m) continue;
            if(pingmu[i][j]==0){
                pingmu[i][j]=it.idx;
                continue;
            }
            windowssss pre=findById(pingmu[i][j]);
            if(pre.cengji<it.cengji||it.idx>pre.idx)
            pingmu[i][j]=it.idx;
        }
}

void create(){
    windowssss t;
    // string name;
    // int x,y;
    // int w,h;
    // int cengji;
    cin>>t.name>>t.x>>t.y>>t.w>>t.h>>t.cengji;
    t.idx=++cnt;
    if(Name.find(t.name)!=Name.end()){
        cout<<"false"<<endl;
        return;
    }
    cout<<"true"<<endl;
    Name.insert(t.name);
    v.push_back(t);
    shuaxinone(t);
}

void remove(){
    string name;
    cin>>name;
    if(Name.find(name)==Name.end()){
        cout<<"false"<<endl;
        return;
    }
    cout<<"true"<<endl;
    Name.erase(name);
    for(int i=0;i<v.size();i++){
        if(v[i].name==name){
            v[i]=v.back();
            v.pop_back();
        }
    }
    shuaxin();
}

void queryVisibility(){
    string name;
    cin>>name;
    if(Name.find(name)==Name.end()){
        cout<<"false"<<endl;
        return;
    }
    windowssss t=findByName(name);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    if(pingmu[i][j]==t.idx){
        cout<<"true"<<endl;
        return;
    }
    cout<<"false"<<endl;

}

void resize(){
    string name;
    int w,h;
    cin>>name>>w>>h;
    if(w<=0||h<=0||Name.find(name)==Name.end()){
        cout<<"false"<<endl;
        return;
    }
    
    for(int i=0;i<v.size();i++){
        if(v[i].name==name){
            v[i].w=w;
            v[i].h=h;
            break;
        }
    }

    cout<<"true"<<endl;
    shuaxin();
}

void move(){
     string name;
    int x,y;
    cin>>name>>x>>y;
    if(Name.find(name)==Name.end()){
        cout<<"false"<<endl;
        return;
    }
    for(int i=0;i<v.size();i++){
        if(v[i].name==name){
            v[i].x=x;
            v[i].y=y;
            break;
        }
    }
    cout<<"true"<<endl;
    shuaxin();
}

struct cmp{
    bool operator ()(const windowssss x,windowssss y){
        if(x.cengji!=y.cengji){
            return x.cengji>y.cengji;
        }
        return x.name<y.name;
    }
};

void queryAllVisibleWindows(){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    vector<windowssss> ans;
    unordered_set<int> s;
    for(int i=x;i<x+w;i++)
    for(int j=y;j<y+h;j++){
        if(pingmu[i][j]==0) continue;
        if(s.find(pingmu[i][j])!=s.end()) continue;
        s.insert(pingmu[i][j]);
        ans.push_back(findById(pingmu[i][j]));
    }
    if(ans.size()==0){
        cout<<"NoVisibleWindow"<<endl;
        return;
    }
    sort(ans.begin(),ans.end(),cmp{});
    string rans="";
    for(int i=0;i<ans.size();i++){
        rans+=ans[i].name+";";
    }
    rans.pop_back();
    cout<<rans<<endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string op;
    while(cin>>op){
        ++cnt;
        if(op=="init"){
            cin>>n>>m;
            if(n<=0||m<=0) cout<<"false"<<endl;else cout<<"true"<<endl;
        }else if(op=="createWindow"){
            create();
        }else if(op=="removeWindow"){
            remove();
        }else if(op=="queryVisibility"){
            queryVisibility();
        }else if(op=="resize"){
            resize();
        }else if(op=="move"){
            move();
        }else if(op=="queryAllVisibleWindows"){
            queryAllVisibleWindows();
        }
        else{
            cout<<"error"<<endl;
            return 0;
        }
    }
    return 0;
}