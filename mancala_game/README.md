                                      Game Overview

The game is played on a board with:

-12 small cups: six on the player's side and six on the computer's side.

-2 large empty cups: one for the player and one for the computer.

-Stones placed in the small cups at the start of the game.

                                      Objective

The goal is to collect the most stones in your large cup by strategically distributing the stones from your side of the board.

                                      Game Setup

-You choose the number of stones (n) to place in each small cup, which must be a multiple of 6.

-The game board is initialized, and the stones are placed in the small cups, while the large cups remain empty.

                                      Gameplay
-Players take turns selecting a cup from their own side and distributing the stones counterclockwise, placing one stone per cup.

-Stones are placed in the player's large cup but skipped over the opponent's large cup.

-If the last stone lands in the player's own large cup, they get another turn.

-If the last stone lands in an empty cup, the opponent takes their turn.

                                     Game End

The game ends when one side of the board is empty.

The winner is the player with the most stones in their large cup.

                                    Project Structure

*This program is divided into several functions to modularize the game logic.

                                    Functions:
1)initializeGame() [20 pts]
Initializes the game board. It places n stones in each of the small cups and leaves the large cups empty. This function uses a 2D array to represent the game board.

2)printBoard() [20 pts]
Displays the current state of the board, showing the number of stones in each cup. It helps players visualize the game and make informed decisions.

3)gamePlay() [30 pts]
Manages the entire game flow, handling turns between the user and the computer, validating moves, checking the game end condition, and determining the winner.

4)move() [30 pts]
Distributes stones from a selected cup according to the game's rules. It updates the board and prints the state after each move.

                                    Game Flow:
The player selects a cup, and the stones are distributed across the cups.

The game switches turns between the player and the computer until one side is empty.

The final score is tallied, and the winner is determined based on the number of stones in each large cup.
