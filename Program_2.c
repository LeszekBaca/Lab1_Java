//Autor: Leszek Baca
#include <stdio.h>
#include <stdlib.h>
#define x 31
#define y 15
#define z 30
int main()
{
    
    FILE *wskaznik;
    int zm;
    int wiersze, kolumny, znaki;
    char tab[x][y][z];
    double liczba;
    double liczba2;
    int licznik;
    int licznik2;
    wiersze=0;
    kolumny=0;
    znaki=0;
    if((wskaznik=fopen("gliwice.csv", "r"))==NULL)
    printf("Nie moge otorzyc pliku\n"); 
//Petla odpowiedzialna za czytanie z pliku i wpisanie do tablicy  
    while ((zm=fgetc(wskaznik)) != EOF)  
    {
      if(zm==',')
       { 
         znaki=0;
         kolumny++;
       }
       else if (zm=='\n')
       { 
         znaki=0;
         kolumny=0;
         wiersze++;      
       } 
       else if (zm!=',' && zm!='\n')
       {
         tab[wiersze][kolumny][znaki]=zm;
         znaki++;  
       }

  
}
//zamkniecie pliku
fclose(wskaznik);


//Czesc kodu odpowiedzialna za utworzenie i otwarcie pliku 
if ((wskaznik=fopen("srednia.csv","w"))==NULL)
	printf("Nie moge otorzyc pliku\n\n"); 



//czesc kodu odpowiedzialna za wpisanie z kolumny 3 wartosci sredniej 
for (licznik=1;licznik<=29;licznik++) 
  {
	liczba += atoi(tab[licznik][3]);
  }
printf("temperatrura srednia: %.2f\n",liczba/29);
fprintf(wskaznik,"temperatrura srednia: %.2f\n",liczba/29);



//czesc kodu odpowiedzialna za wpisanie z kolumny 3 wartosci sredniej 
for (licznik2=1;licznik2<=29;licznik2++) 
  {
	liczba2 += atoi(tab[licznik2][7]);
  }
printf("wilgotnosc srednia: %.2f\n",liczba2/29);
fprintf(wskaznik,"wilgotnosc srednia: %.2f\n",liczba2/29);

//zamkniecie pliku    
fclose(wskaznik);
return 0;


}
