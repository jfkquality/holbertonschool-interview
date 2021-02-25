#!/usr/bin/python3
"""
0. Change comes from within
 determine the fewest number of coins needed to meet a given amount
"""


def makeChange(coins, total):
    """ determine the fewest number of coins needed to meet a given amount. """
    if total <= 0:
        return 0
    if len(coins) <= 0:
        return -1

    coinsList = sorted(coins, reverse=True)
    # print(coins, total)
    # print(sorted_c, total)
    # sorted_c = sorted_c[::-1]

    count = 0
    num = 0
    coinIdx = 0
    running = total
    temp = total
    lastIdx = len(coins) -1

    # for coin in coinsList:
    while coinIdx < len(coinsList):
        num = total // coinsList[coinIdx]
        count += num
        # total -= coinsList[coinIdx] * num
        temp -= coinsList[coinIdx] * num
        # print("first temp ", temp)

        if coinIdx == lastIdx - 1 and temp != 0:
            # print("next coin list value ", coinsList[coinIdx + 1])
            if temp < coinsList[coinIdx + 1]: # and temp != 0: # and coindIdx + 1 < len(coinsList) - 1:
                count -= num
                temp = total
                # print("temp ", temp)
        total = temp
        # print("total ", total)
        coinIdx += 1

        if total == 0:
            return count
    return -1

    # for c in sorted_c:
    #     while (running - c >= 0):
    #         running = running - c
    #         num = num + 1

    # if running != 0 and running - sorted_c[-1] < 0:
    #     return -1
    # return num
