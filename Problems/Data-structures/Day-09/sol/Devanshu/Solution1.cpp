Approach: Simply store the value in the array, mae if-else statements and filter the values.
Time Complexity: O(nq)
Code:​
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int q;
    cin>>n>>q;
    int p[n];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<q;i++){
        char c;
        cin>>c;
        if(c=='!'){
            int k, x;
            cin>>k>>x;
            p[k-1]=x;
        }
        else if(c=='?'){
            int a,b,count=0;
            cin>>a>>b;
            for(int i=0;i<n;i++){
                if(p[i]>=a && p[i]<=b){
                    count++;
                }
            }
            cout<<count<<endl;
        }
    }
}
