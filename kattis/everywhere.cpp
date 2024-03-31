    #include <iostream>
    #include <set>


    using namespace std;

    void solve(){
        set<string> places;

        int n;

        cin >> n;

        for (int i=0;i<n;i++){
            string s;

            cin >> s;

            places.insert(s);
        }

        cout << places.size() << "\n";
    }

    int main(){
        int c;

        cin >> c;

        for (int i=0;i<c;i++){
            solve();
        }



        return 0;
    }