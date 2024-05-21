#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char* nroUSP() {
    return("#######");
}

char* nome() {
    return("Nazivon");
}

typedef struct estr {
        int chave;
        struct estr* prox;
} NO;

void removerCompartilhados(NO* *p1, NO* *p2);

int check (NO* *p1, NO* *p2, NO**ant1, NO**ant2, NO**atual) {
*atual = NULL;
  NO*p = *p1; *ant1 = NULL;
  while (p) {
    NO*q = *p2; *ant2 = NULL;
    while (q) {
      if (p == q) {
        *atual = p;
        return 1;
      }
      *ant2 = q;
      q = q->prox;
    }
    *ant1 = p;
    p = p->prox;
}
return 0;
}

void removerCompartilhados(NO* *p1, NO* *p2) {
  NO*ant1; NO*ant2; NO*atual;
  int retorno = check(p1, p2, &ant1, &ant2, &atual);
  if (retorno) {
    while (atual) {
      NO*aux = atual->prox;
      free(atual);
      atual = aux;
    }
  }
  if (ant1) {
    ant1->prox = *p1;
  } else {
    *p1 = ant1;
  }
  if (ant2) {
    ant2->prox = *p2;
  } else {
    *p2 = ant2;
  }
  return;
}
