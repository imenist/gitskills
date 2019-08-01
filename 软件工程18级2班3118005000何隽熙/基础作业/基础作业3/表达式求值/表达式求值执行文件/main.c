#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct node1              /*������ջ�Ľڵ�*/
{
    double num;
    struct node1* pnext;
}Node1,*pNode1;

typedef struct stack1             /*������ջ�Ľṹ*/
{
    pNode1 top;
    pNode1 bottom;
}Stack1,*pStack1;

typedef struct node2              /*�����ջ�Ľڵ�*/
{
    char sym;
    struct node2* pnext;
}Node2,*pNode2;

typedef struct stack2             /*�����ջ�Ľṹ*/
{
    pNode2 top;
    pNode2 bottom;
}Stack2,*pStack2;

void Stackinit1(Stack1* s);
void Stackinit2(Stack2* s);
void Stackpush1(Stack1* s,double a);
void Stackpush2(Stack2* s,char b);
double Stackout1(Stack1* s);
char Stackout2(Stack2* s);
double Stackget1(Stack1* s);
char Stackget2(Stack2* s);
int Stackempty1(Stack1* s);
int Stackempty2(Stack2* s);
int Priority(char y);
double operate(double a,double b,char y);
void Inputexpression(char str[]);


void main()
{
    char str[100];
    char *q="q";
    puts("Input your expression:");
    while(scanf("%s",str)==1)
    {
       if(!strcmp(str,q))
        break;
       Inputexpression(str);
       puts("input q to quit.next:");
    }
    puts("bye!");
}



void Stackinit1(Stack1* s)
{
   s->top=(pNode1)malloc(sizeof(Node1));
   s->bottom=s->top;
   s->top->pnext=NULL;
}

void Stackinit2(Stack2* s)
{
   s->top=(pNode2)malloc(sizeof(Node2));
   s->bottom=s->top;
   s->top->pnext=NULL;
}

void Stackpush1(Stack1* s,double a)
{
      pNode1 pNew=(pNode1)malloc(sizeof(Node1));
      pNew->num=a;
      pNew->pnext=s->top;
      s->top=pNew;
}

void Stackpush2(Stack2* s,char b)
{
      pNode2 pNew=(pNode2)malloc(sizeof(Node2));
      pNew->sym=b;
      pNew->pnext=s->top;
      s->top=pNew;
}


double Stackout1(Stack1* s)          /*��ջ*/
{
     pNode1 pFree=NULL;
     double a;
     if(s->bottom==s->top)
        return 0;
     else
     {
         a=s->top->num;
         pFree=s->top;
         s->top=s->top->pnext;    /*ָ����һ���ڵ�*/
         free(pFree);
         return a;
     }
}

char Stackout2(Stack2* s)          /*��ջ*/
{
     pNode2 pFree=NULL;
     char a;
     if(s->bottom==s->top)
        return 0;
     else
     {
         a=s->top->sym;
         pFree=s->top;
         s->top=s->top->pnext;    /*ָ����һ���ڵ�*/
         free(pFree);
         return a;
     }
}


double Stackget1(Stack1* s)            /*��ȡջ��Ԫ��*/
{
    double a;
    if(s->top==s->bottom)
        return 0;
    else
    {
        a=s->top->num;
        return a;
    }
}

char Stackget2(Stack2* s)            /*��ȡջ��Ԫ��*/
{
    char a;
    if(s->top==s->bottom)
        return 0;
    else
    {
        a=s->top->sym;
        return a;
    }
}

int Stackempty1(Stack1* s)
{
    if(s->top==s->bottom)
        return 0;
    else
        return 1;
}

int Stackempty2(Stack2* s)
{
    if(s->top==s->bottom)
        return 0;
    else
        return 1;
}

int Priority(char y)
{
    int a;
    switch(y)
    {
       case '+':
       case '-':a=1;break;
       case '*':
       case '/':a=2;break;
    }
    return a;
}

double operate(double a,double b,char y)
{
    double c=0;
    switch (y)
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
    case '*':
        c=a*b;
        break;
    case '/':
        if(b==0)
        {
            puts("The denominator is 0!");
            return 0;
        }
        else
            c=a/b;
        break;
    default:
        puts("Input error !");
        break;
    }
    return c;
}

void Inputexpression(char str[])
{
    Stack1 s,s1;
    Stack2 t,t1;
    Stackinit1(&s);
    Stackinit2(&t);
    Stackinit1(&s1);
    Stackinit2(&t1);
    int i,j;
    double a=0,b=0,c=0,f=0;
    char d[100];
    char y=0;
    for(i=0;str[i]!='\0';i++)
    {
        switch(str[i])
        {
              case '+':
              case '-':
                if(!Stackempty2(&t))
                    Stackpush2(&t,str[i]);
                else
                {
                    a=Stackout1(&s);
                    b=Stackout1(&s);
                    y=Stackout2(&t);
                    c=operate(b,a,y);               //�ȳ�ջ��λ�������֮������Ҫ�Ȱ�b���������
                    Stackpush1(&s,c);
                    Stackpush2(&t,str[i]);
                }
                break;
              case '*':
              case '/':
                if(!Stackempty2(&t)||(Priority(str[i])>Priority(Stackget2(&t))))   //��ǰ����������ȼ���Ļ���Ҫ���㣬������ջ����������
                    Stackpush2(&t,str[i]);
                else
                {
                    a=Stackout1(&s);
                    b=Stackout1(&s);
                    y=Stackout2(&t);
                    c=operate(b,a,y);                 //�ȳ�ջ��λ�������֮������Ҫ�Ȱ�b���������
                    Stackpush1(&s,c);
                    Stackpush2(&t,str[i]);
                }
                break;
              default:
                j=0;
                while(str[i]>='0'&&str[i]<='9')
                {
                    d[j++]=str[i];
                    i++;
                }
                d[j]='\0';
                i--;
                f=atof(d);
                Stackpush1(&s,f);
                break;
        }
    }
    if(Priority(Stackget2(&t))==2)
    {
        a=Stackout1(&s);
        b=Stackout1(&s);
        y=Stackout2(&t);
        c=operate(b,a,y);                    //��ʱ�ȳ�ջ����Ȼ�������ǰ��������b��a
        Stackpush1(&s,c);
    }
    while(Stackempty2(&t))
    {
       while(Stackempty1(&s))
        Stackpush1(&s1,Stackout1(&s));
       Stackpush2(&t1,Stackout2(&t));
    }
    if(!Stackempty2(&t1))
        Stackpush1(&s1,Stackout1(&s));
    while(Stackempty2(&t1))
    {
       a=Stackout1(&s1);
       b=Stackout1(&s1);
       y=Stackout2(&t1);
       c=operate(a,b,y);
       Stackpush1(&s1,c);
    }
    printf("The answer is %f\n",Stackget1(&s1));
}



