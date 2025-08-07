import sys
input = sys.stdin.readline


def set_operator(quest):
    global sets

    if quest[0] == 1:
        set_a = sets[quest[1]]
        set_b = sets[quest[2]]

        sets[quest[1]] = set_a.update(set_b)
        sets[quest[2]] = set_b.clear()
        return

    if quest[0] == 2:
        print(len(sets[quest[1]]))
        return

N, Q = int(input().split())
sets = {}
quests = []

for i in range(N):
    cnt, *A = map(int, input().split())
    sets[i + 1] = set(A)

for _ in range(Q):
    q = list(map(int, input().split()))
    set_operator(q)
