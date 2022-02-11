#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define Max 1000
struct Person
{
	string name;
	string sex;		//1�У�2Ů
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
		cout << "���������Ĳ���ѡ�";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "�˳�ʹ��......" << endl << "��л����ʹ�ã�" << endl;
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
			cout << "����ѡ���������������룺";
			cin >> choice;
			break;
		}
		system("pause");
		system("cls");
	} while (choice!=0);	
}

void showMenu()
{
	cout << "     ��ӭ��ʹ��ͨѶ¼��     " << endl;
	cout << "***************************" << endl;
	cout << "*******" << "1�������ϵ��" << "*******" << endl;
	cout << "*******" << "2����ʾ��ϵ��" << "*******" << endl;
	cout << "*******" << "3��ɾ����ϵ��" << "*******" << endl;
	cout << "*******" << "4��������ϵ��" << "*******" << endl;
	cout << "*******" << "5���޸���ϵ��" << "*******" << endl;
	cout << "*******" << "6�������ϵ��" << "*******" << endl;
	cout << "*******" << "0���˳�ͨѶ¼" << "*******" << endl;
	cout << "***************************" << endl;
}

void addPerson(AdressBook *adressBook)
{
	bool flag;
	while (adressBook->book_num < Max)
	{
		cout << "�������" << adressBook->book_num + 1 << "λ��ϵ����Ϣ��" << endl;
		cout << "������"; 
		cin >> adressBook->person[adressBook->book_num].name;		
		cout << "�Ա�"; 
		cin >> adressBook->person[adressBook->book_num].sex; 		
		cout << "�绰��";
		cin >> adressBook->person[adressBook->book_num].PhoneNumber; 		
		cout << "סַ��";
		cin >> adressBook->person[adressBook->book_num].adress; 		
		adressBook->book_num++;		
		cout << "�Ƿ�������(1/0)��"; cin >> flag;
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
		cout << "�ɴ洢��ϵ��������" << endl;
	}
	return;
}

void showPerson(AdressBook *adressBook)
{
	int n = adressBook->book_num;
	cout << "����" << n << "λ��ϵ��" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "��" << i + 1 << "λ��ϵ�ˣ�" << endl;
		cout << "������" << adressBook->person[i].name << "\t�Ա�" << adressBook->person[i].sex 
			<< "\t���룺" << adressBook->person[i].PhoneNumber << "\tסַ��" << adressBook->person[i].adress << endl;
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
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫɾ������ϵ��������";
		cin >> d_name;
		int locate = isExist(adressBook, d_name);
		if (locate == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else if (locate + 1 == Max)
		{
			adressBook->person[locate] = {};
			adressBook->book_num--;
			cout << "��ɾ�����ˣ�" << endl;
		}
		else
		{
			cout << "�Ѳ鵽���ˣ�" << endl;
			for (int i = locate; i < adressBook->book_num; i++)
			{
				adressBook->person[i] = adressBook->person[i + 1];
			}
			adressBook->book_num--;
			cout << "��ɾ�����ˣ�" << endl;
		}
	}
	return;
}

void findPerson(AdressBook *adressBook)
{
	string f_name;
	if (adressBook->book_num == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ���ҵ���ϵ�ˣ�";
		cin >> f_name;
		int find = isExist(adressBook, f_name);
		if (find == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			cout << "���ҳɹ�����ϵ����Ϣ���£�" << endl;
			cout << "������" << adressBook->person[find].name << "\t�Ա�" << adressBook->person[find].sex
				<< "\t���룺" << adressBook->person[find].PhoneNumber << "\tסַ��" << adressBook->person[find].adress << endl;
		}
	}
	return;
}

void changePerson(AdressBook *adressBook)
{
	string c_name;
	if (adressBook->book_num == 0)
	{
		cout << "ͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������Ҫ���ҵ���ϵ�ˣ�";
		cin >> c_name;
		int change = isExist(adressBook, c_name);
		if (change == -1)
		{
			cout << "���޴��ˣ�" << endl;
		}
		else
		{
			cout << "���ҳɹ���ԭ��ϵ����Ϣ���£�" << endl;
			cout << "������" << adressBook->person[change].name << "\t�Ա�" << adressBook->person[change].sex
				<< "\t���룺" << adressBook->person[change].PhoneNumber << "\tסַ��" << adressBook->person[change].adress << endl;
			cout << "�����޸ģ�" << endl;
			cout << "������";
			cin >> adressBook->person[change].name;
			cout << "�Ա�";
			cin >> adressBook->person[change].sex;
			cout << "�绰��";
			cin >> adressBook->person[change].PhoneNumber;
			cout << "סַ��";
			cin >> adressBook->person[change].adress;
		}
	}
}

void deleteAll(AdressBook *adressBoook)
{
	bool sure;
	cout << "���Ƿ�ȷ��ɾ��ȫ����ϵ��(1/0)��";
	cin >> sure;
	if (sure == 0)
	{
		cout << "��ȡ���ò�����" << endl;
		return;
	}
	else
	{
		cout << "��ʼɾ��........" << endl;
		for (int i = 0; i < adressBoook->book_num; ++i)
		{
			adressBoook->person[i] = {};
		}
		cout << "ɾ���ɹ���" << endl;
	}
	return;
}