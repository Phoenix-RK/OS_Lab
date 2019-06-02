//kiruthya
//interprocess communication
//message passing read
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct mesg_buff{
long msg_type;
     char msg_txt[100];
}message;
int main()
{
key_t key=ftok("progfile",65);
int msgid=msgget(key,0666|IPC_CREAT);
msgrcv(msgid,&message,sizeof(message),0);
printf("\nData read %s",message.msg_txt);
msgctl(msgid,IPC_RMID,NULL);
return 0;
}
