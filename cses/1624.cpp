#include <bits/stdc++.h>

using namespace std;

char G[8][8];

int C;

list<list<int>> solutions = {{0,12,23,29,34,46,49,59},
{0,13,23,26,38,43,49,60},
{0,14,19,29,39,41,52,58},
{0,14,20,31,33,43,53,58},
{1,11,21,31,34,40,54,60},
{1,12,22,24,34,47,53,59},
{1,12,22,27,32,47,53,58},
{1,13,16,30,35,47,50,60},
{1,13,23,26,32,43,54,60},
{1,14,18,29,39,44,48,59},
{1,14,20,31,32,43,53,58},
{1,15,21,24,34,44,54,59},
{2,8,22,28,39,41,51,61},
{2,12,17,31,32,46,51,61},
{2,12,17,31,37,43,54,56},
{2,12,22,24,35,41,55,61},
{2,12,23,27,32,46,49,61},
{2,13,17,28,39,40,54,59},
{2,13,17,30,32,43,55,60},
{2,13,17,30,36,40,55,59},
{2,13,19,24,39,44,54,57},
{2,13,19,25,39,44,54,56},
{2,13,23,24,35,46,52,57},
{2,13,23,24,36,46,49,59},
{2,13,23,25,35,40,54,60},
{2,14,17,31,36,40,51,61},
{2,14,17,31,37,43,48,60},
{2,15,19,30,32,45,49,60},
{3,8,20,31,33,46,50,61},
{3,8,20,31,37,42,54,57},
{3,9,20,31,37,40,50,62},
{3,9,22,26,37,47,48,60},
{3,9,22,26,37,47,52,56},
{3,9,22,28,32,47,53,58},
{3,9,23,28,38,40,50,61},
{3,9,23,29,32,42,52,62},
{3,13,16,28,33,47,50,62},
{3,13,23,25,38,40,50,60},
{3,13,23,26,32,46,52,57},
{3,14,16,31,36,41,53,58},
{3,14,18,31,33,44,48,61},
{3,14,20,25,37,40,50,63},
{3,14,20,26,32,45,55,57},
{3,15,16,26,37,41,54,60},
{3,15,16,28,38,41,53,58},
{3,15,20,26,32,46,49,61},
{4,8,19,29,39,41,54,58},
{4,8,23,27,33,46,50,61},
{4,8,23,29,34,46,49,59},
{4,9,19,29,39,42,48,62},
{4,9,19,30,34,47,53,56},
{4,9,21,24,38,43,55,58},
{4,9,23,24,35,46,50,61},
{4,10,16,29,39,41,51,62},
{4,10,16,30,33,47,53,59},
{4,10,23,27,38,40,53,57},
{4,14,16,26,39,45,51,57},
{4,14,16,27,33,47,53,58},
{4,14,17,27,39,40,50,61},
{4,14,17,29,34,40,51,63},
{4,14,17,29,34,40,55,59},
{4,14,19,24,34,47,53,57},
{4,15,19,24,34,45,49,62},
{4,15,19,24,38,41,53,58},
{5,8,20,25,39,42,54,59},
{5,9,22,24,34,44,55,59},
{5,9,22,24,35,47,52,58},
{5,10,16,30,36,47,49,59},
{5,10,16,31,35,41,54,60},
{5,10,16,31,36,41,51,62},
{5,10,20,30,32,43,49,63},
{5,10,20,31,32,43,49,62},
{5,10,22,25,35,47,48,60},
{5,10,22,25,39,44,48,59},
{5,10,22,27,32,47,49,60},
{5,11,16,28,39,41,54,58},
{5,11,17,31,36,46,48,58},
{5,11,22,24,34,44,49,63},
{5,11,22,24,39,41,52,58},
{5,15,17,27,32,46,52,58},
{6,8,18,31,37,43,49,60},
{6,9,19,24,39,44,50,61},
{6,9,21,26,32,43,55,60},
{6,10,16,29,39,44,49,59},
{6,10,23,25,36,40,53,59},
{6,11,17,28,39,40,50,61},
{6,11,17,31,37,40,50,60},
{6,12,18,24,37,47,49,59},
{7,9,19,24,38,44,50,61},
{7,9,20,26,32,46,51,61},
{7,10,16,29,33,44,54,59},
{7,11,16,26,37,41,54,60}};

int main(){
    set<int> s;
    char c;
    for (int i=0;i<8;i++)
        for (int j=0;j<8;j++){
            cin >> c;
            if (c=='*') s.insert(i*8+j);
        }

    int count=0;
    for (auto l : solutions){
        count += all_of(l.begin(),l.end(),[&](int a){return !s.contains(a);});
    }
    cout << count << '\n';
}