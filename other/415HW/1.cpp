    #include<bits/stdc++.h>
    using namespace std;
    const int N=1007;
    int n,maxH;
    string now;
    string history[N];
    int l,r;
    int curpointer;

    int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin>>n>>maxH;
        now="Blank";
        history[++r]=now;
        string op,x;
        while(n--){
            cin>>op;
            if(op=="visit"){
                cin>>x;
                history[++r]=x;
                now=x;
                curpointer=r;
                if(r-l==maxH+1){
                    l++;
                }
            }else if(op=="back"){
                if(curpointer>=l+1){
                    curpointer--;
                    history[++r]=now;
                    if(r-l==maxH+1){
                        l++;
                    }
                    now=history[curpointer];
                }
            }else if(op=="forward"){
                if(curpointer!=r){
                    curpointer++;
                    now=history[curpointer];
                    history[++r]=now;
                    if(r-l==maxH+1){
                        l++;
                    }
                }
            }else{
                cout<<now<<'\n';
            }
        }
        return 0;
    }