import time
start_time = time.time()
board = [
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ["·","·","·","·","·","·","·","·"],
        ]

# imprimir el tablero
def print_board():
    for row in board:
        print(row)
    print("")

# evaluar si una posicion esta amenazada por otra reina, para fines practicos
def conflict(row, col):
        for i in range(8):
                if board[i][col] == "Q" and i != row:
                        return True
                for j in range(8):
                        if ((i+j) == (row+col) or (i-j) == (row-col)) and (i != row and j != col):
                                if board[i][j] == "Q":
                                        return True
        return False

def insert(row, col):
        board[row][col] = "Q"
        board[row][col-1] = "·"

def main():
        for col0 in range(8):
                insert(0, col0)
                for col1 in range(8):
                        insert(1, col1)
                        for col2 in range(8):
                                insert(2, col2)
                                for col3 in range(8):
                                        insert(3, col3)
                                        for col4 in range(8):
                                                insert(4, col4)
                                                for col5 in range(8):
                                                        insert(5, col5)
                                                        for col6 in range(8):
                                                                insert(6, col6)
                                                                for col7 in range(8):
                                                                        insert(7, col7)
                                                                        if not conflict(0, col0) and not conflict(1, col1) and not conflict(2, col2) and not conflict(3, col3) and not conflict(4, col4) and not conflict(5, col5) and not conflict(6, col6) and not conflict(7, col7):
                                                                                print("found!")
                                                                                print_board()
                                                                                print("--- %s seconds ---" % (time.time() - start_time))
                                                                                quit()

main()