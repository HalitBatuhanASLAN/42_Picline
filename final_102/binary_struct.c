#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int a;
    char c;
}example;

int main()
{
    example x = 
    {
        .a = 19,
        .c = 'k'
    };
    example y;
    FILE *bin;
    bin = fopen("example.bin","wb");
    if(!bin)
        return 2;
    fwrite(&x,sizeof(example),1,bin);
    fclose(bin);
    bin = fopen("example.bin","rb");
    if(!bin)
        return 3;
    fread(&y,sizeof(example),1,bin);
/*aşşağıdakiler yerine bunu yapmak daha güzel olur*/
/*    fwrite(&x.a,sizeof(x),1,bin);
    fwrite(&x.c,sizeof(x),1,bin);
    fclose(bin);
    bin = fopen("struct.bin","rb");
    if(!bin)
        return 3;
    fread(&y.a,sizeof(y),1,bin);
    fread(&y.c,sizeof(y),1,bin);*/
    fclose(bin);
    printf("%d\n",y.a);
    printf("%c\n",y.c);

/*    bin = fopen("struct.bin","wb");
    if(!bin)
        return 2;
    fwrite(&x.a,sizeof(int),1,bin); burada izin vermiyor x->a olmasına
    /*fwrite(&x.c,sizeof(char),1,bin);
    fclose(bin);
    bin = fopen("struct.bin","rb");
    if(!bin)
        return 3;
    fread(&y.a,sizeof(int),1,bin);
    fread(&y.c,sizeof(y.c),1,bin);
    fclose(bin);
    printf("%d\n",y.a);
    printf("%c\n",y.c);
*/
}