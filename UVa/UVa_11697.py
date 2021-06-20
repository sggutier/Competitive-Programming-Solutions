#!/env/python 3


def encrypt(table, rows, cols, line):
    line = ''.join(line.split()).upper()
    n = len(line)
    i = 0
    ans = ""
    while i < n:
        if i + 1 == n or line[i] == line[i+1]:
            a = line[i]
            b = 'X'
            i -= 1
        else:
            a, b = (line[i], line[i+1])
        if rows[a] == rows[b]:
            a = table[rows[a]][(cols[a] + 1) % 5]
            b = table[rows[b]][(cols[b] + 1) % 5]
        elif cols[a] == cols[b]:
            a = table[(rows[a] + 1) % 5][cols[a]]
            b = table[(rows[b] + 1) % 5][cols[b]]
        else:
            a, b = (table[rows[a]][cols[b]], table[rows[b]][cols[a]])
        ans = ans + a + b
        i += 2
    return ans


def makeTab(line):
    line = (line + "abcdefghijklmnoprstuvwxyz").upper()
    rows = {}
    cols = {}
    table = [['' for i in range(5)] for j in range(5)]
    cnt = 0
    for c in line:
        if not c.isalpha() or c in rows:
            continue
        table[cnt // 5][cnt % 5] = c
        rows[c] = cnt // 5
        cols[c] = cnt % 5
        cnt += 1
    return [table, rows, cols]


def main():
    tc = int(input())
    for i in range(tc):
        print(encrypt(*(makeTab(input()) + [input()])))


main()
