
///////////////////////////////                    In the name of God                    /////////////////////////////////////

// tozihat:
// 1.man az gets_s be gaye fgets estefade kardam choon fgets \n ra dar reshte be hesab miavard vali gets_s injoor nabood
// 2.baraye save shodane etelaat dar file hatman bayad az gozineh <<exit>> estefadeh shavad


#include <stdio.h>
//#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
/*#ifdef _MSC_BUILD
#define scanf scanf_s
#endif*/ // _MSC_BUILD

#pragma warning (disable:4996)

#define sleeptime 4200
#define showtime 220

struct people {
	char firstname[30];
	char lastname[30];
	char nationalcode[15];
	char username[30];
	char password[30];
	char email[30];
	char bloodtype[5];
	int age;
	float height;
	float weight;
	int health_code;
	int dead_flag;
	time_t test[100];
	time_t place[100];
	time_t meet[100];
	char met_person_nc[100][30];
	char met_person_name[100][30];
	char met_place[100][30];
	char met_place_status[100][30];
	int ttest;
	int tplace;
	int tmeet;
	int temp_health_code[100];
	int met_person_health_code[100];
} people;

struct people user[100];

struct job_owner {
	char firstname[30];
	char lastname[30];
	char nationalcode[15];
	char username[30];
	char password[30];
	char email[30];
	char placename[20];
	char city[20];
	char region[20];
	char place_code[10];
	time_t reg;
} job_owner;

struct job_owner shop_owner[100];

struct manager {
	char username[30];
	char nationalcode[15];
	char password[30];
	char email[30];
} manager;

struct manager admin;

struct clinic {
	char name[30];
	char city[20];
	char region[20];
} clinic;

struct clinic hospital[50];

FILE* fp;

void File_to_struct();
void Lock();
void Login();
void Admin_menu();
void User_menu(int index);
void Shop_owner_menu(int index);
void New_account();
void Forgetpass();
void Point_about_coronr();
void EXit();

int countofusers = 0;
int countofshop_owners = 0;
int countofadmin = 0; // we only have one admin
int countofhospitals = 0;
//int countofdead = 0;

int main() {
	File_to_struct();
	Lock();
}
void File_to_struct() {


	if (fopen("users.bin", "rb") == NULL) {
		int a = -1;
		fp = fopen("users.bin", "wb");
		fwrite(&a, sizeof(int), 1, fp);
		fclose(fp);
	}
	else{
		fp = fopen("users.bin", "rb");
		fread(&countofusers, sizeof(int), 1, fp);
		fread(&user, sizeof(struct people), countofusers + 1, fp);
		fclose(fp);
	}
	time_t now1 = time(NULL);
	for (int i = 0;i < countofusers;i++) {
		if ((user[i].health_code > 1) && (user[i].health_code < 4) && (now1 - user[i].test[user[i].ttest] > 604800)) {
			user[i].health_code--;
			user[i].ttest++;
			user[i].test[user[i].ttest] = now1;
		}
	}
	if (fopen("shop_owners.bin", "rb") == NULL) {
		int a = -1;
		fp = fopen("shop_owners.bin", "wb");
		fwrite(&a, sizeof(int), 1, fp);
		fclose(fp);
	}
	else {
		fp = fopen("shop_owners.bin", "rb");
		fread(&countofshop_owners, sizeof(int), 1, fp);
		fread(&shop_owner, sizeof(struct job_owner), countofshop_owners + 1, fp);
		fclose(fp);
	}
	time_t now2 = time(NULL);
	for (int i = 0;i <= countofshop_owners;i++) {
		if ((strcmp(shop_owner[i].place_code, "Red") == 0) && (now2 - shop_owner[i].reg > 1209600)) {
			strcpy(shop_owner[i].place_code, "White");
		}
	}
	if (fopen("admin.bin", "rb") == NULL) {
		int a = -1;
		fp = fopen("admin.bin", "wb");
		fwrite(&a, sizeof(int), 1, fp);
		strcpy(admin.username, "Alireza80");
		strcpy(admin.nationalcode, "4421020796");
		strcpy(admin.email, "shapour8080");
		strcpy(admin.password, "discover88");
		fclose(fp);
	}
	else {
		fp = fopen("admin.bin", "rb");
		fread(&countofadmin, sizeof(int), 1, fp);
		fread(&admin, sizeof(struct manager), countofadmin + 2, fp);
		fclose(fp);
	}
	if (fopen("hospitals.bin", "rb") == NULL) {
		int a = -1;
		fp = fopen("hospitals.bin", "wb");
		fwrite(&a, sizeof(int), 1, fp);
		fclose(fp);
	}
	else {
		fp = fopen("hospitals.bin", "rb");
		fread(&countofhospitals, sizeof(int), 1, fp);
		fread(&hospital, sizeof(struct clinic), countofhospitals + 1, fp);
		fclose(fp);
	}
	return;
}
void Lock() {
	system("cls");
	system("color 1b");
	char menuoption[30];
	for (int c = 0;c < 17;c++) {
		if (c == 0)
			printf("\n                                         ***** IN THE NAME OF GOD *****                                        \n\n");
		else if (c == 1) 
			printf("   \"\" Alireza Mirhoseini presents \"\"   \n\n   <<++ Nicknamed SHAPOUR DISCOVER ++>>   ");
		else if (c == 2)
			printf("\n\n\n                                               HELLO , WELCOME  TO                             \n\n\n");
		else if (c == 3)
			printf("            $$$$$$$$$$$$$$$    $$$               $$$   $$$$$$$$$$$$$$$$$$                         \n");
		else if (c == 4)
			printf("            $$$$$$$$$$$$$$$$    $$$             $$$    $$$$$$$$$$$$$$$$$$                        \n");
		else if (c == 5)
			printf("            $$$           $$$    $$$           $$$     $$$                                         \n");
		else if (c == 6)
			printf("            $$$            $$$    $$$         $$$      $$$                                        \n");
		else if (c == 7)
			printf("            $$$           $$$      $$$       $$$       $$$                                        \n");
		else if (c == 8)
			printf("            $$$          $$$        $$$     $$$        $$$                                         \n");
		else if (c == 9)
			printf("            $$$$$$$$$$$$$$$          $$$$$$$$$         $$$$$$$$$$$$$$$$$$                          \n");
		else if (c == 10)
			printf("            $$$$$$$$$$$$$$$             $$$            $$$$$$$$$$$$$$$$$$           COVID 19 , 20 , 21 , ...\n");
		else if (c == 11)
			printf("            $$$           $$$           $$$            $$$                                         \n");
		else if (c == 12)
			printf("            $$$            $$$          $$$            $$$                                         \n");
		else if (c == 13)
			printf("            $$$             $$$         $$$            $$$                                         \n");
		else if (c == 14)
			printf("            $$$            $$$          $$$            $$$                                          \n");
		else if (c == 15)
			printf("            $$$$$$$$$$$$$$$$$           $$$            $$$$$$$$$$$$$$$$$$                          \n");
		else if (c == 16)
			printf("            $$$$$$$$$$$$$$$$            $$$            $$$$$$$$$$$$$$$$$$                       \n\n\n");
		Sleep(showtime);
	}
	for (int i = 0;i < 5;i++) {
		if (i == 0)
			puts("  1 : Login");
		else if (i == 1)
			puts("  2 : Create new account");
		else if (i == 2)
			puts("  3 : Forget password");
		else if (i == 3)
			puts("  4 : Points about corona");
		else if (i == 4)
			puts("  0 : Close the program");

		Sleep(showtime);
	}
	do
	{
		printf(" Command:");
		gets_s(menuoption);
	} while (strcmp(menuoption, "") == 0);
	if (strcmp(menuoption, "1") == 0 || strcmp(strlwr(menuoption), "login") == 0) {
		Login();
	}
	if (strcmp(menuoption, "2") == 0 || strcmp(strlwr(menuoption), "create new account") == 0) {
		New_account();
	}
	if (strcmp(menuoption, "3") == 0 || strcmp(strlwr(menuoption), "forget password") == 0) {
		Forgetpass();
	}
	if (strcmp(menuoption, "4") == 0 || strcmp(strlwr(menuoption), "points about corona") == 0) {
		Point_about_coronr();
	}
	if (strcmp(menuoption, "0") == 0 || strcmp(strlwr(menuoption), "close the program") == 0) {
		EXit();
	}
	else {
		printf(" It doesn't exist... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	return;
}
void Point_about_coronr() {
	system("cls");
	system("color 47");
	puts(" primary points about coronavirus :");
	puts(" 1.Wash your hands regularly.");
	puts(" 2.Keep a safe distance in communities and use Mask.");
	puts(" 3.Maintain respiratory hygiene.");
	puts(" 4.Avoid touching your face.");
	puts(" 5.Keep equipment clean and disinfected.");

	char back[5];
	printf(" Enter <back> to go back to main menu ");
	gets_s(back);
	if (strcmp(back, "back") == 0) {
		Lock();
	}
	return;
}
void Login() {
	system("cls");
	system("color bc");
	char account_type[30];
	char uname[30], password[30];
	do
	{
		printf("\n  What is your account_type ? ( 1 : Common account __ 2 : Shopowner account __ 3 : Admin account ) : ");
		gets_s(account_type);
	} while (strcmp(account_type, "") == 0);
	if (strcmp(account_type, "1") == 0 || strcmp(strlwr(account_type), "common account") == 0) {
		puts("");
		do
		{
			printf(" Enter your username (dont enter space): ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);

		printf(" Enter your password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		for (int i = 0;i < countofusers;i++) {
			if (strcmp(uname, user[i].username) == 0 && strcmp(password, user[i].password) == 0&&user[i].dead_flag==0) {
				User_menu(i);
			}
		}
		puts(" User not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	else if (strcmp(account_type, "2") == 0 || strcmp(strlwr(account_type), "shopowner account") == 0) {
		puts("");
		do
		{
			printf(" Enter your username (dont enter space): ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);

		printf(" Enter your password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		for (int i = 0;i < countofshop_owners;i++) {
			if (strcmp(uname, shop_owner[i].username) == 0 && strcmp(password, shop_owner[i].password) == 0) {
				Shop_owner_menu(i);
			}
		}
		puts(" Shopowner not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	else if (strcmp(account_type, "3") == 0 || strcmp(strlwr(account_type), "admin account") == 0) {
		puts("");
		do
		{
			printf(" Enter your username (dont enter space): ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);

		printf(" Enter your password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		if (strcmp(uname, admin.username) == 0 && strcmp(password, admin.password) == 0) {
			Admin_menu();
		}
		puts(" Admin not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	printf(" It doesn't exist... please wait then try again");
	Sleep(sleeptime);
	Lock();
	return;
}
void New_account() {
	system("cls");
	system("color 57");
	char account_type[30];
	do
	{
		printf("\n  What is your account_type ? ( 1 : Common account __ 2 : Shopowner account ) : ");
		gets_s(account_type);
	} while (strcmp(account_type, "") == 0);
	if (strcmp(account_type, "1") == 0 || strcmp(strlwr(account_type), "common account") == 0) {
		do
		{
			printf(" Enter your Firstname : ");
			gets_s(user[countofusers].firstname);
		} while (strcmp(user[countofusers].firstname, "") == 0);
		do
		{
			printf(" Enter your Lastname : ");
			gets_s(user[countofusers].lastname);
		} while (strcmp(user[countofusers].lastname, "") == 0);
		do
		{
			printf(" Enter your National code : ");
			gets_s(user[countofusers].nationalcode);
			int i;
			for (i = 0;i < countofusers;i++) {
				if (strcmp(user[countofusers].nationalcode, user[i].nationalcode) == 0 && i!=countofusers) {
					break;
				}
			}
			while (strcmp(user[countofusers].nationalcode, user[i].nationalcode) == 0 && i != countofusers)
			{
				printf(" It already existed ... Enter your new National code (dont enter space): ");
				gets_s(user[countofusers].nationalcode);
				for (i = 0;i < countofusers;i++) {
					if (strcmp(user[countofusers].nationalcode, user[i].nationalcode) == 0 && i != countofusers) {
						break;
					}
				}
			}
		} while (strcmp(user[countofusers].nationalcode, "") == 0);
		do
		{
			printf(" Enter your Username (dont enter space): ");
			gets_s(user[countofusers].username);
			int i;
			for (i = 0;i < countofusers;i++) {
				if (strcmp(user[countofusers].username, user[i].username) == 0 && i != countofusers) {
					break;
				}
			}
			while (strcmp(user[countofusers].username, user[i].username) == 0 && i != countofusers)
			{
				printf(" It already existed ... Enter your Username (dont enter space): ");
				gets_s(user[countofusers].username);
				for (i = 0;i < countofusers;i++) {
					if (strcmp(user[countofusers].username, user[i].username) == 0 && i != countofusers) {
						break;
					}
				}
			}
		} while (strcmp(user[countofusers].username, "") == 0);
		char rpass[30], password[30];
		printf(" Enter your Password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		puts("");
		printf(" Enter your Password again : ");
		int counte = 0;
		while (1) {
			rpass[counte] = getch();
			if (rpass[counte] == '\b' && counte > 0) {
				printf("\b \b");
				counte--;
			}
			else if (rpass[0] == '\r') {}
			else if (rpass[counte] != '\r') {
				printf("*");
				counte++;
			}
			else if (rpass[counte] == '\r') {
				counte++;
				break;
			}
		}
		rpass[counte - 1] = '\0';
		puts("");
		while (strcmp(password, rpass) != 0) {
			printf("\n The entered Passwords are different.  try again\n\n");
			printf(" Enter your Password (dont enter space): ");
			int coun = 0;
			while (1) {
				password[coun] = getch();
				if (password[coun] == '\b' && coun > 0) {
					printf("\b \b");
					coun--;
				}
				else if (password[0] == '\r') {}
				else if (password[coun] != '\r') {
					printf("*");
					coun++;
				}
				else if (password[coun] == '\r') {
					coun++;
					break;
				}
			}
			password[coun - 1] = '\0';
			puts("");
			printf(" Enter your Password again : ");
			int counter = 0;
			while (1) {
				rpass[counter] = getch();
				if (rpass[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (rpass[counter] == '\r') {
					counter++;
					break;
				}
			}
			rpass[counter - 1] = '\0';
			puts("");
		}
		strcpy(user[countofusers].password, password);
		do
		{
			printf(" Enter your Email : ");
			gets_s(user[countofusers].email);
		} while (strcmp(user[countofusers].email, "") == 0);
		printf(" Enter your Blood type (enter to skip): ");
		gets_s(user[countofusers].bloodtype);
		char tage[10], tweight[10], theight[10];
		printf(" Enter your Age (enter to skip): ");
		gets_s(tage);
		user[countofusers].age = atoi(tage);
		printf(" Enter your Weight (enter to skip): ");
		gets_s(tweight);
		user[countofusers].weight = atof(tweight);
		printf(" Enter your Height (enter to skip): ");
		gets_s(theight);
		user[countofusers].height = atof(theight);
		user[countofusers].health_code = 1;
		user[countofusers].ttest = 0;
		user[countofusers].tmeet = 0;
		user[countofusers].tplace = 0;
		countofusers++;
		printf(" saved... please wait to go back to main menu");
		Sleep(sleeptime);
		Lock();
	}
	else if (strcmp(account_type, "2") == 0 || strcmp(strlwr(account_type), "shopowner account") == 0) {
		do
		{
			printf(" Enter your Firstname : ");
			gets_s(shop_owner[countofshop_owners].firstname);
		} while (strcmp(shop_owner[countofshop_owners].firstname, "") == 0);
		do
		{
			printf(" Enter your Lastname : ");
			gets_s(shop_owner[countofshop_owners].lastname);
		} while (strcmp(shop_owner[countofshop_owners].lastname, "") == 0);
		do
		{
			printf(" Enter your National code : ");
			gets_s(shop_owner[countofshop_owners].nationalcode);
			int i;
			for (i = 0;i < countofshop_owners;i++) {
				if (strcmp(shop_owner[countofshop_owners].nationalcode, shop_owner[i].nationalcode) == 0 && i != countofshop_owners) {
					break;
				}
			}
			while (strcmp(shop_owner[countofshop_owners].nationalcode, shop_owner[i].nationalcode) == 0 && i != countofshop_owners)
			{
				printf(" It already existed ... Enter your National code (dont enter space): ");
				gets_s(shop_owner[countofshop_owners].nationalcode);
				for (i = 0;i < countofshop_owners;i++) {
					if (strcmp(shop_owner[countofshop_owners].nationalcode, shop_owner[i].nationalcode) == 0 && i != countofshop_owners) {
						break;
					}
				}
			}
		} while (strcmp(shop_owner[countofshop_owners].nationalcode, "") == 0);
		do
		{
			printf(" Enter your Username (dont enter space): ");
			gets_s(shop_owner[countofshop_owners].username);
			int i;
			for (i = 0;i < countofshop_owners;i++) {
				if (strcmp(shop_owner[countofshop_owners].username, shop_owner[i].username) == 0 && i != countofshop_owners) {
					break;
				}
			}
			while (strcmp(shop_owner[countofshop_owners].username, shop_owner[i].username) == 0 && i != countofshop_owners)
			{
				printf(" It already existed ... Enter your Username (dont enter space): ");
				gets_s(shop_owner[countofshop_owners].username);
				for (i = 0;i < countofshop_owners;i++) {
					if (strcmp(shop_owner[countofshop_owners].username, shop_owner[i].username) == 0 && i != countofshop_owners) {
						break;
					}
				}
			}
		} while (strcmp(shop_owner[countofshop_owners].username, "") == 0);
		char rpass[30], password[30];
		printf(" Enter your Password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		puts("");
		printf(" Enter your Password again : ");
		int counte = 0;
		while (1) {
			rpass[counte] = getch();
			if (rpass[counte] == '\b' && counte > 0) {
				printf("\b \b");
				counte--;
			}
			else if (rpass[0] == '\r') {}
			else if (rpass[counte] != '\r') {
				printf("*");
				counte++;
			}
			else if (rpass[counte] == '\r') {
				counte++;
				break;
			}
		}
		rpass[counte - 1] = '\0';
		puts("");
		while (strcmp(password, rpass) != 0) {
			printf("\n The entered Passwords are different.  try again\n\n");
			printf(" Enter your Password (dont enter space): ");
			int coun = 0;
			while (1) {
				password[coun] = getch();
				if (password[coun] == '\b' && coun > 0) {
					printf("\b \b");
					coun--;
				}
				else if (password[0] == '\r') {}
				else if (password[coun] != '\r') {
					printf("*");
					coun++;
				}
				else if (password[coun] == '\r') {
					coun++;
					break;
				}
			}
			password[coun - 1] = '\0';
			puts("");
			printf(" Enter your Password again : ");
			int counter = 0;
			while (1) {
				rpass[counter] = getch();
				if (rpass[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (rpass[0] == '\r'){}
				else if (rpass[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (rpass[counter] == '\r') {
					counter++;
					break;
				}
			}
			rpass[counter - 1] = '\0';
			puts("");
		}
		strcpy(shop_owner[countofshop_owners].password, password);
		do
		{
			printf(" Enter your Email : ");
			gets_s(shop_owner[countofshop_owners].email);
		} while (strcmp(shop_owner[countofshop_owners].email, "") == 0);
		do
		{
			printf(" Enter Name of your shop : ");
			gets_s(shop_owner[countofshop_owners].placename);
		} while (strcmp(shop_owner[countofshop_owners].placename, "") == 0);
		do
		{
			printf(" Enter your City : ");
			gets_s(shop_owner[countofshop_owners].city);
		} while (strcmp(shop_owner[countofshop_owners].city, "") == 0);
		do
		{
			printf(" Enter your Region : ");
			gets_s(shop_owner[countofshop_owners].region);
		} while (strcmp(shop_owner[countofshop_owners].region, "") == 0);
		strcpy(shop_owner[countofshop_owners].place_code, "White");
		countofshop_owners++;
		printf(" saved... please wait to go back to main menu");
		Sleep(sleeptime);
		Lock();
	}
	printf(" It doesn't exist... please wait then try again");
	Sleep(sleeptime);
	Lock();
	return;
}
void Forgetpass() {
	system("cls");
	system("color 2f");
	char account_type[30];
	char uname[30], ncode[30], emeil[30];
	do
	{
		printf("\n  What is your account_type ? ( 1 : Common account __ 2 : Shopowner account __ 3 : Admin account ) : ");
		gets_s(account_type);
	} while (strcmp(account_type, "") == 0);
	if (strcmp(account_type, "1") == 0 || strcmp(strlwr(account_type), "common account") == 0) {
		do
		{
			printf(" Enter your Username : ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);
		do
		{
			printf(" Enter your National code : ");
			gets_s(ncode);
		} while (strcmp(ncode, "") == 0);
		do
		{
			printf(" Enter your Email : ");
			gets_s(emeil);
		} while (strcmp(emeil, "") == 0);
		int i;
		for (i = 0;i < countofusers;i++) {
			if (strcmp(user[i].username, uname) == 0) {
				break;
			}
		}
		if (strcmp(uname, user[i].username) == 0 && strcmp(ncode, user[i].nationalcode) == 0 && strcmp(emeil, user[i].email) == 0) {
			printf(" Hello %s, Enter your new password (dont enter space): ", user[i].firstname);
			char rpass[30], password[30];
			int counter = 0;
			while (1) {
				password[counter] = getch();
				if (password[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (password[0] == '\r') {}
				else if (password[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (password[counter] == '\r') {
					counter++;
					break;
				}
			}
			password[counter - 1] = '\0';
			puts(" Enter your new Password again : ");
			int counte = 0;
			while (1) {
				rpass[counte] = getch();
				if (rpass[counte] == '\b' && counte > 0) {
					printf("\b \b");
					counte--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counte] != '\r') {
					printf("*");
					counte++;
				}
				else if (rpass[counte] == '\r') {
					counte++;
					break;
				}
			}
			rpass[counte - 1] = '\0';
			while (strcmp(password, rpass) != 0) {
				printf("\n The entered Passwords are different.  try again\n\n");
				puts(" Enter your new password (dont enter space): ");
				int count = 0;
				while (1) {
					password[count] = getch();
					if (password[count] == '\b' && count > 0) {
						printf("\b \b");
						count--;
					}
					else if (password[0] == '\r') {}
					else if (password[count] != '\r') {
						printf("*");
						count++;
					}
					else if (password[count] == '\r') {
						count++;
						break;
					}
				}
				password[count - 1] = '\0';
				puts(" Enter your new Password again : ");
				int coun = 0;
				while (1) {
					rpass[coun] = getch();
					if (rpass[coun] == '\b' && coun > 0) {
						printf("\b \b");
						coun--;
					}
					else if (rpass[0] == '\r') {}
					else if (rpass[coun] != '\r') {
						printf("*");
						coun++;
					}
					else if (rpass[coun] == '\r') {
						coun++;
						break;
					}
				}
				rpass[coun - 1] = '\0';
			}
			strcpy(user[i].password, password);
			printf("\nThe entered information was recorded (please wait to return to main menu)");
			Sleep(sleeptime);
			Lock();
		}
		printf(" Not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	else if (strcmp(account_type, "2") == 0 || strcmp(strlwr(account_type), "shopowner account") == 0) {
		do
		{
			printf(" Enter your Username : ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);
		do
		{
			printf(" Enter your National code : ");
			gets_s(ncode);
		} while (strcmp(ncode, "") == 0);
		do
		{
			printf(" Enter your Email : ");
			gets_s(emeil);
		} while (strcmp(emeil, "") == 0);
		int i;
		for (i = 0;i < countofshop_owners;i++) {
			if (strcmp(shop_owner[i].username, uname) == 0) {
				break;
			}
		}
		if (strcmp(uname, shop_owner[i].username) == 0 && strcmp(ncode, shop_owner[i].nationalcode) == 0 && strcmp(emeil, shop_owner[i].email) == 0) {
			printf(" Hello %s, Enter your new password (dont enter space): ", shop_owner[i].firstname);
			char rpass[30], password[30];
			int counter = 0;
			while (1) {
				password[counter] = getch();
				if (password[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (password[0] == '\r') {}
				else if (password[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (password[counter] == '\r') {
					counter++;
					break;
				}
			}
			password[counter - 1] = '\0';
			puts(" Enter your new Password again : ");
			int counte = 0;
			while (1) {
				rpass[counte] = getch();
				if (rpass[counte] == '\b' && counte > 0) {
					printf("\b \b");
					counte--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counte] != '\r') {
					printf("*");
					counte++;
				}
				else if (rpass[counte] == '\r') {
					counte++;
					break;
				}
			}
			rpass[counte - 1] = '\0';
			while (strcmp(password, rpass) != 0) {
				printf("\n The entered Passwords are different.  try again\n\n");
				puts(" Enter your new password (dont enter space): ");
				int count = 0;
				while (1) {
					password[count] = getch();
					if (password[count] == '\b' && count > 0) {
						printf("\b \b");
						count--;
					}
					else if (password[0] == '\r') {}
					else if (password[count] != '\r') {
						printf("*");
						count++;
					}
					else if (password[count] == '\r') {
						count++;
						break;
					}
				}
				password[count - 1] = '\0';
				puts(" Enter your new Password again : ");
				int coun = 0;
				while (1) {
					rpass[coun] = getch();
					if (rpass[coun] == '\b' && coun > 0) {
						printf("\b \b");
						coun--;
					}
					else if (rpass[0] == '\r') {}
					else if (rpass[coun] != '\r') {
						printf("*");
						coun++;
					}
					else if (rpass[coun] == '\r') {
						coun++;
						break;
					}
				}
				rpass[coun - 1] = '\0';
			}
			strcpy(shop_owner[i].password, password);
			printf("\nThe entered information was recorded (please wait to return to main menu)");
			Sleep(sleeptime);
			Lock();
		}
		printf(" Not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	else if (strcmp(account_type, "3") == 0 || strcmp(strlwr(account_type), "admin account") == 0) {
		do
		{
			printf(" Enter your Username : ");
			gets_s(uname);
		} while (strcmp(uname, "") == 0);
		do
		{
			printf(" Enter your National code : ");
			gets_s(ncode);
		} while (strcmp(ncode, "") == 0);
		do
		{
			printf(" Enter your Email : ");
			gets_s(emeil);
		} while (strcmp(emeil, "") == 0);
		if (strcmp(uname, admin.username) == 0 && strcmp(ncode, admin.nationalcode) == 0 && strcmp(emeil, admin.email) == 0) {
			printf(" Hello admin, Enter your new password (dont enter space): ");
			char rpass[30], password[30];
			int counter = 0;
			while (1) {
				password[counter] = getch();
				if (password[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (password[0] == '\r') {}
				else if (password[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (password[counter] == '\r') {
					counter++;
					break;
				}
			}
			password[counter - 1] = '\0';
			puts(" Enter your new Password again : ");
			int counte = 0;
			while (1) {
				rpass[counte] = getch();
				if (rpass[counte] == '\b' && counte > 0) {
					printf("\b \b");
					counte--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counte] != '\r') {
					printf("*");
					counte++;
				}
				else if (rpass[counte] == '\r') {
					counte++;
					break;
				}
			}
			rpass[counte - 1] = '\0';
			while (strcmp(password, rpass) != 0) {
				printf("\n The entered Passwords are different.  try again\n\n");
				puts(" Enter your new password (dont enter space): ");
				int count = 0;
				while (1) {
					password[count] = getch();
					if (password[count] == '\b' && count > 0) {
						printf("\b \b");
						count--;
					}
					else if (password[0] == '\r') {}
					else if (password[count] != '\r') {
						printf("*");
						count++;
					}
					else if (password[count] == '\r') {
						count++;
						break;
					}
				}
				password[count - 1] = '\0';
				puts(" Enter your new Password again : ");
				int coun = 0;
				while (1) {
					rpass[coun] = getch();
					if (rpass[coun] == '\b' && coun > 0) {
						printf("\b \b");
						coun--;
					}
					else if (rpass[0] == '\r') {}
					else if (rpass[coun] != '\r') {
						printf("*");
						coun++;
					}
					else if (rpass[coun] == '\r') {
						coun++;
						break;
					}
				}
				rpass[coun - 1] = '\0';
			}
			strcpy(admin.password, password);
			printf("\nThe entered information was recorded (please wait to return to main menu)");
			Sleep(sleeptime);
			Lock();
		}
		printf(" Not found... please wait then try again");
		Sleep(sleeptime);
		Lock();
	}
	printf(" It doesn't exist... please wait then try again");
	Sleep(sleeptime);
	Lock();
	return;
}
void Admin_menu() {
	system("cls");
	system("color 8e");
	char menuop[30],answer1[5], answer2[5], answer3[5], answer4[5];
	puts("\n                                  Hello admin\n\n");
	puts("  1 : Add hospital");
	puts("  2 : View statistics (Users who has corone)");
	puts("  3 : Add cured or dead person");
	puts("  4 : Users list");
	puts("  5 : Dead list");
	puts("  6 : Places list");
	puts("  7 : Hospitals list");
	puts("  8 : Edit Profile");
	puts("  9 : Lock");
	puts("  0 : Exit");
	do
	{
		gets_s(menuop);
	} while (strcmp(menuop, "") == 0);
	if (strcmp(menuop, "1") == 0 || strcmp(strlwr(menuop), "add hospital") == 0) {
		system("cls");
		do
		{
			printf(" Enter Name of hospital : ");
			gets_s(hospital[countofhospitals].name);
		} while (strcmp(hospital[countofhospitals].name, "") == 0);
		do
		{
			printf(" Enter City : ");
			gets_s(hospital[countofhospitals].city);
		} while (strcmp(hospital[countofhospitals].city, "") == 0);
		do
		{
			printf(" Enter Region : ");
			gets_s(hospital[countofhospitals].region);
		} while (strcmp(hospital[countofhospitals].region, "") == 0);
		countofhospitals++;
	}
	else if (strcmp(menuop, "2") == 0 || strcmp(strlwr(menuop), "view statistics") == 0) {
		system("cls");
		for (int i = 0;i < countofusers;i++) {
			if (user[i].health_code == 4) {
				struct tm tm = *localtime(&user[i].test[user[i].ttest - 1]);
				printf(" %d-%02d-%02d   %02d:%02d:%02d           Firstname:%s          Lastname:%s          National code = %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, user[i].firstname,user[i].lastname,user[i].nationalcode);
			}
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "3") == 0 || strcmp(strlwr(menuop), "add cured or dead person") == 0) {
		system("cls");
		char ncou[20];
		do
		{
			printf(" Enter National code of user : ");
			gets_s(ncou);
		} while (strcmp(ncou, "") == 0);
		int i;
		bool yaft = false;
		for (i = 0;i < countofusers;i++) {
			if (strcmp(ncou, user[i].nationalcode) == 0) {
				yaft = true;
				break;
			}
		}
		if (yaft) {
			char answer[10];
			do
			{
				printf(" Current situation = %d\n", user[i].health_code);
				printf(" Is user dead or has cured ? (_dead_ or _cured_) ");
				gets_s(answer);
			} while (strcmp(answer, "") == 0);
			if (strcmp(answer, "dead") == 0) {
				user[i].dead_flag = 1;
			}
			else if (strcmp(answer, "cured") == 0) {
				user[i].health_code = 2;
			}
		}
		else if (!yaft) {
			puts(" Not found");
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "4") == 0 ||strcmp(strlwr(menuop), "users list") == 0) {
		system("cls");
		for (int i = 0;i < countofusers;i++) {
			if (user[i].dead_flag != 1) {
				printf("Firstname : %s , Lastname : %s , National code : %s , Health code : %d\n", user[i].firstname, user[i].lastname, user[i].nationalcode, user[i].health_code);
			}
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "5") == 0 || strcmp(strlwr(menuop), "dead list") == 0) {
		system("cls");
		for (int i = 0;i < countofusers;i++) {
			if (user[i].dead_flag == 1) {
				printf("Firstname : %s , Lastname : %s , National code : %s\n", user[i].firstname, user[i].lastname, user[i].nationalcode);
			}
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "6") == 0 || strcmp(strlwr(menuop), "places list") == 0) {
		system("cls");
		for (int i = 0;i < countofshop_owners;i++) {
			printf("Name of Place : %s , Shopowner's National code : %s , Status : %s\n", shop_owner[i].placename, shop_owner[i].nationalcode, shop_owner[i].place_code);
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "7") == 0 || strcmp(strlwr(menuop), "hospitals list") == 0) {
		system("cls");
		for (int i = 0;i < countofhospitals;i++) {
			printf("Name of Hospital : %s , City : %s , Region : %s\n", hospital[i].name, hospital[i].city, hospital[i].region);
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "8") == 0 || strcmp(strlwr(menuop), "edit profile") == 0) {
		system("cls");
		do
		{
			printf(" Do you want to change your Username ? ( Yes or No )");
			gets_s(answer1);
		} while (strcmp(answer1, "") == 0);
		if (strcmp(strlwr(answer1), "yes") == 0) {
			do
			{
				printf(" Enter your new Username (dont enter space): ");
				gets_s(admin.username);
			} while (strcmp(admin.username, "") == 0);
		}
		do
		{
			printf(" Do you want to change your National code  ? ( Yes or No )");
			gets_s(answer2);
		} while (strcmp(answer2, "") == 0);
		if (strcmp(strlwr(answer2), "yes") == 0) {
			do
			{
				printf(" Enter your new National code : ");
				gets_s(admin.nationalcode);
			} while (strcmp(admin.nationalcode, "") == 0);
		}
		do
		{
			printf(" Do you want to change your Email ? ( Yes or No )");
			gets_s(answer3);
		} while (strcmp(answer3, "") == 0);
		if (strcmp(strlwr(answer3), "yes") == 0) {
			do
			{
				printf(" Enter your new Email : ");
				gets_s(admin.email);
			} while (strcmp(admin.email, "") == 0);
		}
		do
		{
			printf(" Do you want to change your Password ? ( Yes or No )");
			gets_s(answer4);
		} while (strcmp(answer4, "") == 0);
		if (strcmp(strlwr(answer4), "yes") == 0) {
			printf(" Enter your new Password (dont enter space): ");
			char rpass[30], password[30];
			int counter = 0;
			while (1) {
				password[counter] = getch();
				if (password[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (password[0] == '\r') {}
				else if (password[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (password[counter] == '\r') {
					counter++;
					break;
				}
			}
			password[counter - 1] = '\0';
			puts(" Enter your new Password again : ");
			int counte = 0;
			while (1) {
				rpass[counte] = getch();
				if (rpass[counte] == '\b' && counte > 0) {
					printf("\b \b");
					counte--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counte] != '\r') {
					printf("*");
					counte++;
				}
				else if (rpass[counte] == '\r') {
					counte++;
					break;
				}
			}
			rpass[counte - 1] = '\0';
			while (strcmp(password, rpass) != 0) {
				printf("\n The entered Passwords are different . try again\n\n");
				puts(" Enter your new password (dont enter space): ");
				int count = 0;
				while (1) {
					password[count] = getch();
					if (password[count] == '\b' && count > 0) {
						printf("\b \b");
						count--;
					}
					else if (password[0] == '\r') {}
					else if (password[count] != '\r') {
						printf("*");
						count++;
					}
					else if (password[count] == '\r') {
						count++;
						break;
					}
				}
				password[count - 1] = '\0';
				puts(" Enter your new Password again : ");
				int coun = 0;
				while (1) {
					rpass[coun] = getch();
					if (rpass[coun] == '\b' && coun > 0) {
						printf("\b \b");
						coun--;
					}
					else if (rpass[0] == '\r') {}
					else if (rpass[coun] != '\r') {
						printf("*");
						coun++;
					}
					else if (rpass[coun] == '\r') {
						coun++;
						break;
					}
				}
				rpass[coun - 1] = '\0';
			}
			strcpy(admin.password, password);
			printf("\nThe entered information was recorded (please wait to return to main menu)");
			Sleep(sleeptime);
			Admin_menu();
		}
	}
	else if (strcmp(menuop, "9") == 0 || strcmp(strlwr(menuop), "lock") == 0) {
		Lock();
	}
	else if (strcmp(menuop, "0") == 0 || strcmp(strlwr(menuop), "exit") == 0) {
		EXit();
	}
	printf(" please wait to go back to your menu");
	Sleep(sleeptime);
	Admin_menu();
	return;
}
void User_menu(int index) {
	system("cls");
	system("color e5");
	char menuop[40];
	printf("\n                                        Hello %s\n\n", user[index].firstname);
	printf("  Health code : %d\n\n", user[index].health_code);
	puts("  1 : Edit Profile");
	puts("  2 : Status (Health status registration)");
	puts("  3 : View History (History of Health status registration)");
	puts("  4 : Meet other users");
	puts("  5 : Meeting History");
	puts("  6 : Add where you went");
	puts("  7 : Places you went to");
	puts("  8 : Corona statistics");
	puts("  9 : Hospitals list (in your area)");
	puts("  10 : Lock");
	puts("  0 : Exit");
	do
	{
		gets_s(menuop);
	} while (strcmp(menuop, "") == 0);
	if (strcmp(menuop, "1") == 0 || strcmp(strlwr(menuop), "edit profile") == 0){
		system("cls");
		do
		{
			printf(" Enter your new Firstname : ");
			gets_s(user[index].firstname);
		} while (strcmp(user[index].firstname, "") == 0);
		do
		{
			printf(" Enter your new Lastname : ");
			gets_s(user[index].lastname);
		} while (strcmp(user[index].lastname, "") == 0);
		do
		{
			printf(" Enter your new National code : ");
			gets_s(user[index].nationalcode);
			int i;
			for (i = 0;i < countofusers;i++) {
				if (strcmp(user[index].nationalcode, user[i].nationalcode) == 0 && i != index) {
					break;
				}
			}
			while (strcmp(user[index].nationalcode, user[i].nationalcode) == 0 && i != index)
			{
				printf(" It already existed ... Enter your new National code (dont enter space): ");
				gets_s(user[index].nationalcode);
				for (i = 0;i < countofusers;i++) {
					if (strcmp(user[index].nationalcode, user[i].nationalcode) == 0 && i != index) {
						break;
					}
				}
			}
		} while (strcmp(user[index].nationalcode, "") == 0);
		do
		{
			printf(" Enter your new Username (dont enter space): ");
			gets_s(user[index].username);
			int i;
			for (i = 0;i < countofusers;i++) {
				if (strcmp(user[index].username, user[i].username) == 0 && i != index) {
					break;
				}
			}
			while (strcmp(user[index].username, user[i].username) == 0 && i != index)
			{
				printf(" It already existed ... Enter your new Username (dont enter space): ");
				gets_s(user[index].username);
				for (i = 0;i < countofusers;i++) {
					if (strcmp(user[index].username, user[i].username) == 0 && i != index) {
						break;
					}
				}
			}
		} while (strcmp(user[index].username, "") == 0);
		char rpass[30], password[30];
		printf(" Enter your new Password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		puts("");
		printf(" Enter your new Password again : ");
		int counte = 0;
		while (1) {
			rpass[counte] = getch();
			if (rpass[counte] == '\b' && counte > 0) {
				printf("\b \b");
				counte--;
			}
			else if (rpass[0] == '\r') {}
			else if (rpass[counte] != '\r') {
				printf("*");
				counte++;
			}
			else if (rpass[counte] == '\r') {
				counte++;
				break;
			}
		}
		rpass[counte - 1] = '\0';
		puts("");
		while (strcmp(password, rpass) != 0) {
			printf("\n The entered Passwords are different.  try again\n\n");
			printf(" Enter your new Password (dont enter space): ");
			int coun = 0;
			while (1) {
				password[coun] = getch();
				if (password[coun] == '\b' && coun > 0) {
					printf("\b \b");
					coun--;
				}
				else if (password[0] == '\r') {}
				else if (password[coun] != '\r') {
					printf("*");
					coun++;
				}
				else if (password[coun] == '\r') {
					coun++;
					break;
				}
			}
			password[coun - 1] = '\0';
			puts("");
			printf(" Enter your new Password again : ");
			int counter = 0;
			while (1) {
				rpass[counter] = getch();
				if (rpass[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (rpass[counter] == '\r') {
					counter++;
					break;
				}
			}
			rpass[counter - 1] = '\0';
			puts("");
		}
		strcpy(user[index].password, password);
		do
		{
			printf(" Enter your new Email : ");
			gets_s(user[index].email);
		} while (strcmp(user[index].email, "") == 0);
		printf(" Enter your new Blood type (enter to skip): ");
		gets_s(user[index].bloodtype);
		char tage[10], tweight[10], theight[10];
		printf(" Enter your new Age (enter to skip): ");
		gets_s(tage);
		user[index].age = atoi(tage);
		printf(" Enter your new Weight (enter to skip): ");
		gets_s(tweight);
		user[index].weight = atof(tweight);
		printf(" Enter your new Height (enter to skip): ");
		gets_s(theight);
		user[index].height = atof(theight);
		printf("\nThe entered information was recorded (please wait to return to main menu)");
		Sleep(sleeptime);
		User_menu(index);
	}
	else if (strcmp(menuop, "2") == 0 || strcmp(strlwr(menuop), "status") == 0) {
		system("cls");
		if (user[index].health_code==4) {
			puts(" You're sick, so you cant set Health status registration");
			printf(" please wait to go back to your menu");
			Sleep(6000);
			User_menu(index);
		}
		int sum = 0,health;
		char skz[5], tbs[5], as[5], gd[5], dok[5];
		printf(" Do you have very much dry coughs ? ( 1 : Yes __ 0 : No) ");
		scanf("%s", skz);
		if (strcmp(skz, "1") == 0 || strcmp(strlwr(skz), "yes") == 0)sum += 30;
		printf(" Do you have fever over 37 degrees ? ( 1 : Yes __ 0 : No) ");
		scanf("%s", tbs);
		if (strcmp(tbs, "1") == 0 || strcmp(strlwr(tbs), "yes") == 0)sum += 20;
		printf(" Do you have asthma ? ( 1 : Yes __ 0 : No) ");
		scanf("%s", as);
		if (strcmp(as, "1") == 0 || strcmp(strlwr(as), "yes") == 0)sum += 20;
		printf(" Do you have sore throat ? ( 1 : Yes __ 0 : No) ");
		scanf("%s", gd);
		if (strcmp(gd, "1") == 0 || strcmp(strlwr(gd), "yes") == 0)sum += 15;
		printf(" Do you have pain and fatigue ? ( 1 : Yes __ 0 : No) ");
		scanf("%s", dok);
		if (strcmp(dok, "1") == 0 || strcmp(strlwr(dok), "yes") == 0)sum += 15;
		if (sum > 75) {
			printf("\n  unfortunately you're sick");
			health = 4;
		}
		else if (sum > 50) {
			printf("\n  you're dangerous");
			health = 3;
		}
		else if (sum > 15) {
			printf("\n  you're suspected to corona");
			health = 2;
		}
		else if (sum >= 0) {
			printf("\n  you're healthy");
			health = 1;
		}
		getchar();
		if ((user[index].ttest == 0)||(user[index].ttest > 0 && user[index].health_code < health)) {
			user[index].health_code = health;
			user[index].temp_health_code[user[index].ttest] = user[index].health_code;
			user[index].test[user[index].ttest] = time(NULL);
			user[index].ttest++;
		}
	}
	else if (strcmp(menuop, "3") == 0 || strcmp(strlwr(menuop), "view history") == 0) {
		system("cls");
		int counter = 0;
		for (int i = user[index].ttest - 1;(i >= 0)&&(counter<10);i--) {
			struct tm tm = *localtime(&user[index].test[i]);
			printf(" %d-%02d-%02d   %02d:%02d:%02d                    Health code = %d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, user[index].temp_health_code[i]);
			counter++;
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			User_menu(index);
		}
	}
	else if (strcmp(menuop, "4") == 0 || strcmp(strlwr(menuop), "meet other users") == 0) {
		system("cls");
		//char ncou[20];
		do
		{
			printf(" Enter National code of user whom you met : ");
			gets_s(user[index].met_person_nc[user[index].tmeet]);
		} while (strcmp(user[index].met_person_nc[user[index].tmeet], "") == 0);
		int i;
		bool yaft = false;
		for (i = 0;i < countofusers;i++) {
			if (strcmp(user[index].met_person_nc[user[index].tmeet], user[i].nationalcode) == 0&&user[i].dead_flag==0) {
				yaft = true;
				break;
			}
		}
		if (yaft) {
			user[index].met_person_health_code[user[index].tmeet] = user[i].health_code;
			strcpy(user[index].met_person_name[user[index].tmeet], user[i].firstname);
			user[index].meet[user[index].tmeet] = time(NULL);
			user[i].meet[user[i].tmeet] = time(NULL);
			time_t now = time(NULL);
			if (user[index].health_code < user[i].health_code) {
				user[index].health_code = user[i].health_code - 1;
				if (user[index].health_code > 1) {
					for (int j = 0;j < countofusers;j++) {
						for (int k = 0;k < user[j].tmeet;k++) {
							if ((user[j].health_code < user[index].health_code) && (strcmp(user[j].met_person_nc[k], user[index].nationalcode) == 0) && (now - user[j].meet[k] < 604800)) {
								user[j].health_code = user[index].health_code - 1;
							}
						}
					}
				}
			}
			else if (user[index].health_code > user[i].health_code) {
				user[i].health_code = user[index].health_code - 1;
				if (user[i].health_code > 1) {
					for (int j = 0;j < countofusers;j++) {
						for (int k = 0;k < user[j].tmeet;k++) {
							if ((user[j].health_code < user[i].health_code) && (strcmp(user[j].met_person_nc[k], user[i].nationalcode) == 0) && (now - user[j].meet[k] < 604800)) {
								user[j].health_code = user[i].health_code - 1;
							}
						}
					}
				}
			}
			
			user[index].tmeet++;
			user[i].tmeet++;
			char back[10];
			printf(" Meet recorded Enter <back> to go back to your menu...");
			gets_s(back);
			if (strcmp(strlwr(back), "back") == 0) {
				printf(" please wait to go back to your menu");
				Sleep(sleeptime);
				User_menu(index);
			}
		}
		if (!yaft) {
			puts(" Not found");
		}
	}
	else if (strcmp(menuop, "5") == 0 || strcmp(strlwr(menuop), "meeting History") == 0) {
		system("cls");
		for (int counter = 0, i = user[index].tmeet-1;(i >= 0)&&(counter < 10);i--) {
			struct tm tm = *localtime(&user[index].meet[i]);
			//int j = 0;
			//for (j = 0;j < countofusers;j++)
			printf(" %d-%02d-%02d   %02d:%02d:%02d          Name of user whom you met : %s          Health code of user whom you met = %d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, user[index].met_person_name[i], user[index].met_person_health_code[i]);
			counter++;
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			User_menu(index);
		}
	}
	else if (strcmp(menuop, "6") == 0 || strcmp(strlwr(menuop), "add where you went") == 0) {
		system("cls");
		do
		{
			printf(" Enter Name of Place you went : ");
			gets_s(user[index].met_place[user[index].tplace]);
		} while (strcmp(user[index].met_place[user[index].tplace], "") == 0);
		
		int i;
		bool yaft = false;
		for (i = 0;i < countofshop_owners;i++) {
			if (strcmp(user[index].met_place[user[index].tplace], shop_owner[i].placename) == 0) {
				yaft = true;
				break;
			}
		}
		char ans[5];
		if (yaft) {
			if (strcmp(shop_owner[i].place_code, "Red") == 0) {
				do
				{
					printf(" This place is << dangerous >> do you continue ? ( _yes_  or  _no_ )");
					gets_s(ans);
				} while (strcmp(ans, "") == 0);
				if (strcmp(ans, "no") == 0) {
					User_menu(index);
				}
				if (strcmp(ans, "yes") == 0) {
					if (user[index].health_code == 1) {
						user[index].health_code = 2;
					}
					strcpy(user[index].met_place_status[user[index].tplace], shop_owner[i].place_code);

					user[index].place[user[index].tplace] = time(NULL);



					user[index].tplace++;
				}
			}
			if (strcmp(shop_owner[i].place_code, "White") == 0) {
				if (user[index].health_code == 4) {
					strcpy(shop_owner[i].place_code, "Red");
					shop_owner[i].reg = time(NULL);
				}
				strcpy(user[index].met_place_status[user[index].tplace], shop_owner[i].place_code);

				user[index].place[user[index].tplace] = time(NULL);



				user[index].tplace++;
			}
			char back[10];
			printf(" Enter <back> to go back to your menu...");
			gets_s(back);
			if (strcmp(strlwr(back), "back") == 0) {
				printf(" please wait to go back to your menu");
				Sleep(sleeptime);
				User_menu(index);
			}
		}
		if (!yaft) {
			puts(" Not found");
		}
	}
	else if (strcmp(menuop, "7") == 0 || strcmp(strlwr(menuop), "places you went to") == 0) {
		system("cls");
		int counter = 0;
		for (int i = user[index].tplace - 1;(i >= 0) && (counter < 10);i--) {
			struct tm tm = *localtime(&user[index].place[i]);
			printf(" %d-%02d-%02d   %02d:%02d:%02d          Name of Place : %s          Place code = %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, user[index].met_place[i],user[index].met_place_status[i]);
			counter++;
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			User_menu(index);
		}
	}
	else if (strcmp(menuop, "8") == 0 || strcmp(strlwr(menuop), "corona statistics") == 0) {
		system("cls");
		int sick_in_day = 0, sick_in_week = 0;
		time_t now = time(NULL);
		for (int i = 0;i < countofusers;i++) {
			if (user[i].health_code == 4) {
				if (now - user[i].test[user[i].ttest - 1] < 86400) {
					sick_in_day++;
				}
				if (now - user[i].test[user[i].ttest - 1] < 604800) {
					sick_in_week++;
				}
			}
		}
		printf(" Number of users who became sick up to 24 hours ago : %d\n", sick_in_day);
		printf(" Number of users who became sick up to 7 days ago : %d\n", sick_in_week);
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			User_menu(index);
		}
	}
	else if (strcmp(menuop, "9") == 0 || strcmp(strlwr(menuop), "hospitals list") == 0) {
		system("cls");
		char cit[30], reg[30];
		do
		{
			printf(" Enter your City : ");
			gets_s(cit);
		} while (strcmp(cit, "") == 0);
		do
		{
			printf(" Enter your Region : ");
			gets_s(reg);
		} while (strcmp(reg, "") == 0);
		bool yaft = false;
		for (int i = 0;i < countofhospitals;i++) {
			if (strcmp(cit, hospital[i].city) == 0 && strcmp(reg, hospital[i].region) == 0) {
				printf(" Name of Hospital : %s , City : %s , Region : %s\n", hospital[i].name, hospital[i].city, hospital[i].region);
				yaft = true;
			}
		}
		if (!yaft) {
			printf(" There is no hospital in your area :(( \n");
		}
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			User_menu(index);
		}
	}
	else if (strcmp(menuop, "10") == 0 || strcmp(strlwr(menuop), "lock") == 0)Lock();
	else if (strcmp(menuop, "0") == 0 || strcmp(strlwr(menuop), "exit") == 0)EXit();
	printf(" please wait to go back to your menu");
	Sleep(sleeptime);
	User_menu(index);
}
void Shop_owner_menu(int index) {
	system("cls");
	system("color bi");
	char menuop[30],note[5];
	printf("\n                                  Hello %s\n\n",shop_owner[index].firstname);
	printf(" Place code : %s\n\n", shop_owner[index].place_code);
	puts("  1 : Notify for cleaning");
	puts("  2 : Numbre of sick people (that were in your place)");
	puts("  3 : Edit Profile");
	puts("  4 : Lock");
	puts("  0 : Exit");
	do
	{
		gets_s(menuop);
	} while (strcmp(menuop, "") == 0);
	if (strcmp(menuop, "1") == 0 || strcmp(strlwr(menuop), "add hospital") == 0) {
		printf(" Did you clean your place ? (1 : Yes _ 0 : No) ");
		scanf("%s", note);
		getchar();
		if (strcmp(note, "1") == 0 || strcmp(strlwr(note), "Yes") == 0)strcpy(shop_owner[index].place_code, "White");
	}
	else if (strcmp(menuop, "2") == 0 || strcmp(strlwr(menuop), "numbre of sick people") == 0) {
		system("cls");
		int number_of_patients = 0;
		for (int i = 0;i < countofusers;i++) {
			if (user[i].health_code > 1) {
				for (int j = 0;j < user[i].tplace;j++) {
					if (strcmp(user[i].met_place[j], shop_owner[index].placename) == 0) {
						number_of_patients++;
						break;
					}
				}
			}
		}
		printf(" Number of Patients who came to your place = %d\n", number_of_patients);
		char back[10];
		printf(" Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Shop_owner_menu(index);
		}
	}
	else if (strcmp(menuop, "3") == 0 || strcmp(strlwr(menuop), "edit profile") == 0) {
		system("cls");
		do
		{
			printf(" Enter your new Firstname : ");
			gets_s(shop_owner[index].firstname);
		} while (strcmp(shop_owner[index].firstname, "") == 0);
		do
		{
			printf(" Enter your new Lastname : ");
			gets_s(shop_owner[index].lastname);
		} while (strcmp(shop_owner[index].lastname, "") == 0);
		do
		{
			printf(" Enter your new National code : ");
			gets_s(shop_owner[index].nationalcode);
			int i;
			for (i = 0;i < countofshop_owners;i++) {
				if (strcmp(shop_owner[index].nationalcode, shop_owner[i].nationalcode) == 0 && i != index) {
					break;
				}
			}
			while (strcmp(shop_owner[index].nationalcode, shop_owner[i].nationalcode) == 0 && i != index)
			{
				printf(" It already used ... Enter your new National code (dont enter space): ");
				gets_s(shop_owner[index].nationalcode);
				for (i = 0;i < countofshop_owners;i++) {
					if (strcmp(shop_owner[index].nationalcode, shop_owner[i].nationalcode) == 0 && i != index) {
						break;
					}
				}
			}
		} while (strcmp(shop_owner[index].nationalcode, "") == 0);
		do
		{
			printf(" Enter your new Username (dont enter space): ");
			gets_s(shop_owner[index].username);
			int i;
			for (i = 0;i < countofshop_owners;i++) {
				if (strcmp(shop_owner[index].username, shop_owner[i].username) == 0 && i != index) {
					break;
				}
			}
			while (strcmp(shop_owner[index].username, shop_owner[i].username) == 0 && i != index)
			{
				printf(" It already used ... Enter your new Username (dont enter space): ");
				gets_s(shop_owner[index].username);
				for (i = 0;i < countofshop_owners;i++) {
					if (strcmp(shop_owner[index].username, shop_owner[i].username) == 0 && i != index) {
						break;
					}
				}
			}
		} while (strcmp(shop_owner[index].username, "") == 0);
		char rpass[30], password[30];
		printf(" Enter your new Password (dont enter space): ");
		int count = 0;
		while (1) {
			password[count] = getch();
			if (password[count] == '\b' && count > 0) {
				printf("\b \b");
				count--;
			}
			else if (password[0] == '\r') {}
			else if (password[count] != '\r') {
				printf("*");
				count++;
			}
			else if (password[count] == '\r') {
				count++;
				break;
			}
		}
		password[count - 1] = '\0';
		puts("");
		printf(" Enter your new Password again : ");
		int counte = 0;
		while (1) {
			rpass[counte] = getch();
			if (rpass[counte] == '\b' && counte > 0) {
				printf("\b \b");
				counte--;
			}
			else if (rpass[0] == '\r') {}
			else if (rpass[counte] != '\r') {
				printf("*");
				counte++;
			}
			else if (rpass[counte] == '\r') {
				counte++;
				break;
			}
		}
		rpass[counte - 1] = '\0';
		puts("");
		while (strcmp(password, rpass) != 0) {
			printf("\n The entered Passwords are different.  try again\n\n");
			printf(" Enter your new Password (dont enter space): ");
			int coun = 0;
			while (1) {
				password[coun] = getch();
				if (password[coun] == '\b' && coun > 0) {
					printf("\b \b");
					coun--;
				}
				else if (password[0] == '\r') {}
				else if (password[coun] != '\r') {
					printf("*");
					coun++;
				}
				else if (password[coun] == '\r') {
					coun++;
					break;
				}
			}
			password[coun - 1] = '\0';
			puts("");
			printf(" Enter your new Password again : ");
			int counter = 0;
			while (1) {
				rpass[counter] = getch();
				if (rpass[counter] == '\b' && counter > 0) {
					printf("\b \b");
					counter--;
				}
				else if (rpass[0] == '\r') {}
				else if (rpass[counter] != '\r') {
					printf("*");
					counter++;
				}
				else if (rpass[counter] == '\r') {
					counter++;
					break;
				}
			}
			rpass[counter - 1] = '\0';
			puts("");
		}
		strcpy(shop_owner[index].password, password);
		do
		{
			printf(" Enter your new Email : ");
			gets_s(shop_owner[index].email);
		} while (strcmp(shop_owner[index].email, "") == 0);
		do
		{
			printf(" Enter new Name of your shop : ");
			gets_s(shop_owner[index].placename);
		} while (strcmp(shop_owner[index].placename, "") == 0);
		do
		{
			printf(" Enter your new City : ");
			gets_s(shop_owner[index].city);
		} while (strcmp(shop_owner[index].city, "") == 0);
		do
		{
			printf(" Enter your new Region : ");
			gets_s(shop_owner[index].region);
		} while (strcmp(shop_owner[index].region, "") == 0);
		char back[10];
		printf(" New information recorded. Enter <back> to go back to your menu...");
		gets_s(back);
		if (strcmp(strlwr(back), "back") == 0) {
			printf(" please wait to go back to your menu");
			Sleep(sleeptime);
			Shop_owner_menu(index);
		}
	}
	else if (strcmp(menuop, "4") == 0 || strcmp(strlwr(menuop), "lock") == 0)Lock();
	else if (strcmp(menuop, "0") == 0 || strcmp(strlwr(menuop), "exit") == 0)EXit();
	printf(" please wait to go back to your menu");
	Sleep(sleeptime);
	Shop_owner_menu(index);
}
void EXit() {
	fp = fopen("users.bin", "wb");
	fwrite(&countofusers, sizeof(int), 1, fp);
	fwrite(&user, sizeof(struct people), countofusers + 1, fp);
	fclose(fp);
	fp = fopen("shop_owners.bin", "wb");
	fwrite(&countofshop_owners, sizeof(int), 1, fp);
	fwrite(&shop_owner, sizeof(struct job_owner), countofshop_owners + 1, fp);
	fclose(fp);
	fp = fopen("admin.bin", "wb");
	fwrite(&countofadmin, sizeof(int), 1, fp);
	fwrite(&admin, sizeof(struct manager), countofadmin + 1, fp);
	fclose(fp);
	fp = fopen("hospitals.bin", "wb");
	fwrite(&countofhospitals, sizeof(int), 1, fp);
	fwrite(&hospital, sizeof(struct clinic), countofhospitals + 1, fp);
	fclose(fp);
	exit(0);
}