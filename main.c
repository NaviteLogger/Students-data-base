/*
*Marek Kacprzak, WCY22IY3S1
*Zajecia: 10.01.2023, rozliczenie: 17.01.2023 23:59
*Temat: Zadanie 5 Oceny studentow
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define liczbaStudentow 20  //stala liczba studentow
#define liczbaPrzedmiotow 5 //stala liczba przedmiotow
#define maksymalnaDlugosc 30
#define liczbaImionINazwisk 50

struct Student
{
    char imie[40];
    char nazwisko[40];
    float oceny[liczbaPrzedmiotow];
};

int losujProporcje()
{
    int proporcja = rand()%liczbaStudentow;
    return proporcja;
}

void losowanieImionINazwisk(int tablicaTymczasowa[])
{
    for(int i = 0; i < liczbaImionINazwisk; i++) //przypisanie wartosci domyslnych do tablicy
    {
        tablicaTymczasowa[i] = i;
    }

    int zmiennaLosowaTymczasowa = 0;
    int temp = 0;

    for(int i = 0; i < liczbaImionINazwisk; i++)
    {
        zmiennaLosowaTymczasowa = rand()%liczbaImionINazwisk; //rand() % 50
        temp = tablicaTymczasowa[i];
        tablicaTymczasowa[i] = tablicaTymczasowa[zmiennaLosowaTymczasowa];
        tablicaTymczasowa[zmiennaLosowaTymczasowa] = temp;
    }
}

void wygenerowanieStudentow(int proporcja, struct Student strukturaStudentow[], char imionaMeskie[][maksymalnaDlugosc], char nazwiskaMeskie[][maksymalnaDlugosc], char imionaZenskie[][maksymalnaDlugosc], char nazwiskaZenskie[][maksymalnaDlugosc])
{
    int tablicaTymczasowa[liczbaImionINazwisk];
    losowanieImionINazwisk(tablicaTymczasowa);

    for (int i = 0; i < proporcja; i++)
    {
        strcpy(strukturaStudentow[i].imie,  imionaMeskie[tablicaTymczasowa[i]]);

        strcpy(strukturaStudentow[i].nazwisko, nazwiskaMeskie[tablicaTymczasowa[i]]);

        for(int j = 0; j < liczbaPrzedmiotow; j++)
        {
            strukturaStudentow[i].oceny[j] = (float) (rand() % 5 + 2);
        }
    }
    for (int i = proporcja; i < liczbaStudentow; i++)
    {
        strcpy(strukturaStudentow[i].imie, imionaZenskie[tablicaTymczasowa[i]]);

        strcpy(strukturaStudentow[i].nazwisko, nazwiskaZenskie[tablicaTymczasowa[i]]);

        for(int j = 0; j < liczbaPrzedmiotow; j++)
        {
            strukturaStudentow[i].oceny[j] = (float) (rand() % 5 + 2);
        }
    }
}

void printStudentsWithGrades(struct Student strukturaStudentow[], char przedmioty[][maksymalnaDlugosc])
{
    for (int i = 0; i < liczbaStudentow; i++)
    {
        printf("%i: Imie i nazwisko: %-15.15s %-15.15s Oceny z przedmiotow: ",i, strukturaStudentow[i].imie, strukturaStudentow[i].nazwisko);
        for(int j = 0; j < liczbaPrzedmiotow; j++)
        {
            printf("%s:\t %.2f ",przedmioty[j],strukturaStudentow[i].oceny[j]);
        }
        printf("\n");
    }
}

void printStudentsWithTheirAverages(struct Student strukturaStudentow[], char przedmioty[][maksymalnaDlugosc])
{
    for (int i = 0; i < liczbaStudentow; i++)
    {
        float sredniaOcenUcznia = 0;
        printf("%i: Imie i nazwisko: %-15.15s %-15.15s Oceny z przedmiotow: ",i, strukturaStudentow[i].imie, strukturaStudentow[i].nazwisko);
        for(int j = 0; j < liczbaPrzedmiotow; j++)
        {
            sredniaOcenUcznia += strukturaStudentow[i].oceny[j];
        }
        printf("Srednia ucznia: %f", sredniaOcenUcznia);
        printf("\n");
    }
}

void printStudent(struct Student strukturaStudentow[], char przedmioty[][maksymalnaDlugosc])
{
    printf("Podaj numer studenta: ");
    char c[2];
    scanf(" %s", c);
    int tempNumer = atoi(c);
    float sredniaOcenUcznia = 0;
    for(int i = 0; i < liczbaPrzedmiotow; i++)
    {
        sredniaOcenUcznia += strukturaStudentow[i].oceny[i];
    }
    printf("%i: Imie i nazwisko: %-15.15s %-15.15s Oceny z przedmiotow: ",tempNumer, strukturaStudentow[tempNumer].imie, strukturaStudentow[tempNumer].nazwisko);
    for(int j = 0; j < liczbaPrzedmiotow; j++)
    {
        printf("%s:\t %.2f ",przedmioty[j],strukturaStudentow[tempNumer].oceny[j]);
    }
    printf("Srednia ucznia: %f", sredniaOcenUcznia);
    printf("\n");
}

void printSredniaGrupy(struct Student strukturaStudentow[])
{
    float sredniaGrupy = 0;
    for(int i = 0; i < liczbaStudentow; i++) {
        for (int j = 0; j < liczbaPrzedmiotow; j++)
        {
        sredniaGrupy += strukturaStudentow[i].oceny[j];
        }
    }
    printf("Srednia calej grupy to: %f", sredniaGrupy);
}

void printSredniaPrzemiotu(struct Student strukturaStudentow[], char przedmioty[][maksymalnaDlugosc])
{
    printf("Podaj numer  przedmiotu: ");
    for(int i = 0; i < liczbaPrzedmiotow; i++)
    {
        printf("%i: %s",i,przedmioty[i]);
    }

    char c[2];
    scanf(" %s", c);
    int tempNumer = atoi(c);
    float sredniaZPrzedmiotu = 0;
    for(int i = 0; i < liczbaStudentow; i++)
    {
        sredniaZPrzedmiotu += strukturaStudentow[i].oceny[tempNumer];
    }
    printf("Srednia z przedmiotu: %s grupy to: %f",przedmioty[tempNumer],sredniaZPrzedmiotu);
}

int main()
{
    srand(time(NULL));

    char imionaMeskie[][maksymalnaDlugosc] = {"Adam", "Aleksander", "Andrzej", "Antoni", "Bartlomiej", "Bogdan", "Cezary", "Damian", "Dariusz", "Dawid", "Edward", "Fabian", "Feliks", "Filip", "Franciszek", "Grzegorz", "Henryk", "Igor", "Jacek", "Jan", "Jozef", "Kamil", "Karol", "Lech", "Leslaw", "Marek", "Mariusz", "Mateusz", "MichaL", "Piotr", "RafaL", "Robert", "Sebastian", "Slawomir", "Stanislaw", "Tomasz", "Wojciech", "Zbigniew", "Zdzislaw", "Adrian", "Arkadiusz", "Bartosz", "Damian", "Daniel", "Dariusz", "Dominik", "Fabian", "Grzegorz", "Jakub", "Kamil"};
    char nazwiskaMeskie[][maksymalnaDlugosc] = {"Kowalski", "Mazur", "Kowalczyk", "Wojciechowski", "Kaminski", "Kowalewski", "Zielinski", "Szymanski", "Wozniak", "Dabrowski", "Kozlowski", "Jankowski", "Wojciechowski", "Kwiatkowski", "Kaczmarek", "Malinowski", "Piotrowski", "Grabowski", "Nowakowski", "Pawlowski", "Michalski", "Adamczyk", "Dudek", "Zajac", "Wieczorek", "JabloNski", "Krol", "Majewski", "Olszewski", "Jaworski", "Wrobel", "Makowski", "Kaczmarczyk", "Domanski", "Zalewski", "Jakubowski", "JasiNski", "Zawadzki", "Sadowski", "Bak", "Chmielewski", "Wlodarczyk", "Borkowski", "Czarnecki", "Sawicki", "Sokolowski", "Urbanski", "Kubiak", "Maciejewski", "Szewczyk"};
    char imionaZenskie[][maksymalnaDlugosc] = {"Anna", "Maria", "Katarzyna", "Agnieszka", "Ewa", "Malgorzata", "Joanna", "Krystyna", "Barbara", "Elzbieta", "Danuta", "Halina", "Helena", "Irena", "Jadwiga", "Janina", "Kazimiera", "Magdalena", "Teresa", "Zofia", "Dorota", "Aleksandra", "Bozena", "Cecylia", "Ewelina", "Gabriela", "Iwona", "Julia", "Karolina", "Lidia", "Liliana", "Lucyna", "Marianna", "Monika", "Renata", "Sandra", "Stanislawa", "Urszula", "Weronika", "Zuzanna", "Beata", "Jolanta", "Stanislawa", "Alicja", "Amelia", "Kamila", "Kinga", "Maja", "Natalia", "Paulina"};
    char nazwiskaZenskie[][maksymalnaDlugosc] = {"Nowak", "Kowalska", "Wisniewska", "Wojcik", "Kowalczyk", "Kaminska", "Lewandowska", "Dabrowska", "Zielinska", "Szymanska", "Wozniak", "Kozlowska", "Jankowska", "Mazur", "Wojciechowska", "Kwiatkowska", "Krawczyk", "Kaczmarek", "Piotrowska", "Grabowska", "Zajac", "Pawlowska", "Nowacka", "Adamczyk", "Tyszkiewicz", "Stepien", "Olszewska", "Jablonska", "Chmielewska", "Wlodarczyk", "Borkowska", "Czarnecka", "Sobczak", "Krupa", "Maciejewska", "Sikora", "Mroz", "Dudek", "Kot", "Stasiak", "Baran", "Rutkowska", "Michalska", "Sawicka", "Sadowska", "WrOblewska", "Walczak", "Sosnowska", "Kacprzak", "Kempowinska"};
    char przedmioty[][maksymalnaDlugosc] = {"Matematyka 1","Matematyka 2","J. angielski","Informatyka","Etyka Zawodowa"};

    struct Student strukturaStudentow[20]; //zainicjowanie listy struktur o typie Student
    int proporcja = losujProporcje();

    
    printf("\nDZIENNIK STUDENCKI UCZELNI XYZ\n");
    printf("Wybierz, ktore zadanie ma wykonac dziennik:\n");
    printf("[1]Wyswietlenie listy wszystkich studentow grupy dziekanskiej, wraz z zestawem ich ocen.\n");
    printf("[2]Wyswietlenie ocen danego studenta oraz jego srednia ocen.\n");
    printf("[3]Wyswietlenie studentow oraz ich srednie z przedmiotow.\n");
    printf("[4]Wyswietlenie sredniej ocen calej grupy dziekanskiej.\n");
    printf("[5]Wyswietlenie sredniej oceny z wybranego przez uzytkownika przedmiotu.\n");
    printf("[6]Ponowne wygenerowanie nowych danych studentow grupy, wraz z ocenami.\n");
    printf("[0]Konczenie dzialania aplikacji.\n");
    printf("Wybor:\n>");

    char odpowiedzuzytkownika = getche();
    int numerOdpowiedziUzytkownika = atoi(odpowiedzuzytkownika);
    fflush(stdin);


    return 0;
}