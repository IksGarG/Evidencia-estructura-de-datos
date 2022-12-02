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

# evaluar si una posicion esta amenazada por otra reina
def conflict(row, col):
        for i in range(8):
                ''' no se evalua si en la misma fila hay otra reina porque nunca va a suceder eso
                solo se evalua la columna y que no se trate de la misma posicion, ya que en ese 
                caso siempre seria verdadero porque en la posicion que esta buscando hay una reina,
                ella misma'''
                if board[i][col] == "Q" and i != row:
                        return True
                for j in range(8):
                        '''aqui checa en las diagonales, y como en la condicion pasada, checa que no
                        se encuentre en la misma posicion que la que busca'''
                        if ((i+j) == (row+col) or (i-j) == (row-col)) and (i != row and j != col):
                                if board[i][j] == "Q":
                                        return True
        return False

# funcion para insertar, inserta en la posicion dada y quita la de la fila anterior
def insert(row, col):
        board[row][col] = "Q"
        board[row][col-1] = "·"

def main():
        '''aqui hay 8 for anidados porque esencialmente esta tratando todas las combinaciones posibles
        hasta llegar a la primera solucion'''
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
                                                                        '''en el for mas interno, que se ejecuta en cada iteracion, 
                                                                        se coloca la evaluacion de que todas las reinas no esten amenazadas,
                                                                        o sea, que haya llegado a una solucion, y si es el caso, sale del programa'''
                                                                        if not conflict(0, col0) and not conflict(1, col1) and not conflict(2, col2) and not conflict(3, col3) and not conflict(4, col4) and not conflict(5, col5) and not conflict(6, col6) and not conflict(7, col7):
                                                                                print("found!")
                                                                                print_board()
                                                                                print("--- %s seconds ---" % (time.time() - start_time))
                                                                                quit()

main()