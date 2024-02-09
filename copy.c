#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * Copie le contenu du fichier message.txt dans un fichier copie.txt
 */
int main() {
    chdir("..");    // Obligatoire si utilisation de Cmake (pour définir le bon working directory)
    int source_fd = open("message.txt", O_RDONLY);
    if(source_fd < 0) {
        printf("Une erreur est survenue lors de l'ouverture du fichier source.\n");
    } else {
        char source_buffer[670];
        int source_rsize = read(source_fd, source_buffer, 669);
        source_buffer[source_rsize] = '\0';

        int dest_fd = open("copie.txt", O_RDWR | O_CREAT | O_TRUNC);
        if(dest_fd < 0) {
            printf("Une erreur est survenue lors de l'ouverture du fichier destinataire.\n");
        } else {
            int dest_wsize = write(dest_fd, source_buffer, source_rsize);
            lseek(dest_fd, 0, SEEK_SET);
            if(dest_wsize > 0) {
                // Bonus de lecture du fichier clone
                char dest_buffer[670];
                int dest_rsize = read(dest_fd, dest_buffer, dest_wsize);
                if(dest_rsize < 0) {
                    printf("Une erreur est survenue lors de la lecture du fichier clone.\n");
                } else {
                    write(1, dest_buffer, dest_rsize);
                }
            } else {
                printf("Une erreur est survenue lors de l'écriture du fichier clone.\n");
            }
        }
    }
}