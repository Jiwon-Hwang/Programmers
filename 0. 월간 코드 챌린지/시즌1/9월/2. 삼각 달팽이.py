def solution(n):
    snail = [[0]*n for _ in range(n)]
    cnt = n 
    num = 1
    
    [i, j] = [0, 0]
    state = 1 # state = 1,2,3 (방향 종류)

    while cnt:
        if state == 1:
            for _ in range(cnt):
                snail[i][j] = num
                i += 1
                num += 1
            cnt -= 1
            i -= 1
            j += 1
            state = 2
            
        elif state == 2:
            for _ in range(cnt):
                snail[i][j] = num
                j += 1
                num += 1
            cnt -= 1
            i -= 1
            j -= 2
            state = 3
            
        else:
            for _ in range(cnt):
                snail[i][j] = num
                i -= 1
                j -= 1
                num += 1
            cnt -= 1
            i += 2
            j += 1
            state = 1
    
    answer = []
    for x in range(n):
        for y in range(x+1):
            answer.append(snail[x][y])
    
    return answer