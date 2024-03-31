#include <iostream>

using namespace std;


long long findNext(long long m, long long &i, long long n){
    long long left,tmp;
    left = 0;
    while (i<n){
        cin>>tmp;
        i++;
        if (tmp == m){
            return left;
        }
        left += tmp;
        if (tmp < m) left=0;
    }
    return 0;
}

void work(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;

    cin >> n >> m;

    long long s=0,tmp,left,right,i;
    left = right = 0, i = 0;
    
    while (i<n){
        cin>>tmp;
        i++;
        if (tmp == m){
            s = max(s,left+right+m);
            left = right;
            right = 0;
        }else if (tmp < m){
            s = max(s,left+right+m);
            right = 0;
            left = findNext(m,i,n);
        }else{
            right += tmp;
        }
    }
    s = max(s,left+right+m);
    cout << s << '\n';
}

int main(){

    int cases;

    cin>>cases;

    for (int i=0;i<cases;i++){
        work();
    }

    return 0;
}