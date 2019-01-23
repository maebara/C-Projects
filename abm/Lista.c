#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

void crear_lista(t_lista *pl){

    *pl = NULL;
}


void vaciar_lista(t_lista *pl){

    t_nodo *nae;

    while(*pl){
        nae = *pl;
        *pl = nae->pSig;
        free(nae);
    }

}

int lista_vacia(const t_lista *pl){

    return *pl == NULL;
}




int buscar( const t_lista *pl, t_dato *d, t_cmp cmp){

    while(*pl && cmp(d, &(*pl)->info) != 0)
        pl = &(*pl)->pSig;

    if(*pl == NULL) return 0;

    *d = (*pl)->info;

    return 1;
}

int lista_sacar_primero(t_lista* pl, t_dato* d){

    if(*pl == NULL) return 0;

    t_nodo *nae = *pl;
    *d = nae->info;
    *pl = nae->pSig;
    free(nae);
    return 1;
}

int lista_llena(const t_lista* pl){

    t_nodo *aux = (t_nodo*) malloc(sizeof(t_nodo));
    free(aux);
    return aux == NULL;
}


int eliminar_de_lista(t_lista* pl, t_dato* d, t_cmp cmp){

    while(*pl && cmp(d, &(*pl)->info) != 0)
        pl = &(*pl)->pSig;

    if(*pl == NULL) return 0;

    t_nodo *nae = *pl;
    *pl = nae->pSig;
    *d = nae->info;
    free(nae);

    return 1;
}

int lista_insertar_en_orden_asc(t_lista* pl, const t_dato* d, t_cmp cmp){

    while(*pl && cmp(d,&(*pl)->info) > 0)
        pl = &(*pl)->pSig;

    if(*pl)
        if(cmp(d,&(*pl)->info) == 0) return 0;

    t_nodo *nue = (t_nodo*) malloc(sizeof(t_nodo));
    if(!nue) return 0;

    nue->info = *d;
    nue->pSig = *pl;
    *pl = nue;
    return 1;
}


int comp_dni(const void *a, const void *b){

    return ((t_reg_indice*)a)->dni - ((t_reg_indice*)b)->dni;
}


