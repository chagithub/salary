
#include<iostream>
#include<fstream>
using namespace std;
extern int n=0;//����ȫ�ֱ���n��ְ��������
struct zggz
{
	char gonghao[100];
	char xingming[100];
	float ganggong;
	float xingong;
	float zhitie;
	float jizi;
	float yingzi;
	float geshui;
	float shizi;
}zggz[100];
void grsds(int i)//��ְ��Ӧ�����ʣ���������˰��ʵ������
{
		zggz[i].yingzi=zggz[i].ganggong+zggz[i].xingong+zggz[i].zhitie+zggz[i].jizi;//����Ӧ�ù���
		if(zggz[i].yingzi>100000)//���㲻ͬ���ʵĶ�Ӧ��������˰
		{
			zggz[i].geshui=(zggz[i].yingzi-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz[i].yingzi>80000)
		{
			zggz[i].geshui=(zggz[i].yingzi-80000)*0.4+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz[i].yingzi>60000)
		{
			zggz[i].geshui=(zggz[i].yingzi-60000)*0.35+6000+5000+3000+450+150+25;
		}
		else if(zggz[i].yingzi>40000)
		{
			zggz[i].geshui=(zggz[i].yingzi-40000)*0.3+5000+3000+450+150+25;
		}
		else if(zggz[i].yingzi>20000)
		{
			zggz[i].geshui=(zggz[i].yingzi-20000)*0.25+3000+450+150+25;
		}
		else if(zggz[i].yingzi>5000)
		{
			zggz[i].geshui=(zggz[i].yingzi-5000)*0.2+450+150+25;
		}
		else if(zggz[i].yingzi>2000)
		{
			zggz[i].geshui=(zggz[i].yingzi-2000)*0.15+150+25;
		}
		else if(zggz[i].yingzi>500)
		{
			zggz[i].geshui=(zggz[i].yingzi-500)*0.1+150+25;
		}
		else if(zggz[i].yingzi<500)
		{
			zggz[i].geshui=zggz[i].yingzi*0.05;
		}
		zggz[i].shizi=zggz[i].yingzi-zggz[i].geshui;//����ʵ�ù���
	
}
int read()//��ȡְ������
{
	FILE *fp;
	fp=fopen("gx.dat","rb");//���ļ�
	fseek(fp,0,SEEK_SET);//�ƶ�ָ��
	fseek(fp,0,SEEK_END);//ͬ��
    int number=ftell(fp)/sizeof(struct zggz);//���ֽڳ��ȳ��Խṹ�嵥λ���ȼ�Ϊ����
	n=number;
	fseek(fp,0,SEEK_SET);
	if(fp==NULL)
	{
		return -1;
	}
	fread((char*)zggz,sizeof(struct zggz),n,fp);//��ȡ����
	cout<<"Ŀǰ����"<<n<<"��ְ����Ϣ"<<endl;
	fclose(fp);
    return 0;
}
void find()//��ѯ
{
	char gonghao[100];
	cout<<"����Ҫ��ѯ��ְ����"<<endl;
	cin>>gonghao;//���빤��
	for(int i=0;i<n;i++)
	{
		if(strcmp(gonghao,zggz[i].gonghao)==0)//��ѯ�Ƿ���ƥ��Ĺ���
		{
			cout<<zggz[i].gonghao<<" "
		        <<zggz[i].xingming<<" "
		        <<zggz[i].ganggong<<" "
		        <<zggz[i].xingong<<" "
		        <<zggz[i].zhitie<<" "
		        <<zggz[i].jizi<<" "
		        <<zggz[i].yingzi<<" "
		        <<zggz[i].geshui<<" "
		        <<zggz[i].shizi
		        <<endl;
			break;
		}
		if(i==n-1)
		{
			cout<<"���޴���"<<endl;
		}
	}
}
void modify()//�޸�
{
	char gonghao[100];
	int i;
	cout<<"����Ҫ��ѯ��ְ����"<<endl;
	cin>>gonghao;//����Ҫ��ѯ�Ĺ���
	for(i=0;i<=n;i++)
	{
		if(strcmp(gonghao,zggz[i].gonghao)==0)//��ѯ�Ƿ���ƥ��Ĺ���//�����޸�
		{
			char q[100];
	        float w;
	        float e;
	        float r;
	        float t;
			cout<<"������������ţ�Ӧ�����ʣ���������˰��ʵ��������������Ϣ"<<endl;
			cin>>q>>w>>e>>r>>t;
			void grsds(char gonghao);//����grsds()������Ӧ�����ʣ���������˰��ʵ������
			strcpy(zggz[i].xingming,q);
			zggz[i].ganggong=w;
			zggz[i].xingong=e;
			zggz[i].zhitie=r;
			zggz[i].jizi=t;
		}
	}
}
void add()//���
{
	cout<<"������Ҫд���Ա����"<<endl;
	int num;
	cin>>num;
	
	for(int i=n;i<num+n;i++)
	{
		cout<<"��������ְ����Ϣ"<<endl;
	    cout<<"����"<<"����"<<"��λ����"<<"н������"<<"ְ�����"<<"��Ч����"<<endl;
		cin>>zggz[i].gonghao
	       >>zggz[i].xingming
	       >>zggz[i].ganggong
	       >>zggz[i].xingong
	       >>zggz[i].zhitie
	       >>zggz[i].jizi;
        grsds(i);
	}
	n=n+num;
}
void del()//ɾ��ָ��Ա������Ϣ
{
	char gonghao[100];
	cout<<"������Ҫɾ����Ա������"<<endl;
	cin>>gonghao;
	for(int i=0;i<n;i++)
	{
	    if(strcmp(gonghao,zggz[i].gonghao)==0)//��ѯ�Ƿ���ƥ��Ĺ���//����ɾ��
		{
			if(i!=n-1)
		{
			for(;i<n;i++)
			{
			    zggz[i].ganggong=zggz[i+1].ganggong;
			    zggz[i].geshui=zggz[i+1].geshui;
			    strcpy(zggz[i].gonghao,zggz[i+1].gonghao);
			    zggz[i].jizi=zggz[i+1].jizi;
			    zggz[i].shizi=zggz[i+1].shizi;
			    strcpy(zggz[i].xingming,zggz[i+1].xingming);
			    zggz[i].xingong=zggz[i+1].xingong;
			    zggz[i].yingzi=zggz[i+1].yingzi;
			    zggz[i].zhitie=zggz[i+1].zhitie;
			}
			n=n-1;//������Ӧ��һ
		}
			else
		{
			n=n-1;//������Ӧ��һ
		}

		}
	}
}
int write()//д��ְ������
{
	FILE *fp;
	fp=fopen("gx.dat","wb");
	if(fp==NULL)
	{
		return -1;
	}
	fwrite((char*)zggz,sizeof(struct zggz),n,fp);//д������
	fclose(fp);
}
void list()//�б�
{
	int i;
    for(i=0;i<n;i++)
	{
		cout<<zggz[i].gonghao<<" "
		<<zggz[i].xingming<<" "
		<<zggz[i].ganggong<<" "
		<<zggz[i].xingong<<" "
		<<zggz[i].zhitie<<" "
		<<zggz[i].jizi<<" "
		<<zggz[i].yingzi<<" "
		<<zggz[i].geshui<<" "
		<<zggz[i].shizi
		<<endl;
    }
}
int main()
{
    read();
	for(int i=0;i<7;)
	{
		
	    cout<<"���ѽ���ְ�����ʹ���ϵͳ"<<endl;
	    cout<<"������Ӧ���ֽ��в�����"<<endl;
	    cout<<"1.��ѯ"<<" "<<"2.�޸�"<<" "
		    <<"3.���"<<" "<<"4.ɾ��"<<" "
		    <<"5.����"<<" "<<"6.���"<<" "
		    <<"7.�˳�"<<endl;
	int p;
	cin>>p;
	switch(p)//���ѡ���ִ�к���
	{
	    case 1: 
			{
                system("cls");
				find();
				break;
			}
		case 2:
			{
				system("cls");
				modify();
				break;
			}
		case 3: 
			{
				system("cls");
				add();
				break;
			}
		case 4: 
			{
				system("cls");
				del();
				break;
			}
		case 5: 
			{
				system("cls");
				write();
				break;
			}
		case 6: 
			{
				system("cls");
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
