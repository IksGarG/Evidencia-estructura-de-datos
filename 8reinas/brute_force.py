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

# insertar una reina en el tablero, no evalua si es posible insertarla porque eso lo hace el main
def insert_queen(row, col):
        for i in range(8):
                if board[row][i] == "0":
                        board[row][i] = "X"
                if board[i][col] == "0":
                        board[i][col] = "X"
                for j in range(8):
                        if (i+j) == (row+col) or (i-j) == (row-col):
                                board[i][j] = "X"
        board[row][col] = "Q"
        print("Reina colocada en la posicion: ", row, ",", col)
        print_board()

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

# eliminar una reina del tablero
def remove_queen(row, col):
        board[row][col] = "0"
        for i in range(8):      
                if board[row][i] == "X" and not isThreatened(row, i):
                        board[row][i] = "0"
                if board[i][col] == "X" and not isThreatened(i, col):
                        board[i][col] = "0"
                for j in range(8):
                        if (i+j) == (row+col) or (i-j) == (row-col):
                                if not isThreatened(i, j):
                                        board[i][j] = "0"
        print("Reina removida de la posicion: ", row, ",", col)
        print_board()

def outOfSpaces(row):
        for i in range(row, 8):
                if not "0" in board[i]:
                        return True
        return False
                                
def main():
        for row0 in range(8):
                for col0 in range(8):
                        if not isThreatened(row0, col0):
                                insert_queen(row0, col0)
                        else:
                            remove_queen(row0, col0)
                        for row1 in range(8):
                                for col1 in range(8):
                                        if not isThreatened(row1, col1):
                                                insert_queen(row1, col1)
                                        else:
                                            remove_queen(row1, col1)
                                        for row2 in range(8):
                                                for col2 in range(8):
                                                        if not isThreatened(row2, col2):
                                                                insert_queen(row2, col2)
                                                        else:
                                                                remove_queen(row2, col2)
                                                        for row3 in range(8):
                                                                for col3 in range(8):
                                                                        if not isThreatened(row3, col3):
                                                                                insert_queen(row3, col3)
                                                                        else:
                                                                                remove_queen(row3, col3)
                                                                        for row4 in range(8):
                                                                                for col4 in range(8):
                                                                                        if not isThreatened(row4, col4):
                                                                                                insert_queen(row4, col4)
                                                                                        else:
                                                                                                remove_queen(row4, col4)
                                                                                        for row5 in range(8):
                                                                                                for col5 in range(8):
                                                                                                        if not isThreatened(row5, col5):
                                                                                                                insert_queen(row5, col5)
                                                                                                        else:
                                                                                                                remove_queen(row5, col5)
                                                                                                        for row6 in range(8):
                                                                                                                for col6 in range(8):
                                                                                                                        if not isThreatened(row6, col6):
                                                                                                                                insert_queen(row6, col6)
                                                                                                                        else:
                                                                                                                                remove_queen(row6, col6)
                                                                                                                        for row7 in range(8):
                                                                                                                                for col7 in range(8):
                                                                                                                                        if not isThreatened(row7, col7):
                                                                                                                                                insert_queen(row7, col7)
                                                                                                                                                print("Solucion encontrada!")
                                                                                                                                                print_board()
                                                                                                                                        else:
                                                                                                                                                remove_queen(row7, col7)                                                                                                                                                             
main()