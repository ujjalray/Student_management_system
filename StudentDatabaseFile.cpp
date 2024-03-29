#include<iostream>
#include<fstream>

using namespace std;
int ID;

class Student
{

public:

    int id;
    string name;
    int age;
    string stream;

    void addStudent()
    {
        cout<<"Enter name"<<endl;
        cin.get();
        getline(cin,name);
        cout<<"Enter your age"<<endl;
        cin>>age;
        cout<<"Enter your stream"<<endl;
        cin.get();
        getline(cin,stream);
        ID++;

        ofstream fout;
        fout.open("C:/File/student.txt", ios::app);
        fout<<"\n"<<ID;
        fout<<"\n"<<name;
        fout<<"\n"<<age;
        fout<<"\n"<<stream;
        fout.close();

        fout.open("C:/File/id.txt",ios::app);
        fout<<"\n"<<ID;
        fout.close();

        cout<<"Record added successfully"<<endl;
    }

    void printAllStudent()
    {
        ifstream fin;
        Student s;

        fin.open("C:/File/student.txt");

        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);

            fin>>s.age;
            fin.ignore();

            getline(fin,s.stream);

            cout<<"ID  =>"<<s.id<<", ";
            cout<<"Name  =>"<<s.name<<", ";
            cout<<"Age  =>"<<s.age<<", ";
            cout<<"Stream  =>"<<s.stream<<" "<<endl;

        }
        fin.close();
    }


    void searchStudent(int id)
    {

        ifstream fin;

        Student s;

        fin.open("C:/File/student.txt");

        while(!fin.eof())
        {
            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);

            fin>>s.age;
            fin.ignore();

            getline(fin,s.stream);


            if(s.id==id)
            {
                cout<<"ID  =>"<<s.id<<", ";
                cout<<"Name  =>"<<s.name<<", ";
                cout<<"Age  =>"<<s.age<<", ";
                cout<<"Stream  =>"<<s.stream<<" "<<endl;

            }
        }

        fin.close();
    }


    void updateStudent(int id)
    {


       deleteStudent(id);

       Student s;
       cout<<"Enter name"<<endl;
       cin.get();
       getline(cin,s.name);
       cout<<"Enter Age"<<endl;
       cin>>s.age;
       cout<<"Enter Stream"<<endl;
       cin.get();
       getline(cin,s.stream);

       ofstream fout;
       fout.open("c:/file/student.txt", ios::app);

       fout<<"\n"<<id;
       fout<<"\n"<<s.name;
       fout<<"\n"<<s.age;
       fout<<"\n"<<s.stream;

       fout.close();

       cout<<"Record Updated Successfully"<<endl;

  }




    void deleteStudent(int id)
    {

       ifstream fin;

       fin.open("C:/File/student.txt");

       ofstream fout;

       fout.open("C:/File/temp.txt");

       Student s;

       while(!fin.eof())
       {

            fin>>s.id;
            fin.ignore();
            getline(fin,s.name);

            fin>>s.age;
            fin.ignore();

            getline(fin,s.stream);


            if(s.id!=id)
            {

                fout<<s.id;
                fout<<s.name;
                fout<<s.age;
                fout<<s.stream;
            }
       }

       fin.close();
       fout.close();


       remove("C:/File/student.txt");
       rename("C:/File/temp.txt","C:/File/student.txt");

       cout<<"Record Delete successfully"<<endl;


    }


};

int main()
{
    int choice;

    ifstream fin;

    fin.open("C:/File/id.txt");

    if(!fin)
    {
        cout<<"File Not Found"<<endl;
    }
    else
    {
        while(!fin.eof())
        {
            fin>>ID;                     //read value store in id gloval variable;
        }
    }


    fin.close();


    cout<<"============================================"<<endl<<endl;


    while(true)
    {


        cout<<"Enter your choice "<<endl<<endl;
        cout<<"1. Add Student"<<endl<<endl;
        cout<<"2. Print all students"<<endl<<endl;
        cout<<"3. Search a student"<<endl<<endl;
        cout<<"4. Update a student"<<endl<<endl;
        cout<<"5. Delete a student"<<endl<<endl;

        cin>>choice;

        Student s;
        int id;

        switch(choice)
        {
        case 1:
            s.addStudent();
            break;

        case 2:
            s.printAllStudent();
            break;

        case 3:
            cout<<"Enter student id"<<endl;
            cin>>id;
            s.searchStudent(id);
            break;

        case 4:
            cout<<"Enter student id"<<endl;
            cin>>id;
            s.updateStudent(id);
            break;

        case 5:
            cout<<"Enter student id"<<endl;
            cin>>id;
            s.deleteStudent(id);
            break;

        default :

            return 0;

        }

    }

    return 0;
}
