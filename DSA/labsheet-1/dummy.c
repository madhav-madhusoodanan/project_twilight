#include<stdio.h>
typedef int array[3];

int main(){
	array arrayList;
	
	arrayList[0] = 1;
	arrayList[1] = 2;
	arrayList[2] = 3;
	
	printf("%d %d %d", arrayList[0], arrayList[1], arrayList[2]);
	
	return 0;
}
