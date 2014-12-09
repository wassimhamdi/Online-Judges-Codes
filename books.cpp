 #include <cstdio>
    #include <iostream>
    #include <queue>
    #include <cstring>

    using namespace std;
    #define mp make_pair
    #define pb push_back

    const int MX=100009;
    //priority_queue
    //priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int, int > > >q;

	int dur(int debut,int fin,int* tps){
	if(debut==0) return tps[fin];
		else return (tps[fin]-tps[debut-1]) ;
	}
	
	
	
    int main(){
        int n,t,cmp=0,mx=0;
        cin>>n>>t;
        int val;
		int tps[n];
		cin>>tps[0];
        for(int i=1;i<n;++i){
        cin>>val;
		tps[i]=val+tps[i-1];
        //q.push(mp(i,val));
        }
        int t1=0;
        /*while(!q.empty()){
        //if(!q.empty()){
			int debut=q.top().second;
			while(t1<t&&!q.empty()){
				t1+=q.top().second;
				q.pop();
				++cmp;
            }
			
        }
        if (t1>t) cout<<cmp-1<<endl;
            else cout<<cmp<<endl;*/

	for(int i=0;i<n&&(n-i)>mx;++i){
		int f=n-1; int nb=0;
		int ext=n-1; int intrn=i;
		while(true){
			if(dur(i,f,tps)<t){
				if(f==(int)((f+ext)/2)) {
					break ;
					}
				else {
					intrn=f; 
					f=(int)((f+ext)/2);
				}
			}

			else if (dur(i,f,tps)>t) {
				if((int)((intrn+f)/2)==intrn){
					f--;
					break;
				}
				else ext=f;
			f=(int)(intrn+f)/2;
			}

			else break;
		}
		if(f==i) {if(dur(i,i,tps)>t) nb=0; else nb=f-i+1;}
		else nb=f-i+1;

		if(nb>mx){ mx=nb;}
	}	
	cout<< mx <<endl;

	return 0;
	}
