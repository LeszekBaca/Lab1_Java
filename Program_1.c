//Autor: Leszek Baca.  Temat: Biblioteki i funkcje bibloteczne
#include<stdio.h>
/*zawiera prototyp malloc()*/
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ROZMIAR 8
#define KONIEC "koniec"
#define ZNAK "="

struct dane 
{
  char nazwa[ROZMIAR+1];
  
 union
 {
   double zmienp;
   int calkowita;
 }liczby;
//wskazuje na nastepna strukture  
   struct dane * nast;
};

    
struct dane *glowa;
int wpiszint (struct dane **list, char *string, int liczba);
int wpiszzmp (struct dane **list, char *string, double licz);
void wypisz();
void usun ();


int main()
{ 
  char tab[30];  
  char *wskaznik;
  double liczby;
  int integer;
  char *p, lit = '.';
  
  
  printf("Podaje dane. Wpisz \"koniec\" aby wyswietlic liste\n");
//Wpisanie slowa "koniec" w nowym wierszu, powoduje zakoncznie petli while
  while(gets(tab) != NULL  && strcmp(tab,KONIEC) != 0)
  {
   p = strchr(tab,lit);
// Funkcja strtok rozklada lancuch na osobne tokenty.
//Znakiem rozdzielajacym jest "="
   wskaznik = strtok(tab,ZNAK);
   
   if(p>wskaznik)
     {
//Funckja atof pobiera lancuch znakowy, 
//a zwraca odpowiadajaca mu wartosc zmiennoprzecinkowa
       liczby = atof(strtok (NULL,ZNAK));
       wpiszzmp(&glowa,wskaznik,liczby);   
     }
    else
                  
     {
//Funckja atoi pobiera lancuch znakowy, 
//a zwraca odpowiadajaca mu wartosc calkowita
       integer = atoi(strtok (NULL,ZNAK)); 
        wpiszint(&glowa,wskaznik,integer);  
                   
     }
              
   }

wypisz();   
usun();

return 0;  
}
//Funkcja odpowiedzialna za obsluge liczb calkowitych
int wpiszint (struct dane **list, char *string, int liczba)
{
  struct dane *element,*ostatni;
//proba przydzielenia pamieci
  element = (struct dane*)malloc(sizeof(struct dane));
//przypuszczalnie brak pamieci
  if (!element) 
    exit(1);
//wczytanie wyrazu
  strcpy(element->nazwa,string);
  
  element->liczby.calkowita = liczba;
  
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
                
                ostatni->liczby.calkowita = liczba;
                
                return 0;
              }
         }
             ostatni->nast=element;   
     }
return 0;
}
//Funkcja odpowiedzialna za obsluge liczb zmiennoprzecinkowych
int wpiszzmp (struct dane **list, char *string, double licz)
{
  struct dane *element,*ostatni;
//proba przydzielenia pamieci
  element = (struct dane*)malloc(sizeof(struct dane));
//przypuszczalnie brak pamieci
  if (!element) 
    exit(1);
//wczytanie wyrazu
  strcpy(element->nazwa,string);
  
  element->liczby.zmienp = licz;
  element->liczby.calkowita = 0;
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
                
                ostatni->liczby.zmienp = licz;
                
                return 0;
              }
         }
             ostatni->nast=element;   
     }
return 0;
}
//wypisanie listy
void wypisz()
{
    
  struct dane *wsk;

  wsk=glowa;
  while(wsk!=NULL)
  {
     if (wsk->liczby.calkowita==0)
      {                       
         printf("%s=%.2f\n",wsk->nazwa,wsk->liczby.zmienp);
      }
      else
       { 
         printf("%s=%d\n",wsk->nazwa,wsk->liczby.calkowita);
       }
    wsk = wsk->nast;
  }
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
 
    
 
    
    
    
