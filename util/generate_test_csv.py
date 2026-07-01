"""
Util file used to generate solve .csv files.
Used in testing whether SolveManager.cpp in our project is reading and interpreting this .csv correctly.
"""

import random
import time

# Create scrambles with the format "time,date,scramble" and times like this:
# For the ith solve: i.XX,[TIME],R U R' U' (where .XX is a random decimal and [TIME] is time since the Unix Epoch)
def sequential_distribution(num_solves: int) -> None:
	with open("test_solves.csv", "w+") as f:
		f.write("time,date,scramble\n")
		for i in range(num_solves):
			f.write(str(i + 1))
			f.write("." + str(random.randint(10, 100)) + ",")
			f.write(str(int(time.time())) + ",")
			f.write("R U R' U'\n")
		f.close()


if __name__ == "__main__":
	sequential_distribution(200)
