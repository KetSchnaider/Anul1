#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Imobil {
    char proprietarul[50];
    char tipul[50];
    char adresa[50];
    float suprafata;
    float costul;
};

void introducere_elemente(struct Imobil* tablou, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Introduceti datele pentru imobilul %d:\n", i+1);
        printf("Proprietarul: ");
        scanf("%s",tablou[i].proprietarul);
        printf("Tipul: ");
        scanf("%s", tablou[i].tipul);
        printf("Adresa: ");
        scanf("%s",tablou[i].adresa);
        printf("Suprafata: ");
        scanf("%f", &tablou[i].suprafata);
        printf("Costul: ");
        scanf("%f", &tablou[i].costul);
    }
}

void afisare_fisier_textual(struct Imobil* tablou, int n, char* nume_fisier) {
    FILE* fisier = fopen(nume_fisier, "w");
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fisier, "%s %s %s %.2f %.2f\n", tablou[i].proprietarul, tablou[i].tipul, tablou[i].adresa, tablou[i].suprafata, tablou[i].costul);
    }
   
fclose(fisier);
}

void afisare_fisier_binar(struct Imobil* tablou, int n, char* nume_fisier) {
FILE* fisier = fopen(nume_fisier, "wb");
fwrite(tablou, sizeof(struct Imobil), n, fisier);
fclose(fisier);
}

void sortare_text_fisier(struct Imobil* tablou, int n, char* nume_fisier) {
int i, j;
struct Imobil aux;
for (i = 0; i < n-1; i++) {
for (j = i+1; j < n; j++) {
if (strcmp(tablou[i].proprietarul, tablou[j].proprietarul) < 0) {
aux = tablou[i];
tablou[i] = tablou[j];
tablou[j] = aux;
}
}
}
afisare_fisier_textual(tablou, n, nume_fisier);
}

void sortare_binar_fisier(struct Imobil* tablou, int n, char* nume_fisier) {
int i, j;
struct Imobil aux;
for (i = 0; i < n-1; i++) {
for (j = i+1; j < n; j++) {
if (tablou[i].suprafata > tablou[j].suprafata) {
aux = tablou[i];
tablou[i] = tablou[j];
tablou[j] = aux;
}
}
}
afisare_fisier_binar(tablou, n, nume_fisier);
}

void afisare_text_fisier_sortat(char* nume_fisier) {
FILE* fisier = fopen(nume_fisier, "r");
char c;
while ((c = fgetc(fisier)) != EOF) {
printf("%c", c);
}
fclose(fisier);
}

void afisare_binar_fisier_sortat(char* nume_fisier) {
FILE* fisier = fopen(nume_fisier, "rb");
struct Imobil imobil;
while (fread(&imobil, sizeof(struct Imobil), 1, fisier)) {
printf("%s %s %s %.2f %.2f\n", imobil.proprietarul, imobil.tipul, imobil.adresa, imobil.suprafata, imobil.costul);
}
fclose(fisier);
}

int main() {
int n;
printf("Introduceti numarul de elemente: ");
scanf("%d", &n);
struct Imobil* tablou = (struct Imobil*) malloc(n * sizeof(struct Imobil));
if (tablou == NULL) {
printf("Alocarea memoriei a esuat.\n");
return 1;
}
introducere_elemente(tablou, n);
afisare_fisier_textual(tablou, n, "imobile.txt");
afisare_fisier_binar(tablou, n, "imobile.bin");
sortare_text_fisier(tablou, n, "imobile_sortate.txt");
sortare_binar_fisier(tablou, n, "imobile_sortate.bin");
printf("Continutul fisierului textual cu datele sortate:\n");
afisare_text_fisier_sortat("imobile_sortate.txt");
printf("Continutul fisierului binar cu datele sortate:\n");
afisare_binar_fisier_sortat("imobile_sortate.bin");
free(tablou);
return 0;
}