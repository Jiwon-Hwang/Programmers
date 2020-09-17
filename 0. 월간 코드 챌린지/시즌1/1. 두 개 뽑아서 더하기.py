def solution(numbers):
    arr = set()
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            arr.add(numbers[i]+numbers[j])
    arr = sorted(list(arr))
    return arr