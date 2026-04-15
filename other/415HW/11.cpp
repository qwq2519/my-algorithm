#include<bits/stdc++.h>
using namespace std;
const int N=10007;
int n,maxH;
string now;
list<string> history;

void print(){
    cout<<endl<<"---------"<<endl;
    for(auto it:history){
        cout<<it<<' ';
    }
    cout<<endl<<"---------"<<endl<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>maxH;
    now="Blank";
    history.push_back(now);
    auto it=history.begin();

    string op,x;
    for(int i=1;i<=n;i++)
    {
        //  cout<<i<<"步执行前  :"<<*it<<endl;
        cin>>op;
        if(op=="visit"){
            cin>>x;
            while(next(it)!=history.end()){
                history.pop_back();
            }
            history.push_back(x);
            it=prev(history.end());
            while(history.size()>maxH){
                history.pop_front();
            }
        }else if(op=="back"){
           if(it!=history.begin()){
            it=prev(it);
           }
        }else if(op=="forward"){
           if(next(it)!=history.end()){
                it=next(it);
           }
        }else{
            cout<<*it<<endl;
        }       
        //  cout<<i<<"步执行完成"<<*it<<endl;
    }
    return 0;
}