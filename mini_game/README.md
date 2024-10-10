                                                        Student Maze Game
                                                        Overview
This project implements a simple text-based maze game where a student (P) needs to collect courses represented by 1 and 2 objects to earn ECTS credits and progress through two sets of walls to ultimately reach the goal (X). The objective of the game is to collect enough ECTS points to pass the two walls and finish the game by reaching the X mark.

                                                        How to Play
Initial Setup:

The game board is 16x16 in size, and the student starts at the exact center, surrounded by two walls representing first and second grade.
The player must collect 1 and 2 objects representing first and second-year courses, respectively.
Each 1 object grants 8 ECTS points for the first grade, and each 2 object grants 8 ECTS points for the second grade.

Winning Conditions:

Collect 32 ECTS points (from first grade) to pass the first wall.
Collect 24 ECTS points (from second grade) to pass the second wall.
After collecting enough credits and passing both walls, reach the X in the bottom right corner to complete the game.

Controls:

Move the student using:
--w: Move up
--a: Move left
--s: Move down
--d: Move right
**The movement is case-insensitive, so both lowercase and uppercase versions of the letters will work.

Restrictions:

The player cannot pass the walls without earning the required ECTS points.
The player must collect all necessary first-year courses (1) before attempting to pass the first wall.
After passing the first wall, they must collect the second-year courses (2) before progressing through the second wall.
End of the Game:

Once the player reaches the X, the game will display the total ECTS earned and the total number of movements made by the player.

                                                    Functions
1)initialize_game()
This function initializes the game board, places the player (P) in the center, sets up the two walls, and randomly places the 1 and 2 objects (representing courses) on the board.

2)print_board()
Displays the current state of the game board. The symbols used are:

.:Empty spaces

#: Walls

1: First-year courses

2: Second-year courses

P: Player's position

X: Goal position

3)move_player(char direction)
Handles the player movement based on the given direction (w, a, s, d). It updates the player's position, checks if enough ECTS points are earned to pass the walls, and collects courses if the player lands on them.
