 /*
 *Marek Kacprzak, WCY22IY3S1
 *Zajecia: 10.01.2023, rozliczenie: 17.01.2023 23:59
 *Temat: Zadanie 4 Oceny studentow
 */
 #include <stdio.h>
 #include <time.h>
 #include <stdlib.h>
 #include <string.h>

 #define liczbaStudentow 9 //stala liczba studentow
 #define liczbaPrzedmiotow 4 //stala liczba przedmiotow

 struct Student {
     char imieINazwisko[40];
     int oceny[liczbaPrzedmiotow];
     float sredniaArytmetycznaOcen;
 };

 int main()
 {
     float srednieZPrzedmiotow[liczbaPrzedmiotow]; //zainicjowanie tablicy srednich z przedmiotu

     struct Student strukturaStudent[10]; //zainicjowanie listy struktur o typie Student

     char ImionaINazwiska[][30] = {
             {"Jane Smith"},
             {"John Doe"},
             {"Mike Williams"},
             {"Emily Johnson"},
             {"Jacob Jones"},
             {"Amanda Brown"},
             {"Jessica Garc"},
             {"Robert Miller"},
             {"Ashley Davis"},
             {"Michael Rod"}
     };

     srand(time(NULL));
     int r;

     char tekstAplikacji[][40] = {
             "Imie i nazwisko: ",
             "Oceny:     ",
             "   matematyka 1: ",
             "   matematyka 2: ",
             "   informatyka: ",
             "   j. angielski: ",
             "       srednia ucznia:     ",
             "Srednia z przedmiotu: ",
             };

     //zerowanie srednich ucznia oraz z przedmiotu
     for (int i = 0; i < liczbaStudentow; i++)
     {
         strukturaStudent[i].sredniaArytmetycznaOcen = 0;
     }
     for (int i = 0; i < liczbaPrzedmiotow; ++i)
     {
         srednieZPrzedmiotow[i] = 0;
     }

     //losowanie ocen
     for(int i = 0; i < liczbaStudentow;i++)
     {
         for (int j = 0; j < liczbaPrzedmiotow;j++)
         {
             r = rand() % 4 + 2;
             strukturaStudent[i].sredniaArytmetycznaOcen += (float)r;
             strukturaStudent[i].oceny[j] = r;
         }
         strukturaStudent[i].sredniaArytmetycznaOcen = strukturaStudent[i].sredniaArytmetycznaOcen / liczbaPrzedmiotow;
         strcpy(strukturaStudent[i].imieINazwisko,ImionaINazwiska[i]);
     }

     float sredniaWszystkiego = 0;

     //wyliczanie sredniej
     for(int i=0;i<liczbaPrzedmiotow;i++)
     {
         for(int j=0;j<liczbaStudentow;j++)
         {
             srednieZPrzedmiotow[i] += (float)strukturaStudent[j].oceny[i];
             sredniaWszystkiego += (float)strukturaStudent[j].oceny[i];

         }
         srednieZPrzedmiotow[i] = srednieZPrzedmiotow[i] / (float)liczbaStudentow;
     }

     sredniaWszystkiego = sredniaWszystkiego / (float)(liczbaStudentow*liczbaPrzedmiotow);

     //wyswietlanie struktur
     for(int i = 0; i<liczbaStudentow;i++) {
         int temp = 0;
         printf("%s", tekstAplikacji[temp]);
         temp++;
         printf("%s \t", strukturaStudent[i].imieINazwisko);
         printf("%s", tekstAplikacji[temp]);
         temp = +6;
         for (int k = 0; k < liczbaPrzedmiotow; ++k) {
             printf("%s", tekstAplikacji[k + 2]);
             printf("%i ", strukturaStudent[i].oceny[k]);
         }
         printf("%s", tekstAplikacji[temp]);
         printf("%.2f", strukturaStudent[i].sredniaArytmetycznaOcen);
         printf("\n");
     }

     //wyswietlanie sredniej ocen
     for (int i = 0; i < liczbaPrzedmiotow; i++)
     {
         printf("%s %s \t%.2f\n",tekstAplikacji[7],tekstAplikacji[i+2],srednieZPrzedmiotow[i]);
     }

     printf("Srednia ze wszystkich ocen to: \t\t\t%0.2f",sredniaWszystkiego);

     return 0;
 }