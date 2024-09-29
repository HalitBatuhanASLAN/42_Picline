#include<stdio.h>
#include<string.h>
#define BINARRY_NUM_SIZE 9 /*size for 8 bits binary values*/
#define INSTRUCTION_NUM 30 /*max instructions number*/
#define MEMORY_CAPACITY 128 /*max memory capacitor*/
#define REGISTER_A 102 /*definening adress of register A*/
#define REGISTER_B 103 /*definening adress of register B*/
#define PROGRAM_COUNTER_1 104 /*definening adress of program counter 1*/
#define PROGRAM_COUNTER_2 105 /*definening adress of program counter 2*/
#define INSTRUCTION_REGISTER 106 /*definening adress of instruction register*/
/*Define binary addresses for registers A and B*/
char adress_of_register_A[BINARRY_NUM_SIZE] = "01100110";
char adress_of_register_B[BINARRY_NUM_SIZE] = "01100111";
/*Define a structure to represent the assembly simulator*/
struct assembly_simulator
{
    char A[BINARRY_NUM_SIZE];/*for register A*/
    char B[BINARRY_NUM_SIZE];/*for register B*/
    char PC[2][BINARRY_NUM_SIZE];/*for program counters*/
    char IR[3][BINARRY_NUM_SIZE];/*for instructions registers*/
};
/*Define a structure to represent the instructions ifnormations*/
struct instructions
{
    char opcode[BINARRY_NUM_SIZE];/*for opcodes*/
    char type;/*for type value*/
    char format[5];/*for formats*/
    char A[4],B[4];/*for register types*/
};
int to_binary(int decimal_number);
int to_decimal(char bianry_number[BINARRY_NUM_SIZE]);
void instruction_file(struct instructions instruction_from_file[INSTRUCTION_NUM]);
void taking_assembly_code_from_file(char *file_name,char memory[MEMORY_CAPACITY][2][9],struct instructions instruction_from_file[INSTRUCTION_NUM],char tmp_array[30][3][9]);
void initializing_memory(struct instructions instruction_from_file[INSTRUCTION_NUM],char memory[MEMORY_CAPACITY][2][9],char tmp_array[20][3][9],int *line);
void decoding_and_fetching(struct instructions instruction_from_file[INSTRUCTION_NUM],char memory[MEMORY_CAPACITY][2][9]);
void ADD_function(struct assembly_simulator *assembly);
void ADDI_function(struct assembly_simulator *assembly);
void ADDM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void SUB_function(struct assembly_simulator *assembly);
void SUBI_function(struct assembly_simulator *assembly);
void SUBM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void INC_function(struct assembly_simulator *assembly);
void DEC_function(struct assembly_simulator *assembly);
void SWP_function(struct assembly_simulator *assembly);
void PRI_function(struct assembly_simulator *assembly);
void PRII_function(struct assembly_simulator *assembly);
void PRIM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void AND_function(struct assembly_simulator *assembly);
void ANDI_function(struct assembly_simulator *assembly);
void ANDM_fnction(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void OR_function(struct assembly_simulator *assembly);
void ORI_function(struct assembly_simulator *assembly);
void ORM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void NOR_function(struct assembly_simulator *assembly);
void LESS_function(struct assembly_simulator *assembly);
void GRT_function(struct assembly_simulator *assembly);
void LDAI_function(struct assembly_simulator *assembly);
void LDA_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void STR_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9]);
void J_function(struct assembly_simulator *assembly);
void SHL_function(struct assembly_simulator *assembly);
void SHR_function(struct assembly_simulator *assembly);
int BRE_function(struct assembly_simulator *assembly);
int BRN_function(struct assembly_simulator *assembly);
void printing_memory(char memory[MEMORY_CAPACITY][2][9]);
int main()
{
    /*to keep memory*/
    char memory[MEMORY_CAPACITY][2][BINARRY_NUM_SIZE];
    /*to keep intructions informations according to values on struct*/
    struct instructions instruction_from_file[INSTRUCTION_NUM];
    /*keeping informations of instructions*/
    instruction_file(instruction_from_file);
    char choise = '1';
    /*to keep file name and keeping instructions from .asm file*/
    char file_name[50],tmp_array[30][3][BINARRY_NUM_SIZE];
    /*while user enter 0 take .asm file name and do processes*/
    do
    {
        printf("Enter the filename : ");
        scanf("%s",file_name);
        /*control if it is valid or not*/
        if(strstr(file_name,".asm") == NULL)
        {
            printf("Please enter the file name with '.asm'\n");
            continue;
        }
        printf("file name : %s\n",file_name);
        /*taking code from file into tempruary array than memory*/
        taking_assembly_code_from_file(file_name,memory,instruction_from_file,tmp_array);
        /*decoding and fetching parts of code*/
        decoding_and_fetching(instruction_from_file,memory);
        printf("Last situation of memory\n");
        /*printing last form of memory*/
        printing_memory(memory);
        /*taking if user want to countinue or not*/
        do
        {
            printf("\nDo you want to execute another assembly code : Press (1) for yes (0) for exit : ");
            scanf(" %c",&choise);
            if(choise != '0' && choise != '1')
                printf("Please enter a valid value 1 or 0\n");
        }while(choise != '1' && choise != '0');
    }
    while(choise != '0' && choise == '1');
    printf("\nThanks for chosing our assembly simulator\nHave a good day\n");
    return 0;
}
/*printing memory*/
void printing_memory(char memory[MEMORY_CAPACITY][2][9])
{
    int line;/*%-8s to write from left with 8 bits long*/
    for(line = 0;line<MEMORY_CAPACITY;line++)
        printf("%-8s%-8s\n",memory[line][0],memory[line][1]);
}
/*decoding and fetcing of code*/
void decoding_and_fetching(struct instructions instruction_from_file[INSTRUCTION_NUM],char memory[MEMORY_CAPACITY][2][9])
{
    /*initialize some variables of assembly struct like program counter value and instructions register values*/
    struct assembly_simulator assembly;
    strcpy(assembly.PC[0],"00000000");
    strcpy(assembly.PC[1],"00000001");
    strcpy(assembly.IR[0],memory[INSTRUCTION_REGISTER-1][1]);
    strcpy(assembly.IR[1],memory[INSTRUCTION_REGISTER][1]);
    strcpy(assembly.IR[2],memory[INSTRUCTION_REGISTER+1][1]);
    strcpy(assembly.A,memory[REGISTER_A-1][1]);
    strcpy(assembly.B,memory[REGISTER_B-1][1]);
    int curret_line = 0,i,decimal_num = 1,value;
    char opcode[9];
    char format[5];
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index;
    int counter = 0;
    int pc_num;
    /*till values in IR is not equal to exit opcode value do processes*/
    while(strcmp(assembly.IR[0],"00011110") != 0)
    {
        strcpy(opcode,assembly.IR[0]);
        /*printf("%s is ir1\n",assembly.IR[0]);
        printf("%s in the reg a\n",assembly.A);
        printf("%s in the reg b\n\n",assembly.B);*/
        /*try to find format of code by using opcode in memory*/
        for(i = 0;i<INSTRUCTION_NUM;i++)
        {
            if(strcmp(opcode,instruction_from_file[i].opcode) == 0)
            {
                strcpy(format,instruction_from_file[i].format);
                break;
            }
        }
        /*comparing current format with formats and according to relevent one calling relevent function*/
        if(strncmp(format,"ADDI",4) == 0)
        {
            printf("Function ADDI\n");
            ADDI_function(&assembly);
        }
        else if(strncmp(format,"ADDM",4) == 0)
        {
            printf("ADDM function\n");
            ADDM_function(&assembly,memory);
        }
        else if(strncmp(format,"ADD",3) == 0) 
        {
            printf("Function ADD\n");
            ADD_function(&assembly);
        }
        else if(strncmp(format,"ANDI",4) == 0)
        {
            printf("ANDI function\n");
            ANDI_function(&assembly);
        }
        else if(strncmp(format,"ANDM",4) == 0)
        {
            printf("ANDM function\n");
            ADDM_function(&assembly,memory);
        }
        else if(strncmp(format,"AND",3) == 0)
        {
            printf("AND function\n");
            AND_function(&assembly);
        }
        else if(strncmp(format,"ORI",3) == 0)
        {
            printf("ORI function\n");
            ORI_function(&assembly);
        }
        else if(strncmp(format,"ORM",3) == 0)
        {
            printf("ORM function\n");
            ORM_function(&assembly,memory);
        }
        else if(strncmp(format,"OR",2) == 0)
        {
            printf("OR function\n");
            OR_function(&assembly);
        }
        else if(strncmp(format,"SUBI",4) == 0)
        {
            printf("SUBI function");
            SUBI_function(&assembly);
        }
        else if(strncmp(format,"SUBM",4) == 0)
        {
            printf("SUBM function");
            SUBM_function(&assembly,memory);
        }
        else if(strncmp(format,"SUB",3) == 0)
        {
            printf("SUB function");
            SUB_function(&assembly);
        }
        else if(strncmp(format,"INC",3) == 0)
        {
            printf("INC function");
            INC_function(&assembly);
        }
        else if(strncmp(format,"DEC",3) == 0)
        {
            printf("DEC function");
            DEC_function(&assembly);
        }
        else if(strncmp(format,"SHL",3) == 0)
        {
            printf("Function SHL\n");
            SHL_function(&assembly);
        }
        else if(strncmp(format,"SHR",3) == 0)
        {
            printf("Function SHR\n");
            SHR_function(&assembly);
        }
        else if(strncmp(format,"BRE",3) == 0) 
        {
            printf("Function BRE\n");
            value = BRE_function(&assembly);
            /*if return values is one than continue from beginning*/
            if(value == 1) continue;
        }
        else if(strncmp(format,"BRN",3) == 0)
        {
            printf("Function BRN\n");
            value = BRN_function(&assembly);
            /*if return values is one than continue from beginning*/
            if(value == 1) continue;
        }
        else if(strncmp(format,"J",1) == 0)
        {
            printf("Function J\n");
            J_function(&assembly);
            /*continue from beginning with new program counter value*/
            continue;
        }
        else if(strncmp(format,"NOR",3) == 0)
        {
            printf("Function NOR\n");
            NOR_function(&assembly);
        }
        else if(strncmp(format,"LDAI",4) == 0) 
        {
            printf("Function LDAI\n");
            LDAI_function(&assembly);
        }
        else if(strncmp(format,"LDA",3) == 0) 
        {
            printf("Function LDA\n");
            LDA_function(&assembly,memory);
        }
        else if(strncmp(format,"STR",3) == 0)
        {
            printf("Function STR\n");
            STR_function(&assembly,memory);
        }
        else if(strncmp(format,"SWP",3) == 0)
        {
            
            printf("Function SWP\n");
            SWP_function(&assembly);
        }
        else if(strncmp(format,"LESS",4) == 0)
        {
            printf("Function LESS\n");
            LESS_function(&assembly);
        }
        else if(strncmp(format,"GRT",3) == 0)
        {
            printf("Function GRT\n");
            GRT_function(&assembly);
        }
        else if(strncmp(format,"PRII",4) == 0)
        {
            printf("Function PRII\n");
            PRII_function(&assembly);
        }
        else if(strncmp(format,"PRIM",4) == 0)
        {
            printf("Function PRIM\n");
            PRIM_function(&assembly,memory);
        }
        else if(strncmp(format,"PRI",3) == 0) 
        {
            printf("Function PRI\n");
            PRI_function(&assembly);
        }
        /*printf("%s in the reg a after oper\n",assembly.A);
        printf("%s in the reg b after oper\n",assembly.B);*/
        /*afeter each step change program counter and keep binary for into PC value of assembly struct*/
        decimal_num += 3;
        pc_num = decimal_num;
        index = BINARRY_NUM_SIZE-2;
        counter = 0;
        while(counter != 8)
        {
            remainder = to_binary(pc_num);
            arr_binary[index] = remainder + 48;
            pc_num /= 2;
            index--;
            counter++;
        }
        arr_binary[counter] = '\0';
        strcpy(assembly.PC[1],arr_binary);
        /*keep new instructions opcodes into IR values of assembly struct*/
        strcpy(assembly.IR[0],memory[decimal_num-1][1]);
        strcpy(assembly.IR[1],memory[decimal_num][1]);
        strcpy(assembly.IR[2],memory[decimal_num+1][1]);
        /*printf("%s is ir1 after operation\n\n",assembly.IR[0]);*/
    }
    /*do the same process for exit situation(it does not doing into while loop)*/
    decimal_num += 3;
    pc_num = decimal_num;
    index = BINARRY_NUM_SIZE-2;
    counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(pc_num);
        arr_binary[index] = remainder + 48;
        pc_num /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly.PC[1],arr_binary);
    /*change some special adresses values of memory according to registers*/
    strcpy(memory[PROGRAM_COUNTER_2-1][1],assembly.PC[1]);
    strcpy(memory[INSTRUCTION_REGISTER-1][1],assembly.IR[0]);
    strcpy(memory[INSTRUCTION_REGISTER][1],assembly.IR[1]);
    strcpy(memory[INSTRUCTION_REGISTER+1][1],assembly.IR[2]);
    strcpy(memory[REGISTER_A-1][1],assembly.A);
    strcpy(memory[REGISTER_B-1][1],assembly.B);
    printf("You have completed all process\n");
}
/*initialize memory*/
void initializing_memory(struct instructions instruction_from_file[INSTRUCTION_NUM],char memory[MEMORY_CAPACITY][2][9],char tmp_array[30][3][9],int *line)
{
    int current_line,i,memory_index,counter,decimal_num,tmp_num;
    float adress;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2,info_num,flag = 0;
    int tmp_A,tmp_B;
    /*
    for(i = 0;i<*line;i++)
    {
        for(info_num = 0;info_num<3;info_num++)
            printf("%d line %d column : %s\n",i+1,info_num+1,tmp_array[i][info_num]);
        printf("\n");
    }*/
    /*assign 8bit long of 0 for bwginnig of memory*/
    for(i=0;i<MEMORY_CAPACITY;i++)
        strcpy(memory[i][1],"00000000");
    /*for row numbers cast integers numbers to string*/
    for(i=0;i<MEMORY_CAPACITY;i++)
    {
        index = 0;
        counter = 0;
        adress = i+1;
        while(adress > 0.9999999)
        {
            adress/= 10;
            counter++;
        }
        while(counter>0)
        {
            adress*=10;
            memory[i][0][index] = (int)adress % 10 + 48;
            index++;
            counter--;
        }
        memory[i][0][index] = '\0';
    }
    int memory_adress;
    char choise;
    /*till user enters 0 takes adress and number for that adres from user and put them into memory*/
    do
    {
        printf("Enter the memory adress of number and number which you want to put into memory\n");
        printf("You can not enter adress between 102-108 : ");
        scanf("%d %d",&memory_adress,&decimal_num);
        counter = 0;
        index = BINARRY_NUM_SIZE-2;
        while(counter != 8)
        {
            remainder = to_binary(decimal_num);
            arr_binary[index] = remainder + 48;
            decimal_num /= 2;
            index--;
            counter++;
        }
        arr_binary[counter] = '\0';
        strcpy(memory[memory_adress-1][1],arr_binary);
        printf("Do you want to put another numnber? If not enter '0' else enter any number: ");
        scanf(" %c",&choise);
    }while(choise != '0');
    /*from first line to end of line number of tmp_array initialize memory*/
    for(current_line = 0,memory_index = 0;current_line<*line;current_line++)
    {
        flag = 0;
        /*find opcode of instructons according to format wihch is taken from .asm file*/
        for(i = 0;i<INSTRUCTION_NUM;i++)
        {
            if(strcmp(tmp_array[current_line][0],instruction_from_file[i].format) == 0)
            {
                strcpy(memory[memory_index][1],instruction_from_file[i].opcode);
                /*if instructions is LDAI keep number into tempurary variable
                according to which registers do we want to keep that value*/
                if(strcmp(tmp_array[current_line][0],"LDAI") == 0)
                {
                    if(strcmp(tmp_array[current_line][1],"A") == 0)
                        sscanf(tmp_array[current_line][2],"%d",&tmp_A);
                    else if(strcmp(tmp_array[current_line][1],"B") == 0)
                        sscanf(tmp_array[current_line][2],"%d",&tmp_B);
                    /*printf("%d is num and %d is for B\n",tmp_A,tmp_B);*/
                }
                memory_index++;
            }    
        }
        /*printf("%s adress and %s\n",memory[memory_index-1][0],memory[memory_index-1][1]);*/
        /*in second column if not null*/
        if(tmp_array[current_line][1] != NULL)
        {
            /*printf("%s\n",tmp_array[current_line][1]);*/
            /*if string is equal to A then write its adress into memory as binary number*/
            if(strncmp(tmp_array[current_line][1],"A",1) == 0)
            {
                decimal_num = REGISTER_A;
                counter = 0;
                index = BINARRY_NUM_SIZE-2;
                while(counter != 8)
                {
                    remainder = to_binary(decimal_num);
                    arr_binary[index] = remainder + 48;
                    /*printf("%c",arr_binary[index]);*/
                    decimal_num /= 2;
                    index--;
                    counter++;
                }
                arr_binary[counter] = '\0';
                /*printf(" binary of a :%s\n",arr_binary);*/
                strcpy(memory[memory_index][1],arr_binary);
                /*printf(" binary of a in memory : %s\n",memory[memory_index][1]);*/
            }
            /*if string is equal to B then write its adress into memory as binary number*/
            else if(strncmp(tmp_array[current_line][1],"B",1) == 0)
            {                
                decimal_num = REGISTER_B;
                counter = 0;
                index = BINARRY_NUM_SIZE-2;
                while(counter != 8)
                {
                    remainder = to_binary(decimal_num);
                    arr_binary[index] = remainder + 48;
                    decimal_num /= 2;
                    index--;
                    counter++;
                }
                arr_binary[counter] = '\0';
                strcpy(memory[memory_index][1],arr_binary);
            }
            /*if string is equal to M[A] then write adress which is in that register into memory as binary number*/
            else if(strcmp(tmp_array[current_line][1],"M[A]") == 0)
                strcpy(memory[memory_index][1],memory[REGISTER_A-1][1]);
            /*if string is equal to M[B] then write adress which is in that register into memory as binary number*/
            else if(strcmp(tmp_array[current_line][1],"M[B]") == 0)
                strcpy(memory[memory_index][1],memory[REGISTER_B-1][1]);
        }
        /*if null write 8 bit long 0*/
        else if(tmp_array[current_line][1] == NULL)
            strcpy(memory[memory_index][1],"00000000");
        memory_index++;
        /*printf("%s adress and %s\n",memory[memory_index-1][0],memory[memory_index-1][1]);*/
        /*in third column if not null*/
        if(tmp_array[current_line][2] != NULL)
        {
            /*printf("%sis 3.column in tmp array\n",tmp_array[current_line][2]);*/
            /*if string is equal to M[A] then write tempurary value which we found previous*/
            if(strncmp(tmp_array[current_line][2],"M[A]",4) == 0)
            {
                /*printf("kontrol amclı m[a] görüyormu\n");*/
                strcpy(memory[memory_index][1],memory[tmp_A-1][1]);
                /*printf("%s is binary in memory for register A\n",memory[memory_index][1]);*/
            }
            /*if string is equal to M[B] then write tempurary value which we found previous*/
            else if(strncmp(tmp_array[current_line][2],"M[B]",4) == 0)
            {
                /*printf("kontrol amclı m[b] görüyormu\n");*/
                strcpy(memory[memory_index][1],memory[tmp_B-1][1]);
                /*printf("%s is binary in memory for register B\n",memory[memory_index][1]);*/
            }
            /*if string is equal to A then write its adress into memory as binary number*/
            else if(strncmp(tmp_array[current_line][2],"A",1) == 0)
            {
                decimal_num = REGISTER_A;
                counter = 0;
                index = BINARRY_NUM_SIZE-2;
                while(counter != 8)
                {
                    remainder = to_binary(decimal_num);
                    arr_binary[index] = remainder + 48;
                    decimal_num /= 2;
                    index--;
                    counter++;
                }
                arr_binary[counter] = '\0';
                strcpy(memory[memory_index][1],arr_binary);
            }
            /*if string is equal to B then write its adress into memory as binary number*/
            else if(strncmp(tmp_array[current_line][2],"B",1) == 0)
            {
                decimal_num = REGISTER_B;
                counter = 0;
                index = BINARRY_NUM_SIZE-2;
                while(counter != 8)
                {
                    remainder = to_binary(decimal_num);
                    arr_binary[index] = remainder + 48;
                    decimal_num /= 2;
                    index--;
                    counter++;
                }
                arr_binary[counter] = '\0';
                strcpy(memory[memory_index][1],arr_binary);
            }/*for other situatins take number than convert it to binary and write into memory*/
            else
            {
                sscanf(tmp_array[current_line][2],"%d",&decimal_num);
                counter = 0;
                index = BINARRY_NUM_SIZE-2;
                while(counter != 8)
                {
                    remainder = to_binary(decimal_num);
                    arr_binary[index] = remainder + 48;
                    decimal_num /= 2;
                    index--;
                    counter++;
                }
                arr_binary[counter] = '\0';
                strcpy(memory[memory_index][1],arr_binary);
            }
        }
        else if(tmp_array[current_line][2] == NULL)
            strcpy(memory[memory_index][1],"00000000");
        memory_index++;
        /*printf("%s adress and %s\n",memory[memory_index-1][0],memory[memory_index-1][1]);*/
    }
    /*initializing IR values in memory with first 3 line of memory*/
    strcpy(memory[INSTRUCTION_REGISTER-1][1],memory[0][1]);
    strcpy(memory[INSTRUCTION_REGISTER][1],memory[1][1]);
    strcpy(memory[INSTRUCTION_REGISTER+1][1],memory[2][1]);
    sscanf(memory[0][0],"%d",&decimal_num);
    counter = 0;
    index = BINARRY_NUM_SIZE-2;
    while(counter != 8)
    {
        remainder = to_binary(decimal_num);
        arr_binary[index] = remainder + 48;
        decimal_num /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(memory[PROGRAM_COUNTER_2-1][1],arr_binary);
    /*initialize PC of memory at the beginnig*/
    printf("first situation of memeory\n");
    printing_memory(memory);
}
/*taking code from.asm file*/
void taking_assembly_code_from_file(char *file_name,char memory[MEMORY_CAPACITY][2][9],struct instructions instruction_from_file[INSTRUCTION_NUM],char tmp_array[30][3][9])
{
    FILE *assembly = fopen(file_name,"r");
    char character;
    int index,i,column;
    /*initialize array as null*/
    for(i=0;i<30;i++)
    {
        strcpy(tmp_array[i][0],"\0");
        strcpy(tmp_array[i][1],"\0");
        strcpy(tmp_array[i][2],"\0");
    }
    int line,info_num;
    line = 0;
    index = 0;
    column = 0;
    /*till end of file read file and keep values into tmp_array*/
    while((character = fgetc(assembly)) != EOF)
    {
        if(character == ' ')
        {
            tmp_array[line][column][index] = '\0';
            column++;
            index = 0;
        }
        if(character == '\n')
        {
            tmp_array[line][column][index] = '\0';
            line++;
            index = 0;
            column = 0;
        }
        if(character != ' ' && character != '\n')
        {
            tmp_array[line][column][index] = character;
            index++;
        }
    }
    tmp_array[line][column][index] = '\0';
    /*for(i = 0;i<line+1;i++)
    {
        for(info_num = 0;info_num<3;info_num++)
            printf("%d line %d column : %s\n",i+1,info_num+1,tmp_array[i][info_num]);
        printf("\n");
    }*/
    line++;
    fclose(assembly);
    initializing_memory(instruction_from_file,memory,tmp_array,&line);
}
/*taking instructions from file into an array which is type of struct*/
void instruction_file(struct instructions instruction_from_file[INSTRUCTION_NUM])
{
    FILE *info;
    info = fopen("instructions 1.txt","r");
    char character;
    int counter,index,ins_num = 0,space_counter;
    int index_A,index_B;
    /*till end of file read instruction file*/
    while((character = fgetc(info)) != EOF && ins_num != INSTRUCTION_NUM)
    {
        counter = 0;/*for keeping number of | sign*/
        index = 0;
        index_A = 0,index_B = 0;
        space_counter = 0;
        /*printf("ins_num: %d\n",ins_num+1);*/
        while(counter == 0)
        {
            instruction_from_file[ins_num].opcode[index] = character;
            character = fgetc(info);
            index++;
            if(character == '|')
            {
                counter++;
                instruction_from_file[ins_num].opcode[index] = '\0';
                index = 0;
            }
        }
        while(counter == 1)
        {
            character = fgetc(info);
            if(character == '|')
                counter++;
            if(counter != 2)
                instruction_from_file[ins_num].type= character;
        }
        while(counter == 2)
        {
            character = fgetc(info);
            if(character == '|')
            {
                counter++;
                break;
            }
            if(character == ' ')
            {
                space_counter++;
                continue;
            }
            if(space_counter == 0)
            {
                instruction_from_file[ins_num].format[index] = character;
                index++;
            }
            instruction_from_file[ins_num].format[index] = '\0';
            if(space_counter == 1)
            {
                instruction_from_file[ins_num].A[index_A] = character;
                index_A++;
            }
            instruction_from_file[ins_num].A[index_A] = '\0';
            if(space_counter == 2)
            {
                instruction_from_file[ins_num].B[index_B] = character;
                index_B++;
            }
            instruction_from_file[ins_num].B[index_B] = '\0';
        }
        if(counter == 3)
            while((character = fgetc(info)) != '\n');
        /*
        printf("%s and %c and %s and %s and %s\n",instruction_from_file[ins_num].opcode,instruction_from_file[ins_num].type,instruction_from_file[ins_num].format,instruction_from_file[ins_num].A,instruction_from_file[ins_num].B);
        */
        ins_num++;
    }
    fclose(info);
}
/*change decimal number to binary form*/
int to_binary(int decimal_number)
{
    int reminder;
    reminder = decimal_number % 2;
    return(reminder);
}
/*change binary number to decimal form*/
int to_decimal(char bianry_number[BINARRY_NUM_SIZE])
{
    int i,j;
    int sum = 0,current_sum = 0;
    for(i = BINARRY_NUM_SIZE-2;i>=0;i--)
    {
        current_sum = 1;
        /*if number in that inde is 1 find its decimal value like 2^3 */
        if(bianry_number[i] == '1')
        {
            for(j = 0;j<8-i-1;j++)
                current_sum *= 2;
            sum += current_sum;
        }
    }
    return(sum);
}
/*It adds A and B register values then stores the result in A*/
void ADD_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    num1 += num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It adds register A and given number then stores the result in A*/
void ADDI_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->IR[2]); 
    num1 += num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It adds register A and a number that stored in memory address B then stores the result in A.*/
void ADDM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    num2 = to_decimal(memory[num2-1][1]);
    num1 += num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It does subtraction operation between A and B registers, then stores the result in A.*/
void SUB_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    num1 -= num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It does subtraction operation between register A and given number, then stores the result in A.*/
void SUBI_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->IR[2]); 
    num1 -= num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It does subtraction operation between register A and the value
inside the memory address B, then stores the result in A.*/
void SUBM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B); 
    num2 = to_decimal(memory[num2-1][1]);
    num1 -= num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*Increment A register by 1.*/
void INC_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = 1; 
    num1 += num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*Decrement A register by 1.*/
void DEC_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = 1; 
    num1 -= num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It swaps register A and B.*/
void SWP_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->B,arr_binary);
    index = BINARRY_NUM_SIZE-2;
    counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num2);
        arr_binary[index] = remainder + 48;
        num2 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->A,arr_binary);
}
/*It prints the value of register A.*/
void PRI_function(struct assembly_simulator *assembly)
{
    int num1;
    num1 = to_decimal(assembly->A);
    printf("Value into register is %d\n",num1);
}
/*It prints the value of I.*/
void PRII_function(struct assembly_simulator *assembly)
{
    int num1;
    num1 = to_decimal(assembly->IR[1]);
    printf("Value is %d\n",num1);
}
/*It prints the value from memory address A.*/
void PRIM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int num1;
    num1 = to_decimal(assembly->A);
    num1 = to_decimal(memory[num1-1][1]);
    printf("Value into that adress is %d\n",num1);
}
/*It ands A and B register values then stores the result in A.*/
void AND_function(struct assembly_simulator *assembly)
{
    int index = 0;
    char arr_binary[BINARRY_NUM_SIZE];
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == assembly->B[index]) == '1')
            arr_binary[index] = '1';
        else
            arr_binary[index] = '0';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It ands register A and given number then stores the result in A.*/
void ANDI_function(struct assembly_simulator *assembly)
{
    int index = 0,num = to_decimal(assembly->IR[2]);
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder;
    index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num);
        arr_binary[index] = remainder + 48;
        num /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    index = 0;
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == arr_binary[index]) == '1')
            arr_binary[index] = '1';
        else
            arr_binary[index] = '0';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It ands register A and a number that stored in memory address B
then stores the result in A.*/
void ANDM_fnction(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int index = 0,num = to_decimal(assembly->B);
    char arr_binary[BINARRY_NUM_SIZE];
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == memory[num-1][1][index]) == '1')
            arr_binary[index] = '1';
        else
            arr_binary[index] = '0';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It does or operation between register A and B, then stores the result in A.*/
void OR_function(struct assembly_simulator *assembly)
{
    int index = 0;
    char arr_binary[BINARRY_NUM_SIZE];
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == assembly->B[index]) == '0')
            arr_binary[index] = '0';
        else
            arr_binary[index] = '1';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It does or operation between register A and given number, then
stores the result in A.*/
void ORI_function(struct assembly_simulator *assembly)
{
    int index = 0,num = to_decimal(assembly->IR[2]);
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder;
    index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num);
        arr_binary[index] = remainder + 48;
        num /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    index = 0;
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == arr_binary[index]) == '0')
            arr_binary[index] = '0';
        else
            arr_binary[index] = '1';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It does or operation between register A and the value inside the
memory address B, then stores the result in A.*/
void ORM_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int index = 0,num = to_decimal(assembly->B);
    char arr_binary[BINARRY_NUM_SIZE];
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == memory[num-1][1][index]) == '0')
            arr_binary[index] = '0';
        else
            arr_binary[index] = '1';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It does nor operation between register A and B, then stores the
result in A.*/
void NOR_function(struct assembly_simulator *assembly)
{
    int index = 0;
    char arr_binary[BINARRY_NUM_SIZE];
    while(index != BINARRY_NUM_SIZE)
    {
        if((assembly->A[index] == assembly->B[index]) == '0')
            arr_binary[index] = '1';
        else
            arr_binary[index] = '0';
        index++;
    }
    strcpy(assembly->A,arr_binary);
}
/*It checks whether A is less than B.*/
void LESS_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    if(num1 < num2)
        strcpy(assembly->A,"00000001");
    else
        strcpy(assembly->A,"00000000");
}
/*It check whether A is greater than B.*/
void GRT_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    if(num1 > num2)
        strcpy(assembly->A,"00000001");
    else
        strcpy(assembly->A,"00000000");
}
/*Load I value to A register*/
void LDAI_function(struct assembly_simulator *assembly)
{
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
        strcpy(assembly->A,assembly->IR[2]);
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
        strcpy(assembly->B,assembly->IR[2]);
}
/*It loads the value from memory address B into register A.*/
void LDA_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int num ;
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
    {
        num = to_decimal(assembly->A);
        strcpy(assembly->A,memory[num-1][1]); 
    }
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
    {
        num = to_decimal(assembly->B);
        strcpy(assembly->B,memory[num-1][1]);     
    }
}
/*It stores the value to memory address B from register A.*/
void STR_function(struct assembly_simulator *assembly,char memory[MEMORY_CAPACITY][2][9])
{
    int num = to_decimal(assembly->B);
    strcpy(memory[num-1][1],assembly->A);
}
/*Jump to specific line number which is A + B.*/
void J_function(struct assembly_simulator *assembly)
{
    int num1,num2;
    num1 = to_decimal(assembly->A);
    num2 = to_decimal(assembly->B);
    num1 += num2;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num1);
        arr_binary[index] = remainder + 48;
        num1 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    strcpy(assembly->PC[1],arr_binary);
}
/*Shift register A value to the left I times.*/
void SHL_function(struct assembly_simulator *assembly)
{
    int num1 = to_decimal(assembly->IR[2]),num2;
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
        num2 = to_decimal(assembly->A);
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
        num2 = to_decimal(assembly->B);
    /*printf("%d and num2 %d\n",num1,num2);*/
    int multipy = 2;
    for(;num1>1;num1--)
        multipy *= 2;
    num2 *= multipy;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num2);
        arr_binary[index] = remainder + 48;
        num2 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
        strcpy(assembly->A,arr_binary);
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
        strcpy(assembly->B,arr_binary);
}
/*Shift register A value to the rigth I times.*/
void SHR_function(struct assembly_simulator *assembly)
{
    int num1 = to_decimal(assembly->IR[2]),num2;
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
        num2 = to_decimal(assembly->A);
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
        num2 = to_decimal(assembly->B);
    int divider = 2;
    for(;num1>1;num1--)
        divider *= 2;
    num2 /= divider;
    char arr_binary[BINARRY_NUM_SIZE];
    int remainder,index = BINARRY_NUM_SIZE-2;
    int counter = 0;
    while(counter != 8)
    {
        remainder = to_binary(num2);
        arr_binary[index] = remainder + 48;
        num2 /= 2;
        index--;
        counter++;
    }
    arr_binary[counter] = '\0';
    if(strcmp(assembly->IR[1],adress_of_register_A) == 0)
        strcpy(assembly->A,arr_binary);
    else if(strcmp(assembly->IR[1],adress_of_register_B) == 0)
        strcpy(assembly->B,arr_binary);
}
/*Branch on line A if A and B equal.*/
int BRE_function(struct assembly_simulator *assembly)
{
    if(strcmp(assembly->A,assembly->B) == 0)
    {
        strcpy(assembly->PC[1],assembly->A);
        return(1);
    }
    return(0);
}
/*Branch on line A if A and B not equal.*/
int BRN_function(struct assembly_simulator *assembly)
{
    if(strcmp(assembly->A,assembly->B) != 0)
    {
        strcpy(assembly->PC[1],assembly->A);
        return(1);
    }
    return(0);
}