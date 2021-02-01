#!/usr/bin/python3
""" 0. Rotate 2D Matrix """

def rotate_2d_matrix(matrix):
    """ Rotate 2D matrikx cw """
    print(len(matrix))

    size = len(matrix)

    for row, vals in enumerate(matrix):
        matrix.insert(row, vals[row])
        print(matrix)
        # col 0 becomes row 0
        # col 1 becomes row 1
        # col x becomes row x
        # for col, val in enumerate(row);
