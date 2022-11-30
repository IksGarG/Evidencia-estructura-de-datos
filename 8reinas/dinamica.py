## comente todo lo mio por si sirve para la parte de programacion dinamica

# # como strings para que al imprimir el tablero se vea del mismo tamaño
# board = [
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"],
#         ["0","0","0","0","0","0","0","0"]
#         ]

# # imprimir el tablero
# def print_board():
#     for row in board:
#         print(row)

# # insertar una reina en el tablero, no evalua si es posible insertarla porque eso lo hace el main
# def insert_queen(row, col):
#         for i in range(8):
#                 if board[row][i] == "0":
#                         board[row][i] = "X"
#                 if board[i][col] == "0":
#                         board[i][col] = "X"
#                 for j in range(8):
#                         if (i+j) == (row+col) or (i-j) == (row-col):
#                                 board[i][j] = "X"
#         board[row][col] = "Q"
#         print("Reina colocada en la posicion: ", row, ",", col)
#         print_board()

# # evaluar si una posicion esta amenazada por otra reina, para fines practicos
# def isThreatened(row, col):
#         for i in range(8):
#                 if board[row][i] == "Q" or board[i][col] == "Q":
#                         return True
#                 for j in range(8):
#                         if (i+j) == (row+col) or (i-j) == (row-col):
#                                 if board[i][j] == "Q":
#                                         return True
#         return False

# # eliminar una reina del tablero
# def remove_queen(row, col):
#         board[row][col] = "0"
#         for i in range(8):      
#                 if board[row][i] == "X" and not isThreatened(row, i):
#                         board[row][i] = "0"
#                 if board[i][col] == "X" and not isThreatened(i, col):
#                         board[i][col] = "0"
#                 for j in range(8):
#                         if (i+j) == (row+col) or (i-j) == (row-col):
#                                 if not isThreatened(i, j):
#                                         board[i][j] = "0"
#         print("Reina removida de la posicion: ", row, ",", col)
#         print_board()

# def outOfSpaces(row):
#         for i in range(row, 8):
#                 if not "0" in board[i]:
#                         return True
#         return False
                                
# def main(row, col, cameBack):
#         if outOfSpaces(row):
#                 main(row-1, )
#                 if cameBack:
#                         for i in range(8):
#                                 if board[row][i] == "Q":
#                                         col = i
#                                         break
#                         remove_queen(row, col)
#                         col += 1
#                         if col < 8:
#                                 while col < 8:
#                                         if board[row][col] == "0":
#                                                 insert_queen(row, col, False)
#                                                 main(row+1, 0, False)
#                                         col += 1
#                         else:
#                                 main(row-1, 0, True)
                
#         # if row < 8:
#         #         while col < 8:
#         #                 if cameBack:
#         #                         for i in range(8):
#         #                                 if board[row][i] == "Q":
#         #                                         remove_queen(row, i)
#         #                                         col = i+1
#         #                                         break
#         #                         if board[row][col] == "0":
#         #                                 insert_queen(row, col)
#         #                                 main(row+1, 0, False)
#         #                 else if board[row][col] == "0":
#         #                         insert_queen(row, col)
#         #                         if outOfSpaces(row+1):
#         #                                 remove_queen(row, col)
#         #                                 stillHasSpaces = False
#         #                                 for i in range(col, 8):
#         #                                         if board[row][i] == "0":
#         #                                                 stillHasSpaces = True
#         #                                                 break
#         #                                 if stillHasSpaces:
#         #                                         main(row, col+1, False)
#         #                                 else:
#         #                                         main(row-1, 0, True)
#         #                         else:
#         #                                 main(row+1, 0, False)
                                        
#         #                 col += 1

# main(0, 0, False)