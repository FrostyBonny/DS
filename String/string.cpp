
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
typedef struct
{
	char *str;
	int length;
}HeapString;
 
void InitString(HeapString *S);//串的初始化操作  
void StrAssign(HeapString *S, char cstr[]);//串的赋值操作  
int StrEmpty(HeapString *S);//判断串是否为空  
int StrLength(HeapString *S);//求串的长度操作  
void StrCopy(HeapString *S, HeapString *T);//串的复制操作  
int StrCompare(HeapString *S, HeapString *T);//串的比较操作  
int StrInsert(HeapString *S, int pos, HeapString *T);//串的插入操作  
int StrDelete(HeapString *S, int pos, int len);//串的删除操作  
int StrConcat(HeapString *S, HeapString *T);//串的连接操作  
int SubString(HeapString *Sub, HeapString *S, int poos, int len);//截取子串操作  
int StrReplace(HeapString *S, HeapString *T, HeapString *V);//串的替换操作  
int StrIndex(HeapString *S, int pos, HeapString *T);//串的定位操作  
void StrClear(HeapString *S);//清空串操作  
void StrDestory(HeapString *S);//摧毁串操作  
void StrPrint(HeapString *S);//串的输出声明  
 
 
/*串的初始化*/
void InitString(HeapString *S)
{
	S->length = 0;
	S->str = '\0';   /*将串的值置为空*/
}
 
/*串的赋值操作*/
void StrAssign(HeapString *S, char cstr[])
{
	int i = 0,len;
	if (S->str)
		free(S->str);
	for (i = 0; cstr[i] != '\0'; i++);/*注意分号，这里空循环求cstr字符串的长度*/
	len = i;
	if (!i)
	{
		S->str = '\0';
		S->length = 0;
	}
	else
	{
		S->str = (char *)malloc(len*sizeof(char));
		if (!S->str)
			exit(-1);
		for (i = 0; i < len; i++)
			S->str[i] = cstr[i]; /*将字符串cstr的内容赋值给串S*/
		S->length = len;
	}
}
 
/*判断串是否为空*/
int StrEmpty(HeapString *S)
{
	if (S->length == 0)
		return 1;
	else
		return 0;
}
 
/*求串的长度*/
int StrLength(HeapString *S)
{
	return S->length;
}
 
/*串的复制操作*/
void StrCopy(HeapString *S, HeapString *T)
{
	int i;
	S->str = (char*)malloc(T->length*sizeof(char));
	if (!S->str)
		exit(-1);
	for (i = 0; i < T->length; i++)
		S->str[i] = T->str[i];
	S->length = T->length;
}
 
/*串的比较操作*/
int StrCompare(HeapString *S, HeapString *T)
{
	int i;
	for (i = 0; i < S->length&&i < T->length; i++)
	if (S->str[i] != T->str[i])
		return (S->str[i] - T->str[i]);
	return (S->length - T->length);
}
 
/*串的插入操作*/
int StrInsert(HeapString *S, int pos, HeapString *T)
{
	int i;
	if (pos<0 || pos - 1 > S->length)
	{
		printf("插入的位置不对！\n");
		return 0;
	}
	S->str = (char*)realloc(S->str,(S->length+T->length)*sizeof(char));
	if (!S->str)
	{
		printf("分配内存失败！");
		exit(-1);
	}
	
		for (i = S->length - 1; i >= pos -1; i--)
			/*将串S中第pos个位置的字符往后移动T->length个位置*/
			S->str[i + T->length] = S->str[i];
		for (i = 0; i < T->length; i++)
			S->str[pos + i - 1] = T->str[i];
		S->length = S->length + T->length;
		return 1;
 
 
}
/*串的删除操作*/
int StrDelete(HeapString *S, int pos, int len)
{
	int i;
	char *p;
	if (pos<0 || len<0 || pos + len - 1 > S->length)
	{
		printf("删除的位置不正确，参数len不合法！\n");
		return 0;
	}
	p = (char *)malloc(S->length - len);/*p指向动态分配的内存单元*/
	if (!p)
		exit(-1);
	for (i = 0; i < pos - 1; i++)/*将串第pos位置之前的字符复制到p中*/
		p[i] = S->str[i];
	for (i = pos - 1; i <= S->length - len; i++)
		/*将串第pos+len位置以后的字符复制到p*/
		p[i] = S->str[i + len];
	  S->length = S->length - len;
	  free(S->str);   /*释放原来的串S的内存空间*/
	  S->str = p;     /*将串的str指向p字符*/
		return 1;
 
}
 
/*串的连接操作*/
int StrConcat(HeapString *S, HeapString *T)
{
	int i;
	S->str = (char*)realloc(S->str, (S->length + T->length)*sizeof(char));
	/*重新分配内存空间，使串的长度为S和T的长度和，S中原来的内容不变*/
	if (!S->str)
	{
		printf("分配内存失败！");
		exit(-1);
	}
	else
	{
		for (i = S->length; i < S->length + T->length; i++)
			S->str[i] = T->str[i - S->length];
		S->length = S->length + T->length;
	}
	return 1;
}
 
/*截取子串操作*/
int SubString(HeapString *Sub, HeapString *S, int pos, int len)
{
	int i;
	if (Sub->str)
		free(Sub->str);
	if (pos<0 || len<0 || pos + len - 1>S->length)
	{
		printf("参数len和pos不合法！\n");
		return 0;
	}
	else
	{
		Sub->str = (char*)malloc(len*sizeof(char));
		if (!Sub->str)
		{
			printf("分配内存失败！");
			exit(-1);
		}
		for (i = 0; i < len; i++)    /*将串S的第pos个位置长度为len的字符赋值给Sub*/
			Sub->str[i] = S->str[i + pos - 1];
		Sub->length = len;
		return 1;
	}
}
 
/*串的替换操作*/
int StrReplace(HeapString *S, HeapString *T, HeapString *V)
{
	int i = 0;
	int flag;
	if (StrEmpty(T))
		return 0;
	do
	{
		i = StrIndex(S, i, T);
		if (i)
		{
			StrDelete(S, i, StrLength(T));
			flag = StrInsert(S, i, V);
			if (!flag)
				return 0;
			i += StrLength(V);
		}
	} while (i);
	return 1;
}
 
/*串的定位操作*/
int StrIndex(HeapString *S, int pos, HeapString *T)
{
	int i, j;
	if (StrEmpty(T))
		return 0;
	i = pos;
	j = 0;
	while (i < S->length  &&  j < T->length)
	{
		if (S->str[i-1] == T->str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= T->length)
		return (i - j + 1);
	else
		return -1;
}
 
/*清空串的操作*/
void StrClear(HeapString *S)
{
	if (S->str)
		free(S->str);
	S->str = '\0';
	S->length = 0;
}
 
/*串的销毁*/
void StrDestory(HeapString *S)
{
	if (S->str)
		free(S->str);
}
/*串的输出*/
void StrPrint(HeapString *S)
{
	int i;
	for (i = 0; i < S->length; i++)
	{
		printf("%c", S->str[i]);
	}
	printf("\n");
}
void main()
{
	HeapString S1, S2, Sub;
	char ch[50];
 
	InitString(&S1); 
	InitString(&S2); 
	InitString(&Sub);
 
	printf("请输入第一个字符串：");
	gets(ch);
	StrAssign(&S1, ch);
	printf("经过复制操作后的串S1：");
		StrPrint(&S1);
 
	printf("请输入第二个字符串：");
	gets(ch);
	StrAssign(&S2, ch);
	printf("经过复制操作后的串S2：");
		StrPrint(&S2);
 
	printf("把串S2连接在串S1的末尾，连接后S1：");
	StrConcat(&S1, &S2);
		StrPrint(&S1);
 
	printf("经过复制操作后的串Sub：");
	StrAssign(&Sub, "everyone ");
		StrPrint(&Sub);
 
	printf("将串S2插入到S1的第一位置：");
	StrInsert(&S1, 1, &Sub);
	StrPrint(&S1);
 
	printf("把串S1的第一个位置之后的八个元素删除：");
	StrDelete(&S1, 1, 8);
		StrPrint(&S1);
 
   printf("将串Sub赋值为America:");
   StrAssign(&Sub, "Amercia");
   printf("将串S1中的串S2用Sub取代：\n");	
   StrReplace(&S1, &S2, &Sub);
		StrPrint(&S1);
 
 
	StrDestory(&S1);
	StrDestory(&S2);
	StrDestory(&Sub);
}


