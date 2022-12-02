def conflict(i, j):
    if (j - i) % 4 == 0:
        return True
    if j - i == 3:
        return True
    if j - i == 5:
        return True
    return False

for q1 in range(1, 5):
    x = q1
    for q2 in range(5, 9):
        if not conflict(x, q2):
            y = q2
            for q3 in range(9, 13):
                if not conflict(x, q3) and not conflict(y, q3):
                    z = q3
                    for q4 in range(14, 17):
                        if not conflict(x, q4) and not conflict(y, q4) and not conflict(z, q4):
                            w = q4
                            print(x, y, z, w)