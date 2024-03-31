#include <iostream>
#include <algorithm>

using namespace std;

int Birds[20002];

bool comp(int a, int b){
    return a < b;
}

int main(){
    int l,d,n,count;

    cin >> l >> d >> n;

    for (int i=1;i<=n;i++){
        scanf("%d",&Birds[i]);
    }

    Birds[0] = 6-d;
    Birds[n+1] = l-6+d;

    sort(Birds,Birds+n+2,comp);

    count = 0;
    for (int i=0;i<=n;i++){
        int dist = Birds[i+1]-Birds[i]-2*d;
        if (!dist){
            count++;
        }else if (dist > 0){
            count++;
            count += dist/d;
        }
        
    }

    cout << count << "\n";

    return 0;
}