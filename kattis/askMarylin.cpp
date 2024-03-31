#include <iostream>


using namespace std;


int main(){
    
    
    for (int i=0;i<1000;i++){
        cout << "A\n";
        
        char d;
        int n;
        int random = rand()%2 + 1;
        
        cin >> d >> n;
        
        if (n) cout << d << '\n';
        else if (d=='A'){
            cout << d+random << '\n';
        }else if (d == 'C'){
            if (random == 1){
                cout << "A\n";
            }else{
                cout << "B\n";
            }
        }else{
            if (random == 1){
                cout << "A\n";
            }else{
                cout << "C\n";
            }
        }
        cin >> d >> d;

    }
}