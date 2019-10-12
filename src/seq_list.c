#include <stdbool.h>
#include <malloc.h>
#include <stdio.h>
#include <seq_list.h>

void init_seq_list(SeqList* sl)
{
  sl->nElem = 0;
}


void reinit_seq_list(SeqList* sl)
{
  sl->nElem = 0;
}


int size(SeqList* sl)
{
  return sl->nElem;
}


int seq_search(SeqList* sl, Key key)
{
  int i = 0;
  while(i < sl->nElem) {
    if(key == sl->A[i].key){
      return i;
    }
    else {
      i++;
    }
  }
  return -1;
}


bool insert_elem(SeqList* sl, Register reg, int i)
{
  int j;
  if((sl->nElem == MAX) || (i < 0) || (i > sl->nElem)) {
    return false;
  }
  else {
    for(j = sl->nElem; j > i; j--) {
      sl->A[j] = sl->A[j-1];
    }
    sl->A[i] = reg;
    sl->nElem ++;
    return true;
  }
}

bool remove_elem(Key key, SeqList* sl)
{
  int pos, j;
  pos = seq_search(sl, key);
  if(pos == -1) {
    return false;
  }
  else {
    for(j = pos; j < sl->nElem-1; j++) {
      sl->A[j] = sl->A[j+1]; 
    }
    sl->nElem--;
    return true;
  }
}


void show_list(SeqList* sl)
{
  int i;
  printf("List: \"");

  for(i=0; i < sl->nElem - 1; i++)
    printf("%i ", sl->A[i].key);

  /* Last element isn't followed by blank space */
  printf("%i", sl->A[sl->nElem-1].key);
  printf("\"\n");

}