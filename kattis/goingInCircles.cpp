#include <iostream>
#include <iomanip>
#include <ctime>
#include <list>

#define MOVES 80

using namespace std;


int mask[MOVES];

bool possible(list<int> &lights){
    int i=0;
    for (auto l:lights){
        if (l!=mask[i++]) return false;
    }
    return true;
}

int main(){
    srand(time(NULL));

    for (int i=0;i<MOVES;i++) mask[i] = rand()%2;

    int light;
    int count=0;

    for (int i=0;i<MOVES;i++){
        cin >> light;
        if (mask[i]!=light){
            cout << "? flip" << endl;
            cin >> light;
        }
        cout << "? right" << endl;
    }
    cin >> light;
    bool less=false;
    for (int i=MOVES-1;i>-1;i--){
        cout << "? left"  << endl;
        cin >> light;
        if (mask[i]!=light){
            less=true;
            break;
        }
    }

    if (less){
        cout << "? flip" << endl;
        cin >> light; 
        int cur;
        for (int i=0;i<MOVES;i++){
            cout << "? right" << endl;
            cin >> cur;
            if (light!=cur){
                cout << "? flip" << endl;
                cin >> cur; 
            }
        }
        cout << "? flip" << endl;
        cin >> cur;
        while (true){
            count++;
            cout <<"? right" << endl;
            cin >> cur;
            if (cur == !light) break;
        }
        cout << "! " << count << '\n';
        
        return 0;
    }

    list<int> lights;
    for (int i=0;i<MOVES;i++) lights.push_back(-1);
    for (int i=0;i<MOVES-1;i++){
        cout << "? right" << endl;
        cin >> light;
    }
    while (!possible(lights)){
        count++;
        cout << "? right" << endl;
        cin >> light;
        lights.pop_front();
        lights.push_back(light);
    }

    cout << "! " << count << '\n';

    return 0;
}

