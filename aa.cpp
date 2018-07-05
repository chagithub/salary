/*************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: Staff information management system // �ļ���
Author: ������ Version: 1.0 Date: 2018.6.29 // ���ߡ��汾���������
Description: 
���ж�ְ����Ϣ��1.��ѯ 2.�޸� 3.��� 4.ɾ�� 5.���� 6.����Ȳ�����
//������ϸ˵���˳����ļ���ɵ���Ҫ���ܣ�������ģ������Ľӿڣ�
//���ֵ��ȡֵ��Χ�����弰������Ŀ��ơ�˳�򡢶����������ȹ�ϵ
read()��ȡ���ݡ�find()��ѯ��modify()�޸ġ�add()��ӡ�del()ɾ����write()���桢list()���
Others: �ó�����Ҫ�����ڱ����Ͻ���gx.dat�ļ�// �������ݵ�˵��
Function List: // ��Ҫ�����б�ÿ����¼Ӧ���������������ܼ�Ҫ˵��
1. read()��ȡ���� 2. find()��ѯ 3. modify()�޸� 4. add()��� 5. del()ɾ�� 6. write()���� 7. list()���
History: // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���
1. Date:2018.6.29
Author:������
Modification:���г����Ű�
2. Date:2018.7.5
Author:������
Modification:���������Ű�
*************************************************/
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
extern int n=0;//����ȫ�ֱ���n��ְ��������
struct zggz//����ְ����Ϣ�ṹ������
{
	char job_number[100];
	char name[100];
	float post_salary;
	float salary_scale;
	float job_allowance;
	float performance_pay;
	float payable_wages;
	float personal_income_tax;
	float salary_paid;
}zggz[100];
/*************************************************
Function: grsds // ��������
Description: ��ְ��Ӧ�����ʣ���������˰��ʵ������ // �������ܡ����ܵȵ�����
Calls: ��// �����������õĺ����嵥
Called By: find()��list()��modify()// ���ñ������ĺ����嵥
Input: ��// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: payable_wages ��Ӧ�����ʣ� personal_income_tax ����������˰��salary_paid ��ʵ�����ʣ�// �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void grsds(int i)//��ְ��Ӧ�����ʣ���������˰��ʵ������
{
		zggz[i].payable_wages=zggz[i].post_salary+zggz[i].salary_scale
			                  +zggz[i].job_allowance+zggz[i].performance_pay;//����Ӧ�ù���
		if(zggz[i].payable_wages>100000)//�������ʮ��Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-100000)*0.45
				                        +8000+7000+6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>80000)//������ڰ���Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-80000)*0.4
				                        +7000+6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>60000)//�����������Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-60000)*0.35
				                        +6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>40000)//�����������Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-40000)*0.3
				                        +5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>20000)//�����������Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-20000)*0.25
				                        +3000+450+150+25;
		}

		else if(zggz[i].payable_wages>5000)//���������ǧ�Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-5000)*0.2
				                        +450+150+25;
		}

		else if(zggz[i].payable_wages>2000)//���������ǧ�Ĺ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-2000)*0.15
				                        +150+25;
		}

		else if(zggz[i].payable_wages>500)//���������ٵĹ��ʶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-500)*0.1
				                        +150+25;
		}

		else if(zggz[i].payable_wages<500)//���㹤����������ڵĶ�Ӧ��������˰
		{
			zggz[i].personal_income_tax=zggz[i].payable_wages*0.05;
		}

		zggz[i].salary_paid=zggz[i].payable_wages-zggz[i].personal_income_tax;//����ʵ�ù���
		printf("%g   %g   %g",zggz[i].payable_wages,zggz[i].personal_income_tax,zggz[i].salary_paid);
		//����������������
}
/*************************************************
Function: read // ��������
Description: ��ȡְ������ // �������ܡ����ܵȵ�����
Calls: ��// �����������õĺ����嵥
Called By: main() // ���ñ������ĺ����嵥
Input: ��// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ��// �����������˵����
Return: 0// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
int read()//��ȡְ������
{
        FILE *fp;
        fp=fopen("gx.dat","a+");//���ļ�
        fseek(fp,0,SEEK_SET);//�ƶ�ָ��
        fseek(fp,0,SEEK_END);//ͬ��
        int number=ftell(fp)/sizeof(struct zggz);//���ֽڳ��ȳ��Խṹ�嵥λ���ȼ�Ϊ����
        n=number;//������������ֵ��n
        fseek(fp,0,SEEK_SET);
        if(fp==NULL)//��ʧ��
        {
	        return -1;
        }
        fread((char*)zggz,sizeof(struct zggz),n,fp);//��ȡ����
        fclose(fp);//�ر��ļ�
        return 0;
}
/*************************************************
Function: find // ��������
Description: ��ѯָ�����ŵ�Ա����Ϣ// �������ܡ����ܵȵ�����
Calls: grsds()// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input: char job_number[100] ��ΪҪ��ѯ��Ա������ع��ţ��������ļ���¼�Ƚϣ��ҵ�ƥ���Ա��
// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ���ţ�zggz[i].job_number ������zggz[i].name
        ��λ���ʣ�zggz[i].post_salary н�����ʣ�zggz[i].salary_scale
        ְ�������zggz[i].job_allowance ��Ч���ʣ�zggz[i].performance_pay
        // �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void find()//��ѯ
{
	char job_number[100];
	printf("����Ҫ��ѯ��ְ������\n");
	scanf("%s",job_number);//���빤��
	for(int i=0;i<n;i++)
	{
		if(strcmp(job_number,zggz[i].job_number)==0)//��ѯ�Ƿ���ƥ��Ĺ���
		{
		        printf("����ѯ��ְ����Ϣ��\n");
		        printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
		        printf("%s     %s   %g    %g    %g    %g   "
				,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
				,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
                        grsds(i);//����grsds()������Ӧ�����ʣ���������˰��ʵ�����ʲ����
		        printf("\n");//����
		        break;
		}
		if(i==n-1)//��ʾ���һ�����������Ҳ��ƥ�䣬���ļ��������ְ����¼
		{
		        printf("���޴���\n");
		}
	}
}
/*************************************************
Function: modify // ��������
Description: �޸�ָ�����ŵ�Ա����Ϣ// �������ܡ����ܵȵ�����
Calls: grsds()// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input: char job_number[100] ��ΪҪ�޸ĵ�Ա������ع��ţ��������ļ���¼�Ƚϣ��ҵ�ƥ���Ա��
// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ���ţ�zggz[i].job_number ������zggz[i].name
        ��λ���ʣ�zggz[i].post_salary н�����ʣ�zggz[i].salary_scale
        ְ�������zggz[i].job_allowance ��Ч���ʣ�zggz[i].performance_pay
        // �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void modify()//�޸�
{
	char job_number[100];
	printf("�����޸ģ���ѡ1���˳���ѡ2\n");
	int p;
	scanf("%d",&p);
	switch(p)//���ѡ���ִ�к���
	{
		  case 1: 
		{
			printf("�޸���ɺ��豣�����Ч\n");
			printf("����Ҫ�޸ĵ�ְ������\n");
			scanf("%s",job_number);//���빤��
			for(int i=0;i<n;i++)
			{
			if(strcmp(job_number,zggz[i].job_number)==0)//��ѯ�Ƿ���ƥ��Ĺ���//�����޸�
			{
		        printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
		        printf("%s     %s   %g    %g    %g    %g   "
				      ,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
				      ,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		        grsds(i);//����grsds()������Ӧ�����ʣ���������˰��ʵ�����ʲ����
				printf("\n");//����
		        printf("�����Ӧ����ѡ������޸� 1.������2.��λ���ʣ�3.н�����ʣ�4.ְ�������5.��Ч����\n");
		        printf("Ҳ������6����ȫ���޸�\n");
		        int t;
		        scanf("%d",&t);
		        switch(t)//���ѡ���ִ�к���
		        {
		            case 1: 
						{
                                printf("������������\n");
                                scanf("%s",zggz[i].name);
                                break;
						}
		            case 2: 
						{
                                printf("���������λ����\n");
                                scanf("%f",&zggz[i].post_salary);
                                break;
						}		        
		            case 3: 
						{
                                printf("��������н������\n");
                                scanf("%f",&zggz[i].salary_scale);
                                break;
						}
		            case 4: 
						{
                                printf("��������ְ�����\n");
                                scanf("%f",&zggz[i].job_allowance);
                                break;
						}
		            case 5: 
						{
                                printf("�������뼨Ч����\n");
                                scanf("%f",&zggz[i].performance_pay);
                                break;
						}
		            case 6: 
						{
                                printf("��������  ��������λ���ʣ�н�����ʣ�ְ���������Ч����\n");
                                scanf("%s",zggz[i].name);
                                scanf("%f",&zggz[i].post_salary);
                                scanf("%f",&zggz[i].salary_scale);
                                scanf("%f",&zggz[i].job_allowance);
                                scanf("%f",&zggz[i].performance_pay);
                                break;
						}
		        }
		        printf("�޸ĺ��ְ����Ϣ��\n");
		        printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
		        printf("%s     %s   %g    %g    %g    %g   "
			        ,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
			        ,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		        grsds(i);//����grsds()������Ӧ�����ʣ���������˰��ʵ�����ʲ����
		        break;
		}
		if(i==n-1)//��ʾ���һ�����������Ҳ��ƥ�䣬���ļ��������ְ����¼
		{
		        printf("���޴���\n");
		}
			}
		}
		  case 2:
		{
		    break;
		}
	}
	
}
/*************************************************
Function: add // ��������
Description: ���Ա����Ϣ// �������ܡ����ܵȵ�����
Calls: grsds()// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input:  int num ��Ҫ��ӵ�Ա���������ţ�zggz[i].job_number ������zggz[i].name
        ��λ���ʣ�zggz[i].post_salary н�����ʣ�zggz[i].salary_scale
        ְ�������zggz[i].job_allowance ��Ч���ʣ�zggz[i].performance_pay
        // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ��// �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void add()//���
{
	printf("�����ɺ��豣�����Ч\n");
	printf("Ŀǰ���е�Ա������\n");
	for(int i=0;i<n;i++)
	{
		printf("%s  ",zggz[i].job_number);
	}
	printf("������ӣ���ѡ1���˳���ѡ2\n");
	int p;
	scanf("%d",&p);
	switch(p)//���ѡ���ִ�к���
	{
		  case 1: 
		{
			printf("������Ҫд���Ա����\n");
	        int num;
	        scanf("%d",&num);//����Ҫ���ӵ�����
	        for(int i=n;i<num+n;i++)//ͨ��forѭ��������������ְ����Ϣ
			{
	        printf("��������ְ����Ϣ\n");
	        printf("���� , ���� , ��λ���� , н������ , ְ����� , ��Ч����\n");
	        scanf("%s",zggz[i].job_number);
	        scanf("%s",zggz[i].name);
	        scanf("%f",&zggz[i].post_salary);
	        scanf("%f",&zggz[i].salary_scale);
	        scanf("%f",&zggz[i].job_allowance);
	        scanf("%f",&zggz[i].performance_pay);
			}
	        n=n+num;//��ʱ��������        
		}
		  case 2:
		{
		    break;
		}
	}
}
/*************************************************
Function: del // ��������
Description: ɾ��ָ�����ŵ�Ա����Ϣ// �������ܡ����ܵȵ�����
Calls: ��// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input: char job_number[100] ��ΪҪ��ɾ����Ա������ع��ţ��������ļ���¼�Ƚϣ��ҵ�ƥ���Ա��
       // �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ��// �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void del()//ɾ��ָ��Ա������Ϣ
{
	char job_number[100];
	printf("����ɾ������ѡ1���˳���ѡ2\n");
	int p;
	scanf("%d",&p);
	switch(p)//���ѡ���ִ�к���
	{
		  case 1: 
		{
			printf("ɾ����ɺ��豣�����Ч\n");
			printf("������Ҫɾ����Ա������\n");
			scanf("%s",job_number);//���빤��
			for(int i=0;i<n;i++)
		{
			if(strcmp(job_number,zggz[i].job_number)==0)//��ѯ�Ƿ���ƥ��Ĺ���//����ɾ��
		{
		        if(i!=n-1)//�����Ա���������һ��
		    {
			    for(;i<n;i++)//forѭ������һ�����鸲�ǵ�ǰһ������
			   {
			    zggz[i].post_salary=zggz[i+1].post_salary;
			    zggz[i].personal_income_tax=zggz[i+1].personal_income_tax;
			    strcpy(zggz[i].job_number,zggz[i+1].job_number);
			    zggz[i].performance_pay=zggz[i+1].performance_pay;
			    zggz[i].salary_paid=zggz[i+1].salary_paid;
			    strcpy(zggz[i].name,zggz[i+1].name);
			    zggz[i].salary_scale=zggz[i+1].salary_scale;
			    zggz[i].payable_wages=zggz[i+1].payable_wages;
			    zggz[i].job_allowance=zggz[i+1].job_allowance;
			   }
		        n=n-1;//������Ӧ��һ
		    }
		        else//�����Ա�������һ��
		    {
		        n=n-1;//������Ӧ��һ
		    }

		}
		}	        
		}
		  case 2:
		{
		    break;
		}
	}
}
/*************************************************
Function: write // ��������
Description: ����д���ְ������// �������ܡ����ܵȵ�����
Calls: ��// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input: ��// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ��// �����������˵����
Return: -1// ��������ֵ��˵��
Others: ������ÿ���ļ����ݱ䶯�����д˺���// ����˵��
*************************************************/
int write()//����д���ְ������
{
	FILE *fp;
	fp=fopen("gx.dat","wb");//���ļ�
	if(fp==NULL)//��ʧ��
	{
		return -1;
	}
	fwrite((char*)zggz,sizeof(struct zggz),n,fp);//д������
	fclose(fp);//�ر��ļ�
}
/*************************************************
Function: list // ��������
Description: ��ʾ���е�Ա����Ϣ// �������ܡ����ܵȵ�����
Calls: grsds()// �����������õĺ����嵥
Called By: main()// ���ñ������ĺ����嵥
Input: ��// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ���ţ�zggz[i].job_number ������zggz[i].name
        ��λ���ʣ�zggz[i].post_salary н�����ʣ�zggz[i].salary_scale
        ְ�������zggz[i].job_allowance ��Ч���ʣ�zggz[i].performance_pay
        // �����������˵����
Return: ��// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
void list()//�б�
{
        int i;
        printf("����ְ����Ϣ��\n");
        printf("���� ���� ��λ���� н������ ְ����� ��Ч���� Ӧ������ ��������˰ ʵ������\n");
        for(i=0;i<n;i++)//ͨ��forѭ�������������ְ����Ϣ
	{
		printf("%s     %s   %g    %g    %g    %g   "
			,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
			,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		grsds(i);
		//��������������ͬ���У����ְ��ȫ����Ϣ
		printf("\n");//����
	}
}
/*************************************************
Function: main // ��������
Description: ϵͳ����������ͨ�������������в�����ִ��ϵͳ����ع���// �������ܡ����ܵȵ�����
Calls: find()��modify()��add()��del()��write()��list() // �����������õĺ����嵥
Called By: ��// ���ñ������ĺ����嵥
Input: int p ������Ϊswitch����ѡ�����֣����벻ͬ���ֿ�ִ�в�ͬ�Ĺ���
// �������˵��������ÿ�����������á�ȡֵ˵�����������ϵ��
Output: ��// �����������˵����
Return: 0// ��������ֵ��˵��
Others: ��// ����˵��
*************************************************/
int main()
{
        read();//ִ��read������ȡ�ļ���Ϣ
        for(int i=0;i<7;)
	{
	        printf("\n"); // ��ҳģ��
	        printf("\n");
	        printf("        ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ  ###\n");
	        printf("\n");
	        printf("\n");
	        printf("        Ŀǰ���� ");
	        printf("%d",n);
	        printf(" ��ְ����Ϣ\n");
	        printf("\n");
	        printf("        ��ѡ�� <1 - 7> :\n");
	        printf("        ================================================================\n");
	        printf("        |        1. ��ѯְ�����ʼ�¼                                   |\n");
	        printf("        |        2. �޸�ְ�����ʼ�¼                                   |\n");
	        printf("        |        3. ���ְ�����ʼ�¼                                   |\n");
	        printf("        |        4. ɾ��ְ�����ʼ�¼                                   |\n");
	        printf("        |        5. �������ݵ��ļ�                                     |\n");
	        printf("        |        6. ���ְ����¼                                       |\n");
	        printf("        |        7. �˳�ϵͳ                                           |\n");
	        printf("        ================================================================\n");
	        printf("\n");
	        printf("         ���ѡ���ǣ�\n");
	int p;
	scanf("%d",&p);
	switch(p)//���ѡ���ִ�к���
	{
	        case 1: 
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾfind()������������
                                find();
                                break;
			}
	        case 2:
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾmodify()������������
                                modify();
                                break;
			}
	        case 3: 
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾadd()������������
                                add();
                                break;
			}
	        case 4: 
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾdel()������������
                                del();
                                break;
			}
	        case 5: 
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾwrite()������������
                                write();
                                break;
			}
	        case 6: 
			{
                                system("cls");//ʹ��ʾҳ��ֻ��ʾlist()������������
                                list();
                                break;
			}
	        case 7: 
			{
                                i=7;
			}
		
	}
	}
	return 0;
}