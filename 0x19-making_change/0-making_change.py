#!usr/bin/python3
import sys


# m is size of coins array (number of
# different coins)
def minCoins(coins, m, val):

    # table[i] will be storing the minimum
    # number of coins required for i value.
    # So table[V] will have result
    table = [0 for i in range(val + 1)]

    # Base case (If given value V is 0)
    table[0] = 0

    # Initialize all table values as Infinite
    for i in range(1, val + 1):
        table[i] = sys.maxsize

    # Compute minimum coins required
    # for all values from 1 to V
    for i in range(1, val + 1):

        # Go through all coins smaller than i
        for j in range(m):
            if (coins[j] <= i):
                sub_res = table[i - coins[j]]
                if (sub_res != sys.maxsize and sub_res + 1 < table[i]):
                    table[i] = sub_res + 1

    if table[val] == sys.maxsize:
        return -1

    return table[val]


def makeChange(coins, total):
    return minCoins(coins, len(coins), total)
    # if total <= 0:
    #     return 0

    # coins = [coin for coin in coins if coin <= total]
    # print(coins, total)

    # if len(coins) > 0:
    #     if all(coin % 2 == 0 for coin in coins) and total % 2 > 0:
    #         return -1

    #     if any(coin == total for coin in coins):
    #         return 1

    #     try:
    #         return int(min([total / coin for coin in coins
    # if (total % coin == 0)]))
    #     except:
    #         return
