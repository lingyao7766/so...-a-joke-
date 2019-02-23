#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//���00�� ǰ��ʱ������֮����Ƚ��ʦ����ѧ�������ҵ�ȥ�����ݽṹ�Ŀ���...Ҫ��ѧ��֮ǰ������Ŀγ���ƾ�������ɡ���Ȼһ��ʮ�ֺ�ڣ����Ѿ�������ֻ��Ӳ��ͷƤ����...
   //������Ϊ���������������Ȼ����������������������

//���������  1.ѧ����Ϣ¼�� Input_information()  --�����Լ���������
//            2.ѧ����Ϣ��� Browse_information() --�������
//            3.ѧ����Ϣ��ѯ Query_information()  --��ѯ�ض���㲢������������
//            4.��Ϣ���� Osrt_information()       --1.ʹ��ð�ݷ����߿��ţ�ð�ݵ�ָ��ʵ��...�� 2.��ô������������û����
//            5.��Ϣɾ�� Delete_information()     --ɾ���ض����
//            6.��Ϣ�޸� Revise_information()     --�޸��ض��Ľ��
//            0.�˳� exit()


//--------�ṹ��Ĵ���--------//   ----------------------------------------------
typedef struct student   //������ṹ�壺ѧ�š��������������
{
    char num[20];  //ѧ��
    char name[20]; //����
    int score[4];  //���ġ���ѧ������ܷ�

}student;
typedef struct Node
{
    student data;  //�浽������
    struct Node * next;
}node;

//-----------��������------------//  -----------------------------------------------
node * CreatList()  //Input_information()֮һ���֣���Ȼ�������˵�Ĳ��Ǻ�����
{
    node *L,*p1,*p2;  //��p1ָ���½�㡢p2ָ�����һ�����
    int i,n;
    printf("������ѧ��������\n");
    scanf("%d",&n);
    printf("������ѧ������ɼ� ������ѧ�ţ����������ĳɼ�����ѧ�ɼ���Ӣ��ɼ�\n");
    L=(node*)malloc(sizeof(node)); //����ͷ�ڵ�L
    p2=L;
    for(i=0;i<n;i++)
    {
        p1=(node*)malloc(sizeof(node));  //�����µĽ��
        scanf("%s%s%d%d%d",p1->data.num,p1->data.name,&p1->data.score[0],&p1->data.score[1],&p1->data.score[2]);
        p2->next=p1;
        p2=p1;   //���Ͻ�p1ָ��Ľ�㴫��p2 ...emm˵����ƺ�ûʲô���壬�ո�ע������
    }
    p2->next=NULL;
    printf("ѧ����Ϣ�����ɹ�");
return L;  //����ͨ��һ����ͷ�ڵ������������
}


//------------�������------------//  ------------------------------------------------------
void Print(node *L)
{
    node *p=L->next; //p��ָ��ͷָ��֮�����ֵ����
    while(p!=NULL)
    {
        printf("%s%s%d%d%d",p->data.num,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
        p=p->next; //ÿѭ��һ����ǰָһ��
    }
}  //��ˮ��һ����������������


//-----------��ѯ����------------//  --------------------------------------------------------
void Search_num(node *L) //��ѧ�Ž��е�ѧ����Ϣ��ѯ
{
    node *p=L->next;
    char n[20];
    printf("��������ҵ�ѧ��\n");
        scanf("%s",n); //����Ƚϵ�ѧ�Ų���һ��������...�����ҵ�ʵ����ID A0617M86
    while(p!=NULL)
    {
        if(strcmp(p->data.num,n)==0) //�ַ����ȽϺ���
        {
            printf("%s%s%d%d%d",p->data.num,p->data.name,p->data.score[0],p->data.score[1],p->data.score[2]);
            break;
        }
        else p=p->next;
    }

}
//�ʼ��ʽ˼ά�����ð�ݷ�������...�����������ڴ�..����Ȼ����ѡ���ˡ�����̨���ķ������ܵ���˵��ʡ�˿ռ�
void Search_c(node *L) //���ĳɼ����
{
    node *p1=L->next;
    node *p2=p1->next;
    while(p2!=NULL)
    {
        if(p2->data.score[0] > p1->data.score[0]) //���p2ָ���ֵ������p1
        {
            p1=p2;   //�����ֵ����P1(��p1ָ��p2) ���˹���p1��Զ����p2
            p2=p2->next;   //p2������
        }
        else
        {
            p2=p2->next;  //p2����������
        }
    }
    Print(p1);   //��������ģ����ֵp1���������

}
// ͬ�� ʱ�临�Ӷ� o=2n
void Search_M(node *L)  //��ѧ�ɼ����
{
    node *p1=L->next;
    node *p2=p1->next;
    while(p2) //p2!=NULL �ļ���д��������һ��
    {
        if(p2->data.score[1] > p1->data.score[1])
        {
            p1=p2;
            p2=p2->next;
        }
        else
        {
            p2=p2->next;
        }
    }
    Print(p1); //ע�������Ǻ������ĺ�������ǰ���к���һ���ĺ���������ô��
}
//ͬ����
void Search_E(node *L)  //Ӣ��ɼ����
{
    node *p1=L->next;
    node *p2=p1->next;
    while(p2)
    {
        if(p2->data.score[2] > p1->data.score[2])
        {
            p1=p2;
            p2=p2->next;
        }
        else
        {
            p2=p2->next;
        }
    }
    Print(p1);
}


//------------��������-------------//  --------------------------------------------
void Sort(node *L)  //�����ġ�sort����STL��ڲ��õ��ǿ��ţ�������ˮƽ������ġ�Sort������ʵ����ð�ݷ�����
{
    node *p1 = L->next;
    node *p2 = L->next;
    student temp;
    for(;p1->next!=NULL;p1=p1->next)   //...��Ȼ����ֵ��������ð�������˳�����飩ʵ�ֻ�Ҫ��
    {
        for(p2=L->next;p2->next!=NULL;p2=p2->next)
        {
            if(p2->data.score[3] > p2->next->data.score[3])
            {
                temp = p2->data;         //����ʹ�õ��ǽ�����ݵĽ����������ǽ�㽻����
                p2->data = p2->next->data;  //����ԭ��...emm �����Ǿ仰 ˮƽ���㰡.....
                p2->next->data=temp;   //����᳢�����ҵ��̳̰ѽ�㽻��������
            }
        }
    }

}


//-------------����ɾ��--------------//-------------------------------------
void Delete(node * L) //��ͨ��ɾ������...����˼���������ض����
{
    node *p=L->next;
    node *pre=L; //ǰ�����
    printf("������Ҫɾ����ѧ��ѧ�ţ� \n");
    char num1[20];
    scanf("%s",&num1[20]);
    while((pre!=NULL)&&(pre->next->data.num!=num1)) //��������Ԫ�ص�ǰ��
    {
        pre=pre->next;
    }
    p=pre->next;
    if(p!=NULL)
        {
            pre->next = p->next; //��ǰ�����ֱ�����ӵ�����ѯ������Ľ��
            free(p); //�ͷ���ɾ���Ľ����ڴ�
            printf("ɾ���ɹ�\n");
        }
        else
        {
            printf("δ���ҵ���ͬѧ\n");
        }
}

// --------------�޸��ض��Ľ��----------------// -----------------------
void Modifaaction(node *L)
{
    node *p = L->next;
    char num2[20];
    printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�\n");
    scanf("%s",num2);   //ͬ����ָ���ַ����������λ ��&num2[20]�ȼۣ���һ��
    while(p!=NULL)
    {
        if(strcmp(p->data.num,num2)==0)  //�޸�p������ָ�Ľ������
        {
            printf("������ѧ��������Ϣ��\n");
            scanf("%s%s%d%d%d",p->data.num,p->data.name,&p->data.score[0],&p->data.score[1],&p->data.score[2]);
            printf("�޸ĳɹ�\n");
            break;
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("û�д˿���\n");
    }
}


//********------������ ===========================================---
int main()
{
    //��ʵ��֮ǰ��Ȼ������ô�࿴�����ܸߴ��ϵĺ�����������Ϊ������̫�鷳�˽��һ��Ҳû��...
    //���ǽ��֮ǰֱ������������ʽ
    int n;
    node *L=NULL;
    printf("-----------//--��ӭʹ��ѧ������ϵͳ--//-------------\n");
    printf("----*           1.ѧ����Ϣ¼��                         *\n");
    printf("----*           2.ѧ����Ϣ���                         *\n");
    printf("----*           3.ѧ����Ϣ��ѯ(��ѧ��)                 *\n");
    printf("----*           4.ѧ����Ϣ��ѯ(���������)             *\n");
    printf("----*           5.ѧ����Ϣ��ѯ(����ѧ���)             *\n");
    printf("----*           6.ѧ����Ϣ��ѯ(��Ӣ�����)             *\n");
    printf("----*           7.��Ϣ����(�����ܷ�)                   *\n");
    printf("----*           8.��Ϣɾ��                             *\n");
    printf("----*           9.��Ϣ�޸�                             *\n");
    printf("----*              0.�˳�                              *\n");
    printf("//-------------------------------------------------//\n");
    printf("������Ҫʹ�õĹ��ܱ��:\n");
    while(scanf("%d",&n)!=EOF)
    {
        switch(n)
        {
            case 1:
                L=CreatList();
                break;
            case 2:
                Print(L);
                break;
            case 3:
                Search_num(L);
                break;
            case 4:
                Search_c(L);
                break;
            case 5:
                Search_M(L);
                break;
            case 6:
                Search_E(L);
                break;
            case 7:
                Sort(L);
                break;
            case 8:
                Delete(L);
                break;
            case 9:
                Modifaaction(L);
                break;
            case 0:
                exit(0);
            default:
                printf("�����������������룺\n");
        }
    }
    return 0;
}



//���ļ��Ѵ�ԭ����CPP�޸�������C99ֱ�ӱ���
   //ȷ���˲��ᱨ��
