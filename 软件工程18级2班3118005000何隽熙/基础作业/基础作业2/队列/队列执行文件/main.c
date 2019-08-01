#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct node                              /*节点*/
{
    int num;
    struct node* next;
}Node,*pNode;

typedef struct queue                             /*队列结构*/
{
    pNode front;
    pNode rear;
}LinkQueue,*pQueue;


LinkQueue* Queueinit(LinkQueue *q);
LinkQueue* Queuein(LinkQueue *q);
void Queueout(LinkQueue *q);
void Queueclear(LinkQueue *q);
void Queuedestroy(LinkQueue *q);
void Queuelength(LinkQueue *q);


void main()
{
    LinkQueue q;
    int i;
    Queueinit(&q);
    printf("1-Queuein\t2-Queueout\n");
    printf("3-Queueclear\t4-Queuedestroy\n");
    printf("5-Queueleength\t6-exit\n");
    while(scanf("%d",&i)==1)
    {
        switch(i)
        {
            case 1:Queuein(&q);break;
            case 2:Queueout(&q);break;
            case 3:Queueclear(&q);break;
            case 4:Queuedestroy(&q);puts("bye!");return;
            case 5:Queuelength(&q);break;
            case 6:puts("bye!");return;
            default:puts("Input error !");i=1;
        }
        printf("1-Queuein\t2-Queueout\n");
        printf("3-Queueclear\t4-Queuedestroy\n");
        printf("5-Queuelength\t6-exit\n");
    }
}


LinkQueue* Queueinit(pQueue q)                   /*队列初始化*/
{
    q->front=q->rear=(pNode)malloc(sizeof(Node));
    q->front=q->rear=NULL;
    return q;
}

LinkQueue* Queuein(LinkQueue *q)                 /*插入队尾*/
{
    pNode p;
    int num;
    puts("Input your number:");
    while(scanf("%d",&num)==1)
    {
       p=(pNode)malloc(sizeof(Node));
       p->next=NULL;
       p->num=num;
       if(q->rear==NULL)
          q->front=q->rear=p;
       else
      {
          q->rear->next=p;
          q->rear=p;
      }
      puts("Input your number:");
    }
    return q;
}

void Queueout(LinkQueue *q)                      /*出队*/
{
   pNode p;
   if(q->front==NULL)
   {
       printf("The queue is empty!\n");
       return;
   }
   p=q->front;
   if(q->front==q->rear)
   {
       printf("The number is %d\n",p->num);
       q->front=q->rear=NULL;
       free(p);
   }
   else
   {
       printf("The number is %d\n",p->num);
       q->front=q->front->next;
       free(p);
   }
}

void Queueclear(LinkQueue *q)                   /*清空队列*/
{
    pNode p;
    if(q->rear==NULL)
        puts("You haven't put any number in it!");
    else
    {
        q->front=q->rear=NULL;
        puts("Your queue has been clear!");
    }
}

void Queuedestroy(LinkQueue *q)                 /*销毁队列*/
{
    pNode p=q->front;
    pNode r;
    if(p!=NULL)
    {
        r=p->next;
        while(r!=NULL)
        {
            free(p);
            p=r;
            r=p->next;
        }
    }
    free(p);
    free(q);
}

void Queuelength(LinkQueue *q)                  /*队列长度*/
{
    int a=1;
    pNode p;
    p=q->front;
    if(q->rear==NULL)
        a=0;
    else
    {
       while(p!=q->rear)
      {
        a++;
        p=p->next;
       }
    }
    printf("The queue length is %d\n",a);
}





