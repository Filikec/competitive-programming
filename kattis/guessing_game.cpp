#include <iostream>
#include <string>



using namespace std;

void solve(int n){
    int flag = 0, low = 0, high = 11;
    string reply;

    getline(cin,reply);
    while (reply.compare("right on")){
        if (!reply.compare("too high")){
            if (n <= low){
                flag = 1;
            }
            high = n;
        }else{
            if (n >= high){
                flag = 1;
            }
            low = n;
        }
        
        cout << n << "what\n";
        getline(cin,reply);
    }
    if (flag){
        printf("Stan is dishonest\n");
    }else{
        printf("Stan may be honest\n");
    }

}

int main(){
    int n;

    while (true){
        cin >> n;
        if (n == 0){
            break;
        }
        solve(n);
    }
    return 0;
}