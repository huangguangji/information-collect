 #include "head.h"

/*  管理员  */
int administrator()
{
	char num;

	while (1)
	{
		printf("======================================================\n\n\n");
		printf("\t\t1.List information\n");
		printf("\t\t2.Logout user\n");
		printf("\t\t3.leave a message \n");
		printf("\t\t4.return\n");
		printf("\n======================================================\n");

		num = getchar();

		while (getchar() != '\n');

		if (num == '1')
		{
			list_information();
		}

		else if (num == '2')
		{
			logout_user();
		}

		else if (num == '3')
		{
			leave_a_message();
		}

		else if (num == '4')
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

 /*  列出所有用户信息  */
int list_information()
{
	int i;

	for (i = 0; i < 5; i++)
	{
		if (user[i].register_flag == 1)
		{
			printf("======================================================\n\n\n");
			printf("\t\tname:%s\n",user[i].name);
			printf("\t\tage:%d\n",user[i].age);
			printf("\t\ttel:%s\n",user[i].tel);
			printf("\t\ttime_of_learn:%f\n",user[i].time_of_learn);
			printf("\t\ttime_of_play:%f\n",user[i].time_of_play);
			printf("\n======================================================\n");
		}
	}

	return 0;
}

/*  注销用户  */
int logout_user()
{
	int i;
	char name[20];
	int flag = 0;

	while (1)
	{
		printf("Please enter the user you want to delete:");

		fgets(name, 20, stdin);
		name[strlen(name) - 1] = '\0';

		for (i = 0; i < 5; i++)
		{
			if (strcmp(name, user[i].name) == 0)
			{
				flag = 1;
				user[i].register_flag = 0;
				user[i].login_flag = 0;
				user[i].time_of_play = 0;
				user[i].time_of_learn = 0;

				printf("Deleted successfully\n");
				printf("======================================================\n\n\n\n");
				printf("\t\tDeleted successfully\n");
				printf("\n\n======================================================\n");

				break;
			}
		}

		if (flag == 0)
		{
			printf("======================================================\n\n\n\n");
			printf("\t\tPlease input correctly!\n");
			printf("\n\n======================================================\n");

			continue;
		}
		else 
		{
			break;
		}
	}

	return 0;
}

 /*  给用户留言  */
int leave_a_message()
{
	int i;
	char name[20];
	char message[50];
	int flag = 0;

	while (1)
	{
		printf("Please enter a name:");
		fgets(name, 20, stdin);
		name[strlen(name) - 1] = '\0';

		for (i = 0; i < 5; i++)
		{
			if (strcmp(name, user[i].name) == 0)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			printf("======================================================\n\n\n\n");
			printf("\t\tPlease input correctly!\n");
			printf("\n\n======================================================\n");
			continue;
		}
		else 
		{
			break;
		}  /*end of if (flag == 0)*/
	}

	printf("Please enter a message:");
	fgets(message, 50, stdin);;
	message[strlen(message) - 1] = '\0';

	strcpy(user[i].message, message);

	return 0;
}