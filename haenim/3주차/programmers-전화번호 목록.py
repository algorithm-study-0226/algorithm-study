"""

각 접두어 마다 저장하다가 이후에 겹치는 접두어가 나오면 False 리턴

"""


def solution(phone_book):
    phone_book_dict = {}

    phone_book.sort(key=len)  # 길이 순으로 정렬

    # 제일 짧은 길이 - 1 (제일 짧은 전화번호 보다 짧으면 굳이 키로 저장할 필요 없으니까 제외하려고)
    start = len(phone_book[0]) - 1

    for phone_numbers in phone_book:  # 각 전화 번호에 대해서
        for i in range(start, len(phone_numbers)):

            prefix = phone_numbers[: i + 1]

            # 이 접두어가 전에도 나왔으면
            if phone_book_dict.get(prefix):
                # 이 접두어가 phone_book의 전화번호에 있는 전화번호면
                if prefix in phone_book:
                    return False

            # 이 접두어가 처음 나왔으면
            else:
                phone_book_dict[prefix] = 1

    return True
