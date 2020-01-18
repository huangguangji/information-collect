#include "head.h"

/*  主界面  */
int main_interface(int i)
{
	char num;

	while (1)
	{
		printf("======================================================\n");
		printf("\t\t1.computing_time\n");
		printf("\t\t2.show\n");
		printf("\t\t3.change information\n");
		printf("\t\t4.return\n");
		printf("\t\t5.switch_user\n");
		printf("\t\t6.exit user\n");
		printf("======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1') {
			computing_time(i);
		} else if (num == '2') {
			show(i);
		} else if (num == '3') {
			change_information(i);
		} else if (num == '4') {
			break;
		} else if (num == '5') {
			switch_user();
		} else if (num == '6') {
			user[i].login_flag = 0;
			break;
		} else {
			continue;
		}
	}

	return 0;
}

/*  计时  */
int computing_time(int i)
{
	char num;

	while (1)
	{
		printf("======================================================\n\n\n\n\n");
		printf("\t\t1. play time\n");
		printf("\t\t2. learn time\n");
		printf("\t\t3. return\n");
		printf("\n\n\n======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1')
		{
			play_time(i);
		}

		else if (num == '2')
		{
			learn_time(i);
		}

		else if (num == '3')
		{
			break;
		}

		else
		{
			printf("Please try again!\n");
		}
	}

	return 0;	
}

 /*  游戏计时  */
int play_time(int i)
{
	char num;
	time_t start,end;   /*存储开始的时间，存储结束的时间*/

	while (1)
	{
		printf("=========================play=========================\n\n\n\n\n");
		printf("\t\t1. start\n");
		printf("\t\t2. stop\n");
		printf("\t\t3. return\n");
		printf("\n\n\n======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1')
		{

			time(&start);

			while (1)
			{
				printf("=========================play=========================\n\n\n\n\n");
				printf("\t\t Start timing!\n\n\n\n");
				printf("(Enter 2 to stop!)\n");
				printf("======================================================\n");

				num = getchar();

				while (getchar() != '\n');

				if (num == '2')
				{
					printf("=========================play=========================\n\n\n\n\n");
					printf("\t\t Closing time!\n");
					printf("\n\n\n\n======================================================\n");

					time(&end);

					user[i].time_of_play += difftime(end,start);  //获取时间差

					break;
				}

				else
				{
					printf("Please stop first!\n");
				}
			}
		}

		else if (num == '2')
		{
			printf("Please start!\n");
		}

		else if (num == '3')
		{
			break;
		}
		else
		{
			printf("Please try again!\n");
			continue;
		}
	}

	return 0;
}

/*  学习计时  */
int learn_time(int i)
{
	char num;
	time_t start,end;   /*存储开始的时间，存储结束的时间*/

	while (1)
	{
		printf("=========================learn========================\n\n\n\n\n");
		printf("\t\t1. start\n");
		printf("\t\t2. stop\n");
		printf("\t\t3. return\n");
		printf("\n\n\n======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1')
		{
			printf("=========================learn========================\n\n\n\n\n");
			printf("\t\t Start timing!\n\n\n\n");
			printf("(Enter 2 to stop!)\n");
			printf("======================================================\n");

			time(&start);

			while (1)
			{
				num = getchar();

				while (getchar() != '\n');

				if (num == '2')
				{
					printf("=========================learn========================\n\n\n\n\n");
					printf("\t\t Closing time!\n");
					printf("\n\n\n\n======================================================\n");

					time(&end);

					user[i].time_of_learn += difftime(end,start);  //获取时间差

					break;
				}

				else
				{
					printf("Please stop first!\n");
				}
			}
		}

		else if (num == '2')
		{
			printf("Please start!\n");
		}

		else if (num == '3')
		{
			break;
		}
		else
		{
			printf("Please try again!\n");
			
			continue;
		}
	}

	return 0;
}

 /*  显示用户信息  */
int show(int i)
{
	char str;
	
	while (1)
	{
		printf("======================================================\n");
		printf("\t\tname:%s\n",user[i].name);
		printf("\t\tpassword:%s\n", user[i].password);
		printf("\t\tage:%d\n", user[i].age);
		printf("\t\ttel:%s\n", user[i].tel);
		printf("\t\ttime_of_learn:%f\n", user[i].time_of_learn);
		printf("\t\ttime_of_play:%f\n", user[i].time_of_play);
		printf("\t\tmessage:%s\n", user[i].message);
		printf("(Enter q to exit!)\n");
		printf("======================================================\n");

		str = getchar();

		while (getchar() != '\n');

		if (str == 'q')
		{
			break;
		}

	}

	return 0;
}

/*  修改用户信息  */
int change_information(int i)
{
	char num;
	while (1)
	{
		printf("======================================================\n\n");
		printf("\t\t1.change your name\n");
		printf("\t\t2.change your password\n");
		printf("\t\t3.change your age\n");
		printf("\t\t4.change your tel\n");
		printf("\t\t5.return\n");
		printf("\n======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1')
		{
			change_name(i);
		}

		else if (num == '2')
		{
			change_password(i);
		}

		else if (num == '3')
		{
			change_age(i);
		}

		else if (num == '4')
		{
			change_tel(i);
		}

		else if (num == '5')
		{
			break;
		}

		else
		{
			continue;
		}  /*end of if (num == '1')*/



	}
	
	return 0;
}

 /*  修改用户名  */
int change_name(int i)
{
	char new_name[20];

	printf("Please enter a new name:");
	fgets(new_name, 20, stdin);
	new_name[strlen(new_name) - 1] = '\0';

	strcpy(user[i].name, new_name);	

	return 0;
}  

 /*  修改密码  */ 
int change_password(int i)                 
{
	char new_password[20];

	printf("Please enter a new password:");
	fgets(new_password, 20, stdin);

	new_password[strlen(new_password) - 1] = '\0';

	strcpy(user[i].password, new_password);

	return 0;
} 

 /*  修改年龄  */
int change_age(int i)
{
	printf("Please enter your age:");
	scanf("%d",&user[i].age);

	while (getchar() != '\n');

	return 0;
}

/*  修改电话号码  */  
int change_tel(int i) 
{
	char new_tel[20];

	printf("Please enter a new tel:");
	fgets(new_tel, 20, stdin);

	new_tel[strlen(new_tel) - 1] = '\0';

	strcpy(user[i].tel, new_tel);

	return 0;
}   

/*  切换用户*/
int switch_user()
{
	char name[20];
	int j;
	int flag = 0;  /*用于判断是否成功切换  0失败  1成功  */
	int i;

	printf("Logged in users have:");

	for (i = 0; i < 5; i++)
	{
		if (user[i].login_flag == 1)
		{
			printf("\t%s", user[i].name);
		}
	}

	putchar('\n');



	printf("Please enter the user you want to switch:");
	fgets(name, 20, stdin);

	//while (getchar() != '\n');

	name[strlen(name) - 1] = '\0';

	for (j = 0; j < 5; j++)
	{
		if (strcmp(name, user[j].name) == 0)
		{
			if (user[j].login_flag == 1)
			{
				flag = 1;
			
				main_interface(j);
			}
		}
	}

	if (flag == 0)
	{
		printf("The user does not exist or is not logged in！Please try again!\n");
	}

	return 0;
}                             