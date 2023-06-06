#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Biblioteca {
    char denumirea[50];
    char adresa[100];
    char telefonul[20];
    int numarSali;
    int numarCarti;
};

void creareStiva(struct Biblioteca** stiva) {
    *stiva = (struct Biblioteca*)malloc(MAX_SIZE * sizeof(struct Biblioteca));
    if (*stiva == NULL) {
        printf("Nu s-a putut aloca memorie pentru stiva.\n");
    }
}

void citireDate(struct Biblioteca* stiva, int* numarElemente) {
    printf("Introduceti numarul de elemente pentru stiva: ");
    scanf("%d", numarElemente);
    getchar();
    
    for (int i = 0; i < *numarElemente; i++) {
        printf("Elementul %d:\n", i + 1);
        printf("Denumirea: ");
        fgets(stiva[i].denumirea, 50, stdin);
        stiva[i].denumirea[strcspn(stiva[i].denumirea, "\n")] = '\0';
        
        printf("Adresa: ");
        fgets(stiva[i].adresa, 100, stdin);
        stiva[i].adresa[strcspn(stiva[i].adresa, "\n")] = '\0';
        
        printf("Telefonul: ");
        fgets(stiva[i].telefonul, 20, stdin);
        stiva[i].telefonul[strcspn(stiva[i].telefonul, "\n")] = '\0';
        
        printf("Numarul de sali: ");
        scanf("%d", &stiva[i].numarSali);
        getchar();
        
        printf("Numarul de carti: ");
        scanf("%d", &stiva[i].numarCarti);
        getchar();
        
        printf("\n");
    }
}

void afisareStiva(struct Biblioteca* stiva, int numarElemente, const char* fisier) {
    FILE* file = fopen(fisier, "w");
    if (file == NULL) {
        printf("Nu s-a putut deschide fisierul.\n");
        return;
    }
    
    for (int i = 0; i < numarElemente; i++) {
        fprintf(file, "Elementul %d:\n", i + 1);
        fprintf(file, "Denumirea: %s\n", stiva[i].denumirea);
        fprintf(file, "Adresa: %s\n", stiva[i].adresa);
        fprintf(file, "Telefonul: %s\n", stiva[i].telefonul);
        fprintf(file, "Numarul de sali: %d\n", stiva[i].numarSali);
        fprintf(file, "Numarul de carti: %d\n", stiva[i].numarCarti);
        fprintf(file, "\n");
    }
    
    fclose(file);
}

void cautareMaximal(struct Biblioteca* stiva, int numarElemente) {
    int maxCarti = 0;
    int pozitieMax = -1;
    for (int i = 0; i < numarElemente; i++) {
        if (stiva[i].numarCarti > maxCarti) {
            maxCarti = stiva[i].numarCarti;
            pozitieMax = i;
        }
    }

    if (pozitieMax != -1) {
        printf("Elementul cu cele mai multe carti:\n");
        printf("Denumirea: %s\n", stiva[pozitieMax].denumirea);
        printf("Adresa: %s\n", stiva[pozitieMax].adresa);
        printf("Telefonul: %s\n", stiva[pozitieMax].telefonul);
        printf("Numarul de sali: %d\n", stiva[pozitieMax].numarSali);
        printf("Numarul de carti: %d\n", stiva[pozitieMax].numarCarti);
    } else {
        printf("Nu exista elemente in stiva.\n");
    }
}

void copiereStivaInQueue(struct Biblioteca* stiva, int numarElemente, struct Biblioteca* queue, int* rear) {
    for (int i = 0; i < numarElemente; i++) {
        queue[*rear] = stiva[i];
        (*rear)++;
    }
}

void afisareQueue(struct Biblioteca* queue, int rear, const char* fisier) {
    FILE* file = fopen(fisier, "w");
    if (file == NULL) {
        printf("Nu s-a putut deschide fisierul.\n");
        return;
    }
    
    for (int i = 0; i < rear; i++) {
        fprintf(file, "Elementul %d:\n", i + 1);
        fprintf(file, "Denumirea: %s\n", queue[i].denumirea);
        fprintf(file, "Adresa: %s\n", queue[i].adresa);
        fprintf(file, "Telefonul: %s\n", queue[i].telefonul);
        fprintf(file, "Numarul de sali: %d\n", queue[i].numarSali);
        fprintf(file, "Numarul de carti: %d\n", queue[i].numarCarti);
        fprintf(file, "\n");
    }
    
    fclose(file);
}

int determinaLungimeStiva(int numarElemente) {
    return numarElemente;
}

void modificareElement(struct Biblioteca* stiva, int numarElemente) {
    int pozitie;
    printf("Introduceti pozitia elementului pe care doriti sa il modificati: ");
    scanf("%d", &pozitie);
    getchar();

    if (pozitie < 1 || pozitie > numarElemente) {
        printf("Pozitie invalida.\n");
        return;
    }

    struct Biblioteca* element = &stiva[pozitie - 1];

    printf("Introduceti noile valori pentru elementul %d:\n", pozitie);
    printf("Denumirea: ");
    fgets(element->denumirea, 50, stdin);
    element->denumirea[strcspn(element->denumirea, "\n")] = '\0';

    printf("Adresa: ");
        fgets(element->adresa, 100, stdin);
    element->adresa[strcspn(element->adresa, "\n")] = '\0';

    printf("Telefonul: ");
    fgets(element->telefonul, 20, stdin);
    element->telefonul[strcspn(element->telefonul, "\n")] = '\0';

    printf("Numarul de sali: ");
    scanf("%d", &element->numarSali);
    getchar();

    printf("Numarul de carti: ");
    scanf("%d", &element->numarCarti);
    getchar();

    printf("Elementul %d a fost modificat.\n", pozitie);
}

void adaugareLaSfarsit(struct Biblioteca* stiva, int numarElemente, const char* fisier) {
    FILE* file = fopen(fisier, "a");
    if (file == NULL) {
        printf("Nu s-a putut deschide fisierul.\n");
        return;
    }
    
    fprintf(file, "Elementul %d:\n", numarElemente + 1);
    fprintf(file, "Denumirea: %s\n", stiva[numarElemente - 1].denumirea);
    fprintf(file, "Adresa: %s\n", stiva[numarElemente - 1].adresa);
    fprintf(file, "Telefonul: %s\n", stiva[numarElemente - 1].telefonul);
    fprintf(file, "Numarul de sali: %d\n", stiva[numarElemente - 1].numarSali);
    fprintf(file, "Numarul de carti: %d\n", stiva[numarElemente - 1].numarCarti);
    fprintf(file, "\n");
    
    fclose(file);
}

void eliberareMemorieStiva(struct Biblioteca* stiva) {
    free(stiva);
}

void eliberareMemorieQueue(struct Biblioteca* queue) {
    free(queue);
}

int main() {
    struct Biblioteca* stiva = NULL;
    struct Biblioteca* queue = NULL;
    int numarElemente = 0;
    int rear = 0;
    int option;

    do {
        printf("Meniu:\n");
        printf("1. Crearea unei stive dinamice\n");
        printf("2. Citirea datelor referitoare la elementele stivei de la tastatura\n");
        printf("3. Afisarea datelor stivei intr-un fisier stiva.txt/stiva.bin\n");
        printf("4. Cautarea elementului maximal din stiva dupa un camp numeric\n");
        printf("5. Copierea datelor din stiva intr-un sir in asteptare (queue)\n");
        printf("6. Afisarea datelor sirului in asteptare intr-un fisier queue.txt/queue.bin\n");
        printf("7. Determinarea lungimii stivei (numarul de elemente)\n");
        printf("8. Modificarea campurilor unui element din stiva\n");
        printf("9. Afisarea (Adaugarea) datelor modificate ale elementului din stiva la sfarsitul fisierului stiva.txt/stiva.bin\n");
        printf("10. Eliberarea memoriei alocate pentru stiva\n");
        printf("11. Eliberarea memoriei alocate pentru Queue\n");
               printf("0. Iesire din program\n");
        printf("Introduceti optiunea dorita: ");
        scanf("%d", &option);
        getchar(); // pentru a consuma caracterul newline ('\n') lăsat în buffer de scanf

        switch (option) {
            case 1:
                creareStiva(&stiva);
                break;
            case 2:
                citireDate(stiva, &numarElemente);
                break;
            case 3:
                afisareStiva(stiva, numarElemente, "stiva.txt");
                break;
            case 4:
                cautareMaximal(stiva, numarElemente);
                break;
            case 5:
                creareStiva(&queue);
                copiereStivaInQueue(stiva, numarElemente, queue, &rear);
                break;
            case 6:
                afisareQueue(queue, rear, "queue.txt");
                break;
            case 7:
                printf("Lungimea stivei: %d\n", determinaLungimeStiva(numarElemente));
                break;
            case 8:
                modificareElement(stiva, numarElemente);
                break;
            case 9:
                adaugareLaSfarsit(stiva, numarElemente, "stiva.txt");
                break;
            case 10:
                eliberareMemorieStiva(stiva);
                stiva = NULL;
                numarElemente = 0;
                break;
            case 11:
                eliberareMemorieQueue(queue);
                queue = NULL;
                rear = 0;
                break;
            case 0:
                printf("Programul s-a terminat.\n");
                break;
            default:
                printf("Optiune invalida.\n");
                break;
        }

        printf("\n");
    } while (option != 0);

    return 0;
}


