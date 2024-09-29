#ifndef custom_dict
#define custom_dict
/*structs and union which used in functions*/
/*to keep values of item*/
typedef union Value
{
    int int_value;
    double double_value;
    float float_value;
    char char_values;
}Value;
/*to keep informations of items*/
typedef struct Item
{
    union Value *value;
    char *key;
    char *data_type;
    int field;
} Item;
/*to keep informations of dictionary*/
typedef struct Custom_dict
{
    struct Item *items;
    int current_capacity;
    int curent_size;
}Custom_dict;

/*functions prototypes*/
struct Custom_dict *create_dict();
void add_item(Custom_dict *dict,char *key,Value *value,char *data_type,int field);
void delete_items(Custom_dict *dict,char *key);
void set_value(Custom_dict *dict,char *key,Value *value,char *data_type,int field);
union Value *search_item(Custom_dict *dict,char *key);
void sort_dict(Custom_dict *dict);
void print_dict(Custom_dict *dict);
void free_dict(Custom_dict *dict);
int read_csv(Custom_dict *dict,const char *file_name);
#endif