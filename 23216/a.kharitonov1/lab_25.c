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
    char mes1[10]= "\nholder 0\n", mes2[14]="\nsome problem\n", mes3[18]="\nless than BUFFER\n", mes4[10]="\nfinished\n";
    while(1){
        holder = read(1,buf,BUFFER);
        if (holder == 0){
            write(1,mes1,10);
            break;
        }
        else if(holder <0){
            write(1,mes2,14);
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
            write(1,mes3,18);
            break;
        }
    }
    write(1,mes4,10);
    return 0;
}
