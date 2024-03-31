#include <iostream>

using namespace std;

int Prices[100001];

int get_int(){
    int r=0;
    char c;

    while ((c=cin.get())!='\n'){
        r = r*10+c-'0';
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.get();
    for (int i=0;i<n;i++){
        int tmp = get_int();
        Prices[tmp]++;
    }

    int curr = 0;

    int sum = 0;
    for (int i=100000;i>0;i--){
        while (Prices[i]){
            Prices[i]--;
            if (curr != 2){
                curr++;
                sum += i;
            }else{
                curr = 0;
            }
        }
    }

    cout << sum << '\n';

    return 0;
}