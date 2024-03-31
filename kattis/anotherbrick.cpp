#include <iostream>


using namespace std;


int main(){
    int h,w,n;
    
    cin >> h >> w >> n;
    int curr_w, curr_h;

    for (curr_h=0;curr_h<h;curr_h++){
        for (curr_w=0;curr_w<w;){
            int l;
            cin >> l;
            curr_w += l;
        }
        if (curr_w > w) break;
    }

    if (curr_h != h || curr_w != w){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    return 0;
}