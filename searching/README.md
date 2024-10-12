                                          Scientist Information and Pattern Matching Manager
This project consists of two main parts:

1)Scientist Information Manager: Managing and organizing information about famous scientists.
2)Pattern Matching in Text: Identifying specific patterns in a text file using custom search algorithms.

                                              Part 1: Scientist Information Manager
                                              Features  

Sort by Age: Sort and display all individuals by age.

Sort by Branch: Sort and display individuals in their primary and secondary branches, also sorted by age within the branch.

Filter by Branch: Display individuals who belong to a specified branch (either primary or secondary).

Filter by Profession: Filter individuals who work only in one specific branch (without any secondary branch).

Exit: Exit the program.

                                            Input File Format
The program reads information from a file named input1.txt, which contains details about famous scientists. The information includes the following fields, separated by commas:
Name
Surname
Age
Primary Branch (Branch1)
Secondary Branch (Branch2, optional)

                                                    Menu Options
After loading the data from the file, the program presents the following menu:

-Sort and display all individuals by age: Lists scientists sorted by age in ascending order.

-Sort and display individuals in the branch by age: Sorts and displays scientists within their branches, ordered by age.

-Show individuals with the wanted branch: Filters and displays scientists who belong to the user-specified branch.

-Filter people by profession: Displays scientists who only work in one specified branch and have no secondary branch.

-Exit: Ends the program.
                                              Sorting Logic
The program sorts scientists using:

*By Age: The scientists are sorted in ascending order of their age.
*By Branch: Scientists are sorted first by the primary branch, then by the secondary branch (if applicable), and finally by age if both branches are the same.
                                              
                                              Filtering Logic
*Filter by Branch: The program checks both the primary and secondary branches for a match with the user-specified branch.
*Filter by Profession: The program filters out scientists who have only one specified branch and no secondary branch.


                                              Part 2: Pattern Matching
In the second part of the project, the program searches for specific patterns in a text file. The file contains * and + characters arranged in a grid, and the program looks for predefined patterns in the rows, columns, and diagonals.

Patterns

P1: Row Pattern
The row pattern to search for is: ***++++***++++***

P2: Column Pattern
The column pattern to search for is: +*+*+

P3: Diagonal Pattern
The diagonal pattern to search for is: +**+++****+++**+

                                              Search Functions
Row Pattern Search (P1): Finds occurrences of the row pattern ***++++***++++***.

Column Pattern Search (P2): Finds occurrences of the column pattern +*+*+.

Diagonal Pattern Search (P3): Finds occurrences of the diagonal pattern +**+++****+++**+ both from top-left to bottom-right and top-right to bottom-left.
