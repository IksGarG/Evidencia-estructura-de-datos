board = [
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"],
        ["0","0","0","0","0","0","0","0"]
        ]

# imprimir el tablero
def print_board():
    for row in board:
        print(row)

# evaluar si una posicion esta amenazada por otra reina, para fines practicos
def isThreatened(row, col):
        for i in range(8):
                if board[row][i] == "Q" or board[i][col] == "Q":
                        return True
                for j in range(8):
                        if (i+j) == (row+col) or (i-j) == (row-col):
                                if board[i][j] == "Q":
                                        return True
        return False

def check(row, col):
        if (isThreatened(row, col)):
                board[row][col] = "0"
        else:
                board[row][col] = "Q"
                                
def main():
        for col0 in range(8):
                check(0, col0)
                for col1 in range(8):
                        check(1, col1)
                        for col2 in range(8):
                                check(2, col2)
                                for col3 in range(8):
                                        check(3, col3)
                                        for col4 in range(8):
                                                check(4, col4)
                                                for col5 in range(8):
                                                        check(5, col5)
                                                        for col6 in range(8):
                                                                check(6, col6)
                                                                for col7 in range(8):
                                                                        check(7, col7)
        print_board()

main()