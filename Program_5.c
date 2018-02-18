//Autor: Leszek Baca
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROZMIAR 50
struct dane 
{
  char ksiazka[ROZMIAR+1];
//Wskazuje na nastepna strukture
  struct dane *nast; 
};


struct dane *glowa=NULL;
struct dane *ostatni=NULL;
int wpisz (struct dane *lista, char *string);
void menu();
void wypisz();
void usun();
void wpiszdopliku();
int wczytajzpliku();
int main()
{
  char wybor[1];

  do
  {
    menu();
    printf("Polecenie: ");
//Kazdy wybor nalezy potwierdzac enterem
    gets(wybor);
    printf("\n");
 
//Poprawne dane gdy tekst wpisany sklada sie z jednego znaku   
    while(wybor[1]!='\0')
    {
      printf("Podaj poprawne dane\n");
      gets(wybor);
    }
    switch(wybor[0])
    {
      case '1':
      {       
        char tab[ROZMIAR];  
        printf("Podaj tytuly ksiazek\n");
//Dwukrotnie naciśniecie entera powoduje wyjście z petli, a wiec i zakonczenie 
// pobiernia danych do listy
        while(gets(tab) != NULL  && tab[0] != '\0')
        wpisz(glowa,tab); 
      } 
       break;
      
       case '2':
       {            
         wypisz();
         printf("\n");
       }
       break;
      
       case '3':
         wpiszdopliku();
       break;
    
       case '4':
         wczytajzpliku();
       break;
      
       case '5':
         usun ();
       break;
    
       default:   
         printf("\nzly wybor\n");
     }
  }
while(wybor[0]!='5');
return 0;
}

//Tekst menu
void menu()
{
  printf("Menu\n");                        
  printf("1. dodaj ksiazke\n");
  printf("2. wyswietl liste\n");
  printf("3. zapisz do pliku\n");
  printf("4. odczytaj z pliku\n");
  printf("5. wyjscie\n");
     	
}
//Funkcja odpowiedzialna za wczytanie ksiazek i utworzenie listy
int wpisz (struct dane *lista, char *string)
{
  struct dane *element;
  element = (struct dane*)malloc(sizeof(struct dane));
  
//przypuszczalnie brak pamieci
  if (!element) 
    exit(1); 
  strcpy(element->ksiazka,string);

  if (glowa==NULL)
  {
    element->nast=NULL;    
    glowa=element;
    ostatni=element;
  }
  else
  {
    element->nast=NULL;
    ostatni->nast=element;
    ostatni=element;        
  }
return 0;
}

//Wypisywanie listy
void wypisz()
{
  struct dane *wsk;
  if (glowa!=NULL)
    printf("\nLista ksiazek:\n");
  else
  
//Jezeli lista jest pusta zostanie wyswietlony tekst "Lista jest pusta". 
//W przeciwnym wypadku zostanie wyswietlony tekst "Lista ksiazek", a pod
//nim lista ksiazek 
    printf("\nLista jest pusta\n");  
 
  for(wsk=glowa;wsk;wsk=wsk->nast)
    printf("%s\n",wsk->ksiazka);
 
}

//Usuniecie listy z pamieci
void usun ()
{
  struct dane *wsk;
  while(glowa!=NULL)
  {
    wsk = glowa->nast;
    free(glowa);
    glowa=wsk;                
  }
 
}


//Zapisanie listy do pliku
void wpiszdopliku()
{
  FILE *plik;
  struct dane *wsk;
  if ((plik=fopen("listaksiazek.txt","w"))==NULL)
    printf("Nie moge otworzyc pliku\n\n");
  for(wsk=glowa;wsk;wsk=wsk->nast)
    fprintf(plik,"%s\n",wsk->ksiazka);    
  fclose(plik);           
} 

//Odczytanie z pliku i wpisanie do listy. 
//Kazdy wers w pliku wpisywany jest do nowego elementu listy. 
//Program działa poprawnie jezeli długosc wersu nie przekracza rozmiaru 
//tablicy tabs   
int wczytajzpliku()
{
   FILE *plik;
   char buf;
   char tabs[ROZMIAR];
   int i;
   i=0;
   if ((plik=fopen ("listaksiazek.txt", "r")) == NULL ) 
     printf("Nie moge znalesc pliku wejsciowego\n");
     
   while ((buf=fgetc(plik))!=EOF)
   {
     if (buf == '\n') 
     {
       tabs[i]='\0';
       wpisz(glowa,tabs);
       i=0;
     }
     else
     {
       tabs[i]=buf;
       i++;
     }
   }
fclose(plik);       
return 0;
}
