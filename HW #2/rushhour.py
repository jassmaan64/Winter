
#hueristic #2 Distance rom goal

def rushhour(hnumber, start):
    def h0(state):
        num = 0
        for rows in range(0, len(state)-1):
            for columns in range(0, len(state[rows])):
                if state[rows][columns] == 'X' and state[rows][columns+1] == 'X':
                    if state[rows][columns+1] == 'X':
                        tempcol = columns + 2
                        #print(tempcol)

                        while tempcol < len(state[rows]):
                            #print(tempcol)
                            if state[rows][tempcol] != 'X':
                                num = num+1
                                if state[rows][tempcol] == '-':
                                    num = num-1
                                elif state[rows][tempcol] == state[rows][tempcol-1]:
                                    num= num-1
                                tempcol = tempcol + 1
                            elif tempcol < len(state[rows]):
                                    if state[rows][tempcol] == state[rows][tempcol - 1]:
                                        num = num-1
                else:
                    continue
        return num
    def g(hnumber, start):

        def moveright(staterow, size, stindex, endindex):
            if endindex + 1 <= len(staterow) - 1:
                if (staterow[endindex + 1] == '-'):
                    for i in range(endindex, stindex):
                        staterow[endindex + 1]= staterow[endindex]

        def moveleft(staterow, size, stindex, endindex):
            if stindex - 1 < 0:
                if (staterow[stindex - 1] == '-'):
                    for i in range(stindex, endindex):
                        staterow[stindex-1]= staterow[stindex]



    if hnumber == 0:
        x = h0(start)
    print(x)

rushhour(0, ["--B---","--B---","XXB---","--AA--","------","------"])