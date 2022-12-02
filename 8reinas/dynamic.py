N = 8
# NxN matrix with all elements set to 0
board = [["·"]*N for _ in range(N)]

def attack(i, j):
    #checking vertically and horizontally
    for k in range(N):
        if board[i][k]=="Q" or board[k][j] == "Q":
            return True
    #checking diagonally
    for k in range(N):
        for l in range(N):
            if (k+l==i+j) or (k-l == i-j):
                if board[k][l] == "Q":
                    return True
    return False

def N_queens(n):
    if n == 0:
        return True
    for i in range(N):
        for j in range(N):
            if (not(attack(i,j))) and (board[i][j] != "Q"):
                board[i][j] = "Q"
                if N_queens(n-1) == True:
                    return True
                board[i][j] = "·"
    return False
    
N_queens(N)
for i in board:
    print(i)