                                            CSE102 - Assignment 10: Assembly Language Execution Simulator
This repository contains the implementation of an Assembly Language Execution Simulator as part of CSE102 Assignment 10. The simulator is designed to execute assembly language code from a file, utilizing a simplified instruction set. It displays the results of the operations performed on registers and memory.

                                            Contents

Main Program (assembly_simulator.c)

Instruction Set (instructions.txt)

                                          Features

Assembly Code Execution: The simulator reads assembly instructions from a .asm file, decodes them, and executes the corresponding operations.

Registers: Two registers (A and B) are implemented, each capable of storing 8 bits.

Program Counter: A program counter (PC) keeps track of the current instruction being executed.

Instruction Register: The instruction register (IR) holds the current instruction being processed.

Memory: The simulator uses a stack-like structure for memory, with each location storing 8 bits.

Decimal-Binary Conversion: Functions to convert decimal numbers to binary and vice versa.

                                        Instruction Set

The instruction set for the simulator includes various operations such as:

Arithmetic Operations: ADD, ADDI, SUB, SUBI, INC, DEC

Logical Operations: AND, ANDI, OR, ORI, NOR

Data Transfer: LDA, LDAI, STR

Control Flow: J (jump), BRE (branch if equal), BRN (branch if not equal), PRI (print value)

The complete set of instructions can be found in the instructions.txt file.

                                      How to run
1)Firstly compile program

2)Input the Assembly Code File: When prompted, enter the name of the assembly code file (ensure it has a .asm extension).

3)Memory Initialization: The program will allow you to initialize memory by specifying addresses and values to store.

4)Execute Instructions: The program will fetch, decode, and execute the instructions sequentially until an EXIT instruction is encountered.

5)Output: The state of memory will be printed after the execution of instructions.
