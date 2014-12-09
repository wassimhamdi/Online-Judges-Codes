#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int s,day,month,hour,min,n;
    int mday=1,mmonth=1,mhour=0,mmin=0;
    int count = 0,earning=0,du=0,last=0;

    scanf("%d",&n);
    for(int i=0; i<n; ++i) {
        scanf("%d %d.%d %d:%d",&s,&day,&month,&hour,&min);
        bool verif=false;

        if(month>mmonth) {
            mday=day;
            mmonth=month;
            mhour=hour;
            mmin=min;
            verif=true;
        }
        if(month==mmonth) {
            if(day>mday) {
                mday=day;
                mhour=hour;
                mmin=min;
                verif=true;
            }
            if(day==mday) {
                if(hour>mhour) {
                    mhour=hour;
                    mmin=min;
                    verif=true;
                }
                if(hour==mhour) {
                    if(mmin<min) {
                        mmin=min;
                        verif=true;

                    }
                }
            }
        }
        //count=s+earning+du;
        if(!verif) {
            if(earning+s+du>=0) {
                cout << 0 << endl;
                earning=earning+s+du;
                du=0;
            }
            if(earning+s+du < 0) {
                cout << earning+s+du << endl;
                du=earning+s+du;
                earning=0;

            }
        }
        if(verif) {
            if(s > 0) {
                cout << du << endl;
                earning+=s;
            }
            if(s<0) {
                cout << du+s+earning << endl;
                du=du+s+earning;
                earning=0;
            }
        }
        //cout << earning << " " << s << " " << du << endl;
    }


    return 0;
}
