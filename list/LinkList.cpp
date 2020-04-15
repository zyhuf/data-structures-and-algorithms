#include "LinkList.h"

//头插法建立链表
void CreateListHead(LinkList *&L, ElemType a[], int n)
{
    L = (LinkList *)malloc(sizeof(LinkList));
    L->next = NULL;
    LinkList *s;
    for (int i = 0; i < n; i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}
//尾插法建立链表
void CreateListTail(LinkList *&L, ElemType a[], int n)
{
    L = (LinkList *)malloc(sizeof(LinkList));
    LinkList *s, *r;
    r = L;

    for (int i = 0; i < n; i++)
    {
        s = (LinkList *)malloc(sizeof(LinkList));
        s->data = a[i];
        r->next = s;
        r = s;
    }

    r->next = NULL;
}

//释放链表
void DestroyList(LinkList *&L)
{
    LinkList *pre = L, *p = L->next;
    if (p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }

    free(pre);
}

//判断链表是否为空
bool ListEmpty(LinkList *L)
{
    return (L == NULL || L->next == NULL);
}

int ListLength(LinkList *L)
{
    int n = 0;
    LinkList *p = L;

    while (p != NULL)
    {
        n++;
        p = p->next;
    }

    return n;
}

bool ListInsert(LinkList *&L, int i, ElemType e)
{
    LinkList *p = L;
    int j = 0;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        LinkList *s = (LinkList *)malloc(sizeof(LinkList));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

bool ListDelete(LinkList *&L, int i, ElemType &e)
{
    LinkList *p = L;
    int j = 0;
    while (j < i - 1 && p != NULL)
    {
        j++;
        p = p->next;
    }

    if (p == NULL)
    {
        return false;
    }
    else
    {
        LinkList *q = p->next;
        if (q == NULL)
        {
            return false;
        }
        p->next = q->next;
        free(q);
        return true;
    }
}