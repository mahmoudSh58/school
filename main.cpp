#include <bits/stdc++.h>
using namespace std;
int a[600][600];
int a;

int main(){
    int n,m;
    n = samples.size();
    m = samples[0].size();
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            samples[i][j] += samples[i][j-1];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            samples[j][i] += samples[j-1][i];
        }
    }


    int ans = 0,f=min(n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int ff = f - max(i,j);
            for(int k=1;k<=ff;k++){
                int d = samples[i+k-1][j+k-1];
                if(j-1>=0) d-= samples[i+k-1][j-1];
                if(i-1>=0) d-= samples[i-1][j+k-1];
                if(j-1>=0 && i-1>=0) d+= samples[i-1][j-1];
                if(d == k*k){
                    ans = max(ans,k);
                }
            }
        }
    }

    return ans;
}
