#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

char ** argumentbis(char * cmd)
{
    char *argvbis[100];
    char *argexc [100]];
    char *cmdbuff [100];
    strcpy(cmdbuff, cmd);
    int i = 0;
    argvbis[i] = strtok(cmdbuff, ";");


    while (argvbis[i] != NULL && i < 254) {
        i++;
        argvbis[i] = strtok(NULL, " ");
    }

    int k=0;



    while (argvbis[k]!=NULL){

    i=0;
    argexc[i] = strtok(argvbis[k], " ");

    while (argexc[i] != NULL ) {
        i++;
        argexc[i]=strtok(NULL," ");

    }
    k++;

    executer(argexc);



    }

    return 0;

}

void executer(char*argv[])
{
    pid_t pid = fork();
    switch (pid){

    case -1: perror("Erreur de pid");

    case 0:
        execvp(argv[0],argv);
        perror("Erreur de excv");

    default:
           wait(NULL);

    }

}

int main(int agrc,char *argcv[])
{
    char cmd[100];
    do{

        printf("Munishell>$:");

        gets(cmd);
        argumentbis(cmd);

    }while(strcmp(cmd,"quit")!=0);

    return 0;
}
