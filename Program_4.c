//Autor: Leszek Baca. Struktury, unie i dynamiczne struktury danych
#include<stdio.h>
/*zawiera prototyp malloc()*/
#include<stdlib.h>
#include<string.h>
#define ROZMIAR 8
#define KONIEC "koniec"
#define ZNAK "="

struct dane 
{
  char nazwa[ROZMIAR+1];
  char liczba;
//wskazuje na nastepna strukture    
  struct dane * nast;
};
struct dane *glowa;
int wpisz (struct dane **list, char *string, int liczba);
void wypisz();
void usun ();


int main()
{ 
  char tab[30];  
  char *wskaznik;
  int liczby; 
  printf("Podaje dane. Wpisz \"koniec\" aby wyswietlic liste\n");
//Wpisanie slowa "koniec" w nowym wierszu, powoduje zakoncznie petli while
  while(gets(tab) != NULL  && strcmp(tab,KONIEC) != 0)
  {
// Funkcja strtok rozklada lancuch na osobne tokenty.
//Znakiem rozdzielajacym jest "="
     wskaznik = strtok(tab,ZNAK);
//Funckja atoi pobiera lancuch znakowy, 
//a zwraca odpowiadajaca mu wartosc calkowita
     liczby = atoi(strtok (NULL,ZNAK));
     wpisz(&glowa,wskaznik,liczby); 
   }

wypisz();   
usun();

return 0;  
}
//Wczytanie wyrazow i utworzenie listy
int wpisz (struct dane **list, char *string, int liczba)
{
  struct dane *element,*ostatni;
//proba przydzielenia pamieci
  element = (struct dane*)malloc(sizeof(struct dane));
//przypuszczalnie brak pamieci
  if (!element) 
    exit(1);
//wczytanie wyrazu
  strcpy(element->nazwa,string);
  element->liczba = liczba;
  element->nast=NULL;
  if (*list==NULL)
    *list=element;
    else
     {
//Ponizsza czesc kodu odpowiedzialna jest za znajdowanie w liscie wpisanej 
//wczesniej tej samej nazwy i zaaktualizowanie jej wartosci
        for(ostatni=(*list);ostatni->nast;ostatni=ostatni->nast)
         {  
            if(strcmp(ostatni->nazwa, string)==0)
              {
                ostatni->liczba = liczba;
                return 0;
              }
         }
             ostatni->nast=element;   
     }
return 0;
}

//Wypisywanie listy
void wypisz()
{
  struct dane *wsk;
  for(wsk=glowa;wsk;wsk=wsk->nast)
  printf("%s=%d\n",wsk->nazwa,wsk->liczba);     
}

//Usuniecie listy z pamieci
void usun ()
{
 struct dane *wsk;
 while(wsk!=NULL)
  {
    wsk = glowa->nast;
    free(wsk);
    glowa=wsk;                
  }
}
 
    
 
    
    
    

