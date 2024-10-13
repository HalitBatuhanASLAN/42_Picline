                                                            C Linked List Practice
This repository contains a simple implementation of a singly linked list in C. The program demonstrates how to create, add, delete, and print elements in a linked list using structures. It serves as a practical exercise for understanding the fundamental operations on linked lists.

                                                            Features

Adding Elements: Functions to add elements at the end or at the beginning of the list.

Deleting Elements: Function to delete a specified element from the list.

Printing the List: Function to print all elements in the linked list.

                                                            Structure Definition
The linked list is implemented using a struct named list, which contains:

number: An integer to store the data.

next: A pointer to the next node in the list.

                                                            Functions

struct list *adding(struct list *adding_list, int adding_number): Adds a new element at the end of the list.

struct list *adding_first(struct list *adding_list, int adding_number): Adds a new element at the beginning of the list.

struct list *deleting_num(struct list *adding_list, int deleting_number): Deletes the first occurrence of a specified number from the list.

void printing_list(struct list *printing_list): Prints all elements in the list.

