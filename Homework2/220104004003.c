#include <stdio.h>
int main()
{
	/*variables for taking inputs and comparing*/
	int x_tmp,y_tmp,class;
	int option = 0,best_x,best_y,checking_option = 0;
	int x_0_min = 100,x_0_max = -100,y_0_min = 100,y_0_max = -100;
	int x_1_min = 100,x_1_max = -100,y_1_min = 100,y_1_max = -100;
	/*variables to find best region labels and comparing*/
	int r_1,r_2,r_3,r_4;
	int r_1_best,r_2_best,r_3_best,r_4_best;
	/*till option is equal 4 it countinue to loop*/
	while(option != 4)
	{
		printf("\nPlease select option from following menu\n");/*prints menu*/
		printf("1) Explore Data\n");
		printf("2) Train Model\n");
		printf("3) Test Model\n");
		printf("4) Exit\n");
		printf("Your option is : ");
		scanf("%d",&option);/*taking option*/
		if(option == 1)/*if option is 1 then*/
		{
			FILE *adress;/*file pointer of data.txt file*/
			adress = fopen("data.txt","r");
			/*if the number of inputs are 3 it starts for while loop*/
			while(fscanf(adress,"%d %d %d",&x_tmp,&y_tmp,&class) == 3)
			{
				if(class == 0)/*if class is 0 then it checking for class 0*/
				{
					/*comparing for max-min values of data.txt class 0*/
					if(x_tmp > x_0_max)
						x_0_max = x_tmp;
					if(x_tmp < x_0_min)
						x_0_min = x_tmp;
					if(y_tmp > y_0_max)
						y_0_max = y_tmp;
					if(y_tmp < y_0_min)
						y_0_min = y_tmp;
				}
				else if(class == 1)/*if class is 1 then it checking for class 1*/
				{
					/*comparing for max-min values of data.txt class 1*/
					if(x_tmp > x_1_max)
						x_1_max = x_tmp;
					if(x_tmp < x_1_min)
						x_1_min = x_tmp;
					if(y_tmp > y_1_max)
						y_1_max = y_tmp;
					if(y_tmp < y_1_min)
						y_1_min = y_tmp;
				}
			}
			fclose(adress);
			/*as a result of comparies prints the max-min datas*/
			printf("\nMinimum and Maximum X and Y values ;\n");
			printf("Class 0: X in [%d %d], Y in [%d %d]\n",x_0_min,x_0_max,y_0_min,y_0_max);
			printf("Class 1: X in [%d %d], Y in [%d %d]\n\n",x_1_min,x_1_max,y_1_min,y_1_max);
		}
		else if(option == 2)/*if option is 2 then*/
		{
			FILE *adress;
			adress = fopen("data.txt","r");
			while(fscanf(adress,"%d %d %d",&x_tmp,&y_tmp,&class) ==3)
			{
				if(class == 0)/*same with option 1*/
				{
					if(x_tmp > x_0_max)
						x_0_max = x_tmp;
					if(x_tmp < x_0_min)
						x_0_min = x_tmp;
					if(y_tmp > y_0_max)
						y_0_max = y_tmp;
					if(y_tmp < y_0_min)
						y_0_min = y_tmp;
				}
				else if(class == 1)/*same with option 1*/
				{
					if(x_tmp > x_1_max)
						x_1_max = x_tmp;
					if(x_tmp < x_1_min)
						x_1_min = x_tmp;
					if(y_tmp > y_1_max)
						y_1_max = y_tmp;
					if(y_tmp < y_1_min)
						y_1_min = y_tmp;
				}
			}
			fclose(adress);
			/*prints min-max values for class0 and class1*/
			printf("\nMinimum and Maximum X and Y values ;\n");
			printf("Class 0: X in [%d %d], Y in [%d %d]\n",x_0_min,x_0_max,y_0_min,y_0_max);
			printf("Class 1: X in [%d %d], Y in [%d %d]\n",x_1_min,x_1_max,y_1_min,y_1_max);
			int x_max,y_max,x_min,y_min,x,y,previous_wrong = 100;
			int error;
			/*try to find general min-max values for x and y*/
			if(x_0_max > x_1_max)
				x_max = x_0_max;
			else
				x_max = x_1_max;
			
			if(y_0_max > y_1_max)
				y_max = y_0_max;
			else
				y_max = y_1_max;
			
			if(x_0_min < x_1_min)
				x_min = x_0_min;
			else
				x_min = x_1_min;
			
			if(y_0_min < y_1_min)
				y_min = y_0_min;
			else
				y_min = y_1_min;

			x = x_min;
			y = y_min;
			while(x<=x_max)/*for all x values*/
			{
				y = y_min;/*to start loop from y_min*/
				while(y <= y_max)/*for all y values*/
				{
					int tour = 0;
					/*for all 16 different label combination it controls the errors*/
					for(;tour<16;tour++)
					{
						error = 0;
						if(tour == 0)
							r_1 = 0, r_2 = 0, r_3 = 0, r_4 = 0;

						else if(tour == 1)
							r_1 = 0, r_2 = 0, r_3 = 0, r_4 = 1;

						else if(tour == 2)
							r_1 = 0, r_2 = 0, r_3 = 1, r_4 = 0;

						else if(tour == 3)
							r_1 = 0, r_2 = 1, r_3 = 0, r_4 = 0;

						else if(tour == 4)
							r_1 = 1, r_2 = 0, r_3 = 0, r_4 = 0;

						else if(tour == 5)
							r_1 = 1, r_2 = 1, r_3 = 0, r_4 = 0;

						else if(tour == 6)
							r_1 = 1, r_2 = 0, r_3 = 1, r_4 = 0;

						else if(tour == 7)
							r_1 = 1, r_2 = 0, r_3 = 0, r_4 = 1;

						else if(tour == 8)
							r_1 = 0, r_2 = 1, r_3 = 1, r_4 = 0;

						else if(tour == 9)
							r_1 = 0, r_2 = 1, r_3 = 0, r_4 = 1;

						else if(tour == 10)
							r_1 = 0, r_2 = 0, r_3 = 1, r_4 = 1;

						else if(tour == 11)
							r_1 = 1, r_2 = 1, r_3 = 1, r_4 = 0;

						else if(tour == 12)
							r_1 = 1, r_2 = 1, r_3 = 0, r_4 = 1;

						else if(tour == 13)
							r_1 = 1, r_2 = 0, r_3 = 1, r_4 = 1;
						
						else if(tour == 14)
							r_1 = 0, r_2 = 1, r_3 = 1, r_4 = 1;
						
						else if(tour == 15)
							r_1 = 1, r_2 = 1, r_3 = 1, r_4 = 1;
						
						adress = fopen("data.txt","r");
						/*readining datas and checking if their classes are in correct place or not*/
						while(fscanf(adress,"%d %d %d",&x_tmp,&y_tmp,&class) == 3)
						{
							if(x_tmp<=x && y_tmp>y)
							{
								if(r_1 != class)
									error++;
							}
							else if(x_tmp >x && y_tmp>y)
							{
								if(r_2 != class)
									error++;
							}
							else if(x_tmp<=x && y_tmp<=y)
							{
								if(r_3 != class)
									error++;
							}
							else if(x_tmp > x && y_tmp<=y)
							{
								if(r_4 != class)
									error++;
							}
						}
						fclose(adress);
						/*if for the new values errors is less than previous best it changec the classes and separators*/
						if(error < previous_wrong)
						{
							previous_wrong = error;
							r_1_best = r_1,r_2_best = r_2,r_3_best = r_3,r_4_best = r_4;
							best_x = x, best_y = y;
						}
					}
					y++;
				}
				x++;
			}
			/*prints the best x-y separators and class labels*/
			printf("Separator is X = %d and Y = %d\n",best_x,best_y);
			printf("R1 label is %d\n",r_1_best);
			printf("R2 label is %d\n",r_2_best);
			printf("R3 label is %d\n",r_3_best);
			printf("R4 label is %d\n",r_4_best);
			printf("Only %d errors\n",previous_wrong);
			checking_option = 2;
		}
		/*if option is 3 and checking option is 2 then*/
		else if(option == 3 && checking_option == 2)
		{
			/*variables for taking inputs*/
			int x_tmp_test,y_tmp_test,class_test,total_data = 0;
			int error_test = 0;
			float success;
			int x_final,y_final,class_final;
			FILE *adress_final;
			FILE *adress_test;
			adress_test = fopen("test 1.txt","r");
			/*counting total data of test1.txt*/
			while(fscanf(adress_test,"%d %d %d",&x_tmp_test,&y_tmp_test,&class_test) == 3)
				total_data++;
			fclose(adress_test);
			adress_test = fopen("test 1.txt","r");
			/*readining datas and checking if their classes are correct place or not*/
			while(fscanf(adress_test,"%d %d %d",&x_tmp_test,&y_tmp_test,&class_test) == 3)
			{
				if(x_tmp_test<=best_x && y_tmp_test>best_y)
				{
					if(r_1_best != class_test)
						error_test++;
				}
				else if(x_tmp_test > best_x && y_tmp_test>best_y)
				{
					if(r_2_best != class_test)
						error_test++;
				}
				else if(x_tmp_test<=best_x && y_tmp_test<=best_y)
				{
					if(r_3_best != class_test)
						error_test++;
				}
				else if(x_tmp_test > best_x && y_tmp_test<=best_y)
				{
					if(r_4_best != class_test)
						error_test++;
				}
			}
			fclose(adress_test);
			/*calculating success and prints it and also separators and region classes*/
			success =((total_data - error_test) / (float)total_data ) *100;
			printf("\nSpearator X: %d and Y: %d\n",best_x,best_y);
			printf("Best r1 = %d\n",r_1_best);
			printf("Best r2 = %d\n",r_2_best);
			printf("Best r3 = %d\n",r_3_best);
			printf("Best r4 = %d\n",r_4_best);
			printf("Only %d erros in  %d datas\n",error_test,total_data);
			printf("Success is %.2f\n\n",success);
			printf("For test final class labels\n");
			adress_final = fopen("test-final.txt","r");
			/*if the number of inputs is 2 then it starts(countinue while loop)*/
			while(fscanf(adress_final,"%d %d",&x_final,&y_final) == 2)
			{
				/*according to regions labels and separators it predicts the correct class for each data*/
				if(x_final<=best_x && y_final>best_y)
					class_final = r_1_best;

				else if(x_final > best_x && y_final>best_y)
					class_final = r_2_best;

				else if(x_final<=best_x && y_final<=best_y)
					class_final = r_3_best;

				else if(x_final > best_x && y_final<=best_y)
					class_final = r_4_best;
				printf("%d %d %d\n",x_final,y_final,class_final);
			}
			fclose(adress_final);
		}
		/*if option is 3 and checking option is not 2 then*/
		else if(option == 3 && checking_option != 2)
			printf("\n!!You can not select option 3 before selecting option 2\n");
		/*if option is 4 the it breaks the loop*/
		else if(option == 4)
			break;
		/*if user do not enter between 1-4 then it printserror message*/
		else
			printf("\n!!Unacceptable value\n");
	}
	printf("Thanks for choosing us\n");
	return 0;
}
