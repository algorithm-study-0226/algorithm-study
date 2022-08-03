# https://school.programmers.co.kr/learn/courses/30/lessons/42626?language=python3

"""
# 힙 연산
추가 : 가장 마지막에 요소 추가 후 정렬
삭제 : 루트 삭제 후 가장 마지막에 있는 요소를 루트에 넣고 정렬


구조)
        X                     X/2                   (X-1)/2
                       ==               ==
2X + 1      2X + 2          X    X+1            X-1           X

"""

import heapq


def solution(scoville: list, K):
    answer = 0
    heap = scoville
    heapq.heapify(heap)

    while len(heap) >= 2 and heap[0] < K:  ## 최소한 2개는 더 꺼낼 수 있는 상황이라면
        one = heapq.heappop(heap)
        two = heapq.heappop(heap)
        heapq.heappush(heap, one + two * 2)
        answer += 1

    return answer if heap[0] >= K else -1


print(solution([1, 2, 3, 9, 10, 12], 7))


"""

// 처음에는 힙 구현 겸 정석으로 접근


def heap_add(lst: list, key):
    lst.append(key)

    # 정렬은 추가하는 것에 대해서만 해도 된다
    idx = len(lst) - 1
    while idx // 2 > 1:

        if lst[ idx // 2] > lst[idx]:
            lst[ idx // 2], lst[idx] = lst[idx], lst[ idx // 2]
        idx =  idx // 2
    return lst


def heap_delete_root(lst: list):
    min_scv = lst[0]

    lst[0] = lst.pop(len(lst) - 1)  # 인덱스를 0으로 둘 경우

    idx = 0

    while 2 * idx + 1 < len(lst) or 2 * idx + 2 < len(lst):
        min_idx = False
        if lst[2 * idx + 1] < lst[idx] or lst[2 * idx + 2] < lst[idx]:
            min_idx = 2 * idx + 1 if lst[2 * idx + 1] < lst[2 * idx + 2] else 2 * idx + 2  # 더 작은 값과 바꾼다
            lst[min_idx], lst[idx] = lst[idx], lst[min_idx]

        idx = min_idx if min_idx else 2 * idx + 1

    return min_scv, lst


def solution(scoville: list, K):
    answer = 0
    # scoville.insert(0, -1)  # 일반적으로 힙에서 인덱스를 0으로 두지 않음

    while scoville[0] < K:  # MIN Heap의 루트가 k 미만일 경우에만 반복
        answer += 1

        # 삭제
        min_scv, scoville = heap_delete_root(scoville)

        # 삭제
        min2_scv, scoville = heap_delete_root(scoville)

        # 추가
        scoville = heap_add(scoville, min_scv + 2 * min2_scv)

    return answer


print(solution([1, 2, 3, 9, 10, 12], 7))


// 리스트를 사용하여?
리스트 append, pop 연산에 시간이 많이 소모되니 포인터를 이용하여 시간을 줄이면 될 것 같았음
정확성: 33.3
효율성: 0.0
합계: 33.3 / 100.0


def solution(scoville: list, K):
    scoville.sort()
    answer = 0
    back = len(scoville) - 1
    front = 0
    while scoville[front] < K and front < back:  # MIN Heap의 루트가 k 미만일 경우에만 반복
        answer += 1

        one = scoville[front]
        front += 1

        two = scoville[front]
        front += 1

        scoville.append(one + 2 * two)

        idx = back
        while idx // 2 > front * 2:
            if scoville[idx // 2] > scoville[idx]:
                scoville[idx // 2], scoville[idx] = scoville[idx], scoville[idx // 2]
            idx = idx // 2
        # print(scoville)
    return answer if scoville[front] >= K else -1


// 역으로 루트에 넣어 정렬시킨다면?
작은 값들만 제대로 정렬된다면 문제 없으니까

정확성: 28.6
효율성: 0.0
합계: 28.6 / 100.0 


def solution(scoville: list, K):
    scoville.sort()
    answer = 0
    back = len(scoville) - 1
    front = 0
    while scoville[front] < K and front < back:  # MIN Heap의 루트가 k 미만일 경우에만 반복
        answer += 1

        scoville[front + 1] = scoville[front] + (2 * scoville[front + 1])
        front += 1

        idx = min_idx = front

        while 2 * idx + 2 < back:
            min_idx = idx * 2 + 1 if scoville[idx * 2 + 1] < scoville[idx * 2 + 2] else idx * 2 + 2
            if scoville[min_idx] < scoville[idx]:
                scoville[min_idx], scoville[idx] = scoville[idx], scoville[min_idx]
            else:  # 더 정렬을 안해도 된다는 것
                break
            idx = min_idx
        # print(scoville)
    return answer if scoville[front] >= K else -1
"""
