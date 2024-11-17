#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define   BUFFER   8

int main(){
    int fd[2]; pid_t pid;
    char buf[BUFFER];
    int holder;
    while(1){
        holder = read(1,buf,BUFFER);
        if (holder == 0){
            printf("holder 0");
            break;
        }
        else if(holder <0){
            printf("some problem");
            break;
        }
        else if(holder == BUFFER){
            if (buf[BUFFER-1] == '\n'){
                write(1,buf,holder);
                break;
            }
            write(1,buf,holder);
        }
        else{
            write(1,buf,holder);
            printf("less than BUFFER");
            break;
        }
    }
    printf("finished");
    return 0;
}
