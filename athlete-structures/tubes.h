#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <stdlib.h>

#define firstO(L) L.firstO
#define firstL(L) L.firstL
#define next(P) P->next
#define info(P) P->info
#define firstA(L) L->firstA
#define lomba(P) P->lomba

using namespace std;

struct infOlahraga {
    string nama, kategori;
    int id;
};

struct infoAtlet {
    int tinggi, usia, berat, id;
    string nama;
};

struct infoLomba {
    string nama;
    int id;
};

typedef struct elm_Olahraga *adrOlahraga;
typedef struct elm_Atlet *adrAtlet;
typedef struct elm_Lomba *adrLomba;

struct elm_Olahraga {
    infOlahraga info;
    adrOlahraga next;
    adrAtlet firstA;
};

struct elm_Atlet {
    infoAtlet info;
    adrAtlet next;
    adrLomba lomba;
};

struct elm_Lomba {
    infoLomba info;
    adrLomba next;
};

struct ListOlahraga {
    adrOlahraga firstO;
};

struct ListLomba {
    adrLomba firstL;
};

void createListO(ListOlahraga &LO);
void createListL(ListLomba &LL);
adrOlahraga createNewElmO(infOlahraga X);
adrAtlet createNewElmA(infoAtlet X);
adrLomba createNewElmL(infoLomba X);
void insertFirstO(ListOlahraga &LO, adrOlahraga O);
void insertFirstA(ListOlahraga &LO, adrOlahraga O, adrAtlet A);
void insertFirstL(ListLomba &LL, adrLomba L);
void atletLomba(ListOlahraga &LO, adrAtlet A, adrLomba L);
adrOlahraga searchOlahraga(ListOlahraga LO, string nama);
adrAtlet searchAtlet(ListOlahraga LO, string nama);
adrAtlet searchAtletOlahraga(adrOlahraga O, string nama);
adrLomba searchLomba(ListLomba LL, string nama);
void showO(ListOlahraga LO);
void showL(ListLomba LL);
void showAll(ListOlahraga LO);
int selectMenu();


#endif // TUBES_H_INCLUDED
