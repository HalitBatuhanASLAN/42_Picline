                                            Botanist Flower Collection Game
This project implements a game where a botanist navigates through a forest to collect rare flowers while avoiding obstacles like trees. The botanist can move in different directions, and the game continues until all flowers are collected or the user chooses to exit.


                                Table of Contents
Features
Data Structures
Functions
Game Initialization
Game Logic
Memory Management

                                      Features

Forest Map: A 2D grid representing the forest where:

T denotes trees

B denotes the botanist

X denotes rare flowers

Spaces represent walkable areas

Botanist Movement: The botanist can move left, right, up, or down.

Flower Collection: The botanist collects rare flowers and keeps track of the total collected.

Game Over Conditions: The game ends when the botanist collects all flowers or chooses to exit.

Last State Saving: The final state of the forest and the botanist's position is saved to a file before exiting.
                                            Data Structures

      Forest Structure

The Forest structure stores information about the forest:

      Botanist Structure
The Botanist structure stores information about the botanist:

                                              Functions
The program includes several functions to manage the game:

void init_game(Forest *forest, Botanist *botanist): Initializes the game by reading the forest layout and the botanist's starting position from a file.

void search(Forest *forest, Botanist *botanist, ...): A recursive function that allows the botanist to search for rare flowers by moving in the forest.

void display_forest(Forest *forest, Botanist *botanist, ...): Displays the current state of the forest, including the botanist's position, collected flowers, and remaining bottles.

void last_version(Forest *forest): Saves the final state of the forest to a file before exiting.

                                                Game Initialization
The game initializes by reading from a file called init.txt. The first line contains the dimensions of the forest (height and width), while the second line specifies the botanist's starting coordinates and the number of bottles. The following lines represent the forest layout.



Game Logic
The botanist can move in four directions (up, down, left, right). Movement restrictions apply:

The botanist cannot move into a tree (T).
The botanist collects flowers (X) and updates their count.
If the botanist collects all flowers or chooses to exit, the game saves the final state and ends.

Memory Management
The program uses dynamic memory allocation for managing the botanist's and forest's data. It is essential to manage memory correctly and free any allocated resources to prevent memory leaks.
