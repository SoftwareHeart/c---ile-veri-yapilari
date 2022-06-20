#include <iostream>
#include <chrono>
#include <Windows.h>
#include <unistd.h>
#include "veri.h"

using namespace std;

struct Dugum *agac1 = NULL;
struct Dugum *agac2 = NULL;
struct Dugum *agac3 = NULL;

struct Dugum* agacKur(int deger) {
    struct Dugum *tmp = (struct Dugum *)malloc(sizeof(struct Dugum));
    tmp->veri = deger;
    tmp->sol = tmp->sag = NULL;
    return tmp;
}

struct Dugum* dugumEkle(struct Dugum* agac, int deger) {
    if (agac == NULL) {
        return agacKur(deger);
    }
    if (deger < agac->veri) {
        agac->sol = dugumEkle(agac->sol, deger);
    } else if (deger > agac->veri) {
        agac->sag = dugumEkle(agac->sag, deger);
    }
    return agac;
}

void agacaEkle(Dugum ** agac, int deger) {
    Dugum *tmp = NULL;
    if(!(*agac)) {
        tmp = (Dugum *)malloc(sizeof(Dugum));
        tmp->sol = tmp->sag = NULL;
        tmp->veri = deger;
        *agac = tmp;
        return;
    }
    if(deger < (*agac)->veri) {
        agacaEkle(&(*agac)->sol, deger);
    } else if(deger > (*agac)->veri) {
        agacaEkle(&(*agac)->sag, deger);
    }
}

bool DFS(struct Dugum* agac, int kontrolSayisi) {
    if (agac == NULL) {
        return false;
    }

    bool tempVal1 = BFS(agac->sol, kontrolSayisi);
    if(tempVal1) {
        return true;
    }

    bool tempVal2 = BFS(agac->sag, kontrolSayisi);
    return tempVal2;

    if (agac->veri == kontrolSayisi) {
        return true;
    }
}

bool BFS(struct Dugum* agac, int kontrolSayisi) {
    if (agac == NULL) {
        return false;
    }

    if (agac->veri == kontrolSayisi) {
        return true;
    }

    bool tempVal1 = BFS(agac->sol, kontrolSayisi);
    if(tempVal1) {
        return true;
    }

    bool tempVal2 = BFS(agac->sag, kontrolSayisi);
    return tempVal2;
}

void agaciYazdir(struct Dugum* agac) {
    if (agac != NULL) {
        agaciYazdir(agac->sol);
        printf("%d \n", agac->veri);
        agaciYazdir(agac->sag);
    }
}

void agaclariOlustur() {
    agac1 = dugumEkle(agac1, dizi1[0]);
    for(int i = 1; i<UZUNLUK; i++) {
        dugumEkle(agac1, dizi1[i]);
    }

    agac2 = dugumEkle(agac2, dizi2[0]);
    for(int i = 1; i<UZUNLUK; i++) {
        dugumEkle(agac2, dizi2[i]);
    }

    agac3 = dugumEkle(agac3, dizi3[0]);
    for(int i = 1; i<UZUNLUK; i++) {
        dugumEkle(agac3, dizi3[i]);
    }
}

int main() {
    int agacSecimi, yontemSecimi, kontrolDegeri, agacKontrol;
    agaclariOlustur();

    printf("Lutfen arama yapmak istediginiz agaci secin: (1,2,3)");
    scanf("%d", &agacSecimi);

    if(agacSecimi == 1) {
        printf("\nLutfen agac %d icin arama yonteminizi secin. (DFS:1, BFS:2)", agacSecimi);
        scanf("%d", &yontemSecimi);

        if(yontemSecimi == 1) {
            printf("\nAgac %d uzerinde DFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac1 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = DFS(agac1, kontrolDegeri);
            auto end4Agac1 = chrono::steady_clock::now();

            auto elapsed4Agac1 = chrono::duration_cast<chrono::nanoseconds>(end4Agac1 - begin4Agac1);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %ld nano-saniye", elapsed4Agac1.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac1.count());
            }
        } else if(yontemSecimi == 2) {
            printf("\nAgac %d uzerinde BFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac1 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = BFS(agac1, kontrolDegeri);
            auto end4Agac1 = chrono::steady_clock::now();

            auto elapsed4Agac1 = chrono::duration_cast<chrono::nanoseconds>(end4Agac1 - begin4Agac1);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac1.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac1.count());
            }
        } else {
            printf("\nLutfen varolan arama yontemlerinden birini secin !");
        }
    } else if(agacSecimi == 2) {
        printf("\nLutfen agac %d icin arama yonteminizi secin. (DFS:1, BFS:2)", agacSecimi);
        scanf("%d", &yontemSecimi);

        if(yontemSecimi == 1) {
            printf("\nAgac %d uzerinde DFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac2 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = DFS(agac2, kontrolDegeri);
            auto end4Agac2 = chrono::steady_clock::now();

            auto elapsed4Agac2 = chrono::duration_cast<chrono::nanoseconds>(end4Agac2 - begin4Agac2);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac2.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac2.count());
            }
        } else if(yontemSecimi == 2) {
            printf("\nAgac %d uzerinde BFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac2 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = BFS(agac2, kontrolDegeri);
            auto end4Agac2 = chrono::steady_clock::now();

            auto elapsed4Agac2 = chrono::duration_cast<chrono::nanoseconds>(end4Agac2 - begin4Agac2);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac2.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac2.count());
            }
        } else {
            printf("\nLutfen varolan arama yontemlerinden birini secin !");
        }
    } else if(agacSecimi == 3) {
        printf("\nLutfen agac %d icin arama yonteminizi secin. (DFS:1, BFS:2)", agacSecimi);
        scanf("%d", &yontemSecimi);

        if(yontemSecimi == 1) {
            printf("\nAgac %d uzerinde DFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac3 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = DFS(agac3, kontrolDegeri);
            auto end4Agac3 = chrono::steady_clock::now();

            auto elapsed4Agac3 = chrono::duration_cast<chrono::nanoseconds>(end4Agac3 - begin4Agac3);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac3.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac3.count());
            }
        } else if(yontemSecimi == 2) {
            printf("\nAgac %d uzerinde BFS ile arayacaginiz degeri giriniz: ", agacSecimi);
            scanf("%d", &kontrolDegeri);

            auto begin4Agac3 = chrono::steady_clock::now();
            sleep(1);
            agacKontrol = BFS(agac3, kontrolDegeri);
            auto end4Agac3 = chrono::steady_clock::now();

            auto elapsed4Agac3 = chrono::duration_cast<chrono::nanoseconds>(end4Agac3 - begin4Agac3);

            if(agacKontrol == 1) {
                printf("\nSONUC => VERI BULUNDU");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac3.count());
            } else {
                printf("\nSONUC => VERI BULUNAMADI");
                printf("\nGECEN SURE => %d nano-saniye", elapsed4Agac3.count());
            }
        } else {
            printf("\nLutfen varolan arama yontemlerinden birini secin !");
        }
    } else {
        printf("\nLutfen sadece varolan agaclardan birini secin !");
    }
}