#include "head.h"

/*  注册登录界面  */
int registration_login_interface()
{
	char num;

	
	while (1)
	{
		printf("======================================================\n\n\n\n");
		printf("\t\t1. register\n");
		printf("\t\t2. login\n");
		printf("\t\t3. exit\n");
		printf("\t\t4. switch user\n");
		printf("\n\n\n======================================================\n");

		num = getchar();

		if (num == '1')
		{
			registered_user();
		}

		else if (num == '2')
		{
			user_login();
		}
		else if (num == '3')
		{
			break;
		}

		else if (num == '4')
		{
			switch_user();
		}

		else 
		{
			printf("Please enter again!\n");
			continue;
		}  /*end of if (num == '1')*/
	}
	
	return 0;
}

/*注册用户*/
int registered_user()
{
	int i;
	int flag = 1;  /*用于判断是否存了5个人的信息  0否 1是*/

	for (i = 0; i < 5; i++)
	{
		if (user[i].register_flag == 0)
		{
			flag = 0;
			user[i].register_flag = 1;

			break;
		}
	}

	if (flag == 1)
	{
		printf("User limit reached!Please contact the administrator!\n");

		return 0;
	}

	while (getchar() != '\n');

	printf("Please enter registration information!\n");

	printf("Please enter your name:");
	fgets(user[i].name, 20, stdin);
	user[i].name[strlen(user[i].name)- 1] = '\0';

	printf("Please enter your password:");
	fgets(user[i].password, 20, stdin);
	user[i].password[strlen(user[i].password)- 1] = '\0';

	printf("Please enter your age:");
	scanf("%d",&user[i].age);

	while(getchar() != '\n');

	printf("Please enter your tel:");
	fgets(user[i].tel, 11, stdin);
	user[i].tel[strlen(user[i].tel)- 1] = '\0';

	return 0;
}

/*  用户登录  */
int user_login()
{
	char enter_name[20];
	char enter_password[20];
	int i;
	int successful_login = 0; /*  用于判断是否成功登录  0失败  1成功  */

	while (getchar() != '\n');

	printf("Please enter user information!\n");

	printf("Please enter your user name:");
	fgets(enter_name, 20, stdin);
	enter_name[strlen(enter_name) - 1] = '\0';

	printf("Please enter your password:");
	fgets(enter_password, 20, stdin);
	enter_password[strlen(enter_password) - 1] = '\0';

	for (i = 0; i < 5; i++)
	{
		if (strcmp(enter_name, user[i].name) == 0)
		{
			if (strcmp(enter_password, user[i].password) == 0)
			{
				if (user[i].register_flag == 1)
				{
					printf("======================================================\n\n\n\n");
					printf("\t\tSuccessful login!\n");
					printf("\n\n\n======================================================\n");

					user[i].login_flag = 1;
					successful_login = 1;

					main_interface(i);
				}

			}
		}
	}

	if (strcmp(enter_name,"www") == 0)
	{
		if (strcmp(enter_password,"123456") == 0)
		{
			printf("======================================================\n\n\n\n");
			printf("\t\tAdministrator login!\n");
			printf("\n\n\n======================================================\n");

			administrator();
			
			successful_login = 1;
		}
	}
	
	if (successful_login == 0)
	{
		printf("The user name or password error you entered!Please login again!\n");
	} 
	
	return 0;
}