#include <iostream>


using namespace std;


int Count[10];

int main(){

    int c;

    while ((c=getchar())!='\n'){
        Count[c-'0']++;
    }

    int least_d, least = 1001;
    for (int i=0;i<10;i++){
        if (least > Count[i] || (least == Count[i] && !least_d)){
            least_d = i;
            least = Count[i];
        }
    }

   
    if (!least_d) cout << 1;
    while (least-->=0){
        cout << least_d;
    }
    cout << '\n';
    


    return 0;
}