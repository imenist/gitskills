#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Lnode
{
    int data;
    struct Lnode *next;                          /*����������Ҫǰ��ָ��*/
}Lnode,*LinkList;                                /*Lnode *==LinkList*/


LinkList Createlist();                           /*��������������ͷ*/
LinkList Checktail(LinkList h);                  /*h�Ǳ�ͷ,���ر�β*/
LinkList Insertlist(LinkList h,int i,int data);  /*h�Ǳ�ͷ,i�ǲ���λ��,data������*/
LinkList Deletelist(LinkList h,int i,int c);     /*h�Ǳ�ͷ,i��ɾ��λ��,c��������*/
void Searchlist(LinkList h,int a);               /*h�Ǳ�ͷ,a�ǲ���Ԫ��*/
void Updatelist(LinkList h,int i);               /*h�Ǳ�ͷ,i�Ǹ���λ��*/
LinkList Destroylist(LinkList h);                /*h�Ǳ�ͷ*/
void Showlistright(LinkList h);                  /*h�Ǳ�ͷ*/
int checklist(LinkList h);                       /*h�Ǳ�ͷ���������������*/



int main()
{
   LinkList h,b;
   h=NULL,b=NULL;
   int data,i=1,a,c=0;
   while(i)
   {
       printf("1-Createlist\t2-Insertlist\n");
       printf("3-Deletelist\t4-Searchlist\n");
       printf("5-Updatelist\t6-Destroylist\n");
       printf("7-Showlistright\t");
       printf("0-exit\n");
       scanf("%d",&i);
   switch(i)
   {
       case 1:h=Createlist();
              b=Checktail(h);
              Showlistright(h);
              c=checklist(h);
              break;
       case 2:t:printf("Input your insert place:\n");
              scanf("%d",&i);
              if(i>c+1||i==0)                           /*c+1��֤���Բ��뵽��β*/
              {
                  puts("input error!\nchoose again");
                  i=1;                                 /*ȷ�����Լ���ѭ��*/
                  goto t;                              /*������һ��*/
              }
              printf("Input your insert data:\n");
              scanf("%d",&data);
              h=Insertlist(h,i,data);                  /*���ر�ͷ*/
              b=Checktail(h);                          /*���ر�β*/
              Showlistright(h);
              c=checklist(h);                          /*���¼��������*/
              break;
       case 3:t1:printf("Input your delete place:\n");
              scanf("%d",&i);
              if(i>c||i==0)
              {
                  puts("input error!");
                  goto t1;                            /*������һ��*/
              }
              h=Deletelist(h,i,c);
              Showlistright(h);
              c=checklist(h);
              break;
       case 4:printf("Input your search data:\n");
              scanf("%d",&a);
              Searchlist(h,a);
              break;
       case 5:printf("Input your update place:\n");
              scanf("%d",&i);
              Updatelist(h,i);
              Showlistright(h);
              c=checklist(h);
              break;
       case 6:h=Destroylist(h);
              b=NULL;
              break;
       case 7:Showlistright(h);
              break;
       case 0:puts("bye!");
              return;
              break;
       default:puts("error!Input again!");
   }
   }
}


LinkList Createlist()
{
    int data;
    LinkList lhead=NULL;
    LinkList ltail,lnew;
    printf("Input your data\nThis is the first list\n");
    while(scanf("%d",&data)==1)
    {
        lnew=(LinkList)malloc(sizeof(Lnode));
        if(lhead==NULL)
            lhead=lnew;
        else
            ltail->next=lnew;
        lnew->data=data;
        lnew->next=NULL;
        ltail=lnew;
        printf("next:\n");
    }
    return lhead;
}


LinkList Checktail(LinkList h)
{
    LinkList p=h;
    while(p->next!=NULL)
       p=p->next;
    return p;
}



LinkList Insertlist(LinkList h,int i,int data)
{
    LinkList q,p,p1;
    int j=0;
    p=h;
    if(i>1)
    {
        while(j<i-2)
      {
        p=p->next;
        j++;
       }
       p1=p->next;
       q=(LinkList)malloc(sizeof(Lnode));
       q->data=data;
       q->next=p1;
       p->next=q;
       return h;
    }
    else
    {
       q=(LinkList)malloc(sizeof(Lnode));
       q->data=data;
       q->next=p;
       return q;
    }
}



LinkList Deletelist(LinkList h,int i,int c)
{
    LinkList p,p1;
    int j=0;
    p=h;
    if(i>1&&i!=c)
    {
        while(j<i-2)
      {
        p1=p1->next;
        j++;
      }
        p=p1->next;
        p1->next=p->next;
    }
    else if(i==1)
        h=p->next;
    else if(i==c)
    {
       while(j<i-2)
       {
           p=p->next;
           j++;
       }
       p1=p;
       p=p1->next;
       p1->next=NULL;
    }
    free(p);
    return h;
}



void Searchlist(LinkList h,int a)
{
    LinkList p;
    int i=1,flag=0;
    for(p=h;p!=NULL;p=p->next)
    {
        if(p->data==a)
        {
             flag=1;
             printf("In the %d list\n",i);
        }
        i++;
    }
    if(flag==0)
        puts("not find!");
}



void Updatelist(LinkList h,int i)
{
    LinkList p=h;
    int j=0;
    while(j<i-1)
    {
       p=p->next;
       j++;
    }
    printf("Input your new data:\n");
    scanf("%d",&p->data);
}



LinkList Destroylist(LinkList h)
{
    LinkList p=h;
    while(p!=NULL)
    {
        h=p->next;
        free(p);
        p=h;
    }
    h=NULL;
    printf("your list has been destroy!\n");
    return h;
}


void Showlistright(LinkList h)
{
    if(h==NULL)
        printf("This is a NULL list!\n");
    else
    {
        puts("The list is:");
        LinkList p;
        for(p=h;p!=NULL;p=p->next)
      {
            printf("%d\t",p->data);
      }
        printf("\n");
    }
}



int checklist(LinkList h)
{
    LinkList p=h;
    int i=0;
    while(p)
    {
        p=p->next;
        i++;
    }
    return i;
}




