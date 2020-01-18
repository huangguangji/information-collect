#include "head.h"

int main(int argc, char *argv[])
{
	int i;
	welcome();

	for (i = 0; i < 5; i++)
	{
		user[i].time_of_learn = 0;
		user[i].time_of_play = 0;
		user[i].register_flag = 0;
		user[i].login_flag = 0;
		strcpy(user[i].message,"No message!");
	}
	
	//sleep(5);
	
	registration_login_interface();

	byebye();

	//sleep(5);
		
	putchar('\n');
	
	return 0;
}