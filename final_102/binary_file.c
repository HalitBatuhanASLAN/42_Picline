#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *bin_file;
    bin_file = fopen("example.bin","wb");
    if(bin_file == NULL)
        return 2;
    int *num;
    char character;
    int arr[3] = {1,2,3};
    fwrite(arr,sizeof(arr),1,bin_file);
    /*num = 12;*/
    character = 'a';
    /*fwrite(&num,sizeof(num),1,bin_file);*/
    fwrite(&character,sizeof(character),1,bin_file);
    fclose(bin_file);

    bin_file = fopen("example.bin","rb");
    if(bin_file == NULL)
        return 3;
    fread(num,sizeof(num),4,bin_file);
    fread(&character,sizeof(char),1,bin_file);
    fclose(bin_file);
    printf("%d\n",num[2]);
    printf("%c\n",character);
}