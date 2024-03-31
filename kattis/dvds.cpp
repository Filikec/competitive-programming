#include <iostream>

using namespace std;

int get_int(){
    char c;
    int n=0;
    while ((c=cin.get())){
        if (c=='\n' || c ==' '){
            return n;
        }
        n = n*10+(c-'0');
    }
    return n;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n, cases;

    cases = get_int();
    for (int j=0;j<cases;j++){
        n = get_int();

        int curr,operations=0,comp = 1;
        for (int i=0;i<n;i++){
            curr = get_int();
            int comparison = curr==comp;
            comp += comparison;
            operations += !comparison;
        }
        cout << operations << '\n';
    }

    return 0;
}