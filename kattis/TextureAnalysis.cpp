#include <iostream>
#include <string>

using namespace std;


int main(){

    string line;

    int c = 1;
    while (getline(cin,line)){
        
        if (line == "END") break;

        int prev = 0;
        int space = 0;
        bool started = false;
        bool solved = false;
        for (int i=1;i<line.size();i++){
            if (line[i] != '*') space++;
            else if (started){
                if (space != prev){
                    cout << c++ << " NOT EVEN\n";
                    solved = 1;
                    break;
                }
                prev = space;
                space = 0;
            }else{
                started = true;
                prev = space;
                space = 0;
            }
        }
        if (!solved) cout << c++ << " EVEN\n";
    }

    return 0;
}