#include <iostream>

using namespace std;


int R,C;
int Count[100];

int get_line(){
    int count = 0, length = 0;
    char c;
    while ((c=cin.get())!='\n'&&!cin.eof()){
        length++;
        if (c=='*') count++;
    }
    if (cin.eof()) return -2;
    if (!length) return -1;
    if (!C) C = length;
    return count;
}

bool get_sqaure(){
    int tmp=1;
    R = 0;
    C = 0;
    while ((tmp=get_line())>=0){
        Count[R] = tmp;
        R++;
    }
    if (tmp == -2) return false;
    return true;
}

void print_square(){
    int right=0;

    for (int i=0;i<R;i++){
        for (int j=0;j<C-right-Count[i];j++){
            cout << '.';
        }
        for (int j=0;j<Count[i];j++){
            cout << '*';
        }
        for (int j=0;j<right;j++){
            cout << '.';
        }
        right += Count[i];
        cout << '\n';
    }
    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (get_sqaure()){
        print_square();
    }
    int right=0;

    for (int i=0;i<R;i++){
        for (int j=0;j<C-right-Count[i];j++){
            cout << '.';
        }
        for (int j=0;j<Count[i];j++){
            cout << '*';
        }
        for (int j=0;j<right;j++){
            cout << '.';
        }
        right += Count[i];
        cout << '\n';
    }

    return 0;
}