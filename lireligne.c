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
    if(fd < 0)
        return -1;
    int old_size = lseek(fd, 0, SEEK_CUR);
    int read_size = read(fd, s, size);
    int i = 0;
    while (i < read_size && s[i] != '\n')
        i++;
    s[i] = '\0';
    printf("%i, %i\n", read_size, i);
    lseek(fd, old_size + i+2, SEEK_SET);
    return i;
}

int main() {
    chdir("..");    // Obligatoire si utilisation de Cmake (pour définir le bon working directory)
    int fd = open("message.txt", O_RDONLY);
    char buffer[4096];
    printf("%i\n", lireligne(fd, buffer, 4096));
    printf("%s\n", buffer);
    printf("%i\n", lireligne(fd, buffer, 4096));
    printf("%s\n", buffer);
    printf("%i\n", lireligne(fd, buffer, 4096));
    printf("%s\n", buffer);
    printf("%i\n", lireligne(fd, buffer, 4096));
    printf("%s\n", buffer);
}