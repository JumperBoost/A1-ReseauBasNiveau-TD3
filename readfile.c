#include <stdio.h>
#include <fcntl.h>

/**
 * Ouvre le fichier message.txt du répertoire courant et affiche son contenu à l'écran.
 */
int main() {
    chdir("..");    // Obligatoire si utilisation de Cmake (pour définir le bon working directory)
    int fd = open("message.txt", O_RDONLY);
    if(fd < 0) {
        printf("Une erreur est survenue lors de la lecture du fichier.\n");
    } else {
        char buffer[670];
        int size = read(fd, buffer, 669);
        buffer[size] = '\0';
        //printf("%s", buffer);
        write(1, buffer, size);
    }
}
