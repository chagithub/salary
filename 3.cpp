
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
	FILE*fp;
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
	fclose(fp);
    return 0;
}
void find()//��ѯ
{
	char gonghao[100];
	cout<<"����Ҫ��ѯ��ְ����"<<endl;
	cin>>gonghao;//���빤��
	for(int i=0;i<100;i++)
	{
		if(gonghao[100]==zggz[i].gonghao[100])
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
		else
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
	ifstream in("gx.dat",ios::binary);//��
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳������൱��exit
	}
	for(i=0;i<=n;i++)
	{
		in.read((char*)&zggz[i],sizeof(zggz[i]));//��ȡ����
		cin>>gonghao;//����Ҫ��ѯ�Ĺ���
		if(gonghao==zggz[i].gonghao)//�����޸�
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
	in.close();
}
void add()//���
{
	cout<<"������Ҫд���Ա����"<<endl;
	int num;
	cin>>num;
	cout<<"��������ְ����Ϣ"<<endl;
	cout<<"����"<<"����"<<"��λ����"<<"н������"<<"ְ�����"<<"��Ч����"<<endl;
	for(int i=0;i<num;i++)
	{
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
		system("cls");
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
		case 1: find();break;
		case 2: modify();break;
		case 3: add();break;
	
		case 5: write();break;
		case 6: list();break;
		case 7: i=7;
		default: cout<<"�������������(1~7)"<<endl;
	}
	}
	return 0;
}

