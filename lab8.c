#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Función para verificar si dos cadenas tienen las mismas letras (en cualquier orden)
bool mismaFrecuencia(char* s1, char* s2, int len) {
    int conteo[26] = {0};
    for (int i = 0; i < len; i++) {
        conteo[s1[i] - 'a']++;
        conteo[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (conteo[i] != 0) return false;
    }
    return true;
}

// Función recursiva que verifica si s2 es una versión revuelta de s1
bool esRevuelo(char* s1, char* s2, int len) {
    if (strncmp(s1, s2, len) == 0) return true;
    if (!mismaFrecuencia(s1, s2, len)) return false;

    for (int i = 1; i < len; i++) {
        // Caso 1: sin intercambio
        if (esRevuelo(s1, s2, i) && esRevuelo(s1 + i, s2 + i, len - i)) {
            return true;
        }
        // Caso 2: con intercambio
        if (esRevuelo(s1, s2 + len - i, i) && esRevuelo(s1 + i, s2, len - i)) {
            return true;
        }
    }
    return false;
}

// Función principal para verificar si dos cadenas pueden ser revueltas una de otra
bool isScramble(char* s1, char* s2) {
    int len = strlen(s1);
    if (len != strlen(s2)) return false;
    return esRevuelo(s1, s2, len);
}

int main() {
    char s1[] = "great";
    char s2[] = "rgeat";

    if (isScramble(s1, s2)) {
        printf("La cadena '%s' sí es revuelta de '%s'\n", s2, s1);
    } else {
        printf("La cadena '%s' NO es revuelta de '%s'\n", s2, s1);
    }

    return 0;
}
