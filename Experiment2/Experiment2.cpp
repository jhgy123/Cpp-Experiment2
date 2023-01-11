
#include <iostream>
#include <string.h>
using namespace std;
struct Bir           //出生日期bir结构体
{
    int year;        //出生年
    int month;       //出生月
    int day;         //出生日
};

struct  Cinfo         //课程信息cinfo结构体
{
    string name1;    //第1门课程名
    string name2;    //第2门课程名
    string name3;    //第3门课程名
    float score1;    //第1门课程成绩
    float score2;    //第2门课程成绩
    float score3;    //第3门课程成绩
};

class People {       //虚基类people
    long id;         //编号
    string name;     //姓名
    string sex;      //性别
    Bir bir;         //出生日期
public:
    People(long id,string name,string sex,int year,int month,int day) {//构造函数
        this->id = id;
        this->name = name;
        this->sex = sex;
        this->bir.year = year;
        this->bir.month = month;
        this->bir.day = day;
    }
    void show() {    //显示数据成员
        cout << "编号：" << id << " 姓名：" << name << " 性别：" << sex << endl;
        cout << "出生日期：" << bir.year << "年" << bir.month << "月" << bir.day << "日" << endl;
    }
};

class Stud {//基类stud
    string tel;
    string e_mail;
public:
    Stud(string tel, string e_mail) {//构造函数
        this->tel = tel;
        this->e_mail = e_mail;
    }
    void show() {    //显示数据成员
        cout << "联系电话：" << tel << " 邮箱：" << e_mail<< endl;
    }
};

class Teacher:virtual public People{//派生类teacher
    string degree;   //学位
    string dep;      //部门
public:
    //构造函数
    Teacher(long id, string name, string sex, int year,
        int month, int day, string degree, string dep) :People(id, name, sex, year, month, day) {
        this->degree = degree;
        this->dep = dep;
    }
    void show() {    //显示数据成员
        cout << "学位：" << degree << " 部门：" << dep << endl;
    }
};

class Student:virtual public People{//派生类student
    long sno;        //学号
    string major;    //专业
public:
    Student(long id, string name, string sex, int year,
        int month, int day, long sno, string major) :People(id, name, sex, year, month, day) {
        this->sno = sno;
        this->major = major;
    }
    void show() {    //显示数据成员
        cout << "学号：" << sno << " 专业：" << major << endl;
    }
};

class Course:public Stud,public Student {
    Cinfo cinfo;
public:
    //构造函数
    Course(long id, string name, string sex, int year, int month, int day,
        long sno, string major, string tel, string e_mail,
        string cname1, float c1g, string cname2, float c2g, string cname3, float c3g
    ) :Student(id, name, sex, year, month, day, sno, major),
        Stud(tel, e_mail), 
        People(id,name,sex,year,month,day) 
    {
        this->cinfo.name1 = cname1;
        this->cinfo.name2 = cname2;
        this->cinfo.name3 = cname3;
        this->cinfo.score1 = c1g;
        this->cinfo.score2 = c2g;
        this->cinfo.score3 = c3g;

    }
    void show() {  //显示数据成员
        cout << "课程1：" << cinfo.name1 << " 成绩：" << cinfo.score1 << endl;
        cout << "课程2：" << cinfo.name2 << " 成绩：" << cinfo.score2 << endl;
        cout << "课程3：" << cinfo.name3 << " 成绩：" << cinfo.score3 << endl;
    }

};





int main()
{  
    cout << "请输入创建的老师对象的信息：" << endl;
    long id; string name; string sex; int year;
    int month; int day; string degree; string dep;
    //读取创建对象所需的参数内容
    cin >> id >> name >> sex >> year >> month >> day >> degree >> dep;
    Teacher teacher(id, name, sex, year, month, day, degree, dep);
    cout << "-----------------------------------------------" << endl;
    People* p;      //定义一个People指针
    p = &teacher;
    p->show();      //多态，调用teacher的虚基类People的show方法
    teacher.show(); //调用teacher的show方法 
    cout << "请输入创建的课程对象的信息：" << endl;
    long id1; string name1; string sex1; int year1; int month1; int day1;
    long sno1; string major1; string tel1; string e_mail1;
    string cname1; float c1g; string cname2; float c2g; string cname3; float c3g;
    //读取创建对象所需的参数内容
    cin >> id1 >> name1 >> sex1 >> year1 >> month1 >> day1 >> sno1 >> major1 >> tel1 >> e_mail1 >> cname1 >> c1g >> cname2 >> c2g >> cname3 >> c3g;
    cout << float(c2g)<<endl;
    Course course(id1, name1, sex1, year1, month1, day1, sno1, major1, tel1, e_mail1, cname1, c1g, cname2, c2g, cname3, c3g);
    cout << "-----------------------------------------------" << endl;
    p = &course;
    p->show();     //多态，调用course的基类People的show方法
    Stud* st;    //定义一个Stud指针
    st = &course;
    st->show();     //多态，调用course的基类Stud的show方法  
    Student* s;    //定义一个Student指针
    s = &course;
    s->show();     //多态，调用course的基类Student的show方法  
    course.show(); //调用course的show方法
    return 0;
}