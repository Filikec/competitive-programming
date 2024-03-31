#include <iostream>
#include <unordered_map>
#include <list>


#define DIV 300

using namespace std;


typedef struct node{
    struct node *p[26];
    int count;
} Node;


Node Nodes[1000000], Root[150];
int Used;
unordered_map<string,int> Before;
string Words[30000];

void add_word(string *word, int index){
    Node *curr = &Root[index];

    for (int i=0;i<word->size();i++){
        if (curr->p[word->at(i)-'a'] == NULL){
            Node *new_node = &Nodes[Used++];
            for (int i=0;i<26;i++){
                new_node->p[i] = NULL;
            } 
            new_node->count = 1;
            curr->p[word->at(i)-'a'] = new_node;
            curr = new_node;
        }else{
            curr = curr->p[word->at(i)-'a'];
            curr->count++;
        }
    }
}

int get_opers(string *word,int index){
    Node *current = &Root[index];
    int result = 0;
    for (int i=0;i<word->size() && current->p[word->at(i)-'a'] != NULL;i++){
        int plus = 0;
        current = current->p[word->at(i)-'a'];
        plus = current->count;
        result += plus;
    }
    return result;
}

int get_prefix(string *s1, string *s2){
    int i = 0;
    while (i<s1->size()&&i<s2->size()&&s1->at(i)==s2->at(i)) i++;
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=0;i<150;i++){
        for (int j=0;j<26;j++){
            Root[i].p[j] = NULL;
        }
    }
    

    int n;

    cin >>n;

    for (int i=0;i<n;i++){
        cin >> Words[i];
        add_word(&Words[i],i/DIV);
        Before.insert(make_pair(Words[i],i));
    }

    int q;

    cin >> q;
    for (int i=0;i<q;i++){
        string w;
        cin >> w;
        int opers = 0;
        if (Before.count(w)){
            opers += Before[w]+1;
        }else{
            opers += n;
        }
        int index = opers;
        int block = (opers-1)/DIV;

        for (int i=0;i<block;i++){
            opers += get_opers(&w,i);
        }
        for (int j=block*DIV;j<index;j++){
            opers += get_prefix(&w, &Words[j]);
        }
        cout << opers << "\n";
    }



    return 0;
}