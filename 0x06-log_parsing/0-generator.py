#!/usr/bin/python3
""" Parse logs and aggregate. """
import random
import sys
from time import sleep
import datetime

if __name__ == "__main__":
    for i in range(10):
        sleep(random.random())
        sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
            random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
            random.randint(1, 255),
            random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
            random.randint(1, 1024)
        ))
        sys.stdout.flush()
