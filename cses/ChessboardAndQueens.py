import sys
# a,b = [int(x) for x in input().split()]
# print(a+b)
"""
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?

Input
The input has eight lines, and each of them has eight characters. Each square is either free (.) or reserved (*).

Output
Print one integer: the number of ways you can place the queens.

Example
Input:

........
........
..*.....
........
........
.....**.
...*....
........
Output:

65
"""

boards = []
# used_row = [0] * 8
used_col = [0] * 8
used_slash = [0] * 16
used_backslash = [0] * 16

for _ in range(8):
    boards.append(sys.stdin.readline().strip())

ans = 0
def search(row):
    global ans
    if row == 8:
        ans += 1
        return
    for col in range(8):
        if boards[row][col] == '*':
            continue
        if used_col[col]:
            continue
        if used_slash[row + col]:
            continue
        if used_backslash[row - col]:
            continue
        
        used_col[col] = 1
        used_slash[row + col] = 1
        used_backslash[row - col] = 1
        
        search(row + 1)
        
        used_col[col] = 0
        used_slash[row + col] = 0
        used_backslash[row - col] = 0

search(0)
print(ans)
