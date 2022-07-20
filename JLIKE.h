#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void makef();
char *readf();
void writef();
typedef char *String;
String _s;
typedef struct hnd
{
	char text[255];
	char content[5000];
	void (*makef)();
	char *(*readf)();
	void (*writef)();
}Handle;

Handle HANDLE()
{
	Handle this;
	this.makef = &makef;
	this.readf = &readf;
	this.writef = &writef;
	return this;
}

void makef(char *fnm)
{
	FILE *fp;
	fp = fopen(fnm,"w");
	fputs("-some text-",fp);
	fclose(fp);
}

char *readf(char *fnm)
{
	FILE *fp;
	char buff[355];
	char text[5000];
	fp = fopen(fnm,"r");
	while(!feof(fp))
	{
		if(!feof(fp))
		{
			fgets(buff,355,stdin);
			strcat(_s,buff);
		}
	}
	fclose(fp);
	return _s;
}

void writef(char *text,char *fnm)
{
	FILE *fp;
	fp = fopen(fnm,"a");
	fputs(text,fp);
	fclose(fp);
}
