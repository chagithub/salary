
#include<iostream>
#include<fstream>
using namespace std;
extern int n=0;//定义全局变量n（职工人数）
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
void grsds(int i)//求职工应发工资，个人所得税，实发工资
{
		zggz[i].yingzi=zggz[i].ganggong+zggz[i].xingong+zggz[i].zhitie+zggz[i].jizi;//计算应得工资
		if(zggz[i].yingzi>100000)//计算不同工资的对应个人所得税
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
		zggz[i].shizi=zggz[i].yingzi-zggz[i].geshui;//计算实得工资
	
}
int read()//读取职工数据
{
	FILE *fp;
	fp=fopen("gx.dat","rb");//打开文件
	fseek(fp,0,SEEK_SET);//移动指针
	fseek(fp,0,SEEK_END);//同上
    int number=ftell(fp)/sizeof(struct zggz);//总字节长度除以结构体单位长度即为人数
	n=number;
	fseek(fp,0,SEEK_SET);
	if(fp==NULL)
	{
		return -1;
	}
	fread((char*)zggz,sizeof(struct zggz),n,fp);//读取数据
	cout<<"目前已有"<<n<<"名职工信息"<<endl;
	fclose(fp);
    return 0;
}
void find()//查询
{
	char gonghao[100];
	cout<<"输入要查询的职工号"<<endl;
	cin>>gonghao;//输入工号
	for(int i=0;i<n;i++)
	{
		if(strcmp(gonghao,zggz[i].gonghao)==0)//查询是否有匹配的工号
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
			cout<<"查无此人"<<endl;
		}
	}
}
void modify()//修改
{
	char gonghao[100];
	int i;
	cout<<"输入要查询的职工号"<<endl;
	cin>>gonghao;//输入要查询的工号
	for(i=0;i<=n;i++)
	{
		if(strcmp(gonghao,zggz[i].gonghao)==0)//查询是否有匹配的工号//进行修改
		{
			char q[100];
	        float w;
	        float e;
	        float r;
	        float t;
			cout<<"重新输入除工号，应发工资，个人所得税，实发工资外其他信息"<<endl;
			cin>>q>>w>>e>>r>>t;
			void grsds(char gonghao);//调用grsds()函数求应发工资，个人所得税和实发工资
			strcpy(zggz[i].xingming,q);
			zggz[i].ganggong=w;
			zggz[i].xingong=e;
			zggz[i].zhitie=r;
			zggz[i].jizi=t;
		}
	}
}
void add()//添加
{
	cout<<"输入想要写入的员工数"<<endl;
	int num;
	cin>>num;
	
	for(int i=n;i<num+n;i++)
	{
		cout<<"依次输入职工信息"<<endl;
	    cout<<"工号"<<"姓名"<<"岗位工资"<<"薪级工资"<<"职务津贴"<<"绩效工资"<<endl;
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
void del()//删除指定员工的信息
{
	char gonghao[100];
	cout<<"输入想要删除的员工工号"<<endl;
	cin>>gonghao;
	for(int i=0;i<n;i++)
	{
	    if(strcmp(gonghao,zggz[i].gonghao)==0)//查询是否有匹配的工号//进行删除
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
			n=n-1;//人数对应减一
		}
			else
		{
			n=n-1;//人数对应减一
		}

		}
	}
}
int write()//写入职工数据
{
	FILE *fp;
	fp=fopen("gx.dat","wb");
	if(fp==NULL)
	{
		return -1;
	}
	fwrite((char*)zggz,sizeof(struct zggz),n,fp);//写入数据
	fclose(fp);
}
void list()//列表
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
		
	    cout<<"你已进入职工工资管理系统"<<endl;
	    cout<<"输入相应数字进行操作："<<endl;
	    cout<<"1.查询"<<" "<<"2.修改"<<" "
		    <<"3.添加"<<" "<<"4.删除"<<" "
		    <<"5.保存"<<" "<<"6.浏览"<<" "
		    <<"7.退出"<<endl;
	int p;
	cin>>p;
	switch(p)//相关选项的执行函数
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
