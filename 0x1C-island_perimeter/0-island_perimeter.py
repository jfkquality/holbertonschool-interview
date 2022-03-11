#!/usr/bin/python3
""" Python 3 program to find perimeter of area
#covered by 1 in 2D matrix consisits of 0's and 1's.
"""


def numofneighbors(mat, row, col, rows, cols):
    """ Find the number of covered side for mat[i][j]."""

    count = 0

    # UP
    if (row > 0 and mat[row - 1][col]):
        count += 1

    # LEFT
    if (col > 0 and mat[row][col - 1]):
        count += 1

    # DOWN
    if (row < rows - 1 and mat[row + 1][col]):
        count += 1

    # RIGHT
    if (col < cols - 1 and mat[row][col + 1]):
        count += 1

    return count


def island_perimeter(grid):
    """ Returns sum of perimeter of shapes formed with 1's. """

    perimeter = 0
    land = grid

    rows = len(land)
    cols = len(land[0])

    # Traversing the matrix and finding ones to
    # calculate their contribution.
    for row in range(0, rows):
        for col in range(0, cols):
            if (land[row][col]):
                perimeter += (4 - numofneighbors(land, row, col, rows, cols))

    return perimeter
