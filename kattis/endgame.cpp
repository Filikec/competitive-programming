#include <bits/stdc++.h>


using namespace std;


set<pair<int,int>> Moves, Squares;

int main(){
    srand(time(NULL));

    int n;

    cin >> n;


    int ax, ay, bx, by;


    cin >> ax >> ay >> bx >> by;

    Moves.insert(make_pair(0,0));
    for (int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;

        Moves.insert(make_pair(x,y));
    }

    for (auto move : Moves){
        pair<int,int> square = {ax,ay};

        square.first += move.first;
        square.second += move.second;

        Squares.insert(square);
    }


    for (auto square : Squares){
        pair<int,int> needed = {bx-square.first,by-square.second};

        if (Moves.count(needed)){
            cout << "Alice wins\n";
            return 0;
        }
    }

    Squares.clear();

    for (auto move : Moves){
        pair<int,int> square = {bx,by};

        square.first += move.first;
        square.second += move.second;
        Squares.insert(square);
    }

    if (n <= 3){
        set<pair<int,int>> squares2;
        for (auto square : Squares){
            for (auto move : Moves){
                pair<int,int> next = {square.first+move.first,square.second+move.second};
                squares2.insert(next);
            }
        }

        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                pair<int,int> square = {i,j};
                if (!squares2.count(square)){
                    cout << "tie " << i << ' ' << j << "\n";
                    return 0;
                }
            }
        }

        cout << "Bob wins\n";
        return 0;
    }

    set<pair<int,int>> used;

    while (true){
        int x = (((long long)rand()) * ((long long) rand()))%(n+1);
        int y = (((long long)rand()) * ((long long) rand()))%(n+1);

        pair<int,int> curr_square = make_pair(x,y);

        if (used.count(curr_square) || x <= 0 || y <= 0 || x > n || y > n) continue;
        used.insert(curr_square);

        for (auto square : Squares){
            pair<int,int> needed = {x-square.first,y-square.second};

            if (!Moves.count(needed)){
                cout << "tie " << x << ' ' << y;
                return 0;
            }
        }
    }

    return 0;   
}