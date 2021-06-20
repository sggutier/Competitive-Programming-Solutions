limN = 40
ans = [0 for i in range(40+1)]


def precarga():
    global limN, ans
    ans[0] = 1
    ans[1] = 1
    for i in range(2, limN+1):
        ans[i] = ans[i-1] + 4*ans[i-2]


def main():
    precarga()
    tc = int(input())
    for i in range(tc):
        a = int(input())
        print(ans[a])
