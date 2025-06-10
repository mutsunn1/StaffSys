#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <fstream>
using namespace std;

// 定义员工结构体
struct Employee
{
    char id[20];       // 工号
    char name[50];     // 姓名
    char position[50]; // 职位
    double salary;     // 工资
};

Employee employees[100]; // 员工数组
int employeeCount = 0;

// 手动添加测试数据
Employee e1 = {"E001", "张三", "销售", 5000.0};
Employee e2 = {"E003", "李四", "经理", 8000.0};
Employee e3 = {"E002", "王五", "技术", 6500.0};

// 交换两个员工信息
void swapEmployees(Employee &a, Employee &b)
{
    Employee temp = a;
    a = b;
    b = temp;
}

// 冒泡排序函数 - 按工号排序
void sortById(Employee employees[], int size, bool ascending = true)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            bool needSwap = ascending ? (strcmp(employees[j].id, employees[j + 1].id) > 0) : (strcmp(employees[j].id, employees[j + 1].id) < 0);
            if (needSwap)
            {
                swapEmployees(employees[j], employees[j + 1]);
            }
        }
    }
}

// 冒泡排序函数 - 按姓名排序
void sortByName(Employee employees[], int size, bool ascending = true)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            bool needSwap = ascending ? (strcmp(employees[j].name, employees[j + 1].name) > 0) : (strcmp(employees[j].name, employees[j + 1].name) < 0);
            if (needSwap)
            {
                swapEmployees(employees[j], employees[j + 1]);
            }
        }
    }
}

// 冒泡排序函数 - 按职位排序
void sortByPosition(Employee employees[], int size, bool ascending = true)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            bool needSwap = ascending ? (strcmp(employees[j].position, employees[j + 1].position) > 0) : (strcmp(employees[j].position, employees[j + 1].position) < 0);
            if (needSwap)
            {
                swapEmployees(employees[j], employees[j + 1]);
            }
        }
    }
}
// 打印员工信息
void printEmployees(Employee employees[], int size)
{
    cout << "员工列表：" << endl;
    cout << "工号\t姓名\t职位\t工资" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << employees[i].id << "\t"
             << employees[i].name << "\t"
             << employees[i].position << "\t"
             << employees[i].salary << endl;
    }
    cout << endl;
}
void Sort()
{
    cout << "请选择排序方式：" << endl;
    cout << "1. 按工号排序" << endl;
    cout << "2. 按姓名排序" << endl;
    cout << "3. 按职位排序" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    if(choice < 1 || choice > 3)
    {
        cout << "无效选项，请重新输入" << endl;
    }
    cout << "请选择排序顺序：" << endl;
    cout << "1. 升序" << endl;
    cout << "2. 降序" << endl;
    cout << "请输入您的选择：";
    int orderChoice;
    cin >> orderChoice;
    bool isAscending = (orderChoice == 1);

    switch (choice)
    {
    case 1:
        sortById(employees, employeeCount, isAscending);
        break;
    case 2:
        sortByName(employees, employeeCount, isAscending);
        break;
    case 3:
        sortByPosition(employees, employeeCount, isAscending);
        break;
    default:
        cout << "无效的选择！" << endl;
        return;
    }

    // 打印排序结果
    printEmployees(employees, employeeCount);
}

int main()
{
    // 初始化员工数据
    employees[0] = e1;
    employees[1] = e2;
    employees[2] = e3;
    employeeCount = 3;

    // 进行排序操作
    Sort();

    return 0;
}