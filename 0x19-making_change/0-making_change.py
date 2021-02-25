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

    sc = sorted(coins)
    sc = sc[::-1]

    num = 0
    running = total
    for c in sc:
        while (running - c >= 0):
            running = running - c
            num = num + 1

    if running != 0 and running - sc[-1] < 0:
        return -1
    return num
