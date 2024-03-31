#include <iostream>
#include <unordered_map>


using namespace std;

void work(int c){
    int n;
    
    unordered_map<int,int> invited;
    
    cin >> n;

    for (int i=0;i<n;i++){
        int tmp; \
        cin >> tmp;
        invited[tmp]++; 
    } 


    int wrong = 0;
    for (auto p : invited){
        if (p.second%2){
            wrong = p.first;
            break;
        }
    }
    cout << "Case #" << c << ": " << wrong << '\n';

}


int main(){


    int cases;


    cin >> cases;


    for (int i=0;i<cases;i++){
        work(i+1);
    }

    return 0;
}