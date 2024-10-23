#include "tubes.h"

void createListO(ListOlahraga &LO){
    firstO(LO) = NULL;
}

void createListL(ListLomba &LL){
    firstL(LL) = NULL;
}

adrOlahraga createNewElmO(infOlahraga X){
    adrOlahraga O = new elm_Olahraga;
    info(O) = X;
    next(O) = NULL;
    firstA(O) = NULL;
    return O;
}

adrAtlet createNewElmA(infoAtlet X){
    adrAtlet A = new elm_Atlet;
    info(A) = X;
    next(A) = NULL;
    lomba(A) = NULL;
    return A;
}

adrLomba createNewElmL(infoLomba X){
    adrLomba L = new elm_Lomba;
    info(L) = X;
    next(L) = NULL;
    return L;
}

void insertFirstO(ListOlahraga &LO, adrOlahraga O){
    if (firstO(LO) == NULL) {
        firstO(LO) = O;
    }else {
        next(O) = firstO(LO);
        firstO(LO) = O;
    }
}

void insertFirstA(ListOlahraga &LO, adrOlahraga O, adrAtlet A){
    if (firstA(O) == NULL) {
        firstA(O) = A;
    }else {
        next(A) = firstA(O);
        firstA(O) = A;
    }
}

void insertFirstL(ListLomba &LL, adrLomba L){
    if (firstL(LL) == NULL) {
        firstL(LL) = L;
    }else {
        next(L) = firstL(LL);
        firstL(LL) = L;
    }
}

void atletLomba(ListOlahraga &LO, adrAtlet A, adrLomba L){
    lomba(A) = L;
}

adrOlahraga searchOlahraga(ListOlahraga LO, string nama) {
    adrOlahraga O = firstO(LO);
    while (O != NULL && info(O).nama != nama) {
        O = next(O);
    }
    return O;
}

adrAtlet searchAtlet(ListOlahraga LO, string nama){
    adrOlahraga O = firstO(LO);
    adrAtlet A = firstA(O);
    while(O != NULL && info(A).nama != nama) {
        A = firstA(O);
        while(A != NULL && info(A).nama != nama) {
            A = next(A);
        }
        O = next(O);
    }
    return A;
}

adrAtlet searchAtletOlahraga(adrOlahraga O, string nama) {
    adrAtlet A = firstA(O);
    while (A != NULL && info(A).nama != nama) {
        A = next(A);
    }
    return A;
}

adrLomba searchLomba(ListLomba LL, string nama) {
    adrLomba L = firstL(LL);
    while (L != NULL && info(L).nama != nama) {
        L = next(L);
    }
    return L;
}

void showO(ListOlahraga LO){
    adrOlahraga O = firstO(LO);
    if(firstO(LO) == NULL) {
        cout << "List Olahrahga KOSONG" << endl;
    }else {
        while(O != NULL) {
            cout << info(O).nama << "   " << info(O).kategori << " " << endl;
            O = next(O);
        }
    }
}

void showL(ListLomba LL) {
    adrLomba L = firstL(LL);
    if (L == NULL) {
        cout << "List Lomba KOSONG" << endl;
    } else {
        while (L != NULL) {
            cout << info(L).nama << endl;
            L = next(L);
        }
    }
}

void showAll(ListOlahraga LO){
    adrOlahraga O = firstO(LO);
    if(firstO(LO) == NULL) {
        cout << "List Olahraga KOSONG" << endl;
    }else {
        while(O != NULL) {
            cout << ">>Cabang Olahraga<<" << endl;
            cout << info(O).nama << endl;

            adrAtlet A = firstA(O);
            cout << ">>Atlet<<" << endl;
            if(A == NULL){
                cout << "-none-" << endl;
            }else {
                while(A != NULL) {
                    cout << info(A).nama << " | " << info(A).tinggi << " | " << info(A).berat << " | " << info(A).usia << endl;
                    if (lomba(A) != NULL) {
                        cout << "Mengikuti lomba " << info(lomba(A)).nama << endl;
                    }
                    cout << endl;
                    A = next(A);
                }
            }
            O = next(O);
        }
        cout << endl;
    }
}

int selectMenu() {
    cout << "=====" << "MENU" << "=====" << endl;
    cout << "1. Menambah Data" << endl;
    cout << "2. Menghapus Data" << endl;
    cout << "3. List Lomba" << endl;
    cout << "0. Exit" << endl;

    int inputUser = 0;
    cout << ">> Masukan User: " ;
    cin >>inputUser;

    return inputUser;

}
