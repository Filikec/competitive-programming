#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> Set;
#include <iostream>


int main(){
    int n,m;
    

    cin >> n >> m;
    while (n || m){
        int result = 0;
        getchar();
        for (int i=0;i<n;i++){
            int cd=0;
            char c;
            while((c=getchar())!='\n'){
                cd = cd*10+(c-'0');
            }
            Set.insert(cd);
        }

        for (int i=0;i<m;i++){
            int cd=0;
            char c;
            while((c=getchar())!='\n'){
                cd = cd*10+(c-'0');
            }
            result += Set.count(cd);
        }

        cout << result << "\n";
        cin >> n >> m;
        Set.clear();
    }

    


    


    return 0;
}