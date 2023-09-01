#include <iostream>
#include <string.h>
using namespace std;
struct product
{
    int ID;
    char name[150];
    float price;
};
typedef struct product product;
void enter_prod(product l[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> l[i].ID;
        cout << "Name: ";
        getchar();
        gets(l[i].name);
        cout << "Price: ";
        cin >> l[i].price;
    }
}
void exp_prod(product l[], int n)
{
    cout << "\n******************************";
    cout << "\nID\tName\tPrice\n";
    for (int i = 0; i < n; i++)
    {
        cout << l[i].ID << "\t" << l[i].name << "\t" << l[i].price << endl;
    }
    cout << "******************************\n";
}
product *product_search(product l[], int n, float find_price)
{
    int left = 0;
    int right = n - 1;
    int mid;
    do
    {
        mid = (left + right) / 2;
        if (l[mid].price == find_price)
            return &l[mid];
        else if (l[mid].price > find_price)
            right = mid - 1;
        else
            left = mid + 1;
    } while (left <= right);
    return NULL;
}
int main()
{
    int n;
    product l[n];
    cout << "Enter n: ";
    cin >> n;
    enter_prod(l, n);
    exp_prod(l, n);
    float fp;
    cout << "Enter price to find product: ";
    cin >> fp;
    product *p = product_search(l, n, fp);
    if (p == NULL)
    {
        cout << "Product not found";
    }
    else
    {
        cout << "\n******************************";
        cout << "\nID\tName\tPrice\n";
        cout << p->ID << "\t" << p->name << "\t" << p->price;
        cout << "\n******************************";
    }
}