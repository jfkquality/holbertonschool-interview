#!/usr/bin/python3
"""  solve N Queen Problem using backtracking """

from sys import argv

k = 1


# A utility function to print solution
def printSolution(board):
    """ check if a queen can be placed on board[row][col]. """

    print([(ix, iy) for ix, row in enumerate(board)
           for iy, i in enumerate(row) if i == 1])


def isSafe(board, row, col, n):
    """ issafe function """

    # Check this row on left side
    for i in range(col):
        if (board[row][i]):
            return False

    # Check upper diagonal on left side
    i = row
    j = col
    while i >= 0 and j >= 0:
        if(board[i][j]):
            return False
        i -= 1
        j -= 1

    # Check lower diagonal on left side
    i = row
    j = col
    while j >= 0 and i < n:
        if(board[i][j]):
            return False
        i = i + 1
        j = j - 1

    return True


def solveNQUtil(board, col, n):
    """ If all queens are placed then return true """
    if (col == n):
        printSolution(board)
        return True

    res = False
    for i in range(n):

        if (isSafe(board, i, col, n)):

            # Place this queen in board[i][col]
            board[i][col] = 1

            # Make result true if any placement
            # is possible
            res = solveNQUtil(board, col + 1, n) or res

            board[i][col] = 0  # BACKTRACK

    return res


def solveNQ(args):
    """ solve n queens puzzle """

    if len(args) < 2:
        print("Usage: nqueens N")
        exit(1)

    n = args[1]

    try:
        n = int(argv[1])
    except Exception:
        n = argv[1]

    if not isinstance(n, int):
        print("N must be a number")
        exit(1)

    if n < 4:
        print("N must be at least 4")
        exit(1)

    board = [[0 for j in range(n)]
             for i in range(n)]

    if (solveNQUtil(board, 0, n) is False):

        print("Solution does not exist")
        return
    return


# Driver Code
solveNQ(argv)
