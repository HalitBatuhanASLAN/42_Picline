                                                            Custom Dictionary Implementation
This project implements a custom dictionary data structure in C, designed to store key-value pairs where keys are strings and values can be arrays of various types, including integers, floats, doubles, and characters. The custom dictionary is implemented in the customDict.h header file, with accompanying functionality for managing and manipulating the dictionary.

                                                          Features

Add Items: Users can add items with a specified key and associated values of different data types (int, double, float, char).

Delete Items: Remove items from the dictionary based on the key.

Set Values: Modify existing values associated with a specific key.

Search Items: Retrieve values by their associated key.

Sort Dictionary: Sort the items in the dictionary by their keys.

Print Dictionary: Display all items in the dictionary.

Read from CSV: Load items from a CSV file to populate the dictionary.

                                            Data Structures

CustomDict Structure
The CustomDict structure holds the items in the dictionary, along with their current size and capacity.

Value Union
The Value union represents the different types of values that can be stored in the dictionary.

Item Structure
The Item structure represents a key-value pair in the dictionary. It consists of:

key: A pointer to a string representing the key.

value: A dynamic array of the Value union representing the values associated with the key.

data_type: The type of data stored (int, double, float, char).

field: The number of values associated with the key.

                                      Functions

The following functions are implemented to facilitate dictionary operations:

struct CustomDict* create_dict(): Initializes a new custom dictionary.

void add_item(struct CustomDict* dict, char* key, union Value* value): Adds a new item to the dictionary with the specified key and value.

void delete_item(struct CustomDict* dict, char* key): Deletes an item from the dictionary by its key.

void set_value(struct CustomDict* dict, char* key, union Value* value): Updates the value associated with a given key in the dictionary.

union Value* search_item(struct CustomDict* dict, char* key): Searches for an item in the dictionary by its key and returns its value.

void sort_dict(struct CustomDict* dict): Sorts the dictionary by keys.

void print_dict(struct CustomDict* dict): Prints the contents of the dictionary in the format "Key: Value".

void free_dict(struct CustomDict* dict): Frees the memory allocated for the dictionary.

int read_csv(struct CustomDict* dict, const char* filename): Reads data from a CSV file and populates the dictionary accordingly.

