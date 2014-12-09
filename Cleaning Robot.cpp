#include<iomanip>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define mp make_pair
char graph[25][25]={'.'};

int N,M;
int nbp;

int BFS1(int x1,int x2){
    int result=0;
    int flag[25][25]={0};
    queue<int> q1,q2;
    q1.push(x1);
    q2.push(x2);
    flag[x1][x2]=0;
    while(!q1.empty()){
        int a=q1.front(),b=q2.front();
        q1.pop();
        q2.pop();
        if(graph[a][b]=='*'){
            ++result;
        }
        if(a<N-1 && graph[a+1][b]!='x' && !flag[a+1][b]){
            q1.push(a+1);
            q2.push(b);
            flag[a+1][b]=1;
        }
        if(a>0 && graph[a-1][b]!='x' && !flag[a-1][b]){
            q1.push(a-1);
            q2.push(b);
            flag[a-1][b]=1;
        }
        if(b<M-1 && graph[a][b+1]!='x' && !flag[a][b+1]){
            q1.push(a);
            q2.push(b+1);
            flag[a][b+1]=1;
        }
        if(b>0 && graph[a][b-1]!='x' && !flag[a][b-1]){
            q1.push(a);
            q2.push(b-1);
            flag[a][b-1]=1;
        }
    }
    return result;
}

int BFS2(int x1,int x2){
    int result=0;
    queue<pair<int,pair<int,int> > > q;
    q.push(mp(0,mp(x1,x2)));
    while(!q.empty()){
        int a=((q.front()).second).first,b=((q.front()).second).second;
        int t=(q.front()).first;
        if(graph[a][b]=='*'){

        }
        if(a<N-1 && graph[a+1][b]!='x' && !flag[a+1][b]){
            q.push(mp(t+1,mp(a+1,b)));
        }
        if(a>0 && graph[a-1][b]!='x' && !flag[a-1][b]){
            q.push(mp(t+1,mp(a-1,b)));
        }
        if(b<M-1 && graph[a][b+1]!='x' && !flag[a][b+1]){
            q.push(mp(t+1,mp(a,b+1)));
        }
        if(b>0 && graph[a][b-1]!='x' && !flag[a][b-1]){
            q.push(mp(t+1,mp(a,b-1)));
        }
    }
}

int main(){
    while(1){
        cin>>N>>M;
        if(N==0 && M==0){
            break;
        }
        int x,y;
        nbp=0;
        vector <pair<int,int> > v;
        for(int i=0;i<N;++i){
            for(int j=0;;j<M;++j){
                char c;
                cin.get(c);
                if(c=='\n'){
                    cin.get(c);
                }
                graph[i][j]=c;
                if(c=='o'){
                    x=i;
                    y=j;
                }
                if(c=='*'){
                    ++nbp;
                    v.push_back(mp(i,j));
                }
            }
        }
        int can_do=BFS1(x,y);
        if(nbp!=can_do){
            cout<<-1<<endl;
            continue;
        }
    }
    return 0;
}
