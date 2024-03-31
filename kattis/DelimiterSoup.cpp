#include <iostream>
#include <list>

using namespace std;


bool matches(char a, char b){
    if (a == ')') return (b == '(');
    if (a == '}') return (b == '{');
    if (a == ']') return (b == '[');
}


int main(){
    int n;
    cin >> n;
    string s;
    cin.get();
    getline(cin,s);


    list<char> stack;

    for (int i=0;i<s.size();i++){
        auto c = s[i];

        if (c == ']' || c == '}' || c == ')'){
            if (stack.size() && matches(c,stack.front())){
                stack.pop_front();
            }else{
                cout << c << ' ' << i <<  '\n';
                return 0; 
            }
        }else if (c == '(' || c == '{' || c == '['){
            stack.push_front(c);
        }
    }

    cout << "ok so fa\n";
}