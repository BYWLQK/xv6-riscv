#include"kernel/types.h"
#include"kernel/stat.h"
#include"user/user.h"

#define BUF_SIZE 16

int main(int argc, char *argv[]){

    int p[2];
    char buf[BUF_SIZE];

    pipe(p);
    int pid = fork();
    if(pid>0){
        int curPid = getpid();
        write(p[1],"ping",12);
        wait((int *)0);
        read(p[0],buf,BUF_SIZE);
        printf("Parent:My pid is <%d>,I receive %s\n",curPid,buf);
    }
    else{
        int curPid = getpid();
        read(p[0],buf,BUF_SIZE);
        printf("Child:My pid is <%d>, I receive %s\n",curPid,buf);
        write(p[1],"pong",12);
    }

    return 0;    
}