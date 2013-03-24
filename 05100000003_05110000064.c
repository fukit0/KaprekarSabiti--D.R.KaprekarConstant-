#include <stdio.h>
#include <stdlib.h>

#define BOYUT_SAYI 9
#define BOYUT_FARK 100

void yerdegistir(int *,int *);
void dizi_sirala_min_max(int *,int);
void dizi_sirala_max_min(int *,int);
int dizide_ara(int *,int,int);
int diziden_sayi_hesapla(int *,int);
int bas_say_bul(long int);
long int us_al(int,int);

int main()
{
    int i,sayac=0,kontrol=0,kucuk_sayi,buyuk_sayi;
    int sayi_dizi[BOYUT_SAYI]={0};
    int fark[BOYUT_FARK]={0};
    long int sayi;

    do{
        printf("En az 2, en fazla 9 basamakli pozitif bir tam sayi giriniz: ");
        scanf("%ld",&sayi);

        for(i=0;i<BOYUT_SAYI;i++){
            sayi_dizi[i]=sayi%us_al(10,i+1)/us_al(10,i);
        }

        dizi_sirala_min_max(sayi_dizi,bas_say_bul(sayi));
        buyuk_sayi=diziden_sayi_hesapla(sayi_dizi,bas_say_bul(sayi));
        dizi_sirala_max_min(sayi_dizi,bas_say_bul(sayi));
        kucuk_sayi=diziden_sayi_hesapla(sayi_dizi,bas_say_bul(sayi));

    }while(kucuk_sayi==buyuk_sayi);

    do{
        for(i=0;i<BOYUT_SAYI;i++){
            sayi_dizi[i]=sayi%us_al(10,i+1)/us_al(10,i);
        }

        dizi_sirala_min_max(sayi_dizi,bas_say_bul(sayi));
        buyuk_sayi=diziden_sayi_hesapla(sayi_dizi,bas_say_bul(sayi));
        dizi_sirala_max_min(sayi_dizi,bas_say_bul(sayi));
        kucuk_sayi=diziden_sayi_hesapla(sayi_dizi,bas_say_bul(sayi));

        fark[sayac]=buyuk_sayi-kucuk_sayi;

        if(bas_say_bul(fark[sayac])<bas_say_bul(sayi))
            fark[sayac]*=10;

        kontrol=dizide_ara(fark,fark[sayac],sayac);

        sayi=fark[sayac];

        sayac++;

    }while(kontrol==0);

    printf("-----------------------------------------------------------\n");

    if(kontrol==1)
    {

        printf("%d adimda seriye ulasildi.\nSerinin uzunlu: %d\nSeriyi olusturan sayilar:\n",sayac,sayac-1);

        for(i=0;i<sayac-1;i++)
          {
            printf("\n%d\n",fark[i]);
          }
    }

    else
     {
        if(kontrol==2)
            printf("%d adimda kapali bir sayiya ulasildi. Bu kapali sayi: %d\n",sayac,fark[sayac-1]);
     }

return 0;
}

void yerdegistir(int *w,int *t)
{
    int gecici;

    gecici=*w;
    *w=*t;
    *t=gecici;
}

void dizi_sirala_min_max(int *dizi,int eleman_say)
{
    int i,j,min_indeks;

    for(i=0;i<eleman_say-1;i++)
    {
        min_indeks=i;

        for(j=i;j<eleman_say;j++){
            if(dizi[j]<dizi[min_indeks])
                min_indeks=j;
        }

        if(min_indeks!=i)
            yerdegistir(&dizi[min_indeks],&dizi[i]);
    }
}

void dizi_sirala_max_min(int *dizi,int eleman_say)
{
    int i,j,max_indeks;

    for(i=0;i<eleman_say-1;i++){
        max_indeks=i;

        for(j=i;j<eleman_say;j++)
        {
            if(dizi[j]>dizi[max_indeks])
                max_indeks=j;
                yerdegistir(&dizi[max_indeks],&dizi[i]);
        }


    }
}

int dizide_ara(int *dizi,int aranan,int sayac)
{
    int i,kontrol=0;

    for(i=0;i<sayac;i++){
        if(aranan==dizi[i]){
            if(i==sayac-1){
                kontrol=2;
            }
            else{
                kontrol=1;break;
            }
        }
    }

    return kontrol;
}

int diziden_sayi_hesapla(int *dizi, int eleman_say)
{
    int i;
    long int sonuc=0;

    for(i=0;i<eleman_say;i++){
        sonuc+=dizi[i]*us_al(10,i);
    }

    return sonuc;
}

int bas_say_bul(long int a)
{
    int basamak=0;

    do{
        basamak++;
        a=a/10;
    }while(a>0);

    return basamak;
}

long int us_al(int a,int b)
{
    int i;
    long int carpim=1;

    for(i=0;i<b;i++){
        carpim=carpim*a;
    }

    return carpim;
}
