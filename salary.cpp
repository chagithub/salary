
#include<iostream>
#include<fstream>
using namespace std;
int n=0;//����ȫ�ֱ���n��ְ��������
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
};
void grsds()
{
	float a;
	zggz zggz3[50];
	ifstream in("gx.dat",ios::binary);//��
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳������൱��exit
	}
	for(int i=0;i<50;i++)
	{
		in.read((char*)&zggz3[i],sizeof(zggz3[i]));//��ȡ����
		zggz3[i].yingzi=zggz3[i].ganggong+zggz3[i].xingong+zggz3[i].zhitie+zggz3[i].jizi;//����Ӧ�ù���
		if(zggz3[i].yingzi>100000)//���㲻ͬ���ʵĶ�Ӧ��������˰
		{
			a=(zggz3[i].yingzi-100000)*0.45+8000+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz3[i].yingzi>80000)
		{
			a=(zggz3[i].yingzi-80000)*0.4+7000+6000+5000+3000+450+150+25;
		}
		else if(zggz3[i].yingzi>60000)
		{
			a=(zggz3[i].yingzi-60000)*0.35+6000+5000+3000+450+150+25;
		}
		else if(zggz3[i].yingzi>40000)
		{
			a=(zggz3[i].yingzi-40000)*0.3+5000+3000+450+150+25;
		}
		else if(zggz3[i].yingzi>20000)
		{
			a=(zggz3[i].yingzi-20000)*0.25+3000+450+150+25;
		}
		else if(zggz3[i].yingzi>5000)
		{
			a=(zggz3[i].yingzi-5000)*0.2+450+150+25;
		}
		else if(zggz3[i].yingzi>2000)
		{
			a=(zggz3[i].yingzi-2000)*0.15+150+25;
		}
		else if(zggz3[i].yingzi>500)
		{
			a=(zggz3[i].yingzi-500)*0.1+150+25;
		}
		else if(zggz3[i].yingzi<500)
		{
			a=zggz3[i].yingzi*0.05;
		}
		zggz3[i].shizi=zggz3[i].yingzi-a;//����ʵ�ù���
	}
}
void read()//��ȡְ������
{
	zggz zggz2[100];
	ifstream in("gx.dat",ios::binary);//���������ļ�������in���򿪶����������ļ�gx.dat
	if(!in)//�����ʧ�ܣ�in����0ֵ
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳������൱��exit
	}
	for(int i=0;i<100;i++)
	{
		if(in.eof())
		{
			in.close();
		}
		else
		{
			in.read((char*)&zggz2[i],sizeof(zggz2[i]));
			n=n+1;
		}
	}
}
void find()
{
	char gonghao[100];
	int i;
	zggz zggz4[50];
	cout<<"����Ҫ��ѯ��ְ����"<<endl;
	ifstream in("gx.dat",ios::binary);//��
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳������൱��exit
	}
	for(i=0;i<=gonghao[100];i++)
	{
		in.read((char*)&zggz4[i],sizeof(zggz4[i]));//��ȡ����
		cin>>gonghao;
		cout<<zggz4[gonghao[100]].gonghao<<" "
		<<zggz4[gonghao[100]].xingming<<" "
		<<zggz4[gonghao[100]].ganggong<<" "
		<<zggz4[gonghao[100]].xingong<<" "
		<<zggz4[gonghao[100]].zhitie<<" "
		<<zggz4[gonghao[100]].jizi<<" "
		<<zggz4[gonghao[100]].yingzi<<" "
		<<zggz4[gonghao[100]].geshui<<" "
		<<zggz4[gonghao[100]].shizi
		<<endl;
	}
	int choose;//�������˵��ĳ���   
    system("cls");
    cout<<"����1�������˵�\n"<<endl;
    cin>>choose;
    switch(choose)
    {
       case 1: break;                 
    }
}
void write()//д��ְ������
{
	zggz zggz1[50]={
		"0","a0",78941,5620.1,1232,444.4,0,0,0,
		"1","a1",2000,4000,1500,10000,0,0,0,
		"2","a2",4123,9895,3315,44200,0,0,0,
		"3","a3",15364.2,4512,4541.5,99871.2,0,0,0,
		"4","a4",22254.4,12156,78512,334.1,0,0,0,
		"5","a5",100,4.5,120,76.1,0,0,0,
		"6","a6",30,10,52,22.1,0,0,0,
		"7","a7",140,5820,99941,2103,0,0,0,
		"8","a8",7894.1,666.6,4521.2,741.3,0,0,0,
		"9","a9",11111,22222,33333,44444,0,0,0,
		"10","a10",45621,75231,20.1,7894,0,0,0,
		"11","a11",693.1,8524.2,7410,32657.9,0,0,0,
	};
	ofstream out("gx.dat",ios::binary);//��������ļ�������out���򿪶���������ļ�gx.dat
	if(!out)//�����ʧ�ܣ�out����0ֵ
	{
		cout<<"Cannot open output file.\n";
		abort();//�˳������൱��exit
	}
	for(int i=0;i<50;i++)
		out.write((char*)&zggz1[i],sizeof(zggz1[i]));
	out.close();
}
void list()
{
	int i;
	zggz zggz5[50];
	cout<<"����Ҫ��ѯ��ְ����"<<endl;
	ifstream in("gx.dat",ios::binary);//��
	if(!in)
	{
		cout<<"Cannot open input file.\n";
		abort();//�˳������൱��exit
	}
	for(i=0;i<50;i++)
	{
		in.read((char*)&zggz5[i],sizeof(zggz5[i]));//��ȡ����
		cout<<zggz5[i].gonghao<<" "
		<<zggz5[i].xingming<<" "
		<<zggz5[i].ganggong<<" "
		<<zggz5[i].xingong<<" "
		<<zggz5[i].zhitie<<" "
		<<zggz5[i].jizi<<" "
		<<zggz5[i].yingzi<<" "
		<<zggz5[i].geshui<<" "
		<<zggz5[i].shizi
		<<endl;
	}
	int choose;//�������˵��ĳ���   
    system("cls");
    cout<<"����1�������˵�\n"<<endl;
    cin>>choose;
    switch(choose)
    {
       case 1: break;                 
    }
}
int main()
{
	while(1)//��ѭ��
	{
		system("cls");
	    cout<<"���ѽ���ְ�����ʹ���ϵͳ"<<endl;
	    cout<<"������Ӧ���ֽ��в�����"<<endl;
	    cout<<"1.��ѯ"<<" "<<"2.�޸�"<<" "
		    <<"3.���"<<" "<<"4.ɾ��"<<" "
		    <<"5.����"<<" "<<"6.���"<<" "
		    <<"7.�˳�"<<endl;
	int n;
	cin>>n;
	switch(n)//���ѡ���ִ�к���
	{
		case 1: find();break;
		case 2: modify();break;
		case 3: add();break;
		case 4: del();break;
		case 5: write();break;
		case 6: list();break;
		case 7: exit(0);
		default: cout<<"�������������(1~7)"<<endl;
	}
	}
	return 0;
}

