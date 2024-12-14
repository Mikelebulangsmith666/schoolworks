#include <stdio.h> 
#include <stdlib.h>

#define MaxSize 50
typedef char ElemType;

typedef struct{
	ElemType data[MaxSize];
	int length;
} SqList ;

void test(){
	printf("yes\n");
}

void CreateList(SqList*& L,ElemType a[],int n){
	int i=0,k=0;
	//L=malloc(sizeof(SqList));
	L=(SqList*)malloc(sizeof(SqList));
	while (i<n){
		L->data[i]=a[i];
		k++;
		i++;
		
	}
	L->length=k;
}

void InitList(SqList*&L){
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
	
}

void DestroyList(SqList* &L){
	free(L);
}
bool ListEmpty(SqList*L){
	return(L->length==0);
	
}

int ListLength(SqList* L){
	
	return(L->length);
}//·µ»ØÖµ 
void DispList(SqList * L){
	for (int i=0;i<L-> length;i++)
		printf("%c ",L->data[i]);
	printf("\n");
}
bool GetElem(SqList * L, int i, ElemType &e){//3->char
	if(i<1 || i>L->length)
		return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList * L,ElemType e){

	int i=0;
	while (i< L-> length && L->data[i]!=e)
		i++;
	if (i>=L->length)
		return 0;
	else
		return i+1;
}
bool ListInsert(SqList *&L,int i, ElemType e){
	int j;
	if(i<1 || i>L->length+1)
		return false;
	i--;
	for(j=L->length; j>i ;j--)
	L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;
}
bool ListDelete(SqList* &L,int i, ElemType& e){//3->char
	int j;
	if (i< 1|| i>L-> length)
		return false;
	i--;
	e=L->data[i];
	for (j=i;j<L-> length-1;j++)
		L->data[j]=L-> data[j+1];
	L-> length--;
	return true;
}
