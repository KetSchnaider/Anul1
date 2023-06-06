#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void identifyPatterns(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Eroare la deschiderea fisierului.");
        return;
    }

    // Definim pattern-ul căutat
    const char* pattern = "cuvant_cheie";

    // Citim datele din fisier linie cu linie
    char line[100];
    int lineIndex = 1;
    while (fgets(line, sizeof(line), file)) {
        // Identificăm pattern-ul în fiecare linie
        char* position = strstr(line, pattern);
        if (position != NULL) {
            printf("Pattern identificat in linia %d: %s", lineIndex, line);
        }
        lineIndex++;
    }

    fclose(file);
}
int main() {
    const char* filename = "imobile.txt";
    identifyPatterns(filename);

    return 0;
}
