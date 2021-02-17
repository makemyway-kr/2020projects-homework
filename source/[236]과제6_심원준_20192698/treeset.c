#include<stdio.h>
struct node//Ʈ���� ��� ����ü
{
    char value;
    int rank;
    struct node* parent;
};

struct node* find_root(struct node s)//��Ʈ ��带 ã�� �Լ�
{
    if (s.parent == &s)//��Ʈ����� ��� �ش� ����� �ּҰ� ��ȯ
    {
        return &s;
    }
    else
    {
        struct node* temp = &s;
        while (1)
        {
            if (temp->parent == temp) break;//��Ʈ���(��Ʈ����� ��Ʈ �����ʹ� �ڽ��� ����Ű�Ƿ�)ã��.
            else temp = temp->parent;
        }
        return temp;//��Ʈ ��带 ã�� ��ȯ
    }
}
void merge_set(struct node b, struct node t)//������ ��ġ�� �Լ�,(rank�� �̿��� Union)
{
    struct node* t1;
    t1 = find_root(b);
    struct node* t2;
    t2 = find_root(t);
    if (t1->rank > t2->rank)
    {
        t2->parent = t1;
    }
    else if (t1->rank == t2->rank)
    {
        t1->parent = t2;
        t2->rank += 1;//������ Ʈ���� ��Ʈ��� rank���� 1�ø�.
    }
    else
    {
        t1->parent = t2;
    }
}
int main()
{
    struct node t[9];
    t[0].value = 'a'; t[0].parent = &t[0]; t[0].rank = 1;
    t[1].value = 'b'; t[1].parent = &t[0]; t[1].rank = 0;
    t[2].value = 'c'; t[2].parent = &t[2]; t[2].rank = 0;
    t[3].value = 'd'; t[3].parent = &t[3]; t[3].rank = 1;
    t[4].value = 'e'; t[4].parent = &t[3]; t[4].rank = 0;
    t[5].value = 'f'; t[5].parent = &t[5]; t[5].rank = 1;
    t[6].value = 'g'; t[6].parent = &t[5]; t[6].rank = 0;
    t[7].value = 'h'; t[7].parent = &t[5]; t[7].rank = 0;
    t[8].value = 'i'; t[8].parent = &t[5]; t[8].rank = 0;
    

    printf("==�ʱ� Ʈ��==\n");
    for (int pr = 0; pr < 9; pr++)
    {
        printf("%c �� ��Ʈ���---> %c\n", t[pr].value, find_root(t[pr])->value); //���� ���� ���
    }
    merge_set(t[0], t[2]);//(a)�� Ʈ������ ��ħ
    merge_set(t[3], t[6]);//(b)�� Ʈ������ ��ħ
    printf("===a�� b�� Ʈ���� ���� ��ħ===\n");
    for (int pr2 = 0; pr2 < 9; pr2++)
    {
        printf("%c�� ��Ʈ��� ---> %c\n", t[pr2].value, find_root(t[pr2])->value); //��ģ �� ���� ���
    }
    merge_set(t[0], t[5]);//a �� b�� Ʈ���� ��ħ
    printf("====a�� b�� Ʈ���� ��ģ ���� ���===\n");
    for (int pr3 = 0; pr3 < 9; pr3++)
    {
        printf("%c�� ��Ʈ��� ---> %c\n", t[pr3].value, find_root(t[pr3])->value); //��ģ �� ���� ���
    }
}