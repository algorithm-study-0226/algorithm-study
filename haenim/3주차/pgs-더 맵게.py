"""
모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return

음식의 스코빌 지수들의 최솟값이 k이상일 때 까지 제일 스코빌 지수가 낮은 두 음식을 섞으면 됨

항상 정렬 돼 있어야 한다
-> 힙큐

"""

import heapq


def solution(scoville, k):
    combined_count = 0  # 음식을 섞은 횟수
    heapq.heapify(scoville)

    while True:
        try:
            minimum = heapq.heappop(scoville)  # 가장 낮은 스코빌 지수를 가져옴

            if minimum >= k:  # 가장 낮은 스코빌 지수가 k이상이면
                return combined_count  # 현재까지 음식을 섞은 횟수 리턴

            second_minimum = heapq.heappop(scoville)  # 두번째로 낮은 스코빌 지수를 가져옴

            # 두 음식을 섞어서 새로운 스코빌 지수를 만듦
            combined_scoville = minimum + second_minimum * 2

            # 새로운 스코빌 지수를 힙큐에 저장함
            heapq.heappush(scoville, combined_scoville)

            # 섞은 횟수 1증가
            combined_count += 1

        except:
            return -1
