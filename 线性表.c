#define MAXSIZE 20
#define OK 1 
#define ERROR 0
typedef int status; 
typedef int ElemType;
typedef struct{
	ElemType data[MAXSIZE]; //线性表总长度 
	int length; //线性表当前长度 
} SqList; 
/*
i 为查找元素的位置 
*/
status GetElem(SqList L, int i, ElemType *e){
	if(L.length == 0 || i < 1 || i > L.length){
		return ERROR;
	}
	
	*e = L.data[i - 1]; 
}
status ListInsert(SqList *L, int i, ElemType e){
	int k;
	if(L->length == MAXSIZE){
		return ERROR;
	}
	if(i < 1 || i > L->length){
		return ERROR;
	}
	if(i <= L->length){
		for(k=L->length - 1;k >= i - 1;k--){
			L->data[k+1] = L->data[k];
		}
	}
	L->data[k+1] = e;
	L->length++;
	
	return OK;
}

status ListDelete(SqList *L, int i, ElemType *e){
	int k;
	if(L->length == 0){
		return ERROR;
	}
	if(i < 1 || i > L->length){
		return ERROR;
	}
	
	*e = L->data[i-1];
	
	if(i < L->length){
		for(k=i; k < L->length - 1; k++){
			L->data[k-1] = L->data[k];
		}
	}
	L->length--;
	
	return OK;
}

int main(){
	return 0;
} 
