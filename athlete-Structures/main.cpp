#include "tubes.h"
using namespace std;

int main()
{
    int pilihan = 4;
    int i, N=0, k=0;

    infOlahraga sports;
    adrOlahraga o;

    infoAtlet athlete;
    adrAtlet a;

    infoLomba exb;
    adrLomba l;

    ListOlahraga lo;
    ListLomba ll;

    string opsi;

    createListO(lo);
    createListL(ll);

    while (pilihan != 0) {
        opsi = "N";
        pilihan = selectMenu();
        switch (pilihan) {

        case 1 :
            //system("cls");
            while (opsi != "Y") {

                cout << endl;
                cout << "===Menu Pilihan===" <<endl;
                cout << "1. Data Olahraga" << endl;
                cout << "2. Data Atlet" << endl;
                cout << "3. Data Lomba" << endl;
                cout << "4. Data Atlet Lomba" << endl;
                cout << endl;
                cout << ">> Pilihan : ";
                cin >> N;
                cout << endl;
                switch (N) {
                case 1:
                    cout << "===LIST OLAHRAGA==="<<endl;
                    cout << "Berapa data yang akan dimasukan ? : " ;
                    cin >> k;
                    for (i = 1; i <= k; i++) {
                        cout << "Masukan Nama Olahraga : " ;
                        cin >> sports.nama ;
                        cout << "Masukan Kategori Olahraga : " ;
                        cin >> sports.kategori ;


                        o = createNewElmO(sports);
                        insertFirstO(lo, o);
                    }
                    cout << endl;
                    cout << "===MENAMPILKAN LIST OLAHRAGA===" << endl;
                    cout << "OLAHRAGA | KATEGORI" << endl;
                    showO(lo);
                    break;
                case 2:
                    cout << "===LIST ATLET==="<<endl;
                    cout << "--Pilihan Olahraga"<< endl;
                    cout << "OLAHRAGA | KATEGORI" << endl;
                    showO(lo);
                    cout << ">> Pilih olahraga : " ;
                    cin >> sports.nama;
                    o = searchOlahraga(lo, sports.nama);
                    cout << "Berapa data yang akan dimasukan ? : " ;
                    cin >> k;
                    for (i = 1; i <= k; i++) {
                        cout << "Masukan Nama Atlet : " ;
                        cin >> athlete.nama;
                        cout << "Masukan Usia Atlet : " ;
                        cin >> athlete.usia;
                        cout << "Masukan Tinggi Atlet : " ;
                        cin >> athlete.tinggi;
                        cout << "Masukan Berat Atlet : " ;
                        cin >> athlete.berat;
                        cout << endl;

                        a = createNewElmA(athlete);
                        insertFirstA(lo, o, a);
                    }
                    cout << "===MENAMPILKAN LIST ATLET===" << endl;
                    showAll(lo);
                    break;
                case 3:
                    cout << "===LIST LOMBA==="<<endl;
                    cout << "Berapa data yang akan dimasukan ? : " ;
                    cin >> k;
                    for (i = 1; i <= k; i++) {
                        cout << "Masukan  Nama Lomba : " ;
                        cin >> exb.nama;
                       // cout << "Masukan ID Lomba : " ;
                       // cin >> exb.id;

                       createListL(ll);
                       l = createNewElmL(exb);
                       insertFirstL(ll, l);
                    }
                    cout << "===MENAMPILKAN LIST LOMBA===" << endl;
                    showL(ll);
                    break;
                case 4:
                    cout << "===>>LIST ATLET<<===" << endl;
                    showAll(lo);
                    cout << "Pilih atlet yang akan diikutsertakan dalam Lomba" << endl;
                    cout << ">> Nama Atlet : ";
                    cin >> athlete.nama;
                    a = searchAtlet(lo, athlete.nama);
                    cout << "===>>LIST LOMBA<<===" << endl;
                    showL(ll);
                    cout << "Pilih Lomba yang akan diikuti" << endl;
                    cout << ">> Nama Lomba :" << endl;
                    cin >> exb.nama;
                    l = searchLomba(ll, exb.nama);
                    atletLomba(lo, a, l);
                    cout << endl;
                    showAll(lo);
                    break;
                }

            }
            cout << "Kembali ke Menu ? (Y/N) : " ;
            cin >> opsi;
            //system("cls");
        }
        break;
    }

    return 0;
}

