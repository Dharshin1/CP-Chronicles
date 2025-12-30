#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    stack<int> st;
    long long res=0;
    
    st.push(0); // inserting first element (always a '(')
    for(int i=1; i<n; i++){
        // trying to close a pair immediately to minimize distance (greedy)
        if(s[i] == ')' || (s[i] == '_' && !st.empty())){
            res += (i-st.top());
            st.pop();
        }
        else{
            st.push(i);
        }
    }

    cout<<res<<endl;
}

// Time Complexity: O(N)
// Space Complexity: O(N) (string + stack)

int main(int argc, char const *argv[])
{
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}