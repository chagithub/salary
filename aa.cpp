/*************************************************
Copyright (C), 1988-1999, Huawei Tech. Co., Ltd.
File name: Staff information management system // 文件名
Author: 侯泽宇 Version: 1.0 Date: 2018.6.29 // 作者、版本及完成日期
Description: 
进行对职工信息的1.查询 2.修改 3.添加 4.删除 5.保存 6.浏览等操作。
//用于详细说明此程序文件完成的主要功能，与其他模块或函数的接口，
//输出值、取值范围、含义及参数间的控制、顺序、独立或依赖等关系
read()读取数据、find()查询、modify()修改、add()添加、del()删除、write()保存、list()浏览
Others: 该程序需要事先在本机上建立gx.dat文件// 其它内容的说明
Function List: // 主要函数列表，每条记录应包括函数名及功能简要说明
1. read()读取数据 2. find()查询 3. modify()修改 4. add()添加 5. del()删除 6. write()保存 7. list()浏览
History: // 修改历史记录列表，每条修改记录应包括修改日期、修改者及修改内容简述
1. Date:2018.6.29
Author:侯泽宇
Modification:进行初次排版
2. Date:2018.7.5
Author:侯泽宇
Modification:进行最终排版
*************************************************/
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
extern int n=0;//定义全局变量n（职工人数）
struct zggz//定义职工信息结构体数组
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
Function: grsds // 函数名称
Description: 求职工应发工资，个人所得税，实发工资 // 函数功能、性能等的描述
Calls: 无// 被本函数调用的函数清单
Called By: find()、list()、modify()// 调用本函数的函数清单
Input: 无// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: payable_wages （应发工资） personal_income_tax （个人所得税）salary_paid （实发工资）// 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void grsds(int i)//求职工应发工资，个人所得税，实发工资
{
		zggz[i].payable_wages=zggz[i].post_salary+zggz[i].salary_scale
			                  +zggz[i].job_allowance+zggz[i].performance_pay;//计算应得工资
		if(zggz[i].payable_wages>100000)//计算大于十万的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-100000)*0.45
				                        +8000+7000+6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>80000)//计算大于八万的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-80000)*0.4
				                        +7000+6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>60000)//计算大于六万的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-60000)*0.35
				                        +6000+5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>40000)//计算大于四万的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-40000)*0.3
				                        +5000+3000+450+150+25;
		}

		else if(zggz[i].payable_wages>20000)//计算大于两万的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-20000)*0.25
				                        +3000+450+150+25;
		}

		else if(zggz[i].payable_wages>5000)//计算大于五千的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-5000)*0.2
				                        +450+150+25;
		}

		else if(zggz[i].payable_wages>2000)//计算大于两千的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-2000)*0.15
				                        +150+25;
		}

		else if(zggz[i].payable_wages>500)//计算大于五百的工资对应个人所得税
		{
			zggz[i].personal_income_tax=(zggz[i].payable_wages-500)*0.1
				                        +150+25;
		}

		else if(zggz[i].payable_wages<500)//计算工资在五百以内的对应个人所得税
		{
			zggz[i].personal_income_tax=zggz[i].payable_wages*0.05;
		}

		zggz[i].salary_paid=zggz[i].payable_wages-zggz[i].personal_income_tax;//计算实得工资
		printf("%g   %g   %g",zggz[i].payable_wages,zggz[i].personal_income_tax,zggz[i].salary_paid);
		//输出计算的三个数据
}
/*************************************************
Function: read // 函数名称
Description: 读取职工数据 // 函数功能、性能等的描述
Calls: 无// 被本函数调用的函数清单
Called By: main() // 调用本函数的函数清单
Input: 无// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 无// 对输出参数的说明。
Return: 0// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
int read()//读取职工数据
{
        FILE *fp;
        fp=fopen("gx.dat","a+");//打开文件
        fseek(fp,0,SEEK_SET);//移动指针
        fseek(fp,0,SEEK_END);//同上
        int number=ftell(fp)/sizeof(struct zggz);//总字节长度除以结构体单位长度即为人数
        n=number;//将所得人数赋值给n
        fseek(fp,0,SEEK_SET);
        if(fp==NULL)//打开失败
        {
	        return -1;
        }
        fread((char*)zggz,sizeof(struct zggz),n,fp);//读取数据
        fclose(fp);//关闭文件
        return 0;
}
/*************************************************
Function: find // 函数名称
Description: 查询指定工号的员工信息// 函数功能、性能等的描述
Calls: grsds()// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input: char job_number[100] 此为要查询的员工的相关工号，用来跟文件记录比较，找到匹配的员工
// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 工号：zggz[i].job_number 姓名：zggz[i].name
        岗位工资：zggz[i].post_salary 薪级工资：zggz[i].salary_scale
        职务津贴：zggz[i].job_allowance 绩效工资：zggz[i].performance_pay
        // 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void find()//查询
{
	char job_number[100];
	printf("输入要查询的职工工号\n");
	scanf("%s",job_number);//输入工号
	for(int i=0;i<n;i++)
	{
		if(strcmp(job_number,zggz[i].job_number)==0)//查询是否有匹配的工号
		{
		        printf("所查询的职工信息：\n");
		        printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
		        printf("%s     %s   %g    %g    %g    %g   "
				,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
				,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
                        grsds(i);//调用grsds()函数求应发工资，个人所得税和实发工资并输出
		        printf("\n");//换行
		        break;
		}
		if(i==n-1)//表示最后一个数组的数据也不匹配，即文件内无相关职工记录
		{
		        printf("查无此人\n");
		}
	}
}
/*************************************************
Function: modify // 函数名称
Description: 修改指定工号的员工信息// 函数功能、性能等的描述
Calls: grsds()// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input: char job_number[100] 此为要修改的员工的相关工号，用来跟文件记录比较，找到匹配的员工
// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 工号：zggz[i].job_number 姓名：zggz[i].name
        岗位工资：zggz[i].post_salary 薪级工资：zggz[i].salary_scale
        职务津贴：zggz[i].job_allowance 绩效工资：zggz[i].performance_pay
        // 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void modify()//修改
{
	char job_number[100];
	printf("继续修改，请选1，退出请选2\n");
	int p;
	scanf("%d",&p);
	switch(p)//相关选项的执行函数
	{
		  case 1: 
		{
			printf("修改完成后需保存才有效\n");
			printf("输入要修改的职工工号\n");
			scanf("%s",job_number);//输入工号
			for(int i=0;i<n;i++)
			{
			if(strcmp(job_number,zggz[i].job_number)==0)//查询是否有匹配的工号//进行修改
			{
		        printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
		        printf("%s     %s   %g    %g    %g    %g   "
				      ,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
				      ,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		        grsds(i);//调用grsds()函数求应发工资，个人所得税和实发工资并输出
				printf("\n");//换行
		        printf("输入对应数字选项进行修改 1.姓名，2.岗位工资，3.薪级工资，4.职务津贴，5.绩效工资\n");
		        printf("也可输入6进行全部修改\n");
		        int t;
		        scanf("%d",&t);
		        switch(t)//相关选项的执行函数
		        {
		            case 1: 
						{
                                printf("重新输入姓名\n");
                                scanf("%s",zggz[i].name);
                                break;
						}
		            case 2: 
						{
                                printf("重新输入岗位工资\n");
                                scanf("%f",&zggz[i].post_salary);
                                break;
						}		        
		            case 3: 
						{
                                printf("重新输入薪级工资\n");
                                scanf("%f",&zggz[i].salary_scale);
                                break;
						}
		            case 4: 
						{
                                printf("重新输入职务津贴\n");
                                scanf("%f",&zggz[i].job_allowance);
                                break;
						}
		            case 5: 
						{
                                printf("重新输入绩效工资\n");
                                scanf("%f",&zggz[i].performance_pay);
                                break;
						}
		            case 6: 
						{
                                printf("重新输入  姓名，岗位工资，薪级工资，职务津贴，绩效工资\n");
                                scanf("%s",zggz[i].name);
                                scanf("%f",&zggz[i].post_salary);
                                scanf("%f",&zggz[i].salary_scale);
                                scanf("%f",&zggz[i].job_allowance);
                                scanf("%f",&zggz[i].performance_pay);
                                break;
						}
		        }
		        printf("修改后的职工信息：\n");
		        printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
		        printf("%s     %s   %g    %g    %g    %g   "
			        ,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
			        ,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		        grsds(i);//调用grsds()函数求应发工资，个人所得税和实发工资并输出
		        break;
		}
		if(i==n-1)//表示最后一个数组的数据也不匹配，即文件内无相关职工记录
		{
		        printf("查无此人\n");
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
Function: add // 函数名称
Description: 添加员工信息// 函数功能、性能等的描述
Calls: grsds()// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input:  int num （要添加的员工数）工号：zggz[i].job_number 姓名：zggz[i].name
        岗位工资：zggz[i].post_salary 薪级工资：zggz[i].salary_scale
        职务津贴：zggz[i].job_allowance 绩效工资：zggz[i].performance_pay
        // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 无// 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void add()//添加
{
	printf("添加完成后需保存才有效\n");
	printf("目前已有的员工工号\n");
	for(int i=0;i<n;i++)
	{
		printf("%s  ",zggz[i].job_number);
	}
	printf("继续添加，请选1，退出请选2\n");
	int p;
	scanf("%d",&p);
	switch(p)//相关选项的执行函数
	{
		  case 1: 
		{
			printf("输入想要写入的员工数\n");
	        int num;
	        scanf("%d",&num);//输入要增加的人数
	        for(int i=n;i<num+n;i++)//通过for循环依次输入新增职工信息
			{
	        printf("依次输入职工信息\n");
	        printf("工号 , 姓名 , 岗位工资 , 薪级工资 , 职务津贴 , 绩效工资\n");
	        scanf("%s",zggz[i].job_number);
	        scanf("%s",zggz[i].name);
	        scanf("%f",&zggz[i].post_salary);
	        scanf("%f",&zggz[i].salary_scale);
	        scanf("%f",&zggz[i].job_allowance);
	        scanf("%f",&zggz[i].performance_pay);
			}
	        n=n+num;//及时更新人数        
		}
		  case 2:
		{
		    break;
		}
	}
}
/*************************************************
Function: del // 函数名称
Description: 删除指定工号的员工信息// 函数功能、性能等的描述
Calls: 无// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input: char job_number[100] 此为要上删除的员工的相关工号，用来跟文件记录比较，找到匹配的员工
       // 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 无// 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void del()//删除指定员工的信息
{
	char job_number[100];
	printf("继续删除，请选1，退出请选2\n");
	int p;
	scanf("%d",&p);
	switch(p)//相关选项的执行函数
	{
		  case 1: 
		{
			printf("删除完成后需保存才有效\n");
			printf("输入想要删除的员工工号\n");
			scanf("%s",job_number);//输入工号
			for(int i=0;i<n;i++)
		{
			if(strcmp(job_number,zggz[i].job_number)==0)//查询是否有匹配的工号//进行删除
		{
		        if(i!=n-1)//如果该员工不是最后一个
		    {
			    for(;i<n;i++)//for循环将后一个数组覆盖掉前一个数组
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
		        n=n-1;//人数对应减一
		    }
		        else//如果该员工是最后一个
		    {
		        n=n-1;//人数对应减一
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
Function: write // 函数名称
Description: 保存写入的职工数据// 函数功能、性能等的描述
Calls: 无// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input: 无// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 无// 对输出参数的说明。
Return: -1// 函数返回值的说明
Others: 必须在每次文件内容变动后运行此函数// 其它说明
*************************************************/
int write()//保存写入的职工数据
{
	FILE *fp;
	fp=fopen("gx.dat","wb");//打开文件
	if(fp==NULL)//打开失败
	{
		return -1;
	}
	fwrite((char*)zggz,sizeof(struct zggz),n,fp);//写入数据
	fclose(fp);//关闭文件
}
/*************************************************
Function: list // 函数名称
Description: 显示所有的员工信息// 函数功能、性能等的描述
Calls: grsds()// 被本函数调用的函数清单
Called By: main()// 调用本函数的函数清单
Input: 无// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 工号：zggz[i].job_number 姓名：zggz[i].name
        岗位工资：zggz[i].post_salary 薪级工资：zggz[i].salary_scale
        职务津贴：zggz[i].job_allowance 绩效工资：zggz[i].performance_pay
        // 对输出参数的说明。
Return: 无// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
void list()//列表
{
        int i;
        printf("所有职工信息：\n");
        printf("工号 姓名 岗位工资 薪级工资 职务津贴 绩效工资 应发工资 个人所得税 实发工资\n");
        for(i=0;i<n;i++)//通过for循环依次输出所有职工信息
	{
		printf("%s     %s   %g    %g    %g    %g   "
			,zggz[i].job_number,zggz[i].name,zggz[i].post_salary
			,zggz[i].salary_scale,zggz[i].job_allowance,zggz[i].performance_pay);
		grsds(i);
		//以上两个函数共同运行，输出职工全部信息
		printf("\n");//换行
	}
}
/*************************************************
Function: main // 函数名称
Description: 系统的主函数，通过在主函数进行操作，执行系统的相关功能// 函数功能、性能等的描述
Calls: find()、modify()、add()、del()、write()、list() // 被本函数调用的函数清单
Called By: 无// 调用本函数的函数清单
Input: int p 该数字为switch语句的选项数字，输入不同数字可执行不同的功能
// 输入参数说明，包括每个参数的作用、取值说明及参数间关系。
Output: 无// 对输出参数的说明。
Return: 0// 函数返回值的说明
Others: 无// 其它说明
*************************************************/
int main()
{
        read();//执行read函数读取文件信息
        for(int i=0;i<7;)
	{
	        printf("\n"); // 主页模板
	        printf("\n");
	        printf("        ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统  ###\n");
	        printf("\n");
	        printf("\n");
	        printf("        目前已有 ");
	        printf("%d",n);
	        printf(" 名职工信息\n");
	        printf("\n");
	        printf("        请选择 <1 - 7> :\n");
	        printf("        ================================================================\n");
	        printf("        |        1. 查询职工工资记录                                   |\n");
	        printf("        |        2. 修改职工工资记录                                   |\n");
	        printf("        |        3. 添加职工工资记录                                   |\n");
	        printf("        |        4. 删除职工工资记录                                   |\n");
	        printf("        |        5. 保存数据到文件                                     |\n");
	        printf("        |        6. 浏览职工记录                                       |\n");
	        printf("        |        7. 退出系统                                           |\n");
	        printf("        ================================================================\n");
	        printf("\n");
	        printf("         你的选择是：\n");
	int p;
	scanf("%d",&p);
	switch(p)//相关选项的执行函数
	{
	        case 1: 
			{
                                system("cls");//使显示页面只显示find()函数操作内容
                                find();
                                break;
			}
	        case 2:
			{
                                system("cls");//使显示页面只显示modify()函数操作内容
                                modify();
                                break;
			}
	        case 3: 
			{
                                system("cls");//使显示页面只显示add()函数操作内容
                                add();
                                break;
			}
	        case 4: 
			{
                                system("cls");//使显示页面只显示del()函数操作内容
                                del();
                                break;
			}
	        case 5: 
			{
                                system("cls");//使显示页面只显示write()函数操作内容
                                write();
                                break;
			}
	        case 6: 
			{
                                system("cls");//使显示页面只显示list()函数操作内容
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