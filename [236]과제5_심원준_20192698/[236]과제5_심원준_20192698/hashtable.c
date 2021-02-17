#include<stdio.h>
#include <stdlib.h>
struct chain_node//ü�̴� �� �̿��� ��� ����ü
{
	int value;
	struct chain_node* nextnode;
};
void put_data_linear(int data, int table[])//���� ���� xmod13�̿�
{
	int index = data % 13;
	while (1)
	{
		if (table[index] == -1)break;
		else index += 1;//�浹�� �߻���, index��ȣ�� 1�� �߰��ϸ� �� �ε����� ����.
	}
	table[index] = data;
}
void put_data_qp(int data, int table[])//������ ����(quadratic probing)�� �̿��� �浹 �ذ�
{
	int i = 0;
	int index;
	while (1)
	{
		index= (data + (i * i)) % 13;//(x+i^2)mod 13�� ���� �ݺ��Ͽ� ����ϸ� �浹 �ذ�.
		if (table[index] == -1)break;
		else i++;//�浹 �߻�
	}
	table[index] = data;
}
void put_data_chain(int data, struct chain_node table[])//ü�̴��� �̿��� �浹�ذ�
{
	int index = data % 13;
	if (table[index].value == -1)
	{
		struct chain_node* newnode=malloc(sizeof(struct chain_node));
		newnode->value = data;
		newnode->nextnode = NULL;
		table[index].nextnode = newnode;
		table[index].value = 1;//�����Ͱ� ����
		
		
	}
	else
	{
		struct chain_node* newnode = malloc(sizeof(struct chain_node));
		newnode->value = data;//�ؽ� ���̺� ü���� �̾� ���̴� �۾�
		newnode->nextnode = table[index].nextnode;
		table[index].nextnode = newnode;
		
		
	}
}
void make_ht(int size, int data[], int table[])//�ؽ� ���̺� ���� �Լ�
{
	for (int i = 0; i< size; i++)
	{
		put_data_qp(data[i], table);//�浹 �ذ� ����� ���� �Լ� ����
		if (i > 3)//33���� 60���� ���� ��� ���
		{
			printf("%d ���� ���\n", data[i]);
			for (int j = 0; j < 13; j++)
			{
				if (table[j] == -1)printf("�ε��� %d : EMPTY\n", j);//���������(-1) EMPTY���
				else printf("�ε��� %d : %d\n",j, table[j]);
			}
			printf("---------------\n");
		}
	}
	
}
void make_ht_chain(int size, int data[], struct chain_node table[])//ü�̴��� �̿��� �ؽ����̺� ���� �Լ�
{
	printf("ü�̴��� �̿��� ���\n");
	for (int i = 0; i < size; i++)
	{
		put_data_chain(data[i], table);//ü�̴��� �̿��� ���� ����
		if (i > 3)//33���� 60���� ���� ��� ���
		{
			printf("%d ���� ���\n", data[i]);
			for (int j = 0; j < 13; j++)
			{
				if (table[j].value == -1)
				{
					printf("�ε��� %d : EMPTY\n", j);
				}
				else
				{
					struct chain_node* temp = table[j].nextnode;
					printf("�ε��� %d : | ", j);
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

int main()//���� ����, ������ ���縦 �̿��ϴ� main�Լ�(���� �̿�)
{
	int A[8] = { 10,20,30,40,33,46,50,60 };//������ ������
	int table[13];
	for (int i = 0; i < 13; i++)
	{
		table[i] = -1;
	}
	make_ht(sizeof(A) / sizeof(int), A, table);
	
}


/*��� �� �ּ� ����
int main()//ü�̴��� �̿��� �ؽ����̺� ���� main �Լ�
{
	int A[8] = { 10,20,30,40,33,46,50,60 };//������ ������
	struct chain_node table[13];
	for (int i = 0; i < 13; i++)
	{
		table[i].value = -1;
		table[i].nextnode = NULL;
		
	}
	make_ht_chain(8, A, table);
}
*/