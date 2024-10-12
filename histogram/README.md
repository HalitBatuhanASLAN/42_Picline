                                              Features
Part 1: Determination of Interval and Drawing Histogram (50 pts)

-The program takes two integer values (A and B) from the user, representing the interval [A, B].

-The interval A must be at least 50, and B must not exceed 200.

-The program generates a histogram displaying the occurrences of each number from the interval in the array number_array[].

*Values outside the interval are ignored.

A function find_size_of_array() determines the size of the array, using -1 as the array terminator.

Part 2: Updating Histogram by Adding New Numbers (30 pts)

-After displaying the histogram, the user can add up to 5 additional numbers to the array.
-The user is prompted to input 1 to add numbers or 0 to skip.
-The program updates the histogram accordingly with the new numbers and displays the revised version.

Part 3: Performing Mathematical Operations (20 pts)

-The program calculates and displays three mathematical properties for the numbers within the interval:

*Average: The mean of the numbers within the interval.
*Mode: The number(s) with the highest frequency of occurrence. If multiple modes exist, all are displayed.
*Median: The middle value in the sorted list of numbers. Handles both even and odd cases.

                                          File Structure
*main.c: The main C program implementing the logic for generating and updating the histogram, and calculating average, mode, and median.

                                          Functions
-find_size_of_array(): Determines the size of an array, where -1 marks the end of the array.

-average(): Calculates and prints the average of the numbers in the given interval.

-frequency(): Calculates the frequency of each number in the array and stores the result in another array.

-mode(): Finds and prints the mode(s) of the numbers.

-median(): Calculates and prints the median of the numbers.

-interval(): Sets up the histogram by assigning values to the x-axis.

-printing_histogram(): Prints a visual representation of the histogram to the terminal using stars (*).

-adding_to_histogram(): Adds user input numbers to the histogram and updates the frequency array.
