#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero_de_processos>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        printf("Por favor, forneça um número positivo maior que zero.\n");
        return 1;
    }

    printf("Criando %d processos...\n", n);

    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == -1) {
            // Erro ao criar o processo filho
            perror("Erro ao criar o processo filho");
            return 1;
        } else if (pid == 0) {
            // Código executado pelo processo filho
            printf("Processo filho %d criado, PID: %d, PID do pai: %d\n", i+1, getpid(), getppid());
            return 0; // O processo filho sai do loop
        } else {
            // Código executado pelo processo pai
            // Continua criando mais processos
        }
    }

    // Código executado somente pelo processo pai
    // Espera todos os filhos terminarem
    for (int i = 0; i < n; i++) {
        wait(NULL);
    }

    return 0;
}