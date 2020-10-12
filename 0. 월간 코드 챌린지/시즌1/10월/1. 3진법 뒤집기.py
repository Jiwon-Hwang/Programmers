def solution(n):
    import math
    
    num = ''
    N = n
    while N >= 3:
        num += str(N % 3)
        N = N // 3
    num += str(N)
    
    num_int = int(num)
    
    answer = 0
    num_len = len(str(num))
    for i in range(num_len):
        answer += (num_int % 10) * pow(3, i)
        num_int = num_int // 10
        
    return answer