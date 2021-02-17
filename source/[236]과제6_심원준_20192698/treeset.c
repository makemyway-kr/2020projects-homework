#include<stdio.h>
struct node//트리의 노드 구조체
{
    char value;
    int rank;
    struct node* parent;
};

struct node* find_root(struct node s)//루트 노드를 찾는 함수
{
    if (s.parent == &s)//루트노드의 경우 해당 노드의 주소값 반환
    {
        return &s;
    }
    else
    {
        struct node* temp = &s;
        while (1)
        {
            if (temp->parent == temp) break;//루트노드(루트노드의 루트 포인터는 자신을 가리키므로)찾음.
            else temp = temp->parent;
        }
        return temp;//루트 노드를 찾아 반환
    }
}
void merge_set(struct node b, struct node t)//집합을 합치는 함수,(rank를 이용한 Union)
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
        t2->rank += 1;//합쳐진 트리의 루트노드 rank값을 1올림.
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
    

    printf("==초기 트리==\n");
    for (int pr = 0; pr < 9; pr++)
    {
        printf("%c 의 루트노드---> %c\n", t[pr].value, find_root(t[pr])->value); //원래 상태 출력
    }
    merge_set(t[0], t[2]);//(a)의 트리들을 합침
    merge_set(t[3], t[6]);//(b)의 트리들을 합침
    printf("===a와 b의 트리를 각각 합침===\n");
    for (int pr2 = 0; pr2 < 9; pr2++)
    {
        printf("%c의 루트노드 ---> %c\n", t[pr2].value, find_root(t[pr2])->value); //합친 후 상태 출력
    }
    merge_set(t[0], t[5]);//a 와 b의 트리를 합침
    printf("====a와 b의 트리를 합친 최종 결과===\n");
    for (int pr3 = 0; pr3 < 9; pr3++)
    {
        printf("%c의 루트노드 ---> %c\n", t[pr3].value, find_root(t[pr3])->value); //합친 후 상태 출력
    }
}