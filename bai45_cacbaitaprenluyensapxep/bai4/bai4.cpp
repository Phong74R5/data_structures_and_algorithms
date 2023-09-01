#include <algorithm>
#include <cstring>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Student
{
    int id;
    char name[100];
};

struct Class
{
    char ClassName[100];
    Student StudentList[100];
    int nStudent;
};

void EnterStudent(Student &sv)
{
    cout << "Nhap thong tin cho Sinh vien" << endl;
    cout << "ID: ";
    cin >> sv.id;
    cout << "Ten: ";
    cin.ignore();
    cin.getline(sv.name, 100);
}

void EnterClass(Class &lop)
{
    cout << "Nhap thong tin cho Lop hoc" << endl;
    cout << "Ten lop: ";
    cin.ignore();
    cin.getline(lop.ClassName, 100);

    cout << "Nhap so luong Sinh vien: ";
    cin >> lop.nStudent;

    for (int i = 0; i < lop.nStudent; i++)
    {
        EnterStudent(lop.StudentList[i]);
    }
}

void ExpStudent(const Student &sv)
{
    cout << sv.id << " - " << sv.name << endl;
}

void ExpClass(const Class &lop)
{
    cout << "Danh sach Sinh vien trong Lop " << lop.ClassName << ": " << endl;
    for (int i = 0; i < lop.nStudent; i++)
    {
        ExpStudent(lop.StudentList[i]);
    }
}

int main()
{
    system("color 0A");
    int n;
    cout << "Nhap so luong Lop hoc: ";
    cin >> n;

    Class dsLop[n];
    for (int i = 0; i < n; i++)
    {
        EnterClass(dsLop[i]);
    }
    cout << "Xuất sinh vien theo lop:" << endl;
    for (int i = 0; i < n; i++)
    {
        ExpClass(dsLop[i]);
    }

    int nSV = 0;
    cout << "Sap xep sinh vien theo ID:" << endl;
    for (int j = 0; j < n; j++)
    {
        nSV += dsLop[j].nStudent;
    }
    Student dsSV[nSV];
    int k = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < dsLop[j].nStudent; i++)
        {
            dsSV[k] = dsLop[j].StudentList[i];
            k++;
        }
    }
    for (int i = 0; i < nSV; i++)
    {
        for (int j = i + 1; j < nSV; j++)
        {
            if (dsSV[i].id > dsSV[j].id)
            {
                Student temp = dsSV[i];
                dsSV[i] = dsSV[j];
                dsSV[j] = temp;
            }
        }
    }
    for (int i = 0; i < nSV; i++)
    {
        ExpStudent(dsSV[i]);
    }
    system("pause");
}
