def parse_input():
    rows, cols, queries_num = list(map(int, input().split()))
    game_map = [list(map(int, input().split())) for i in range(rows)]
    queries = [list(map(int, input().split())) for i in range(queries_num)]
    return rows, cols, queries_num, game_map, queries


def solve_query(rows, cols, game_map, q_row, q_col):
    ans = -10e9
    for r in range(rows - q_row + 1):
        for c in range(cols - q_col + 1):
            tmp = []
            for i in range(q_row):
                for j in range(q_col):
                    tmp.append(game_map[r + i][c + j])
            tmp.sort()
            ans = max(ans, tmp[int((q_row * q_col)/2)])
    return ans


def main():
    (rows, cols, queries_num, game_map, queries) = parse_input()
    for q in queries:
        print(solve_query(rows, cols, game_map, q[0], q[1]))


main()
