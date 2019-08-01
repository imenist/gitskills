#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Lnode
{
    int data;
    struct Lnode *pre;
    struct Lnode *next;
}Lnode,*LinkList;                                /*Lnode *==LinkList*/


LinkList Createlist();                           /*��������������ͷ*/
LinkList Checktail(LinkList h);                  /*h�Ǳ�ͷ,���ر�β*/
LinkList Insertlist(LinkList h,int i,int data);  /*h�Ǳ�ͷ,i�ǲ���λ��,data������*/
LinkList Deletelist(LinkList h,int i,int c);     /*h�Ǳ�ͷ,i��ɾ��λ��,c��������*/
void Searchlist(LinkList h,int a);               /*h�Ǳ�ͷ,a�ǲ���Ԫ��*/
void Updatelist(LinkList h,int i);               /*h�Ǳ�ͷ,i�Ǹ���λ��*/
LinkList Destroylist(LinkList h);                /*h�Ǳ�ͷ*/
void Showlistright(LinkList h);                  /*h�Ǳ�ͷ*/
void Showlistdown(LinkList h);                   /*h�Ǳ�ͷ*/
int checklist(LinkList h);                       /*h�Ǳ�ͷ���������������*/



void main()
{
   LinkList h,b;
   h=NULL,b=NULL;
   int data,i=1,a,c=0;
   while(i)
   {
       printf("1-Createlist\t2-Insertlist\n");
       printf("3-Deletelist\t4-Searchlist\n");
       printf("5-Updatelist\t6-Destroylist\n");
       printf("7-Showlistright\t8-Showlistdown\n");
       printf("0-exit\n");
       scanf("%d",&i);
   switch(i)
   {
       case 1:h=Createlist();
              b=Checktail(h);
              Showlistright(h);
              c=checklist(h);
              break;
       case 2:printf("Input your insert place:\n");
              scanf("%d",&i);
              printf("Input your insert data:\n");
              scanf("%d",&data);
              h=Insertlist(h,i,data);                  /*���ر�ͷ*/
              b=h->pre;                                /*���ر�β*/
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
       case 5:t2:printf("Input your update place:\n");
              scanf("%d",&i);
              if(i>c||i==0)
              {
                   puts("input error!\ninput again");
                   goto t2;
              }
              Updatelist(h,i);
              Showlistright(h);
              c=checklist(h);
              break;
       case 6:h=Destroylist(h);
              b=NULL;
              break;
       case 7:Showlistright(h);
              break;
       case 8:Showlistdown(h);
              break;
       case 0:puts("bye!");
              return;
       default:puts("error!Input again!");
   }
   }
}


LinkList Createlist()
{
    int data,i=1;
    LinkList lhead=NULL;
    LinkList ltail,lnew;
    printf("Input your data\nThis is the first list\n");
    while(scanf("%d",&data)==1)
    {
       if(lhead==NULL)
       {
           lhead=(LinkList)malloc(sizeof(Lnode));
           lhead->data=data;
           lhead->next=lhead;
           lhead->pre=lhead;
       }
       else
       {
           for(ltail=lhead;ltail->next!=lhead;ltail=ltail->next);    /*�ҵ�β�ڵ㣬λ��ͷ���ǰһ��*/
           lnew=(LinkList)malloc(sizeof(Lnode));
           lnew->data=data;
           lnew->next=lhead;
           lnew->pre=ltail;
           ltail->next=lnew;
           lhead->pre=lnew;
       }
       puts("next:");
    }
    return lhead;
}


LinkList Checktail(LinkList h)
{
    LinkList p=h;
    while(p->next!=h)
       p=p->next;
    return p;
}



LinkList Insertlist(LinkList h,int i,int data)
{
    LinkList q,p;
    int j=0;
    p=h;
    if(i==1)
    {
        q=(LinkList)malloc(sizeof(Lnode));
        q->data=data;
        q->pre=h->pre;
        q->next=h;
        h->pre->next=q;
        h->pre=q;
        return q;
    }
    else
    {
        while(j<i-1)
       {
          if(j!=0&&p==h)                                /*���������һȦ������ѭ���������ݷ������*/
            break;
          p=p->next;
          j++;
       }
       q=(LinkList)malloc(sizeof(Lnode));
       q->data=data;
       q->pre=p->pre;
       q->next=p;
       p->pre->next=q;
       p->pre=q;
       return h;
    }
}



LinkList Deletelist(LinkList h,int i,int c)
{
    LinkList p;
    int j=0;
    p=h;
    if(i==1)
    {
        p->pre->next=p->next;
        p->next->pre=p->pre;
        return p->next;
    }
    else
    {
        while(j<i-1)
       {
          if(j!=0&&p==h)
            break;
          p=p->next;
          j++;
       }
       p->pre->next=p->next;
       p->next->pre=p->pre;
       return h;
    }
}



void Searchlist(LinkList h,int a)
{
    LinkList p;
    int i=1,flag=0;
    for(p=h;p->next!=h;p=p->next)
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
    LinkList p=h,q;
    while(p->next!=h)
    {
        q=p->next;
        free(p);
        p=q;
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
        LinkList p=h;
        do
        {
            printf("%d\t",p->data);
            p=p->next;
        }while(p!=h);
        printf("\n");
    }
}


void Showlistdown(LinkList h)
{
    if(h==NULL)
        printf("This is a NULL list!\n");
    else
    {
        puts("The list is:");
        LinkList p=h->pre;
        do
        {
            printf("%d\t",p->data);
            p=p->pre;
        }while(p!=h->pre);
        printf("\n");
    }
}



int checklist(LinkList h)
{
    LinkList p=h;
    int i=1;
    while(p->next!=h)
    {
        p=p->next;
        i++;
    }
    return i;
}



