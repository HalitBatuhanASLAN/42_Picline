                              CSE102 Project Assignment 4 - People Information Query System
This project is designed to let users ask questions about a set of people whose information is stored in two separate text files. The first text file contains exam and course data for students and instructors, while the second text file maps IDs to names, roles, and departments.

                              Features
First and Last Initial Lookup:

Retrieve the first letter of a person's first or last name using their ID.

ID Lookup by Initial:

Find a person's ID using either their first or last initial.

Grade Calculation:

Calculate a student's GPA by their ID, using midterm and final exam scores.

                              Query System:

A menu-driven system allows users to:

-Display whether users pass or fail based on their grades.

-Filter users by their first initial and display relevant information.

-Calculate a specific student's GPA.

-Display if users passed or failed a specific class.

-Print the number of classes taught by an instructor.

-Display department information for all persons with a specific role.

-Display the course IDs for students.

                                Utility Functions
The following utility functions are implemented to manipulate the data:

char first_initial(FILE *id_fp, int id)
=Finds the first initial of the person with the given id from the file.

char last_initial(FILE *id_fp, int id)
= Returns the first letter of the last name for the given id.

int get_id_fi(FILE *id_fp, char first_initial)
= Returns the id of the person whose first name starts with first_initial.

int get_id_li(FILE *id_fp, char last_initial)
= Returns the id of the person whose last name starts with last_initial.

int average_grade(FILE *info_fp, int id)
= Calculates and returns the GPA of the student based on their midterm and final grades.

                                    Menu Options
The program presents the following options in a menu for user interaction:

p: Print whether users pass or fail.

For each course, the program calculates letter grades based on the midterm and final scores.

n: Print information about users with a specific first initial.

Filters students whose first names start with the user-provided letter.

g: Calculate the GPA of a specific student.

Takes the student ID as input and calculates the average GPA based on midterm and final grades.

c: Check pass or fail status for a specific class.

The user provides a course ID, and the program checks whether students passed the class.

t: Print the number of classes taught by an instructor.

The user provides an instructor's ID to retrieve the number of classes they are responsible for.

d: Print department information based on the role.

The user provides a role (e.g., 's' for student, 'i' for instructor) and the department information for all people with that role is displayed.

l: Retrieve the course ID for a given student.

The user provides a student ID to get the associated course ID.

e: Exit the program.
