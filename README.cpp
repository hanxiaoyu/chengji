chengji
=======
//程序实现
#include<iostream>
#include<iomanip>
using namespace std;
//Student数据结构定义
int studentCount = 0;

struct Student
{
	char name[20];

	char number[20];
    
	int score;
    
}
students[100];
void list();
void in();
int find(char* number);
void out();
void inputScore();
int main()
{
	
	//菜单显示
	do
	{
		int action;
		cout<<endl;
		cout<<"1)查看学生名单"<<endl;
		cout<<"2)选课"<<endl;
		cout<<"3)退选"<<endl;
		cout<<"4)录入成绩"<<endl;
		cout<<"5)退出程序"<<endl;
		cin>>action;
		switch(action)
		{
			case 1:
				list();
				break;
			case 2:
				in();
				break;
			case 3:
				out();
				break;
			case 4:
				inputScore();
				break;
			case 5:
				return 0;
			default:
				cout<<"您输入了错误的菜单项，请重新选择！";
		}
	}while(1);
}
//list 显示学生信息
void list(){
	
    cout<<setw(20)<<"姓名"<<setw(20)<<"学号"<<setw(20)<<"成绩"<<endl;
    
    for(int i=0;i<studentCount;i++){
    
        cout<<setw(20)<<students[i].name;
        
        cout<<setw(20)<<students[i].number;
		
		cout<<setw(20)<<students[i].score<<endl;
    }
}
//in 选课（添加新学生）
void in(){
    struct Student student;
    cout<<"姓名：";
    cin>>student.name;
    cout<<"学号：";
    cin>>student.number;
    strcpy(students[studentCount].name,student.name);
	strcpy(students[studentCount].number,student.number);
	students[studentCount].score=-1;
    studentCount++;
}
//find 按学号查找
int find(char* number){
   int i;
   for(i=0;i<studentCount;i++){
      if(strcmp(students[i].number,number)==0){
         break;
      }
   }
   return i;
}
//out 退选（删除学生）
void out(){
    struct Student student;
    cout<<"学号：";
    cin>>student.number;
    for(int i=find(student.number);i<studentCount;i++)
	{
		students[i]=students[i+1];
	}
	strcpy(students[studentCount-1].name,"0");
	strcpy(students[studentCount-1].number,"0");
	students[studentCount-1].score=0;
	studentCount--;
}
//录入成绩
void inputScore()
{
	char number[20];
	cout<<"请输入开始录入的学号：";
	cin>>number;
	int i=find(number);
	for(;i<studentCount;i++)
	{
		if(students[i].score!=-1)
		{
			cout<<"第"<<i+1<<"个学生("<<students[i].name<<","<<students[i].number<<")的成绩已录入"<<endl;
			continue;
		}
		int j;
		cout<<"请输入第"<<i+1<<"个学生的成绩:";
		cin>>students[i].score;
		cout<<"请选择是否继续,1：继续，2：不继续"<<endl;
		cin>>j;
		if(j==2)
			break;
	}
}


