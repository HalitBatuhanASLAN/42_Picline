#include<stdio.h>
char first_initial(FILE *id_fp,int id)
{
	int id_controller;/*to check id equal to student id which user gave*/
	char x;/*to take characters*/
	char initial_first;/*to take first letter of first name*/
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with a loop*/
	while(fscanf(id_fp,"%d;",&id_controller) == 1)
	{
		/*checking wheather we find corect id or not*/
		if(id_controller == id)
		{
			/*taking fist letter of name and puts it to initial_first variable*/
			fscanf(id_fp,"%c",&initial_first);
			fclose(id_fp);/*we dont need to countinue so we close file*/
		}
		else/*if id is not equal the it takes character till end of the line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
	}
	/*returning letter*/
	return(initial_first);
}
char last_initial(FILE *id_fp,int id)
{
	int id_controller;/*to check id equal to student id which user gave*/
	char x;/*to take characters*/
	char initial_last;/*to take first letter of last name*/
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with a loop*/
	while(fscanf(id_fp,"%d;",&id_controller) == 1)
	{
		/*checking wheather we find corect id or not*/
		if(id_controller == id)
		{
			/*taking inputs as characters till first ';'*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != ';');
			/*taking fist letter of surname and puts it to initial_last variable*/
			fscanf(id_fp,"%c",&initial_last);
			fclose(id_fp);/*we dont need to countinue so we close file*/
		}
		else/*if id is not equal the it takes character till end of the line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
	}
	/*returning letter*/
	return(initial_last);
}
int get_id_fi(FILE *id_fp,char first_initial)
{
	char letter_controller;/*to check letter equal to student letter which user gave*/
	char x;/*to take characters*/
	int id,return_id,control = 0;/*id to take id,return_id to return id and controller*/
	FILE *id_first;/*file pointer for first_initial.txt file*/
	id_first = fopen("first_initial.txt","w");/*open txt file to write*/
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with a loop*/
	while(fscanf(id_fp,"%d;",&id) == 1)
	{
		/*taking fist letter of name*/
		fscanf(id_fp,"%c",&letter_controller);
		/*if we find correct letter and control variable is equal to 0*/
		if(letter_controller == first_initial && control == 0)
		{
			return_id = id;/*assign id to return_id*/
			control ++;/*increment controller variable*/
			fprintf(id_first,"%d\n",id);/*printing id to the file*/
			/*taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
		}
		else if(letter_controller == first_initial)
		{
			fprintf(id_first,"%d\n",id);/*printing other id with starting letter which user gave*/
			/*taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
		}
		else/*if we do not find letter taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
	}
	fclose(id_first);/*closing txt file*/
	fclose(id_fp);/*closing txt file*/
	return(return_id);/*returning just the first id with a name starting with letter*/
}
int get_id_li(FILE *id_fp,char last_initial)
{
	char letter_controller;/*to check letter equal to student letter which user gave*/
	char x;/*to take characters*/
	int id,return_id,control = 0;/*id to take id,return_id to return id and controller*/
	FILE *id_last;/*file pointer for first_initial.txt file*/
	id_last = fopen("last_initial.txt","w");/*open txt file to write*/
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with a loop*/
	while(fscanf(id_fp,"%d;",&id) == 1)
	{
		/*taking characters till character is equal to ;*/
		while(fscanf(id_fp,"%c",&x) == 1)
		{
			if(x == ';')
				break;
		}
		/*taking fist letter of surname*/
		fscanf(id_fp,"%c",&letter_controller);
		/*if we find correct letter and control variable is equal to 0*/
		if(letter_controller == last_initial && control == 0)
		{
			return_id = id;/*assign id to return_id*/
			control++;/*increment controller variable*/
			fprintf(id_last,"%d\n",id);/*printing id to the file*/
			/*taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
		}
		else if(letter_controller == last_initial)
		{
			fprintf(id_last,"%d\n",id);/*printing other id with surname starting letter which user gave*/
			/*taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
		}
		else/*if we do not find letter taking characters till end of line*/
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
	}
	fclose(id_fp);/*closing txt file*/
	fclose(id_last);/*closing txt file*/
	return(return_id);/*returning just the first id with a surname starting with letter*/
}
int average_grade(FILE *info_fp,int id)
{
	int id_controller;/*to check id equal to student id which user gave*/
	int midterm1 = 0,midterm2 = 0,final = 0;/*for exam grades*/
	int exam_number = 0;/*exam number counter*/
	char x;/*to take characters*/
	int total_midterm1_102 = 0,total_midterm2_102 = 0,final_102_total = 0,counter_102 = 0,total_midterms_102;
	int total_midterm1_108 = 0,total_midterm2_108 = 0,final_108_total = 0,counter_108 = 0;
	int code;
	float final_ave_102=0,final_ave_108=0,midterm_ave_102=0,midterm_ave_108=0;
	float midterm_gpa=0,final_gpa=0,midterm_ave=0;
	int average_grade;
	info_fp = fopen("first 1.txt","r");/*open txt file to read*/
	/*calculating total grades for class 102*/
	while(fscanf(info_fp,"%d;%d;%d;%d;%d",&id_controller,&midterm1,&midterm2,&final,&code) == 5)
	{
		total_midterm1_102 += midterm1;
		total_midterm2_102 += midterm2;
		final_102_total += final;
		counter_102++;
	}
	total_midterm1_108 += midterm1;
	final_108_total += midterm2;
	counter_108++;
	/*calculating total grades for class 108*/
	while(fscanf(info_fp,"%d;%d;%d;%d",&id_controller,&midterm1,&final,&code) == 4)
	{
		total_midterm1_108 += midterm1;
		final_108_total += final;
		counter_108++;
	}
	fclose(info_fp);/*closing txt file*/
	info_fp = fopen("first 1.txt","r");/*open txt file to read*/
	/*calculating average for class 102 and 108*/
	total_midterms_102 = total_midterm1_102 + total_midterm2_102;
	midterm_ave_102 = (float)total_midterms_102/(counter_102*2),
	final_ave_102 = (float)final_102_total/counter_102;
	midterm_ave_108 = (float)total_midterm1_108/counter_108,
	final_ave_108 = (float)final_108_total/counter_108;
	/*taking id with loop*/
	while(fscanf(info_fp,"%d;",&id_controller) == 1)
	{
		/*checking for id*/
		if(id_controller == id)
		{
			/*finding number of exams*/
			while(fscanf(info_fp,"%c",&x) == 1 && x != '\n')
			{
				if(x == ';')
					exam_number++;
			}
			fclose(info_fp);/*closing txt file*/
			info_fp = fopen("first 1.txt","r");/*open txt file to read*/
			/*taking id with loop*/
			while(fscanf(info_fp,"%d;",&id_controller) == 1)
			{
				/*checking for id */
				if(id_controller == id)
				{
					if(exam_number == 3)
					{
						/*taking midterms and final grades and finds gpa result for both*/
						fscanf(info_fp,"%d;",&midterm1);
						fscanf(info_fp,"%d;",&midterm2);
						fscanf(info_fp,"%d;",&final);
						midterm_ave = (float)(midterm1 + midterm2)/2;
						if(midterm_ave<midterm_ave_102 && midterm_ave<40)
							midterm_gpa = 1.0;
						else if(midterm_ave<midterm_ave_102 && midterm_ave>=40)
							midterm_gpa = 2.5;
						else if(midterm_ave>=midterm_ave_102 && midterm_ave>=40)
							midterm_gpa = 3.0;
						else if(midterm_ave>=midterm_ave_102 && midterm_ave<90)
							midterm_gpa = 3.5;
						else if(midterm_ave>=90)
							midterm_gpa = 4.0;
					
						if(final<final_ave_102 && final<40)
							final_gpa = 1.0;
						else if(final<final_ave_102 && final>=40)
							final_gpa = 2.5;
						else if(final>=final_ave_102 && final>=40)
							final_gpa = 3.0;
						else if(final>=final_ave_102 && final<90)
							final_gpa = 3.5;
						else if(final>=90)
							final_gpa = 4.0;
					}
					else
					{
						/*taking midterm and final grades and finds gpa result for both*/
						fscanf(info_fp,"%d;",&midterm1);
						fscanf(info_fp,"%d;",&final);
						if(midterm1<midterm_ave_108 && midterm1<40)
							midterm_gpa = 1.0;
						else if(midterm1<midterm_ave_108 && midterm1<40)
							midterm_gpa = 2.5;
						else if(midterm1>=midterm_ave_108 && midterm1>=40)
							midterm_gpa = 3.0;
						else if(midterm1>=midterm_ave_108 && midterm1<90)
							midterm_gpa = 3.5;
						else if(midterm1>=90)
							midterm_gpa = 4.0;
						
						if(final<final_ave_108 && final<40)
							final_gpa = 1.0;
						else if(final<final_ave_108 && final>=40)
							final_gpa = 2.5;
						else if(final>=final_ave_108 && final>=40)
							final_gpa = 3.0;
						else if(final>=final_ave_108 && final<90)
							final_gpa = 3.5;
						else if(final>=90)
							final_gpa = 4.0;
					}
					/*calculating average grade and multiply with 100 to make it as integer with floating numbers of real result*/
					average_grade = 100*((midterm_gpa + final_gpa)/2);
				}
				else/*if we do not find id taking characters till end of line*/
					while(fscanf(info_fp,"%c",&x) == 1 && x != '\n');
			}
			fclose(info_fp);/*closing txt file*/
			return(average_grade);/*return gpa*/
		}
		else/*if we do not find id taking characters till end of line*/
			while(fscanf(info_fp,"%c",&x) == 1 && x != '\n');	
	}
}
int f_course_id(FILE *info_fp,int id)
{
	int id_controller;/*to check id equal to student id which user gave*/
	int code,counter = 0;
	int midterm1 = 0,midterm2 = 0,final = 0;
	char x;
	info_fp = fopen("first 1.txt","r");/*open txt file to read*/
	/*taking id with while loop*/
	while(fscanf(info_fp,"%d;",&id_controller) == 1)
	{
		if(id_controller == id)
		{
			/*calculating exam number*/
			while(fscanf(info_fp,"%c",&x) == 1 && x != '\n')
			{
				if(x == ';')
					counter++;
			}
			fclose(info_fp);/*closing txt file*/
			info_fp = fopen("first 1.txt","r");/*open txt file to read*/
			/*taking id with while loop*/
			while(fscanf(info_fp,"%d;",&id_controller) == 1)
			{
				if(id_controller == id)
				{
					if(counter == 3)
					{
						fscanf(info_fp,"%d;",&midterm1);
						fscanf(info_fp,"%d;",&midterm2);
						fscanf(info_fp,"%d;",&final);
						fscanf(info_fp,"%d",&code);
					}
					else
					{
						fscanf(info_fp,"%d;",&midterm1);
						fscanf(info_fp,"%d;",&final);
						fscanf(info_fp,"%d",&code);
					}
				}
				else/*if we do not find id taking characters till end of line*/
					while(fscanf(info_fp,"%c",&x) == 1 && x != '\n');
			}
			fclose(info_fp);/*closing txt file*/
			return(code);/*returns class code*/
		}
		else/*if we do not find id taking characters till end of line*/
			while(fscanf(info_fp,"%c",&x) == 1 && x != '\n');
	}
}
int student_control(FILE *id_fp,int id)
{
	int id_controller,correct;
	char x;
	int controller = 0;
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with while loop*/
	while(fscanf(id_fp,"%d;",&id_controller) == 1)
	{
		if(id_controller == id)
		{
			while(fscanf(id_fp,"%c",&x) == 1 && controller != 2)
			{
				if(x == ';') 
					controller++;
			}
			if(x == 's') 
				correct = 1;
			else 
				correct = 0;
			fclose(id_fp);/*closing txt file*/
			return(correct);
		}
		else
			while(fscanf(id_fp,"%c",&x) == 1 &&  x != '\n');
	}
}
int instructor_lessons(FILE *info_fp,int id)
{
	int id_controller,class_num;
	char x;
	info_fp = fopen("first 1.txt","r");/*open txt file to read*/
	/*taking id with while loop*/
	while(fscanf(info_fp,"%d;",&id_controller) == 1)
	{
		if(id_controller == id)
		{
			fscanf(info_fp,"%d;",&class_num);
			fclose(info_fp);/*closing txt file*/
			return(class_num);
		}
		else
			while(fscanf(info_fp,"%c",&x) == 1 && x != '\n');
	}
}
void id_for_role(FILE *id_fp,char role)
{
	int id,department,count = 0;
	char x;
	id_fp = fopen("second 1.txt","r");/*open txt file to read*/
	/*taking id with while loop*/
	while(fscanf(id_fp,"%d;",&id) == 1)
	{
		count = 0;
		while(fscanf(id_fp,"%c",&x) == 1 && count != 2)
		{
			if(x == ';')
				count++;
		}
		if(x == role)
		{
			while(x != ';' && fscanf(id_fp," %c",&x) == 1);
			fscanf(id_fp,"%d",&department);
			if(role == 's')
				printf("With %d id person is a student and department is %d\n",id,department);
			else if(role == 'i')
				printf("With %d id person is a instructor and department is %d\n",id,department);
		}
		while(fscanf(id_fp,"%c",&x) == 1 && x != '\n');
	}
	fclose(id_fp);/*closing txt file*/
}
void averages(FILE *info_fp,FILE *ave_fp)
{
	int total_midterm1_102 = 0,total_midterm2_102 = 0,final_102_total = 0,counter_102 = 0,total_midterms_102;
	int total_midterm1_108 = 0,total_midterm2_108 = 0,final_108_total = 0,counter_108 = 0;
	int midterm1,midterm2,final;
	int id,a,code;
	char x;
	info_fp = fopen("first 1.txt","r");
	ave_fp = fopen("averages.txt","w");
	while(fscanf(info_fp,"%d;%d;%d;%d;%d",&id,&midterm1,&midterm2,&final,&code) == 5)
	{
		total_midterm1_102 += midterm1;
		total_midterm2_102 += midterm2;
		final_102_total += final;
		counter_102++;
	}
	total_midterm1_108 += midterm1;
	final_108_total += midterm2;
	counter_108++;
	while(fscanf(info_fp,"%d;%d;%d;%d",&id,&midterm1,&final,&code) == 4)
	{
		total_midterm1_108 += midterm1;
		final_108_total += final;
		counter_108++;
	}
	fclose(info_fp);
	total_midterms_102 = total_midterm1_102 + total_midterm2_102;
	fprintf(ave_fp,"102;%.2f;%.2f\n",(float)total_midterms_102/(counter_102*2),(float)final_102_total/counter_102);
	fprintf(ave_fp,"108;%.2f;%.2f\n",(float)total_midterm1_108/counter_108,(float)final_108_total/counter_108);
	fclose(ave_fp);
}
void pass_or_not(FILE *table)
{
	int id,course_id;
	float gpa;
	char letter;
	table = fopen("table.txt","r");
	while(fscanf(table,"%d;%d;%f;%c",&course_id,&id,&gpa,&letter) == 4)
	{
		if(letter != 'F')
			printf("Student with %d id passed %d class with %c letter\n",id,course_id,letter);
		else
			printf("Student with %d id did not pass %d classs\n",id,course_id);
	}
	fclose(table);
}
void pass_or_not_first_initial(FILE *table,int student_id)
{
	int id,course_id;
	float gpa;
	char letter;
	table = fopen("table.txt","r");
	while(fscanf(table,"%d;%d;%f;%c",&course_id,&id,&gpa,&letter) == 4)
	{
		if(id == student_id)
		{
			if(letter != 'F')
				printf("Student with %d id passed %d class with %c letter\n",id,course_id,letter);
			else
				printf("Student with %d id did not pass %d classs\n",id,course_id);
			
		}
	}
	fclose(table);
}
void gpa(FILE *table,int student_id)
{
	int id,course_id;
	float gpa;
	char letter;
	table = fopen("table.txt","r");
	while(fscanf(table,"%d;%d;%f;%c",&course_id,&id,&gpa,&letter) == 4)
	{
		if(id == student_id)
			printf("Student with %d id has %.2f GPA and letter grade is %c for class %d\n",id,gpa,letter,course_id);
	}
	fclose(table);
}
void pass_or_not_class(FILE *table,int id_of_course)
{
	int id,course_id;
	float gpa;
	char letter,character;
	table = fopen("table.txt","r");
	while(fscanf(table,"%d;",&course_id) == 1)
	{
		if(course_id == id_of_course)
		{
			fscanf(table,"%d;%f;%c",&id,&gpa,&letter);
			if(letter != 'F')
				printf("Student with %d id passed %d course with %c letter\n",id,course_id,letter);
			else
				printf("Student with %d id did not pass %d course\n",id,course_id);
		}
		else
			while(fscanf(table,"%c",&character) == 1 && character!= '\n');
	}
	fclose(table);
}
void new_table(FILE *info_fp,FILE *ave_fp,FILE *table)
{
	int student_id,course_id_averages,course_id;
	int midterm1,midterm2,final,tmp;
	float midterm_averages;
	float midterm_ave_102,final_ave_102;
	float midterm_ave_108,final_ave_108;
	float letter_gpa,letter_mid,letter_fin;
	char letter;
	ave_fp = fopen("averages.txt","r");
	table = fopen("table.txt","w");
	while(fscanf(ave_fp,"%d;",&course_id_averages) == 1)
	{
		if(course_id_averages == 102)
			fscanf(ave_fp,"%f;%f",&midterm_ave_102,&final_ave_102);
		else if(course_id_averages == 108)
			fscanf(ave_fp,"%f;%f",&midterm_ave_108,&final_ave_108);
	}
	fclose(ave_fp);
	info_fp = fopen("first 1.txt","r");
	while(fscanf(info_fp,"%d;%d;%d;%d;%d",&student_id,&midterm1,&midterm2,&final,&course_id) == 5)
	{
		midterm_averages = (float)(midterm1 + midterm2 )/2;
		if(midterm_averages<40 && midterm_averages<midterm_ave_102)
			letter_mid = 1;
		else if(midterm_averages>=40 && midterm_averages<midterm_ave_102)
			letter_mid = 2.5;
		else if(midterm_averages>=40 && midterm_averages>=midterm_ave_102)
			letter_mid = 3;
		else if(midterm_averages>=90 && midterm_averages>=midterm_ave_102)
			letter_mid = 3.5;
		else if(midterm_averages>=90)
			letter_mid = 4;

		if(final<40 && final<final_ave_102)
			letter_fin = 1;
		else if(final>=40 && final<final_ave_102)
			letter_fin = 2.5;
		else if(final>=40 && final>=final_ave_102)
			letter_fin = 3;
		else if(final<90 && final>=final_ave_102)
			letter_fin = 3.5;
		else if(final>=90)
			letter_fin = 4;

		letter_gpa = (letter_fin + letter_mid)/2;
		if(letter_gpa<1.5)
			letter = 'F';
		else if(letter_gpa>=1.5 && letter_gpa<=2.5)
			letter = 'D';
		else if(letter_gpa>2.5 && letter_gpa<=3)
			letter = 'C';
		else if(letter_gpa>3 && letter_gpa<=3.5)
			letter = 'B';
		else if(letter_gpa>3.5)
			letter = 'A';
		fprintf(table,"102;%d;%.2f;%c\n",student_id,(float)average_grade(info_fp,student_id)/100,letter);
	}
	final = midterm2;
	do
	{
		if(midterm1<40 && midterm1<midterm_ave_108)
        	letter_mid = 1;
		else if(midterm1>=40 && midterm1<midterm_ave_108)
			letter_mid = 2.5;
		else if(midterm1>=40 && midterm1>=midterm_ave_108)
			letter_mid = 3;
		else if(midterm1<90 && midterm1>=midterm_ave_108)
			letter_mid = 3.5;
		else if(midterm1>=90)
			letter_mid = 4;

		if(final<40 && final<final_ave_108)
			letter_fin = 1;
		else if(final>=40 && final<final_ave_108)
			letter_fin = 2.5;
		else if(final>=40 && final>=final_ave_108)
			letter_fin = 3;
		else if(final<90 && final>=final_ave_108)
			letter_fin = 3.5;
		else if(final>=90)
			letter_fin = 4;

		letter_gpa = (letter_fin + letter_mid) / 2;
		if(letter_gpa<1.5)
			letter = 'F';
		else if(letter_gpa>=1.5 && letter_gpa<=2.5)
			letter = 'D';
		else if(letter_gpa>2.5 && letter_gpa<=3)
			letter = 'C';
		else if(letter_gpa>3 && letter_gpa<=3.5)
			letter = 'B';
		else if(letter_gpa>3.5)
	        letter = 'A';
		fprintf(table,"108;%d;%.2f;%c\n",student_id,(float)average_grade(info_fp,student_id)/100,letter);
	}
	while(fscanf(info_fp,"%d;%d;%d;%d",&student_id,&midterm1,&final,&course_id) == 4);
	fclose(table);
	fclose(info_fp);
}
void menu()
{
	printf("Please select your choice\n");
	printf("‘p’: Print all the users pass or fail\n");
	printf("‘n’: Print only the user with a specific first initial\n");
	printf("‘g’: Calculate the GPA of a given student\n");
	printf("‘c’: Print whether each user passed or failed the same class\n");
	printf("‘t’: Print the number of classes for the instructor\n");
	printf("‘d’: Print the department of all persons according to the role\n");
	printf("‘l’: Print the course_id of a given student\n");
	printf("‘e’: Quit the program\n");
	printf("Your choice is : ");
}
int main()
{
	int id ,course_id,control;
	char choice,role,first_letter;
	FILE *id_fp;
	FILE *info_fp;
	FILE *ave_fp;
	FILE *table;
	averages(info_fp,ave_fp);
	new_table(info_fp,ave_fp,table);
	menu();
	scanf("%c",&choice);
	printf("\n");
	while(choice != 'e')
	{
		switch(choice)
		{
			case 'p':
				pass_or_not(table);
				break;
			case 'n':
				printf("Enter the first letter of the student : ");
				scanf(" %c",&first_letter);
				id = get_id_fi(id_fp,first_letter);
				pass_or_not_first_initial(table,id);
				break;
			case 'g':
				printf("Enter student id : ");
				scanf("%d",&id);
				gpa(table,id);
				break;
			case 'c':
				printf("Enter course id : ");
				scanf("%d",&course_id);
				pass_or_not_class(table,course_id);
				break;
			case 't':
				printf("Enter instructor id : ");
				scanf("%d",&id);
				printf("That instructor has %d lessons\n",instructor_lessons(info_fp,id));
				break;
			case 'd':
				printf("Enter the first letter of the role : ");
				scanf(" %c",&role);
				id_for_role(id_fp,role);
				break;
			case 'l':
				printf("Enter student id : ");
				scanf("%d",&id);
				control = student_control(id_fp,id);
				if(control == 0)
					printf("That id is not a students id\n");
				else
					printf("Student takes %d lesson\n",f_course_id(info_fp,id));
				break;
			default :
				printf("!!Please enter a valid valur from menu\n\n");
		}
		menu();
		scanf(" %c",&choice);
		printf("\n");
	}
	printf("Thanks for choosing us for your query issues\n");
	return 0;
}