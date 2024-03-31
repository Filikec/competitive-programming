#include <iostream>

using namespace std;

int main(){
    int n, bruno =0, adrian = 0, goran = 0;

    cin >> n;

    for (int i=0;i<n;i++){
        char character;
        cin >> character;
        
        int modulo = i%3;

        char sequence_adrian[] = {'A','B','C'};

        if (character == sequence_adrian[modulo]){
            adrian++;
        }

        modulo = i%4;
        char sequence_bruno[] = {'B','A','B','C'};

        if (character == sequence_bruno[modulo]){
            bruno++;
        }

        modulo = i%6;
        char sequence_goran[] = {'C','C','A','A','B','B'};

        if (character == sequence_goran[modulo]){
            goran++;
        }

    }

    int maximum = max(goran,max(bruno,adrian));
    cout << maximum << "\n";
    if (maximum == adrian){
        cout << "Adrian\n";
    }
    if (maximum == bruno){
        cout << "Bruno\n";
    }
    if (maximum == goran){
        cout << "Goran\n";
    }


    return 0;
}