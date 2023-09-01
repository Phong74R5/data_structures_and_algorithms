#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nhanvien
{
	char ms[6];
	char hoten[32];
	char donvi[21];
	int luong;
	int thuong;
};

int ReadFile(nhanvien dsnhanvien[])
{
	int i = 0;
	FILE *f = fopen("danhsach.txt", "rt");
	if (f == NULL)
	{
		cout << "khong the mo file/n";
	}
	else
	{
		char tmp[100];
		char *token;
		while (fgets(tmp, sizeof(tmp), f))
		{
			token = strtok(tmp, "#");
			strcpy(dsnhanvien[i].ms, token);
			token = strtok(NULL, "#");
			strcpy(dsnhanvien[i].hoten, token);
			token = strtok(NULL, "#");
			strcpy(dsnhanvien[i].donvi, token);
			token = strtok(NULL, "#");
			dsnhanvien[i].luong = atoi(token);
			token = strtok(NULL, "#");
			dsnhanvien[i].thuong = atoi(token);
			i++;
		}
	}
	fclose(f);
	return i;
}

void SaveFile(nhanvien nv[], int sonv, FILE *f)
{
	char t[100];
	char lt[10], tt[10];
	for (int i = 0; i < sonv; i++)
	{
		strcpy(t, nv[i].ms);
		strcat(t, "#");
		strcat(t, nv[i].hoten);
		strcat(t, "#");
		strcat(t, nv[i].donvi);
		strcat(t, "#");
		itoa(nv[i].luong, lt, 10);
		strcat(t, lt);
		strcat(t, "#");
		itoa(nv[i].thuong, tt, 10);
		strcat(t, tt);
		strcat(t, "\n");
		fputs(t, f);
	}
}

void nhapnhanvien(nhanvien &nv)
{
	fflush(stdin);
	cout << "ho ten:";
	gets(nv.hoten);
	cout << "ma so nhan vien:";
	gets(nv.ms);
	cout << "don vi:";
	gets(nv.donvi);
	cout << "luong";
	cin >> nv.luong;
	cout << "thuong:";
	cin >> nv.thuong;
}

void AddNhanVien(nhanvien nv[], int &sl)
{
	FILE *f = fopen("danhsach.txt", "wt");
	cout << "nhap thong tin nhan vien moi: ";
	nhapnhanvien(nv[sl]);
	sl++;
	SaveFile(nv, sl, f);
	fclose(f);
}

void ExpNhanVien(nhanvien a)
{
	cout << a.ms << "\t" << a.hoten << "\t" << a.donvi << "\t" << a.luong << "\t" << a.thuong << endl;
}

void ExpDsDonVi(nhanvien dsnv[], int n, char c[100])
{
	for (int i = 0; i < n; i++)
	{
		if (strcmp(c, dsnv[i].donvi) == 0)
		{
			ExpNhanVien(dsnv[i]);
		}
	}
}

void SortNhanVien(nhanvien dsnv[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(dsnv[i].hoten, dsnv[j].hoten) >= 0)
				swap(dsnv[i], dsnv[j]);
		}
	}
}
void swap(nhanvien &nv1, nhanvien &nv2)
{
	nhanvien tmp;
	tmp = nv1;
	nv1 = nv2;
	nv2 = tmp;
}


int main()
{
	nhanvien ds[100];
	int sl = ReadFile(ds);
	ExpDsDonVi(ds, sl, "kinh doanh");
	AddNhanVien(ds,sl);
	SortNhanVien(ds,sl);
}