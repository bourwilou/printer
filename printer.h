#ifndef PRINTER_H_
#define PRINTER_H_
//c11 generic
#include <stdio.h>
#define f(x) _Generic((x), \
    char: "%c", \
    signed char: "%hhd", \
    unsigned char: "%hhu", \
    signed short: "%hd", \
    unsigned short: "%hu", \
    signed int: "%d", \
    unsigned int: "%u", \
    long int: "%ld", \
    unsigned long int: "%lu", \
    long long int: "%lld", \
    unsigned long long int: "%llu", \
    float: "%f", \
    double: "%f", \
    long double: "%Lf", \
    char *: "%s", \
    void *: "%p")
typedef struct recipion
{
	char * buffer;
}recipion_t;
#define escape 2
//find occurences with expectation before if not passe simple empty string "" 
int occurences_expect(const char * string,const char * substring,const char * expect);
//find occurences first occurence from index and expectation before if not passe simple empty string "" 
int firstoccurencesfrom_expect(const char * string,const char * substring,const int from,const char * expect);
//format final string
char * fmt(const int nb,const char *string,int *buff,...);
//make buffer of all indexies should be used with occurences expect
#define mkbfindexies(buffer,format,sub,expect) 			                                      \
			for (int i = 0; i < occurences_expect(format,sub,expect); ++i) {			      \
				if (!i){buffer[i]=firstoccurencesfrom_expect(format,sub,0,expect);}			  \
				else {buffer[i]=firstoccurencesfrom_expect(format,sub,buffer[i-1]+1,expect); }}

#define p0(str,ndx,...) printf(str);
#define p1(str,ndx,p) printf(fmt(1,str,ndx,f(p)),p);
#define p2(str,ndx,p,p1) printf(fmt(2,str,ndx,f(p),f(p1)),p,p1);
#define p3(str,ndx,p,p1,p2) printf(fmt(3,str,ndx,f(p),f(p1),f(p2)),p,p1,p2);
#define p4(str,ndx,p,p1,p2,p3) printf(fmt(4,str,ndx,f(p),f(p1),f(p2),f(p3)),p,p1,p2,p3);				
#define p5(str,ndx,p,p1,p2,p3,p4) printf(fmt(5,str,ndx,f(p),f(p1),f(p2),f(p3),f(p4))p,p1,p2,p3,p4);
#define p6(str,ndx,p,p1,p2,p3,p4,p5) printf(fmt(6,str,ndx,f(p),f(p1),f(p2),f(p3),f(p4),f(p5)),p,p1,p2,p3,p4,p5);
#define p7(str,ndx,p,p1,p2,p3,p4,p5,p6) printf(fmt(7,str,ndx,f(p),f(p1),f(p2),f(p3),f(p4),f(p5),f(p6)),p,p1,p2,p3,p4,p5,p6);
#define p8(str,ndx,p,p1,p2,p3,p4,p5,p6,p7) printf(fmt(8,str,ndx,f(p),f(p1),f(p2),f(p3),f(p4),f(p5),f(p6),f(p7)),p,p1,p2,p3,p4,p5,p6,p7);


#define conc(i,str,indexies,...) p##i(str,indexies,__VA_ARGS__)


#define print(d,l,...){ int hmn=occurences_expect(l,"{}","%");                  \
	int buffer[hmn];															\
	mkbfindexies(buffer,l,"{}","%")												\
	conc(d,l,buffer,__VA_ARGS__)}

#endif