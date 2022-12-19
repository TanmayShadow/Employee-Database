
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Employee
{
	int id,age;
	char name[30],department[20];
	float salary;
public:
	void getData()
	{
		cout<<"\nID:";
		cin>>id;
		cout<<"Name:";
		cin>>name;
		cout<<"Age:";
		cin>>age;
		cout<<"Department:";
		cin>>department;
		cout<<"Salary:";
		cin>>salary;
	}
	void display()
	{
		cout<<"\n****** E M P L O Y E E   D A T A B A S E *******";
		cout<<"\nID:"<<id;
		cout<<"\nName:"<<name;
		cout<<"\nAge:"<<age;
		cout<<"\nDepartment:"<<department;
		cout<<"\nSalary:"<<salary<<endl;
	}
	int getId()
	{
		return this->id;
	}
};

int main()
{
	Employee e1;
	fstream file;
	int ch;
	int id;
	bool flag=false;
	do
	{
		cout<<"\n\t1.Insert Data.";
		cout<<"\n\t2.Display.";
		cout<<"\n\t3.Search Record";
		cout<<"\n\t4.Delete Record";
		cout<<"\n\t5.Update Record";
		cout<<"\n\t6.Exit.";
		cout<<"\nEnter Your Choice:";
		cin>>ch;

		switch(ch)
		{
			case 1:
				e1.getData();
				file.open("C:/Users/admin/Desktop/employee.txt",ios::app|ios::out|ios::binary);
				file.write((char*)&e1,sizeof(Employee));
				file.close();
				break;
			case 2:
				file.open("C:/Users/admin/Desktop/employee.txt",ios::in|ios::binary);
				if(file.eof())
					cout<<"\nFile is empty";
				else
				{
					Employee e2;
					while(file.read((char*)&e2,sizeof(Employee)))
					{
						e2.display();
					}
				}
				file.close();
				break;
			case 3:
				flag=false;
				cout<<"\nEnter Id of employee:";
				cin>>id;
				file.open("C:/Users/admin/Desktop/employee.txt",ios::in|ios::binary);
				if(file.eof())
					cout<<"\nFile is empty";
				else
				{
					Employee e;
					while(file.read((char*)&e,sizeof(Employee)))
					{
						if(e.getId()==id)
						{
							cout<<"\nData Found"<<endl;
							flag=true;
							e.display();
							break;
						}
					}
					if(flag==false)
						cout<<"\nData Not Found";
				}
				break;
			case 4:
				cout<<"\nEnter ID of employee to be deleted:";
				cin>>id;
				file.open("C:/Users/admin/Desktop/employee.txt",ios::in|ios::binary);
				if(file.eof())
					cout<<"File is empty";
				else
				{
					Employee e;
					ofstream fout("C:/Users/admin/Desktop/newemployee.txt");
					while(file.read((char*)&e,sizeof(Employee)))
					{
						if(e.getId()!=id)
							fout.write((char*)&e,sizeof(Employee));
					}
					fout.close();
					file.close();
					remove("C:/Users/admin/Desktop/employee.txt");
					rename("C:/Users/dmin/Desktop/newemployee.txt","C:/Users/admin/Desktop/employee.txt");
					cout<<"\nData Deleted..."<<endl;
				}
				file.close();
				break;
			case 5:
				flag=false;
				cout<<"\nEnter ID of employee:";
				cin>>id;
				file.open("C:/Users/admin/Desktop/employee.txt",ios::in|ios::binary);
				if(file.eof())
					cout<<"\nFile is empty";
				else
				{
					Employee e;
					ofstream fout("C:/Users/admin/Desktop/newemployee.txt");
					while(file.read((char*)&e,sizeof(Employee)))
					{
						if(e.getId()==id)
						{
							e.getData();
							flag=true;
						}
						fout.write((char*)&e, sizeof(Employee));
					}
					fout.close();
					file.close();
					remove("C:/Users/admin/Desktop/employee.txt");
					rename("C:/Users/admin/Desktop/newemployee.txt","C:/Users/admin/Desktop/employee.txt");
					if(flag)
						cout<<"\nRecord Updated.."<<endl;
					else
						cout<<"\nRecord Not Found.."<<endl;
				}
				break;
		}
	}while(ch!=6);

	return 0;
}




