#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define TOTAL_CARD_NUM 52 /*keep for total card numbers*/
#define FACE_NUM 13 /*keep for face numbers of cards*/
#define SUIT_NUM 4 /*keep for suit numbers of cards*/
/*struct to keep face and suit informations of all cards*/
struct card
{
    const char *face;
    const char *suit;
};
int main()
{
    srand(time(NULL));/*every time create new random number*/
    int face_num,suit_num;
    int index,i,flag = 1;
    /*array of struct type by named card*/
    struct card card_box[TOTAL_CARD_NUM];
    for(index = 0;index<TOTAL_CARD_NUM;)
    {
        /*generations of random numbers for suit and face*/
        face_num = rand() % FACE_NUM + 1;
        suit_num = rand() % SUIT_NUM + 1;
        /*according to generated number assign relevant suit name
        to current index of card_box array*/
        switch(suit_num)
        {
        case 1: card_box[index].suit = "Hearths"; break;
        case 2: card_box[index].suit = "Diamonds"; break;
        case 3: card_box[index].suit = "Clubs"; break;
        case 4: card_box[index].suit = "Spades"; break;
        default: break;
        }
        /*according to generated number assign relevant face name
        to current index of card_box array*/
        switch(face_num)
        {
        case 1: card_box[index].face = "Ace"; break;
        case 2: card_box[index].face = "Deuce"; break;
        case 3: card_box[index].face = "Three"; break;
        case 4: card_box[index].face = "Four"; break;
        case 5: card_box[index].face = "Five"; break;
        case 6: card_box[index].face = "Six"; break;
        case 7: card_box[index].face = "Seven"; break;
        case 8: card_box[index].face = "Eight"; break;
        case 9: card_box[index].face = "Nine"; break;
        case 10: card_box[index].face = "Ten"; break;
        case 11: card_box[index].face = "Jack"; break;
        case 12: card_box[index].face = "Queen"; break;
        case 13: card_box[index].face = "King"; break;
        default: break;
        }
        flag = 1;
        /*from beginning to index number compara if suit name used before
        compara it's face name with current one if there is a match then 
        assign 0 to flag and without increment index does same process*/
        for(i = 0;i<index;i++)
        {
            if(strcmp(card_box[i].suit,card_box[index].suit) == 0)
            {
                if(strcmp(card_box[i].face,card_box[index].face) == 0)
                {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1)
            index++;
    }
    /*print all cards face and suits*/
    for(index = 0;index<TOTAL_CARD_NUM;index+=2)
        printf("%-8s of %s\t%-8s of %s\n",card_box[index].face,card_box[index].suit,card_box[index+1].face,card_box[index+1].suit);
}