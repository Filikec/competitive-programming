probs = []

tries = int(input())

for i in range(tries):
    prob = input().split(' ')
    prob = float(prob[1])
    probs.append(prob)
probs.sort(reverse=True)

tries = 0
less = 1

for i in probs:
    tries += less
    less -= i

print(round(tries,4))