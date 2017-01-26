#include<stdio.h>  
#include<string.h>
char* highAdd(char *a,char *b,char *c){//a+b=c
	int i,n1,n2,n;char *d;
	n1=strlen(a);
	n2=strlen(b);
	if (n1<n2){
		d=a;
		a=b;
		b=d;n=n1;n1=n2;n2=n;
	}
//	printf("n1=%d,n2=%d\n",n1,n2);
//	printf("a=%s,b=%s\n",a,b);
	for(i=n1;i>=0;i--){
		*(c+i)='0';
	}
	for (i=n1;i>=n1-n2+1;i--){
		*(c+i)=*(c+i)+*(b+n2+i-n1-1)+*(a-1+n1+i-n1)-'0'-'0';
		while (*(c+i)>'9'){
			*(c+i-1)=*(c+i-1)+1;
			*(c+i)=*(c+i)-10;
		}
	//	printf("%c",*(c+i));
	}
//	printf("\n");
	for (i=n1-n2;i>=1;i--){
		*(c+i)=*(c+i)+*(a+i-1)-'0';
		while (*(c+i)>'9'){
			*(c+i-1)=*(c+i-1)+1;
			*(c+i)=*(c+i)-10;
		}
	}
	*(c+n1+1)='\0';i=0;
	while(*(c+i)=='0'){
		i++;
	}
	return (c+i);
	//printf("%d",n1);
} 
char* highDel(char *a,char* b,char *c){//c=a-b;
	int i,n1,n2;
	n1=strlen(a);
	n2=strlen(b);
	for(i=0;i<=n1-1;i++){
		*(c+i)='0'; 
	}
	for (i=n1-1;i>=n1-n2;i--){
		*(c+i)=*(a+i)-*(b+i-n1+n2)+'0';
		if (*(c+i)<'0'){
			*(a+i-1)=*(a+i-1)-1;
			*(c+i)=*(c+i)+10;
		}
	}
	for(i=n1-n2;i>=0;i--){
		if (i==n1-n2) continue;
		*(c+i)=*(c+i)+*(a+i)-'0';
		if (*(c+i)<'0'){
			*(a+i-1)=*(a+i-1)-1;
			*(c+i)=*(c+i)+10;
		}
	}
	*(c+n1)='\0';i=0;
	while(*(c+i)=='0'&&i<n1-1){
		i++;
	}
	return (c+i);
}
int compare (char* x,char* y){
	int i,n1,n2;
	n1=strlen(x);
	n2=strlen(y);
	if(n1<n2)return -1;
	else{
		if (n1>n2)return 1;
		else{
			for (i=0;i<n1;i++){
				if (*(x+i)<*(y+i))return -1;
				else{
					if(*(x+i)>*(y+i))return 1;
				}
			}
			if (i==n1-1) return 0;
		}
	}
} 
void formatPrint(char *x){
	int i=0,n;
	n=strlen(x);
	if(*(x)=='-'){
		printf("-");
		n--;x++;
	}
	while (*(x+i)!='\0'){
		printf("%c",*(x+i));
		if ((i-n+1)%3==0&&i<n-1){
			printf(",");
		}
		i++;
	}
}
int main(){
	char s1[100],s2[100],s3[100];
	int i,j,a,b;
	scanf("%s %s",s1,s2);
	if (s1[0]!='-'&&s2[0]!='-'){
		formatPrint(highAdd(s1,s2,s3));
	}
	else{
		if (s1[0]=='-'&&s2[0]=='-'){
			printf("-");
			formatPrint(highAdd(&s1[1],&s2[1],s3));
		}
		else{
			if(s1[0]=='-'){
				if (compare(&s1[1],s2)>0){
					printf("-");
					formatPrint(highDel(&s1[1],s2,s3));
				}
				else{
					formatPrint(highDel(s2,&s1[1],s3));
				}
			}
			else{
				if (compare(s1,&s2[1])>0){
					
					formatPrint(highDel(s1,&s2[1],s3));
				}
				else{
					printf("-");
					formatPrint(highDel(&s2[1],s1,s3));
				}
			} 
		}
	}
	
	return 0;
} 
