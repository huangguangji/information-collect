#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int welcome();                       /*  欢迎界面  */
int byebye();                        /*  离开界面  */


int registration_login_interface();  /*  注册登录界面  */
int registered_user();               /*  注册用户  */
int user_login();                    /*  用户登录  */


int main_interface(int a);           /*  主界面  */
int computing_time(int i);           /*  计时  */
int play_time(int i);                /*  游戏计时总时长  */
int learn_time(int i);               /*  学习计时总时长  */
int show(int i);                     /*  显示用户信息  */
int change_information(int i);       /*  修改用户信息  */
int change_name(int i);              /*  修改用户名  */
int change_password(int i);          /*  修改密码  */
int change_age(int i);               /*  修改年龄  */
int change_tel(int i);               /*  修改电话号码  */
int switch_user();                   /*  切换用户  */


int administrator();                 /*  管理员操作  */
int list_information();				 /*  列出所有用户信息  */
int logout_user();					 /*  注销用户  */
int leave_a_message();				 /*  给用户留言  */


/*  注册过的用户信息  */
struct userinfo
{
	char name[20];         /*  名字  */
	char password[20];     /*  密码  */
	int age;               /*  年龄  */
	char tel[11];          /*  电话  */
	float time_of_learn;   /*  学习时间  */
	float time_of_play;    /*  游戏时间  */
	int register_flag;     /*  用于判断是否存了用户信息 0无 1有  */
	int login_flag;        /*  用于判断用户是否登录  0否 1是  */
	char message[50];	   /*  留言  */
}user[5];

#endif