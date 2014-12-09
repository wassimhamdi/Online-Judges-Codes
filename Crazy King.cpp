#include<iostream>
#include<iomanip>
#include<queue>
#define mp make_pair
using namespace std;
int result,N,M;
bool BFS(int x1,int y1,int x2,int y2,char graph[109][109]){
    int flag[109][109]={0};
    queue <pair<int,pair<int,int> > >  q;
    q.push(mp(0,mp(x1,y1)));
    flag[x1][y1]=1;
    while(!q.empty()){
        int t=(q.front()).first;
        int a=((q.front()).second).first;
        int b=((q.front()).second).second;
        q.pop();
        if(a<N-1 && graph[a+1][b]=='B'){
            result=t+1;
            return true;
        }
        else if(a<N-1 && !flag[a+1][b] && graph[a+1][b]!='Z'){
            q.push(mp(t+1,mp(a+1,b)));
            flag[a+1][b]=1;
        }
        if(a>0 && graph[a-1][b]=='B'){
            result=t+1;
            return true;
        }
        else if(a>0 && !flag[a-1][b] && graph[a-1][b]!='Z'){
            q.push(mp(t+1,mp(a-1,b)));
            flag[a-1][b]=1;
        }
        if(b<M-1 && graph[a][b+1]=='B'){
            result=t+1;
            return true;
        }
        else if(b<M-1 && !flag[a][b+1] && graph[a][b+1]!='Z'){
            q.push(mp(t+1,mp(a,b+1)));
            flag[a][b+1]=1;
        }
        if(b>0 && graph[a][b-1]=='B'){
            result=t+1;
            return true;
        }
        else if(b>0 && !flag[a][b-1] && graph[a][b-1]!='Z'){
            q.push(mp(t+1,mp(a,b-1)));
            flag[a][b-1]=1;
        }
        if(a<N-1 && b<M-1 && graph[a+1][b+1]=='B'){
            result=t+1;
            return true;
        }
        else if(a<N-1 && b<M-1 && !flag[a+1][b+1] && graph[a+1][b+1]!='Z'){
            q.push(mp(t+1,mp(a+1,b+1)));
            flag[a+1][b+1]=1;
        }
        if(a<N-1 && b>0 && graph[a+1][b-1]=='B'){
            result=t+1;
            return true;
        }
        else if(a<N-1 && b>0 && !flag[a+1][b-1] && graph[a+1][b-1]!='Z'){
            q.push(mp(t+1,mp(a+1,b-1)));
            flag[a+1][b-1]=1;
        }
        if(a>0 && b<M-1 && graph[a-1][b+1]=='B'){
            result=t+1;
            return true;
        }
        else if(a>0 && b<M-1 && !flag[a-1][b+1] && graph[a-1][b+1]!='Z'){
            q.push(mp(t+1,mp(a-1,b+1)));
            flag[a-1][b+1]=1;
        }
        if(a>0 && b>0 && graph[a-1][b-1]=='B'){
            result=t+1;
            return true;
        }
        else if(a>0 && b>0 && !flag[a-1][b-1] && graph[a-1][b-1]!='Z'){
            q.push(mp(t+1,mp(a-1,b-1)));
            flag[a-1][b-1]=1;
        }
    }
    return false;
}
int main(){
    int T;
    cin>>T;
    while(T>0){
        --T;
        cin>>N>>M;
        result=0;
        char c;
        char graph[109][109]={'.'};
        int x1,y1,x2,y2;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cin.get(c);
                if(c=='\n'){
                    cin.get(c);
                }
                if(c=='B'){
                    graph[i][j]='B';
                    x2=i;
                    y2=j;
                }
                else if(c=='A'){
                    graph[i][j]='A';
                    x1=i;
                    y1=j;
                }
                else if(c=='.' && graph[i][j]!='Z'){
                    graph[i][j]='.';
                }
                else if(c=='Z'){
                    graph[i][j]='Z';
                    if(i>=1 && j<=M-3 && graph[i-1][j+2]!='A' && graph[i-1][j+2]!='B'){
                        graph[i-1][j+2]='Z';
                    }
                    if(i>=1 && j>=2 && graph[i-1][j-2]!='A' && graph[i-1][j-2]!='B'){
                        graph[i-1][j-2]='Z';
                    }
                    if(i<=N-2 && j<=M-3 && graph[i+1][j+2]!='A' && graph[i+1][j+2]!='B'){
                        graph[i+1][j+2]='Z';
                    }
                    if(i<=N-2 && j>=2 && graph[i+1][j-2]!='A' && graph[i+1][j-2]!='B'){
                        graph[i+1][j-2]='Z';
                    }
                    if(i<=N-3 && j>=1 && graph[i+2][j-1]!='A' && graph[i+2][j-1]!='B'){
                        graph[i+2][j-1]='Z';
                    }
                    if(i>=2 && j>=1 && graph[i-2][j-1]!='A' && graph[i-2][j-1]!='B'){
                        graph[i-2][j-1]='Z';
                    }
                    if(i<=N-3 && j<=M-2 && graph[i+2][j+1]!='A' && graph[i+2][j+1]!='B'){
                        graph[i+2][j+1]='Z';
                    }
                    if(i>=2 && j<=M-2 && graph[i-2][j+1]!='A' && graph[i-2][j+1]!='B'){
                        graph[i-2][j+1]='Z';
                    }
                }

            }
            //cin.get(c);
        }
        /*cout<<endl;
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                cout<<graph[i][j];
            }
            cout<<endl;
        }*/
        bool okay=BFS(x1,y1,x2,y2,graph);
        if(!okay){
            cout<<"King Peter, you can't go now!"<<endl;
        }
        else{
            cout<<"Minimal possible length of a trip is "<<result<<endl;
        }
    }
    return 0;
}
