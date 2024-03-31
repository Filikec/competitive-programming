#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;




void solve(){
    string number,source,target;

    cin >> number >> source >> target;
    
    unordered_map<int,int> Base_source,Base_target;

    for (int i=0;i<source.size();i++){
        Base_source[source[i]] = i;
    }

    for (int i=0;i<target.size();i++){
        Base_target[i] = target[i];
    }

    int decimal=0;

    for (int i=number.size()-1;i>=0;i--){
        decimal += Base_source[number[i]]*pow(Base_source.size(),number.size()-1-i);
    }
    string result;
   
    while (decimal){
        result += Base_target[decimal%Base_target.size()];
        decimal /= Base_target.size();
    }
    for (int i=result.size()-1;i>-1;i--){
        cout << result[i];
    }
    cout << '\n';

}

int main(){

    int cases;

    cin >> cases;

    for (int i=0;i<cases;i++){
        cout <<"Case #" << i+1 << ": ";
        solve();
    }


    return 0;
}