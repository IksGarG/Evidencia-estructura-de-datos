def conflict(i, j):
    if (j - i) % 8 == 0:
        return True
    if j - i == 7:
        return True
    if j - i == 9:
        return True
    return False

for q1 in range(1, 9):
    x = q1
    for q2 in range(9, 17):
        if not conflict(x, q2):
            y = q2
            for q3 in range(17, 25):
                if not conflict(x, q3) and not conflict(y, q3):
                    z = q3
                    for q4 in range(25, 33):
                        if not conflict(x, q4) and not conflict(y, q4) and not conflict(z, q4):
                            w = q4
                            for q5 in range(33, 41):
                                if not conflict(x, q5) and not conflict(y, q5) and not conflict(z, q5) and not conflict(w, q5):
                                    v = q5
                                    for q6 in range(41, 49):
                                        if not conflict(x, q6) and not conflict(y, q6) and not conflict(z, q6) and not conflict(w, q6) and not conflict(v, q6):
                                            u = q6
                                            for q7 in range(49, 57):
                                                if not conflict(x, q7) and not conflict(y, q7) and not conflict(z, q7) and not conflict(w, q7) and not conflict(v, q7) and not conflict(u, q7):
                                                    t = q7
                                                    for q8 in range(57, 65):
                                                        if not conflict(x, q8) and not conflict(y, q8) and not conflict(z, q8) and not conflict(w, q8) and not conflict(v, q8) and not conflict(u, q8) and not conflict(t, q8):
                                                            r = q8
                                                            print(x, y, z, w, v, u, t, r)
                                                            quit()