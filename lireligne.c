#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * Lit une ligne du fichier correspondant au descripteur passé en argument jusqu'à lire un retour à la ligne ('\n') ou
 * avoir lu size caractères.
 *
 * @param fd descripteur de fichier ouvert en lecture
 * @param s buffer dans lequel les octets lus sont écrits
 * @param size nombre maximum d'octets à lire
 * @return le nombre d'octets effectivement lus
 */
int lireligne(int fd, char *s, int size) {
    int i = 0;
    if(fd < 0)
        return -1;
    char c;
    while (i < size && read(fd, &c, 1) > 0 && c != '\n')
        s[i++] = c;
    return i;
}

int main() {
    chdir("..");    // Obligatoire si utilisation de Cmake (pour définir le bon working directory)
    int fd = open("message.txt", O_RDONLY);
    char buffer[670];
    printf("%i\n", lireligne(fd, buffer, 100));
    printf("%s\n", buffer);
}