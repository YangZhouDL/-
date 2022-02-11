#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define Max 1000
struct Person
{
	string name;
	string sex;		//1男，2女
	string PhoneNumber;
	string adress;
};
struct AdressBook
{
	Person person[Max]={};
	int book_num = 0;
};

void showMenu();
void addPerson(AdressBook *adressBook);
void showPerson(AdressBook *adressBook);
int isExist(AdressBook *adressBook,string name);
void deletePerson(AdressBook *adressBook);
void findPerson(AdressBook *adressBook);
void changePerson(AdressBook *adressBoook);
void deleteAll(AdressBook *adressBook);

int main()
{
	int choice;
	AdressBook adressBook;
	do
	{
		showMenu();
		cout << "请输入您的操作选项：";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "退出使用......" << endl << "感谢您的使用！" << endl;
			return 0;
			break;
		case 1:
			addPerson(&adressBook);
			break;
		case 2:
			showPerson(&adressBook);
			break;
		case 3:
			deletePerson(&adressBook);
			break;
		case 4:
			findPerson(&adressBook);
			break;
		case 5:
			changePerson(&adressBook);
			break;
		case 6:
			deleteAll(&adressBook);
			break;
		default:
			cout << "输入选项有误，请重新输入：";
			cin >> choice;
			break;
		}
		system("pause");
		system("cls");
	} while (choice!=0);	
}

void showMenu()
{
	cout << "     欢迎您使用通讯录！     " << endl;
	cout << "***************************" << endl;
	cout << "*******" << "1、添加联系人" << "*******" << endl;
	cout << "*******" << "2、显示联系人" << "*******" << endl;
	cout << "*******" << "3、删除联系人" << "*******" << endl;
	cout << "*******" << "4、查找联系人" << "*******" << endl;
	cout << "*******" << "5、修改联系人" << "*******" << endl;
	cout << "*******" << "6、清空联系人" << "*******" << endl;
	cout << "*******" << "0、退出通讯录" << "*******" << endl;
	cout << "***************************" << endl;
}

void addPerson(AdressBook *adressBook)
{
	bool flag;
	while (adressBook->book_num < Max)
	{
		cout << "请输入第" << adressBook->book_num + 1 << "位联系人信息：" << endl;
		cout << "姓名："; 
		cin >> adressBook->person[adressBook->book_num].name;		
		cout << "性别："; 
		cin >> adressBook->person[adressBook->book_num].sex; 		
		cout << "电话：";
		cin >> adressBook->person[adressBook->book_num].PhoneNumber; 		
		cout << "住址：";
		cin >> adressBook->person[adressBook->book_num].adress; 		
		adressBook->book_num++;		
		cout << "是否继续添加(1/0)："; cin >> flag;
		if(flag==1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (adressBook->book_num == Max )
	{
		cout << "可存储联系人已满！" << endl;
	}
	return;
}

void showPerson(AdressBook *adressBook)
{
	int n = adressBook->book_num;
	cout << "共有" << n << "位联系人" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "第" << i + 1 << "位联系人：" << endl;
		cout << "姓名：" << adressBook->person[i].name << "\t性别：" << adressBook->person[i].sex 
			<< "\t号码：" << adressBook->person[i].PhoneNumber << "\t住址：" << adressBook->person[i].adress << endl;
	}
	return;
}

int isExist(AdressBook *adressBook,string name)
{
	for (int i = 0; i < adressBook->book_num; i++)
	{
		if (adressBook->person[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(AdressBook *adressBook)
{
	string d_name;
	if (adressBook->book_num == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		cout << "请输入您要删除的联系人姓名：";
		cin >> d_name;
		int locate = isExist(adressBook, d_name);
		if (locate == -1)
		{
			cout << "查无此人！" << endl;
		}
		else if (locate + 1 == Max)
		{
			adressBook->person[locate] = {};
			adressBook->book_num--;
			cout << "已删除此人！" << endl;
		}
		else
		{
			cout << "已查到此人！" << endl;
			for (int i = locate; i < adressBook->book_num; i++)
			{
				adressBook->person[i] = adressBook->person[i + 1];
			}
			adressBook->book_num--;
			cout << "已删除此人！" << endl;
		}
	}
	return;
}

void findPerson(AdressBook *adressBook)
{
	string f_name;
	if (adressBook->book_num == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		cout << "请输入您要查找的联系人：";
		cin >> f_name;
		int find = isExist(adressBook, f_name);
		if (find == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			cout << "查找成功！联系人信息如下：" << endl;
			cout << "姓名：" << adressBook->person[find].name << "\t性别：" << adressBook->person[find].sex
				<< "\t号码：" << adressBook->person[find].PhoneNumber << "\t住址：" << adressBook->person[find].adress << endl;
		}
	}
	return;
}

void changePerson(AdressBook *adressBook)
{
	string c_name;
	if (adressBook->book_num == 0)
	{
		cout << "通讯录为空！" << endl;
	}
	else
	{
		cout << "请输入您要查找的联系人：";
		cin >> c_name;
		int change = isExist(adressBook, c_name);
		if (change == -1)
		{
			cout << "查无此人！" << endl;
		}
		else
		{
			cout << "查找成功！原联系人信息如下：" << endl;
			cout << "姓名：" << adressBook->person[change].name << "\t性别：" << adressBook->person[change].sex
				<< "\t号码：" << adressBook->person[change].PhoneNumber << "\t住址：" << adressBook->person[change].adress << endl;
			cout << "请您修改！" << endl;
			cout << "姓名：";
			cin >> adressBook->person[change].name;
			cout << "性别：";
			cin >> adressBook->person[change].sex;
			cout << "电话：";
			cin >> adressBook->person[change].PhoneNumber;
			cout << "住址：";
			cin >> adressBook->person[change].adress;
		}
	}
}

void deleteAll(AdressBook *adressBoook)
{
	bool sure;
	cout << "您是否确认删除全部联系人(1/0)：";
	cin >> sure;
	if (sure == 0)
	{
		cout << "已取消该操作！" << endl;
		return;
	}
	else
	{
		cout << "开始删除........" << endl;
		for (int i = 0; i < adressBoook->book_num; ++i)
		{
			adressBoook->person[i] = {};
		}
		cout << "删除成功！" << endl;
	}
	return;
}