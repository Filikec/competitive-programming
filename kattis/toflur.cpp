#include <iostream>
#include <algorithm>

using namespace std;

long long Nums[1000000];


bool cmp(int a, int b){
    return a < b;
}

long long get_int(){
    int result=0;
    char c;
    while ((c=getchar())>='0'){
        result = result*10+c-'0';
    }
    return result;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    n = get_int();

    for (int i=0;i<n;i++){
        Nums[i] = get_int();
    }

    sort(Nums,Nums+n,cmp);

    long long sum = 0;
    for (int i=0;i<n-1;i++){
        sum += (Nums[i]-Nums[i+1])*(Nums[i]-Nums[i+1]);
    }

    printf("%lld\n",sum);

    return 0; 
}