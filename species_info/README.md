                                                    Species Information Manager
This project is designed to manage species data using a linked list structure. The species information consists of biological classifications such as class, order, family, genus, and species. The program allows users to add, modify, sort, and delete species data interactively.

                                                    Features
-Add New Species: Allows users to input and store species data (class, order, family, genus, species) in a linked list structure.

-Modify Species Data: Users can update the data of a species by specifying the species name and providing new information.

-Delete Species: Users can delete a species by entering its name.

-Sort Species: The program provides the option to sort the species data based on class, order, family, genus, or species using a bubble sort algorithm.

-View Species List: Prints the entire list of species data, formatted for easy reading.

-Memory Management: Properly frees dynamically allocated memory to avoid memory leaks.

The program prompts the user to input species information in the format:

Class
Order
Family
Genus
Species

After entering species data, the user is presented with a menu to choose from several options:

                                                Menu Options:
1)Add New Species

Prompts the user to enter information for a new species, which is added to the linked list.

2)Sort Species by (class/order/family/genus/species)

Allows the user to specify a criterion to sort the species list. Sorting is done using the bubble sort algorithm.

3)Modify Species Information

Enables the user to modify data for an existing species by specifying its name and providing updated information.

4)Delete a Species

Allows the user to delete a species by entering its name.

5)View Species List

Prints all species data stored in the list.

6)Exit

Exits the program, ensuring all allocated memory is properly freed.
                                                    
                                                    Detailed Code Breakdown
*Adding Species: The program uses a function adding() that dynamically allocates memory for a new species and appends it to the linked list.

*Handling New Line Characters: The program contains logic to handle cases where the user may accidentally enter a newline character by using getchar() effectively.

*Sorting Function: The sorting() function allows users to sort the species data based on any of the five classifications using a simple bubble sort algorithm.

Memory Management: Before the program terminates, all dynamically allocated memory (used for species data and the linked list) is freed to avoid memory leaks
