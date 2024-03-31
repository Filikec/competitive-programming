#include <iostream>
#include <list>
#include <iomanip>

using namespace std;


long double Fee;


list<long double> Prices;




int main(){

    int n;

    cin >> n;
    cin >> Fee;
    
    long double prev = 1001;

    bool up = 0;
    for (int i=0;i<n;i++){
        long double tmp;
        cin >> tmp;

        if (up && prev > tmp){
            Prices.push_back(prev);
            up = !up;
        }else if (!up && prev < tmp){
            Prices.push_back(prev);
            up = !up;
        }

        prev = tmp;
    }

    Prices.push_back(prev);

    long double best = 100;

    while (Prices.size()){
        auto buy = Prices.front();
        Prices.pop_front();

        if (Prices.empty()) break;

        auto sell = Prices.front();
        Prices.pop_front();


        best = max(best,(best-Fee)/buy*sell-Fee);
    }

    cout << fixed << setprecision(10) << best << '\n';


    return 0;
}