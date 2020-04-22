#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include "printer.h"

int occurences_expect(const char * string,const char * substring,const char * expect)
{

	const int lenofexpect=strlen(expect);
	const int lenofstr=strlen(string);
	const int lenofsubstr=strlen(substring);
	char newbuff[lenofsubstr];
	char *newbuff1=malloc(sizeof(char*)*(lenofexpect+1));
	int count=0;
	for (int i = 0; i < lenofstr; i++)
	{
		for (int j = 0; j <= lenofsubstr; ++j)
		{
			newbuff[j]=string[i+j];	
		}

		if(!(memcmp(newbuff,substring,lenofsubstr)))
		{	

			if (lenofexpect)
			{
				for (int j = 0; j < lenofexpect ; ++j)
				{
					newbuff1[j]=string[i-(lenofexpect-j)];
					
				}
				if (strcmp(newbuff1,expect))
				{
					count++;
				}
				
			}
			else 
			{
				count++;	
			}
			
		}
	}
	free(newbuff1);

	return count;
}
int firstoccurencesfrom_expect(const char * string,const char * substring,const int from,const char * expect)
{

	const int lenofexpect=strlen(expect);
	const int lenofstr=strlen(string);
	const int lenofsubstr=strlen(substring);
	char* newbuff=malloc(sizeof(char*)*(lenofsubstr+1));
	newbuff[lenofsubstr]='\0';
	char* newbuff1=malloc(sizeof(char*)*(lenofexpect+1));
	newbuff[lenofsubstr]='\0';
	int index=0;
	for (int i = from; i < lenofstr; i++)
	{
		if (i<lenofstr-lenofsubstr+1)
		{
			for (int j = 0; j < lenofsubstr; ++j)
			{
				newbuff[j]=string[i+j];
			}
		}
		//printf("%s\n",newbuff );
		if(!(strcmp(newbuff,substring)))
		{		
			
			if (lenofexpect)
			{
				for (int j = 0; j < lenofexpect ; ++j)
				{
					newbuff1[j]=string[i-(lenofexpect-j)];
				}

				if ((strcmp(newbuff1,expect)))
				{

					index=i;
					break;	
				}
					
					
			}
			else 
			{
				index=i;
				break;		
					
			}
		}
		
	}

	free(newbuff);
	free(newbuff1);
	return index;
}

char * fmt(const int nb,const char *string,int *indexbuff,...)
{
	int indexies[nb];
	int lenofallrecipers[nb];
	int lenofrecipers=0,recvindexbuff;
	const int lenofstr=strlen(string);
	recipion_t formatargs[nb];
	for (int i = 0; i < nb; ++i)
	{
		recvindexbuff=*(indexbuff+i);
		memcpy(&indexies[i],&recvindexbuff,sizeof(*(indexbuff+i)));

	}

	va_list args;
	va_start(args,indexbuff);
	for (int i = 0; i < nb; ++i)
	{
		formatargs[i].buffer=va_arg(args,char*);
		lenofallrecipers[i]=strlen(formatargs[i].buffer);
		lenofrecipers+=strlen(formatargs[i].buffer);
	}
	va_end(args);
	const int finalsize=lenofstr+lenofrecipers-(nb*2);
	char *final;
	final=malloc(sizeof(char)*(finalsize+1));
	int count=0,offset=0;
	for (int i = 0; i < lenofstr; ++i)
	{
			
		if (i==indexies[count])
		{
			for (int j = 0; j < lenofallrecipers[count]; ++j)
			{
				final[i+offset+j]=formatargs[count].buffer[j];
			}
			offset=lenofallrecipers[count]-2;
			count++;
			i+=1;
		}
		else
		{		
			final[i+offset]=string[i];	
		}
	}
	offset=0;
	char *buffer=malloc(sizeof(char*)*escape+1);
	for (int i = 0; i < finalsize; ++i)
	{
		
		for (int j = 0; j <2 ; ++j)
		{
			buffer[j]=final[i+offset+j];
		}
		if (!(strcmp(buffer,"%{")))
		{
			offset++;
			final[i]=final[i+offset];
		}
		else
		{
			final[i]=final[i+offset];
		}
	}
	free(buffer);
	final[finalsize]='\0';
	
	return final;
}



		
