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
    count = 0
    num = 0
    temp = total
    lastIdx = len(coins) - 1

    for coinIdx, coinVal in enumerate(coinsList):
        num = total // coinVal
        count += num
        temp -= coinVal * num

        if coinIdx == lastIdx - 1 and temp != 0:
            if temp < coinsList[coinIdx + 1]:
                count -= num
                temp = total
        total = temp

        if total == 0:
            return count
    return -1
