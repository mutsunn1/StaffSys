#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <map>
#include <limits>
using namespace std;

// 定义员工结构体
struct Employee
{
    char id[20];       // 工号
    char name[50];     // 姓名
    char position[50]; // 职位
};

Employee employees[100];    // 员工数组
Employee tempEmployee[100]; // 临时员工变量
int employeeCount = 0;


// 手动添加测试数据，完成后删除
Employee e1 = {"E001", "张三", "销售"};
Employee e2 = {"E003", "李四", "经理"};
Employee e3 = {"E002", "王五", "技术"};
// 打印员工信息
void printEmployees(Employee employees[], int size)
{
    cout << "员工列表：" << endl;
    cout << "工号\t姓名\t职位" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << employees[i].id << "\t"
             << employees[i].name << "\t"
             << employees[i].position << endl;
    }
    cout << endl;
}
void searchEmployee()
{
    int choice;
    cout << "\n===== 查询员工 =====\n";
    cout << "1. 按工号查询\n";
    cout << "2. 按姓名查询\n";
    cout << "3. 按职位查询\n";
    cout << "请选择查询方式: ";
    cin >> choice;

    // 清除输入缓冲区
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool found = false;

    switch (choice)
    {
    case 1:
    { // 按工号查询
        char searchId[20];
        cout << "请输入要查询的工号: ";
        cin.getline(searchId, sizeof(searchId));

        cout << "\n查询结果:\n";
        cout << "工号\t姓名\t职位" << endl;
        for (int i = 0; i < employeeCount; i++)
        {
            if (strcmp(employees[i].id, searchId) == 0)
            {
                cout << employees[i].id << "\t"
                     << employees[i].name << "\t"
                     << employees[i].position << endl;
                found = true;
                break; // 工号唯一，找到后即可退出
            }
        }
        break;
    }
    case 2:
    { // 按姓名查询
        char searchName[50];
        cout << "请输入要查询的姓名: ";
        cin.getline(searchName, sizeof(searchName));

        cout << "\n查询结果:\n";
        cout << "工号\t姓名\t职位" << endl;
        for (int i = 0; i < employeeCount; i++)
        {
            if (strcmp(employees[i].name, searchName) == 0)
            {
                cout << employees[i].id << "\t"
                     << employees[i].name << "\t"
                     << employees[i].position << endl;
                found = true;
            }
        }
        break;
    }
    case 3:
    { // 按职位查询
        char searchPosition[50];
        cout << "请输入要查询的职位: ";
        cin.getline(searchPosition, sizeof(searchPosition));

        cout << "\n查询结果:\n";
        cout << "工号\t姓名\t职位" << endl;
        for (int i = 0; i < employeeCount; i++)
        {
            if (strcmp(employees[i].position, searchPosition) == 0)
            {
                cout << employees[i].id << "\t"
                     << employees[i].name << "\t"
                     << employees[i].position << endl;
                found = true;
            }
        }
        break;
    }
    default:
        cout << "无效的选择！" << endl;
        return;
    }

    if (!found)
    {
        cout << "未找到匹配的员工信息！" << endl;
    }
}
void deleteEmployee(int index) // 删除函数
{
    if (index < 0 || index >= employeeCount)
    {
        cout << "无效的索引！" << endl;
        return;
    }
    // 将后面的员工信息前移
    for (int i = index; i < employeeCount - 1; i++)
    {
        employees[i] = employees[i + 1];
    }
    employeeCount--; // 减少员工数量
    cout << "员工信息已删除。" << endl;
}
void deleteEmployeeBySearch()
{ // 删除函数界面
    searchEmployee();

    int length = sizeof(tempEmployee) / sizeof(tempEmployee[0]); // 获取数组长度
    printEmployees(tempEmployee, length);
    cout << "是否删除以上员工信息？(y/n)";
    char flag;
    cin >> flag;

    if (flag == 'y')
    {
        
       
        for (int j = 0; j < length; j++)
        {
            for (int i = 0; i < employeeCount; i++)
            {
                if (strcmp(employees[i].id,tempEmployee[j].id) == 0)
                {
                    deleteEmployee(i); // 删除员工信息
                    cout << "员工 " << tempEmployee[j].id << " 已删除。" << endl;
                    break; // 找到并删除后退出循环  
                }
            }
        }
    }
    else if (flag == 'n')
    {
    }
    else
    {
        cout << "输入不合法！" << endl;
    }
}
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

void Sort()
{

    cout << "请选择排序方式：" << endl;
    cout << "1. 按工号排序" << endl;
    cout << "2. 按姓名排序" << endl;
    cout << "3. 按职位排序" << endl;
    cout << "请输入您的选择：";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > 3)
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
    // 初始化测试员工数据,待删除
    employees[0] = e1;
    employees[1] = e2;
    employees[2] = e3;
    employeeCount = 3;
    tempEmployee[0] = e1;
    tempEmployee[1] = e2;
    tempEmployee[2] = e3;
    deleteEmployeeBySearch(); // 测试删除功能

    // 进行排序操作
    Sort();
    // 测试查询功能
    searchEmployee();

    return 0;
}