//kiruthya
//interprocess communication
//message passing write
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_buffer{
	long msg_type;
	char msg_text[100];
}message;
int main()
{
key_t key=ftok("pgmfile",65);
int msgid=msgget(key,0666|IPC_CREAT);
message.msg_type=1;
printf("\nwriting data");
gets(message.msg_text);
msgsnd(msgid,&message,sizeof(message),0);
printf("\nmessage written %s",message.msg_text);

}
