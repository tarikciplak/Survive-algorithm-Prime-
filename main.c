#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int parkurbitis,engeladet,i,*healthpoint;
int hp = 100;                                    //GLOBAL DEĞİŞKEN ATAMASI


int engelSayisi (){
   srand(time(NULL));
     engeladet=rand()%4+2;   //MinEngel:2 - MaxEngel:5
     int engelkonum[engeladet];
        printf("Engel Adet: %d\n",engeladet);

    return engelSayisi;
}

void parkurUzunlugu(){
    srand(time(NULL));
    int *p;
    parkurbitis = rand()%51+50;  // Parkur 50-100 metre arasinda random ataniyor
    p = &parkurbitis;
    *p=parkurbitis;

    return 0;
}


int engelHasari (int healthpoint, int engelkonum){
    int buyuk,kucuk,sonuc=1,i;
if (healthpoint > engelkonum){            //Küçük ve büyük sayilari kontrol ediyoruz
        buyuk = healthpoint;
        kucuk = engelkonum;
    }
    else{
        buyuk = engelkonum;
        kucuk = healthpoint;
    }

    for(i=2; i<=kucuk; i++){

        if( buyuk % i == 0 && kucuk % i == 0)    // Obeblerini kontrol ediyoruz
            sonuc = i;
    }

    if(sonuc == 1) {          // Obeb 1 ise aralarinda asaldir
         printf("\n%d ile %d aralarinda asaldir. HASAR ALICAK\n", healthpoint, engelkonum);
        hp = (hp) - (engelkonum) ;


    }

    else
        printf ("\n%d ile %d aralarinda asal degildir. UCUZ YIRTTI\n\n",healthpoint,engelkonum);


    return hp;

}

int main(void){
  int konum, i=0;
  healthpoint = &hp;
  *healthpoint = hp;
engelSayisi();
int engelkonum[engeladet];
parkurUzunlugu();
    for(int a=0;a<engeladet;a++){         // Random engel konumlarını üretiyor ve dizinin içine atiyoruz.
       engelkonum[a] = 5+rand()%50;
       printf("Engeler %d %d\n",(a+1),engelkonum[a]);
     }


    FILE *dosya;
    dosya = fopen("log.txt","w+");    // Degisiklige izin veren .txt uzantılı dosya üretiyoruz.
    fprintf(dosya,"Yarisma Basladi !\n");
    fprintf(dosya,"Yarismaci HP= %d\n",hp);


printf("Parkur Bitis : %d\n",parkurbitis);

for(int j=0;j<parkurbitis;j++){       // Parkur boyunca yarismaciyi kosturan sayacı uretıyoruz.
    for(int b = 0; b<=engeladet;b++){
        if(j == engelkonum[b]){         // Engel anında senaryomuzu uygulamaya koyuyoruz.
           engelHasari(*healthpoint,engelkonum[b]);  // Engelin hasarini uretmesi parametre yolluyoruz.
           fprintf(dosya,"Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",j);
           fprintf(dosya,"%d metrede bir engel var.",j);
           fprintf(dosya,"\nYarismaci HP= %d\n",hp);
           if(hp <=0){
            fprintf(dosya,"\nUzgunum ! Basaramadin :( ");
            break;
           }

           }
}

}
            if (hp > 0)
            fprintf(dosya,"\nTebrikler :) :) Basardin !!");
            fprintf(dosya,"\n%d HP ile oyunu sonlandırdın\n",hp);



  fclose(dosya);

         printf("\n\n NOT : Oyun loglari (C:\) klasorune log olarak uretildi.\n");
}

