#include <List.c>
struct li {
   key_t key;
   value_t value;
   struct li* next;
};

struct list {
   struct li *first;
   int size;
};

struct list *new_list();
struct li* new_list_item();
void delete_items(struct li* it);
void delete_list(struct list *l);
int insert_item( struct list *l, key_t key, value_t value);
int insert_item_uniq( struct list *l, key_t key, value_t value);
int delete_item( struct list *l, key_t key );
void print_list ( struct list *l);
int find_item( struct list *l, key_t key, value_t *value);
