#ifndef SEQ_LIST_H
#define SEQ_LIST_H

#include <stdbool.h>

#define MAX 50

typedef int Key;
typedef struct
{
  Key key;
  /* other fields */
} Register;
typedef struct
{
  Register A[MAX];
  int nElem;
} SeqList;

void init_seq_list(SeqList* sl);
void reinit_seq_list(SeqList* sl);
int size(SeqList* sl);
bool insert_elem(SeqList* sl, Register reg, int i);
int seq_search(SeqList* sl, Key key);
bool remove_elem(Key key, SeqList* sl);
void show_list(SeqList* sl);

#endif /* SEQ_LIST_H */
