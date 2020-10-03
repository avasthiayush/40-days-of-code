//  Written By Dheeraj Maurya
// Btech IET LUCKNOW (2018 - 2022)
// KMP
// problem link: https://cses.fi/problemset/task/1753/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lps[1000005];
 
int main() {
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   ll t,n,i,len,m;
   string s,a;
   cin>>s>>a;
   n = s.size(); m = a.size();
   i=1,len=0;
   lps[0]=0;
   // making lps array
   while(i<m){
     if(a[i]==a[len]){
        lps[i++] = ++len;
     }
     else{
        if(len==0)++i;
        else len = lps[len-1];
     }
   }
 
   ll ans = 0;
   i=len=0;
   while(i<n){
     if(s[i]==a[len]){
        ++i; ++len;
     }
     if(len==m){
        ++ans; len = lps[len-1];
     }
     else if(i<n && s[i] != a[len] ){
        if(len==0)++i;
        else len = lps[len-1];
     }
   }
 
   cout<<ans;
}