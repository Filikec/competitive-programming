#include <iostream>
#include <algorithm>


using namespace std;

int Seeds[100000];


bool cmp(int a, int  b){
    return a > b;
}

int main(){

    int n;


    cin >> n;

    for (int i=0;i<n;i++){
        scanf("%d",&Seeds[i]);
    }

    sort(Seeds,Seeds+n,cmp);

    int maxi = 0;
    for (int i=0;i<n;i++){
        maxi = max(maxi,Seeds[i]+i+2);
    }

    cout << maxi << "\n";
    return 0;
}