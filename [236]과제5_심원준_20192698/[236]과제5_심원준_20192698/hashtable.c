#include<stdio.h>
#include <stdlib.h>
struct chain_node//체이닝 시 이용할 노드 구조체
{
	int value;
	struct chain_node* nextnode;
};
void put_data_linear(int data, int table[])//선형 조사 xmod13이용
{
	int index = data % 13;
	while (1)
	{
		if (table[index] == -1)break;
		else index += 1;//충돌이 발생함, index번호에 1씩 추가하며 빈 인덱스로 저장.
	}
	table[index] = data;
}
void put_data_qp(int data, int table[])//이차원 조사(quadratic probing)을 이용한 충돌 해결
{
	int i = 0;
	int index;
	while (1)
	{
		index= (data + (i * i)) % 13;//(x+i^2)mod 13의 식을 반복하여 계산하며 충돌 해결.
		if (table[index] == -1)break;
		else i++;//충돌 발생
	}
	table[index] = data;
}
void put_data_chain(int data, struct chain_node table[])//체이닝을 이용한 충돌해결
{
	int index = data % 13;
	if (table[index].value == -1)
	{
		struct chain_node* newnode=malloc(sizeof(struct chain_node));
		newnode->value = data;
		newnode->nextnode = NULL;
		table[index].nextnode = newnode;
		table[index].value = 1;//데이터가 들어갔음
		
		
	}
	else
	{
		struct chain_node* newnode = malloc(sizeof(struct chain_node));
		newnode->value = data;//해시 테이블에 체인을 이어 붙이는 작업
		newnode->nextnode = table[index].nextnode;
		table[index].nextnode = newnode;
		
		
	}
}
void make_ht(int size, int data[], int table[])//해쉬 테이블 제작 함수
{
	for (int i = 0; i< size; i++)
	{
		put_data_qp(data[i], table);//충돌 해결 방법에 따른 함수 변경
		if (i > 3)//33부터 60까지 저장 결과 출력
		{
			printf("%d 저장 결과\n", data[i]);
			for (int j = 0; j < 13; j++)
			{
				if (table[j] == -1)printf("인덱스 %d : EMPTY\n", j);//비어있으면(-1) EMPTY출력
				else printf("인덱스 %d : %d\n",j, table[j]);
			}
			printf("---------------\n");
		}
	}
	
}
void make_ht_chain(int size, int data[], struct chain_node table[])//체이닝을 이용한 해쉬테이블 제작 함수
{
	printf("체이닝을 이용한 결과\n");
	for (int i = 0; i < size; i++)
	{
		put_data_chain(data[i], table);//체이닝을 이용한 원소 저장
		if (i > 3)//33부터 60까지 저장 결과 출력
		{
			printf("%d 저장 결과\n", data[i]);
			for (int j = 0; j < 13; j++)
			{
				if (table[j].value == -1)
				{
					printf("인덱스 %d : EMPTY\n", j);
				}
				else
				{
					struct chain_node* temp = table[j].nextnode;
					printf("인덱스 %d : | ", j);
					while (temp != NULL)
					{
						printf("%d | ",temp->value);
						temp = temp->nextnode;
					}
					free(temp);
					printf("\n");
				}
			}
			printf("----------------------\n");
		}
	}
}

int main()//선형 조사, 이차원 조사를 이용하는 main함수(공통 이용)
{
	int A[8] = { 10,20,30,40,33,46,50,60 };//저장할 데이터
	int table[13];
	for (int i = 0; i < 13; i++)
	{
		table[i] = -1;
	}
	make_ht(sizeof(A) / sizeof(int), A, table);
	
}


/*사용 시 주석 해제
int main()//체이닝을 이용한 해쉬테이블 제작 main 함수
{
	int A[8] = { 10,20,30,40,33,46,50,60 };//저장할 데이터
	struct chain_node table[13];
	for (int i = 0; i < 13; i++)
	{
		table[i].value = -1;
		table[i].nextnode = NULL;
		
	}
	make_ht_chain(8, A, table);
}
*/