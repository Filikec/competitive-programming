#include <stdio.h>

double probabilities[500];

void add(double);

int main(int argc, char **argv){
    int amount, i;
    double probability, less, tries;
    char s[13];

    less = 1.0;
    tries = 0;

    scanf("%d",&amount);

    for (i=0;i<amount;i++){
        scanf("%s",s);
        scanf("%lf",&probability);
        add(probability);
    }

    for (i=0;i<amount;i++){
        tries += less;

        less -= probabilities[i];
    }

    printf("%f\n",tries);

    return 0;
}

void add(double n){
    int i;
    double temp;

    for (i=0;i<500;i++){
        if (probabilities[i] < n){
            temp = probabilities[i];
            probabilities[i] = n;
            break;
        }
    }

    while (probabilities[i] && i < 499){
        i++;

        n = temp;
        temp = probabilities[i];
        probabilities[i] = n;

    }
}
