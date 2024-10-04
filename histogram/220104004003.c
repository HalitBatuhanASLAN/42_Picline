#include<stdio.h>
#define MAX_SIZE 250
/*Prototypes*/
int find_size_of_array(int array[]);
void average(int number_array[], int max, int min,int size);
void frequency(int number_array[], int new_array[],int max, int min,int size);
void interval(int histogram_arr[],int min,int max);
void printing_histogram(int new_array[], int max, int min);
void mode(int new_array[], int histogram_arr[], int max, int min);
void median(int new_array[],int histogram_arr[], int max, int min);
void adding_to_histogram(int number_array[], int adding_nums[], int last_array[],int quantity, int new_array[],int max, int min);
int main()
{
    int number_array[] = {22,40,55,55,60,71,71,71,80,80,80,95,147,180,320,-1};
    int min,max,controller = 1;
    int size = find_size_of_array(number_array) +1;
    char choise = 1;
    int quantity = 0,adding_number = 0;
    int adding_nums[5];
    int last_array[size+5];
    /*to take accepted values*/
    while(controller)
    {
        printf("Enter min and max values : ");
        scanf("%d %d",&min,&max);
        if(min>=50 && max<=200 && min<max)
            controller = 0;
        if(min<50)
            printf("min value can not be less than 50.Enter new values\n");
        if(max>200)
            printf("max value can not be higher than 200.Enter new values\n");
        if(min>=max)
            printf("Min value can not be equal or higher than max value.Enter new values\n");
    }
    /*integer arrays to store values for interval*/
    int new_array[MAX_SIZE];
    int histogram_arr[MAX_SIZE];
    interval(histogram_arr,min,max);
    frequency(number_array,new_array,max,min,size);
    printing_histogram(new_array,max,min);
    int j;
    for(j = 0;number_array[j] != -1;j++)
        last_array[j] = number_array[j];
    last_array[j] = -1;
    while(choise != '0')
    {
        printf("Would you like to add new numbers? (Press 1 for yes and 0 for no) : ");
        scanf(" %c",&choise);
        switch(choise)
        {
            case '1':
                quantity = 0;
                adding_number = 0;
                printf("Enter the numbers(new line for each num)(max 5 and for less than 5 enter -1 to break);\n");                
                /*taking numbers for new histogram*/
                while(quantity<5 && adding_number != -1)
                {
                    scanf("%d",&adding_number);
                    if(adding_number != -1)
                    {
                        adding_nums[quantity] = adding_number;
                        quantity++;
                    }
                }
                /*updating histogram and prints it*/
                adding_to_histogram(number_array,adding_nums,last_array,quantity,new_array,max,min);
                printing_histogram(new_array,max,min);
                choise = '0';
                break;
            case '0':
                break;
            default:
                /*for unaccepted values error message*/
                printf("!!Please enter a valid value\n");
        }
    }
    /*finding new size*/
    size = find_size_of_array(last_array);
    /*calculating average,mode,median values*/
    average(last_array,max,min,size);
    mode(new_array,histogram_arr,max,min);
    median(new_array,histogram_arr,max,min);
    return 0;
}
int find_size_of_array(int array[])
{
    int i = 0;
    /*for loop until -1 is new value*/
    for(;array[i] != -1;i++);
    /*return size except -1*/
    return(i);
}
void average(int last_array[],int max,int min,int size)
{
    int i = 0;
    int sum = 0,counter = 0;
    float average;
    /*for loop to find total sum of values */
    for(;i<size;i++)
    {
        if(last_array[i] <= max && last_array[i] >= min) 
        {
            sum += last_array[i];
            counter++;/*increment counter to find numbers of list*/
        }
    }
    /*calculating average of list*/
    average = (float)sum / counter;
    printf("Average : %.2f\n",average);
}
void interval(int histogram_arr[],int min,int max)
{
    int i = 0,tmp_min = min;
    for(;tmp_min<=max;tmp_min++,i++)
        histogram_arr[i] = tmp_min;
}
void frequency(int number_array[],int new_array[],int max,int min,int size)
{
    int i = 0,j = 0,frequency  = 0,tmp_min = min;
    /*for loops to writing frequency of all numbers which are in interval in new_array*/
    for(;tmp_min<=max;tmp_min++,j++)
    {
        for(i = 0,frequency = 0;i<size;i++)
        {
            if(number_array[i] == tmp_min)
                frequency++;
        }
        new_array[j] = frequency;
    }
}
void printing_histogram(int new_array[],int max,int min)
{
    int line = 0,tmp_arr[max-min];
    int i = 0,column= max-min+1;
    /*copy values from new_array to tmp_arr*/
    for(;i<=max-min;i++)
        tmp_arr[i] = new_array[i];
    /*calculating line size*/
    for(i = 0;i<column;i++)
    {
        if(new_array[i] >= line)
            line = new_array[i];
    }
    int k;
    printf("\n");
    /*loop through each lines*/
    for(;line>0;line--)
    {
        k = 0;
        /*loop through each columns*/
        for(;k<column;k++)
        {
            if(line == tmp_arr[k])
            {
                /*star if there is number*/
                printf("*");
                /*decrement frequency of number*/
                tmp_arr[k]--;
            }
            else
                printf(" ");/*space if there is no number*/   
        }
        printf("\n");
    }
    printf("\n");
}
void mode(int new_array[],int histogram_arr[],int max,int min)
{
    int i = 0;
    int maximum = 0;
    printf("Mode : ");
    /*find the maximum frequency in the histogram*/
    for(i = 0;i<max-min+1;i++)
    {
        if(new_array[i] >= maximum)
            maximum = new_array[i];
    }
    /*printing modes*/
    for(i = 0;i<max-min+1;i++)
    {
        if(new_array[i] ==  maximum)
            printf("%d ",histogram_arr[i]);
    }
    printf("\n");
}
void median(int new_array[],int histogram_arr[],int max,int min)
{
    int tmp_arr[150];
    int size = 0,i = 0,j = 0,sum = 0,a;
    float median;
    /*add values into the tempurary array*/
    for(;min<=max;min++)
    {
        for(a = new_array[i];a>0;a--,j++)
        {
            tmp_arr[j] = histogram_arr[i];
            size++;
        }
        i++;
    }
    /*calculate the median*/
    median = (float)tmp_arr[size/2];
    /*if size is even then add the previous with median to calculate the correct median*/
    if(size % 2 == 0)
        median = (median + tmp_arr[size/2 -1])/2;
    printf("Median : %.2f\n",median);
}
void adding_to_histogram(int number_array[],int adding_nums[],int last_array[],int quantity,int new_array[],int max,int min)
{
    int size = find_size_of_array(last_array);
    int i,j,new_size;
    /*copy elements from number_array to last_array until -1 is encountered*/
    for(j = 0;number_array[j] != -1;j++)
        last_array[j] = number_array[j];
    /*add elements from adding_nums to last_array*/
    for(j = 0;quantity>0;quantity--,j++)
        last_array[size+j] = adding_nums[j];
    last_array[size+j] = -1;
    /*updating new_size*/
    new_size = size+j;
    /*update frequency information*/
    frequency(last_array,new_array,max,min,new_size);
}