//Autor: Leszek Baca. Program do zliczania liter w kolumnach tablicy dwuwymiarowej
#include <stdio.h>
#define WIERSZE 20
#define KOLUMNY 20
int dlugosc (char tab[]);
void wpisz(char tab[][KOLUMNY], char string[]);
void drukuj( char tab[][KOLUMNY]);
void zliczajZnaki( char tab[][KOLUMNY]);

int main() 
{
  char tabDwuwym[WIERSZE][KOLUMNY];
  char string[]="JEZYK C JEST JEZYKIEM OGOLNEGO STOSOWANIA";

  printf("Wpisane znaki do tablicy jednowymiarowej: %s\n",string);   
  wpisz(tabDwuwym, string);
  printf("Wypisane znaki z tablicy dwuwymiarowej: ");
  drukuj(tabDwuwym);
  zliczajZnaki(tabDwuwym);
  
  return 0; 
}

//Funkcja zwraca dlugosc tablicy
int dlugosc (char tab[])
{
  int i;
  for (i=0; tab[i]!='\0'; i++);
    return i;  
}

//Funkcja wpisuje tablice jednowymiarowa w dwuwymiarowa
void wpisz(char tab[][KOLUMNY], char string[])
{
  int i,j,k,n;
  n=dlugosc(string);
  k=0;
  for (i=0;i<WIERSZE;i++)
   for(j=0;j<KOLUMNY;j++)
     {
        if(k<n)
          tab[i][j]=string[k++];
        else
          tab[i][j]=' ';
     }
} 

//Funkcja wypisuje z tablicy dwuwymiarowej
void drukuj( char tab[][KOLUMNY])
{ 
  int i,j;
  for (i=0; i<WIERSZE;i++)
  { 
    for (j=0;j<KOLUMNY;j++) 
      printf("%c",tab[i][j]);     
  } 
}
//Funcja odpowiedzialna za zliczanie liter po kolumnach
void zliczajZnaki( char tab[][KOLUMNY])
{
  int i,j,znaki, licznik=0;
  for (j=0;j<KOLUMNY;j++)
  {
     printf("\n\nKOLUMNA %d\n\n: ", j+1);
     for (znaki=65;znaki<=90;znaki++)
     {
         for (i=0; i<WIERSZE;i++)
         {
           if (tab[i][j]==znaki || tab[i][j]==(znaki+32))
             licznik+=1;
         }
       printf("%c: ", znaki);
       printf("%d\n: ", licznik);
       licznik=0;
     }
  }

}
