#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdlib.h>

int count1=0;
int count2=0;
int count3=0;
struct student
{
    char name[1000];
    long num;
    int cla;
    char major[1000];
    char tel[100];
    int year;
    int birth;
    int dor;
    int qq;
};

struct curinformation
{
    int number;
    char name[100];
    int score;
    char tea[100];
    int time;
    int times;
    char place[100];
};

struct atten
{
    char name[100];
    long num;
    int cla;
    int curnum;
    char curname[100];
    int vio;
    int classtime;
    int time;
    char place[100];
};

struct student stuinfo[100];
struct atten attinfo[100];
struct curinformation curinfo[100];

void studentinfo();
void atteninfo();
void curreninfo();
void stuinfoput();
void stuinfodel();
void stuinfodel1();
void stuinfodel2();
void stuinfosea();
void stuinfosea1();
void stuinfosea2();
void attinfoput();
void attinfosea();
void attinfodel();
void infocount();
void Backupdate();
void attinfosea1();
void attinfosea2();
void attinfodel1();
void attinfodel2();
void infocount1();
void infocount2();
void infocount3();
void curinfoput();
void curinfosea();
void curinfosea1();
void curinfosea2();


void main()
{
    int choice=-1;
    while(choice!=0)
    {
        printf("\t\t\t\t\tѧ��������Ϣ����ϵͳ\n");
        printf("\t\t\t\t\t1-������Ϣ\n");
        printf("\t\t\t\t\t2-���ڵǼ���Ϣ\n");
        printf("\t\t\t\t\t3-�γ���Ϣ\n");
        printf("\t\t\t\t\t0-�˳�ϵͳ\n");
        printf("\t\t\t\t\tInput your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:studentinfo();break;
            case 2:atteninfo();break;
            case 3:curreninfo();break;
            case 0:puts("\t\t\t\t\tBYE!");break;
            default:choice=-1;puts("Input error,again");break;
        }
    }
}

void studentinfo()
{
    int choice=-1;
    while(choice!=0)
    {
       printf("\t\t\t\t\t1-������Ϣ��д\n");
       printf("\t\t\t\t\t2-������Ϣɾ��\n");
       printf("\t\t\t\t\t3-������Ϣ��ѯ\n");
       printf("\t\t\t\t\t0-����\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:stuinfoput();break;
           case 2:stuinfodel();break;
           case 3:stuinfosea();break;
           case 0:break;
           default:choice=-1;puts("Input error,again");break;
       }
    }
}

void atteninfo()
{
   int choice=-1;
    while(choice!=0)
    {
       printf("\t\t\t\t\t1-��Ϣ��д\n");
       printf("\t\t\t\t\t2-��Ϣ��ѯ\n");
       printf("\t\t\t\t\t3-��Ϣɾ��\n");
       printf("\t\t\t\t\t4-��Ϣ����\n");
       printf("\t\t\t\t\t5-����ͳ��\n");
       printf("\t\t\t\t\t0-����\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:attinfoput();break;
           case 2:attinfosea();break;
           case 3:attinfodel();break;
           case 4:Backupdate();break;
           case 5:infocount();break;
           case 0:break;
           default:choice=-1;puts("Input error,again");break;
       }
    }
}

void curreninfo()
{
    int choice=-1;
    while(choice!=0)
    {
       printf("\t\t\t\t\t1-��Ϣ��д\n");
       printf("\t\t\t\t\t2-��Ϣ��ѯ\n");
       printf("\t\t\t\t\t0-����\n");
       scanf("%d",&choice);
       switch(choice)
       {
           case 1:curinfoput();break;
           case 2:curinfosea();break;
           case 0:break;
           default:choice=-1;puts("Input error,again");break;
       }
    }
}

void stuinfoput()
{
    int a=1;
    struct student p;
    FILE *fp;
    while(a)
    {
        puts("����,ѧ��,�༶,רҵ,�绰,����,����,����,QQ");
        scanf("%s",stuinfo[count1].name);
        scanf("%ld",&stuinfo[count1].num);
        scanf("%d",&stuinfo[count1].cla);
        scanf("%s",stuinfo[count1].major);
        scanf("%s",stuinfo[count1].tel);
        scanf("%d",&stuinfo[count1].year);
        scanf("%d",&stuinfo[count1].birth);
        scanf("%d",&stuinfo[count1].dor);
        scanf("%d",&stuinfo[count1].qq);
        p=stuinfo[count1];
        printf("����\t\t\tѧ��\t�༶\tרҵ\t�绰\t\t\t����\n");
        printf("%s\t%ld\t%d\t%s\t%s\t%d\n",p.name,p.num,p.cla,p.major,p.tel,p.year);
        printf("����\t���� \tQQ\n");
        printf("%d\t%d\t%d\n",p.birth,p.dor,p.qq);
        fp=fopen("studentinfo.txt","at+");
        fwrite(&stuinfo[count1],sizeof(struct student),1,fp);
        fclose(fp);
        puts("�ѱ��棡");
        count1++;
        printf("��һ������0�˳�,1����\n");
        scanf("%d",&a);
    }
}

void stuinfodel()
{
    int a;
    printf("\t\t\t\t\t1-��ѧ��ɾ��\n");
    printf("\t\t\t\t\t2-������ɾ��\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:stuinfodel1();break;
        case 2:stuinfodel2();break;
        default:puts("Input error");break;
    }
}

void stuinfodel1()
{
    long number;
    int flag=0;
    struct student p;
    FILE *fp,*ft;
    printf("������Ҫɾ����ѧ��:\n");
    scanf("%ld",&number);
    if((fp=fopen("studentinfo.txt","r+"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    ft=fopen("temp.txt","w+");
    while(fread(&p,sizeof(struct student),1,fp))
    {
        if(number!=p.num)
        {
            fwrite(&p,sizeof(struct student),1,ft);
        }
        else
        {
            flag=1;
            printf("����\t\t\tѧ��\t�༶\tרҵ\t�绰\t\t\t����\n");
            printf("%s\t%ld\t%d\t%s\t%s\t%d\n",p.name,p.num,p.cla,p.major,p.tel,p.year);
            printf("����\t���� \tQQ\n");
            printf("%d\t%d\t%d\n",p.birth,p.dor,p.qq);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("studentinfo.txt");
    rename("temp.txt","studentinfo.txt");
    if(flag==0)
        puts("Not find");
}

void stuinfodel2()
{
    char name[20];
    int flag=0;
    struct student p;
    FILE *fp,*ft;
    printf("������Ҫɾ��������:\n");
    scanf("%s",name);
    if((fp=fopen("studentinfo.txt","r+"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    ft=fopen("temp.txt","w+");
    while(fread(&p,sizeof(struct student),1,fp))
    {
        if(strcmp(name,p.name)!=0)
        {
            fwrite(&p,sizeof(struct student),1,ft);
        }
        else
        {
            flag=1;
            printf("����\t\t\tѧ��\t�༶\tרҵ\t�绰\t\t\t����\n");
            printf("%s\t%ld\t%d\t%s\t%s\t%d\n",p.name,p.num,p.cla,p.major,p.tel,p.year);
            printf("����\t���� \tQQ\n");
            printf("%d\t%d\t%d\n",p.birth,p.dor,p.qq);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("studentinfo.txt");
    rename("temp.txt","studentinfo.txt");
    if(flag==0)
        puts("Not find");
}

void stuinfosea()
{
    int a;
    printf("\t\t\t\t\t1-��������ѯ\n");
    printf("\t\t\t\t\t2-��ѧ�Ų�ѯ\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:stuinfosea1();break;
        case 2:stuinfosea2();break;
        default:puts("input error");break;
    }
}

void stuinfosea1()
{
    char name[20];
    int flag=0;
    FILE* fp;
    struct student p;
    printf("������Ҫ��ѯ������:");
    scanf("%s",name);
    if((fp=fopen("studentinfo.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct student),1,fp))
    {
        if(strcmp(p.name,name)==0)
        {
            flag=1;
            printf("����\t\t\tѧ��\t�༶\tרҵ\t�绰\t\t\t����\n");
            printf("%s\t%ld\t%d\t%s\t%s\t%d\t%n",p.name,p.num,p.cla,p.major,p.tel,p.year);
            printf("����\t���� \tQQ\n");
            printf("%d\t%d\t%d\n",p.birth,p.dor,p.qq);
        }
    }
    fclose(fp);
    if(flag==0)
        puts("Not find");
}

void stuinfosea2()
{
    long num;
    int flag=0;
    FILE* fp;
    struct student p;
    printf("������Ҫ��ѯ��ѧ��:");
    scanf("%ld",&num);
    if((fp=fopen("studentinfo.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct student),1,fp))
    {
        if(num==p.num)
        {
            flag=1;
            printf("����\t\t\tѧ��\t�༶\tרҵ\t�绰\t\t\t����\n");
            printf("%s\t%ld\t%d\t%s\t%s\t%d\n",p.name,p.num,p.cla,p.major,p.tel,p.year);
            printf("����\t���� \tQQ\n");
            printf("%d\t%d\t%d\n",p.birth,p.dor,p.qq);
        }
    }
    fclose(fp);
    if(flag==0)
        puts("Not find");
}

void attinfoput()
{
    int a=1;
    FILE *fp;
    struct atten p;
    while(a)
    {
        puts("����:");
        scanf("%s",attinfo[count2].name);
        puts("ѧ��:");
        scanf("%ld",&attinfo[count2].num);
        puts("�༶:");
        scanf("%d",&attinfo[count2].cla);
        puts("�γ̱��:");
        scanf("%d",&attinfo[count2].curnum);
        puts("�γ�����:");
        scanf("%s",attinfo[count2].curname);
        puts("����Υ�ͣ��ٵ�(1)/����(2)/����(3)/����(4)");
        scanf("%d",&attinfo[count2].vio);
        puts("�ڼ��ο�:");
        scanf("%d",&attinfo[count2].classtime);
        puts("ʱ��:");
        scanf("%d",&attinfo[count2].time);
        puts("�ص�:");
        scanf("%s",attinfo[count2].place);
        p=attinfo[count2];
        printf("����\t\tѧ��\t�༶\t�γ̱��\t�γ�����\n");
        printf("%s\t%ld\t%d\t%d\t\t%s\n",p.name,p.num,p.cla,p.curnum,p.curname);
        printf("����Υ��\t�ڼ��ο�\tʱ��\t�ص�\n");
        printf("%d\t\t%d\t\t%d\t%s\n",p.vio,p.classtime,p.time,p.place);
        fp=fopen("ARecord.txt","at+");
        fwrite(&attinfo[count2],sizeof(struct atten),1,fp);
        fclose(fp);
        puts("�ѱ��棡");
        count2++;
        printf("��һ������0�˳���1����\n");
        scanf("%d",&a);
    }
}

void attinfosea()
{
   int a;
    printf("\t\t\t\t\t1-��������ѯ\n");
    printf("\t\t\t\t\t2-��ѧ�Ų�ѯ\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:attinfosea1();break;
        case 2:attinfosea2();break;
        default:puts("input error");break;
    }
}

void attinfodel()
{
    int a;
    printf("\t\t\t\t\t1-��ѧ��ɾ��\n");
    printf("\t\t\t\t\t2-������ɾ��\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:attinfodel1();break;
        case 2:attinfodel2();break;
        default:puts("Input error");break;
    }
}

void infocount()
{
    int a;
    printf("\t\t\t\t\t1-��ĳλѧ��ĳ�ſγ�ͳ��\n");
    printf("\t\t\t\t\t2-��ѧ�����пγ�ͳ��\n");
    printf("\t\t\t\t\t3-��ĳ�����пγ�ͳ��\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:infocount1();break;
        case 2:infocount2();break;
        case 3:infocount3();break;
        default:puts("Input error");break;
    }
}

void attinfosea1()
{
    char name[20];
    int flag=0;
    FILE* ft;
    struct atten p;
    printf("������Ҫ��ѯ������:");
    scanf("%s",name);
    if((ft=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(ft);
    while(fread(&p,sizeof(struct atten),1,ft))
    {
        if(strcmp(p.name,name)==0)
        {
            flag=1;
            printf("����\t\tѧ��\t�༶\t�γ̱��\t�γ�����\n");
            printf("%s\t%ld\t%d\t%d\t\t%s\n",p.name,p.num,p.cla,p.curnum,p.curname);
            printf("����Υ��\t�ڼ��ο�\tʱ��\t�ص�\n");
            printf("%d\t\t%d\t\t%d\t%s\n",p.vio,p.classtime,p.time,p.place);
        }
    }
    fclose(ft);
    if(flag==0)
        puts("Not find");
}

void attinfosea2()
{
    long num;
    int flag=0;
    FILE* fp;
    struct atten p;
    printf("������Ҫ��ѯ��ѧ��:");
    scanf("%ld",&num);
    if((fp=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(num==p.num)
        {
            flag=1;
            printf("����\t\tѧ��\t�༶\t�γ̱��\t�γ�����\n");
            printf("%s\t%ld\t%d\t%d\t\t%s\n",p.name,p.num,p.cla,p.curnum,p.curname);
            printf("����Υ��\t�ڼ��ο�\tʱ��\t�ص�\n");
            printf("%d\t\t%d\t\t%d\t%s\n",p.vio,p.classtime,p.time,p.place);
        }
    }
    fclose(fp);
    if(flag==0)
        puts("Not find");
}

void infocount1()
{
    char name[100];
    char curname[100];
    int flag=0,i=0,j=0;
    int a=0,b=0,c=0,d=0;
    FILE* fp;
    struct atten p;
    printf("������Ҫ��ѯ������:");
    scanf("%s",name);
    printf("������Ҫ��ѯ�Ŀγ�:");
    scanf("%s",curname);
    if((fp=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(strcmp(p.name,name)==0)
        {
            if(strcmp(p.curname,curname)==0)
            {
               flag=1;
               j=p.vio;
               switch(j)
               {
                   case 1:a=a+1;break;
                   case 2:b=b+1;break;
                   case 3:c=c+1;break;
                   case 4:d=d+1;break;
                   default:break;
               }
            }
        }
    }
    fclose(fp);
    if(flag=0)
        puts("Not find");
    else
    {
        printf("\t\t\t�ٵ�:%d\t\t����:%d\n",a,b);
        printf("\t\t\t����:%d\t\t����:%d\n",c,d);
    }
}

void infocount2()
{
    char name[100];
    int flag=0,i=0,j=0;
    int a=0,b=0,c=0,d=0;
    FILE* fp;
    struct atten p;
    printf("������Ҫ��ѯ������:");
    scanf("%s",name);
    if((fp=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(strcmp(p.name,name)==0)
        {
               flag=1;
               j=p.vio;
               switch(j)
               {
                   case 1:a=a+1;break;
                   case 2:b=b+1;break;
                   case 3:c=c+1;break;
                   case 4:d=d+1;break;
                   default:break;
               }
        }
    }
    fclose(fp);
    if(flag=0)
        puts("Not find");
    else
    {
        printf("\t\t\t�ٵ�:%d\t\t����:%d\n",a,b);
        printf("\t\t\t����:%d\t\t����:%d\n",c,d);
    }
}

void infocount3()
{
    int cla;
    int flag=0,i=0,j=0;
    int a=0,b=0,c=0,d=0;
    FILE* fp;
    struct atten p;
    printf("������Ҫ��ѯ�İ༶:");
    scanf("%d",&cla);
    if((fp=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(cla==p.cla)
        {
               flag=1;
               j=p.vio;
               switch(j)
               {
                   case 1:a=a+1;break;
                   case 2:b=b+1;break;
                   case 3:c=c+1;break;
                   case 4:d=d+1;break;
                   default:break;
               }
        }
    }
    fclose(fp);
    if(flag=0)
        puts("Not find");
    else
    {
        printf("\t\t\t�ٵ�:%d\t\t����:%d\n",a,b);
        printf("\t\t\t����:%d\t\t����:%d\n",c,d);
    }
}

void attinfodel1()
{
    long number;
    int flag=0;
    struct atten p;
    FILE *fp,*ft;
    printf("������Ҫɾ����ѧ��:\n");
    scanf("%ld",&number);
    if((fp=fopen("ARecord.txt","r+"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    ft=fopen("temp.txt","w+");
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(number==p.num)
        {
            flag=1;
            printf("����\t\tѧ��\t�༶\t�γ̱��\t�γ�����\n");
            printf("%s\t%ld\t%d\t%d\t\t%s\n",p.name,p.num,p.cla,p.curnum,p.curname);
            printf("����Υ��\t�ڼ��ο�\tʱ��\t�ص�\n");
            printf("%d\t\t%d\t\t%d\t%s\n",p.vio,p.classtime,p.time,p.place);
        }
        else
        {
            fwrite(&p,sizeof(struct atten),1,ft);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("ARecord.txt");
    rename("temp.txt","ARecord.txt");
    if(flag==0)
        puts("Not find");
}

void attinfodel2()
{
    char name[100];
    int flag=0;
    struct atten p;
    FILE *fp,*ft;
    printf("������Ҫɾ��������:\n");
    scanf("%s",name);
    if((fp=fopen("ARecord.txt","r+"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    ft=fopen("temp.txt","w+");
    while(fread(&p,sizeof(struct atten),1,fp))
    {
        if(strcmp(name,p.name)!=0)
        {
            fwrite(&p,sizeof(struct atten),1,ft);
        }
        else
        {
            flag=1;
            printf("����\t\tѧ��\t�༶\t�γ̱��\t�γ�����\n");
            printf("%s\t%ld\t%d\t%d\t\t%s\n",p.name,p.num,p.cla,p.curnum,p.curname);
            printf("����Υ��\t�ڼ��ο�\tʱ��\t�ص�\n");
            printf("%d\t\t%d\t\t%d\t%s\n",p.vio,p.classtime,p.time,p.place);
        }
    }
    fclose(fp);
    fclose(ft);
    remove("ARecord.txt");
    rename("temp.txt","ARecord.txt");
    if(flag==0)
        puts("Not find");
}

void Backupdate()
{
    FILE *fp,*ft;
    int flag=0;
    struct atten p;
    if((fp=fopen("ARecord.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    ft=fopen("backup.txt","w+");
    while(fread(&p,sizeof(struct atten),1,fp))
    {
       flag=1;
       fwrite(&p,sizeof(struct atten),1,ft);
    }
    fclose(fp);
    fclose(ft);
    if(flag==1)
        puts("OK!");
}

void curinfoput()
{
    int a=1;
    struct curinformation p;
    FILE *fp;
    while(a)
    {
        puts("�γ̱��,�γ�����,�γ�ѧ��,�ο���ʦ,�Ͽ�ʱ��,�Ͽδ���,�Ͽεص�");
        scanf("%d",&curinfo[count3].number);
        scanf("%s",curinfo[count3].name);
        scanf("%d",&curinfo[count3].score);
        scanf("%s",curinfo[count3].tea);
        scanf("%d",&curinfo[count3].time);
        scanf("%d",&curinfo[count3].times);
        scanf("%s",curinfo[count3].place);
        p=curinfo[count3];
        printf("�γ̱��\t�γ�����\t�γ�ѧ��\t�ο���ʦ\n");
        printf("%d\t\t%s\t\t%d\t\t%s\n",p.number,p.name,p.score,p.tea);
        printf("�Ͽ�ʱ��\t�Ͽδ���\t�Ͽεص�\n");
        printf("%d\t\t%d\t\t%s\n",p.time,p.times,p.place);
        fp=fopen("curinfo.txt","at+");
        fwrite(&curinfo[count3],sizeof(struct curinformation),1,fp);
        fclose(fp);
        puts("�ѱ��棡");
        count3++;
        printf("��һ������0�˳���1����\n");
        scanf("%d",&a);
    }
}

void curinfosea()
{
   int a;
    printf("\t\t\t\t\t1-���ο���ʦ��ѯ\n");
    printf("\t\t\t\t\t2-�ÿγ����Ʋ�ѯ\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:curinfosea1();break;
        case 2:curinfosea2();break;
        default:puts("input error");break;
    }
}

void curinfosea1()
{
    char name[20];
    int flag=0;
    FILE* fp;
    struct curinformation p;
    printf("������Ҫ��ѯ���ο���ʦ����:");
    scanf("%s",name);
    if((fp=fopen("curinfo.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct curinformation),1,fp))
    {
        if(strcmp(p.tea,name)==0)
        {
            flag=1;
            printf("�γ̱��\t�γ�����\t�γ�ѧ��\t�ο���ʦ\n");
            printf("%d\t\t%s\t\t%d\t\t%s\n",p.number,p.name,p.score,p.tea);
            printf("�Ͽ�ʱ��\t�Ͽδ���\t�Ͽεص�\n");
            printf("%d\t\t%d\t\t%s\n",p.time,p.times,p.place);
        }
    }
    fclose(fp);
    if(flag=0)
        puts("Not find");
}

void curinfosea2()
{
    char name[20];
    int flag=0;
    FILE* fp;
    struct curinformation p;
    printf("������Ҫ��ѯ�Ŀγ�����:");
    scanf("%s",name);
    if((fp=fopen("curinfo.txt","rt"))==NULL)
        printf("\t\t\tERROR!NO FILE!\n");
    rewind(fp);
    while(fread(&p,sizeof(struct curinformation),1,fp))
    {
        if(strcmp(p.name,name)==0)
        {
            flag=1;
            printf("�γ̱��\t�γ�����\t�γ�ѧ��\t�ο���ʦ\n");
            printf("%d\t\t%s\t\t%d\t\t%s\n",p.number,p.name,p.score,p.tea);
            printf("�Ͽ�ʱ��\t�Ͽδ���\t�Ͽεص�\n");
            printf("%d\t\t%d\t\t%s\n",p.time,p.times,p.place);
        }
    }
    fclose(fp);
    if(flag=0)
        puts("Not find");
}


