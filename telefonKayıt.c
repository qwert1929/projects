#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <locale.h>   


  struct pers {
	char tc[13];   		
  	char adi[16]; 
  	char soyadi[16]; 
  	char tel_num[14];
	char bolum[15];   
  	int bayrak;
  }tel;
  
  
  void Ekle (struct pers*);
  void liste ();
  void arama ();
  void sil ();
  void guncelle();
  
  

//-----------------------------------------------------
  
  void Ekle (struct pers* insan){
  	char secim='e';
	int i,j;
FILE *ptVeri;
 
  if((ptVeri=fopen("personel.txt","a"))==NULL){
    return -1;
  }
		for(i=0; i<100; i++){
		system("cls");
		if (insan[i].bayrak==0){
		
		do{
		fflush(stdin);	
		printf("\nT.C. Giriniz!\n");
		scanf("%s",&insan[i].tc);
		fflush(stdin);	
		printf("\n�sim Giriniz!\n");
		scanf("%[^\n]s",&insan[i].adi);
		for (j=0;j<sizeof(insan[i].adi);j++){
		
		insan[i].adi[j]=toupper(insan[i].adi[j]);
	}
		fflush(stdin);
		printf("\nSoyad� Giriniz!\n");
		scanf("%[^\n]s",&insan[i].soyadi);
		for (j=0;j<sizeof(insan[i].soyadi);j++){
		
		insan[i].soyadi[j]=toupper(insan[i].soyadi[j]);
	}
		fflush(stdin);
		printf("\nTelefon Numaras� Giriniz!\n");
		scanf("%s",&insan[i].tel_num);
		fflush(stdin);
		printf("\nB�l�m�n� Giriniz!\n");
		scanf("%[^\n]s",&insan[i].bolum+'\0');
		
		insan[i].bayrak=1;
		printf("KAYIT EKLEND�\n\n");
		system("cls");
		
		fprintf(ptVeri, "%-12s\t%-15s\t%-15s\t%-13s\t%-15s\n", insan[i].tc, insan[i].adi, insan[i].soyadi, insan[i].tel_num, insan[i].bolum);
 		
		
		printf("\n\t\t********************\n");
		printf("\t\t*   KAYIT EKLEND�  *\n");
		printf("\t\t********************\n\n");

		printf( "\n Yeni Kay�t Eklemek �ster Misiniz? (E/H) :");
		secim=getch();
		system("cls");
}while(secim=='e'||secim=='E');
		
		fclose(ptVeri);
		printf("\n\t\tMen� i�in bir tu�a bas�n�z!");
		getch();
		system("cls");
		
		break;
		}
	
	  }


  }
  //---------------------------------------------------------
  
  void liste (){
	
    FILE *ptVeri; 
    struct pers insan3;  
  if((ptVeri=fopen("personel.txt","r"))==NULL){
    return -1;}


	system("cls");
	 printf("\nT.C.K�ML�K\t�S�M\t\tSOY�S�M\t\tTEL. NO:\tB�L�M\n");
  printf("-----------     -------------\t-------------\t-------------\t-------------\n");
  
  	int c;
	if (ptVeri) 
	{
		while ((c = getc(ptVeri)) != EOF)
			putchar(c);
		 fclose(ptVeri);
	}


printf("\n\t\tMen� i�in bir tu�a bas�n�z!");
		getch();
		system("cls");
	return 0;
  }
  
  //-------------------------------------------------------------
  
  void arama (){
  	
    struct pers insan2;	
    int k;
	char tc[13], isim[16], aranan[16], soyisim[16], telNo[14], bolum[16];	
    FILE *ptVeri;
    if((ptVeri=fopen("personel.txt","r"))==NULL){
    return -1;
    }
system("cls");
	printf("ARANACAK K��� �SM�N� G�R�N�Z!\n");
	fflush(stdin);
	scanf("%[^\n]s",&aranan);	
	for (k=0;k<16;k++){
	aranan[k]=toupper(aranan[k]);
	
}	
	system("cls");
	 printf("\nT.C.K�ML�K\t�S�M\t\tSOY�S�M\t\tTEL. NO:\tB�L�M\n");
  printf("-----------     -------------\t-------------\t-------------\t-------------\n");		
	int kayitYok=0;
	while(!feof(ptVeri))
	{

		fscanf(ptVeri,"%13s\t%15s\t%16s\t%14s\t%16s\n",tc,isim,soyisim,telNo,bolum);
      
		if(strstr(isim,aranan))
		{
			printf("%s\t%s\t\t%s\t\t%s\t%s\n",tc,isim,soyisim,telNo,bolum);
			kayitYok++;
		}
   
   }
if (kayitYok!=0){printf("\nToplam %d adet kay�t tespit edilmi�tir.",kayitYok);
}
   	else if(!kayitYok){
	   
	printf("%s Ad�nda bir kay�t bulunamad�\n",aranan);}
	fclose(ptVeri);	
 	
 
  fclose(ptVeri);
  printf("\n\n\t\tMen� i�in bir tu�a bas�n�z!");
		getch();
		system("cls");
  return 0;
}
		


 //-------------------------------------------------------------
  
  void sil (){
  
  struct pers insan4;	
 int i,sil;
	system("cls");
FILE *dosya,*yeni; 
char aranan[16];
char aranan2[16];
system("cls");

printf("S�L�NECEK KAYDIN ADI :\n");

scanf("%s",&aranan);
printf("S�L�NECEK KAYDIN SOYADI :\n");

scanf("%s",&aranan2);
for (i=0;i<16;i++){
	aranan[i]=toupper(aranan[i]);
	aranan2[i]=toupper(aranan2[i]);
	
}

dosya=fopen("personel.txt","r"); 
yeni=fopen("yeniii.txt","w");

   while(!feof(dosya)){

      fscanf(dosya,"%13s%16s%16s%14s%16s\n",insan4.tc,insan4.adi, insan4.soyadi,insan4.tel_num,insan4.bolum);

      if(strstr(insan4.adi,aranan)&&strstr(insan4.soyadi,aranan2)){
      	printf("\n\t\t********************\n");
		printf("\t\t*   KAYIT S�L�ND�  *\n");
		printf("\t\t********************\n\n");

            fscanf(dosya,"%13s%16s%16s%14s%16s\n",insan4.tc,insan4.adi, insan4.soyadi,insan4.tel_num,insan4.bolum);

      }

      fprintf(yeni,"%-12s\t%-15s\t%-15s\t%-13s\t%-15s\n",insan4.tc,insan4.adi, insan4.soyadi,insan4.tel_num,insan4.bolum);

   }

fclose(dosya);
fclose(yeni);

remove("personel.txt");
rename("yeniii.txt","personel.txt");

 printf("\n\n\t\tMen� ��in Bir Tu�a Bas�n�z!");
  	getch();
  	system("cls");
return 0;


}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
  void guncelle (){
  
  struct pers insan5;	
 int i,sil;
	system("cls");
FILE *dosya,*yeni; 
char aranan[16];
char aranan2[16];

char tc[12],adi[15],soyadi[15],telNo[13],bolumu[15];
system("cls");

printf("G�NCELLENECEK KAYDIN ADI :\n");

scanf("%s",&aranan);
printf("G�NCELLENECEK KAYDIN SOYADI :\n");

scanf("%s",&aranan2);
for (i=0;i<16;i++){
	aranan[i]=toupper(aranan[i]);
	aranan2[i]=toupper(aranan2[i]);
	
}

dosya=fopen("personel.txt","r"); 
yeni=fopen("yeniii.txt","w");

   while(!feof(dosya)){

      fscanf(dosya,"%13s%16s%16s%14s%16s\n",insan5.tc,insan5.adi, insan5.soyadi,insan5.tel_num,insan5.bolum);

      if(strstr(insan5.adi,aranan)&&strstr(insan5.soyadi,aranan2)){
      	printf("\nYeni T.C. giriniz:\n");
      	scanf("%s",insan5.tc);
      	fflush(stdin);
      	printf("Ad� giriniz:\n");
      	scanf("%[^\n]s",insan5.adi);
      	
      	printf("Soyad� giriniz:\n");
      	fflush(stdin);
      	scanf("%[^\n]s",insan5.soyadi);
      	printf("Tel. Numaras�n� giriniz:\n");
      	scanf("%s",insan5.tel_num);
      	printf("B�l�m� giriniz:\n");
      	scanf("%s",insan5.bolum);
      	for (i=0;i<16;i++){
	insan5.adi[i]=toupper(insan5.adi[i]);
	insan5.soyadi[i]=toupper(insan5.soyadi[i]);
	
}
      	
      	printf("\n\t\t********************\n");
		printf("\t\t*   KAYIT G�NCELLEND�  *\n");
		printf("\t\t********************\n\n");

            

      }

      fprintf(yeni,"%-12s\t%-15s\t%-15s\t%-13s\t%-15s\n",insan5.tc,insan5.adi, insan5.soyadi,insan5.tel_num,insan5.bolum);

   }

fclose(dosya);
fclose(yeni);

remove("personel.txt");
rename("yeniii.txt","personel.txt");

 printf("\n\n\t\tMen� ��in Bir Tu�a Bas�n�z!");
  	getch();
  	system("cls");
return 0;


}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
int main (){
  	setlocale(LC_ALL,"Turkish");
  	 struct pers tel[200];
  int i=0;  
  int secim;
  char aranacak[16];
 

  for (i=0;i<200;i++){
  	tel[i].bayrak=0;
  	
  }
  do {
  	printf("\n\n");
  	printf(" PERSONEL KAYIT PROGRAMI\n");
  	printf ("*************************");
	printf ("\n*  1- Kay�t Listele\t*");
  	printf ("\n*  2- Kay�t Ara\t\t*");
  	printf ("\n*  3- Kay�t Ekle\t*");
  	printf ("\n*  4- Kay�t Sil\t\t*");
  	printf ("\n*  5- Kay�t G�ncelle\t*");
  	printf ("\n*  6- Programdan ��k��\t*");
  	printf ("\n*************************\n");
  	
  	scanf("\n%d",&secim);
  	
  		while (secim<1 || secim>6){
  		printf("Listeden se�im yap�n�z");
		scanf("\n%d",&secim);  		
	  }
  	
  	switch(secim){
  		
  		case 1:{
  			liste();
			break;
		  }
		case 2:{
 		arama();
        break;
		}  		
		case 3:{
			Ekle(tel);
			break;
		}
		case 4:{
			sil();
			
			break;
		}
		case 5:{
			guncelle();
			break;
		}
		
		case 6:{
			exit(0);
		}
	  }

  
  	
  }
   	  while (!(secim<0||secim>5));
  
  	return 0;
  }


