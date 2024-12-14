#include "sqlist.cpp"


int main(){
	SqList *H;
	char a[]={'a','b','c','d','e'};
	CreateList(H , a , 5);
	printf("%d\n",ListLength(H));
	printf("%d\n",ListEmpty(H));
	DispList(H);
	printf("%d\n",LocateElem(H,'b'));
	ListInsert(H ,4,'f');
	DispList(H);
	char uu;
	
	ListDelete(H,3,uu);
	DispList(H);
	return 0;
}

