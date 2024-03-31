#include <iostream>
#include <string>

using namespace std;



int main(){


    string line,msg;

    getline(cin,line);


    for (int i=0;i<line.size();i++){

        if (line[i] == '<') msg.pop_back();
        else msg += line[i];

        
    }

    cout << msg << '\n';


    return 0;
}