#include <iostream>
#include <vector>

using namespace std;


typedef struct ins{
    string instruction;
    inline bool operator==(struct ins a){
        return (a.instruction == instruction);
    }
} Ins;



int find_string(vector<Ins> s1, vector<Ins> s2){
    vector<int> indexes;
    indexes.reserve(s2.size());

    indexes.push_back(0);
    cout << "0 ";
    for (int i=1;i<s2.size();i++){
        if (s2[i] == s2[indexes[i-1]] || s2[i].instruction == "?" || s2[indexes[i-1]].instruction == "?"){
            indexes.push_back(indexes[i-1]+1);
        }else{
            indexes.push_back((s2[i]==s2[0]));
        }
        cout << indexes.back() << ' ';
    }
    cout << '\n';

    
    int curr = 0, index = 0, count =0;
    while (curr+index < s1.size()){
        cout << curr+index << '\n';
        if (s1[curr+index] == s2[index] || s1[curr+index].instruction == "?" || s2[index].instruction == "?"){
            index++;
            if (index == s2.size()){
                count++;
                curr += index-indexes[index];
                index = indexes[index];
            }
        }else{
            if (index){
                curr += index-indexes[index-1];
                index = indexes[index-1];
            }else{
                curr++;
            }
            
        }
        
    }

    return count;
}



Ins get_ins(){
    Ins new_ins;
    char c = getchar();
    new_ins.instruction += c;
    if (c != '?'){
        getchar();
        new_ins.instruction += getchar();
    }
    getchar();
    return new_ins;
}

int main(){
    int n1,n2;
    vector<Ins> s1, s2;
    cin >> n1 >> n2;
    getchar();
    for (int i=0;i<n1;i++){
        Ins next = get_ins();
        s1.push_back(next);
    }

    for (int i=0;i<n2;i++){
        Ins next = get_ins();
        s2.push_back(next);
    }

    cout << find_string(s1,s2) << "<\n";

}

/*
abcadabcabc
abcabc
*/