#include <stdlib.h>
#include <stdio.h>
#include "cache.h"
#include "lru.h"

void lru_init_queue (Set *set) {
  LRUNode *s = NULL;
  LRUNode **pp = &s;  // place to chain in the next node
  for (int i = 0; i < set->line_count; i++) {
    Line *line = &set->lines[i];
    LRUNode *node = (LRUNode *)(malloc(sizeof(LRUNode)));
    node->line = line;
    node->next = NULL;
    (*pp) = node;
    pp = &((*pp)->next);
  }
  set->lru_queue = s;
}

void lru_init (Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    lru_init_queue(&sets[i]);
  }
}

void lru_destroy (Cache *cache) {
  Set *sets = cache->sets;
  for (int i = 0; i < cache->set_count; i++) {
    LRUNode *p = sets[i].lru_queue;
    LRUNode *n = p;
    while (p != NULL ) {
      p = p->next;
      free(n);
      n = p;
    }
    sets[i].lru_queue = NULL;
  }
}

void lru_fetch(Set* set, unsigned int tag, LRUResult* result) {
  // TODO:
  // Implement the LRU algorithm to determine which line in
  // the cache should be accessed.
  //

// int i = 0;

for (LRUNode **prevp = &(set->lru_queue); (*prevp) != NULL; prevp = &((*prevp)->next)) {
  LRUNode* current = *prevp;
  Line* line = current->line;
  if(line->valid == 1 && line->tag == tag) {
    result->access = HIT;
    // LRUNode *temp = current;
    //   set->lru_queue = temp;
    //   result->line = line;
    //   return;


  }

  else if(line->valid == 0) {
    line->valid = 1;
    line->tag = tag;
    result->access = COLD_MISS;
  //   while(current->next != NULL) {
  //   current->next = current;
  // }
  // current->next = NULL;

  //   set->lru_queue = current;
  //   result->line = line;
  //   return;
  }

  else if(current->next == NULL) {
    line->tag = tag;
    result->access = CONFLICT_MISS;
  //   while(current->next != NULL) {
  //   current->next = current;
  //   }
  // current->next = NULL;

  //   set->lru_queue = current;
  //   result->line = line;
  //   return;
  }

  else {
   // i++;
    continue;
  }

  // int j = i;

  // while(prevp[j+2] != NULL) {
  //   prevp[j] = prevp[j+1];
  //   j++;
  // }

  // LRUNode* itter = prevp[0];
  // prevp[0] = current;
  // int u = 1;
  // while(prevp[u+1] != NULL) {
  //   prevp[u] = itter;
  //   itter = prevp[u+1];
  //   u++;
  // }
  // prevp[u+1] = itter;

 LRUNode* saved = current;
 // saved->next = NULL;

  // while(current->next != NULL) {
  //   current->next = current;
  // }
  // current->next = NULL;


  // saved->next = *prevp;

  set->lru_queue = saved;
  result->line = line;
  return;



  // unchain current from the list
  // place current at the front
  // set the result line to the line
  // return (Note: this is intentionally inside the for)
  return;
  }
}

