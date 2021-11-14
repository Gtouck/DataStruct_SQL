#include<iostream>
#include<string>
using namespace std;

struct Person{//定义联系人结构体
    char name[30];
    int number;
};
typedef struct {//定义通讯录数据结构
    Person* per;
    int length;
    int ContactSize;
}Contact;
bool Compare(Person a, Person b) {//比较两数据是否相同
    if (a.name == b.name && a.number == b.number)
        return true;
    else
        return false;
}
void CreatPerson(Person& per) {//输入联系人姓名和电话
    cout << "请输入用户姓名：";
    cin >> per.name;
    cout << "请输入用户号码：";
    cin >> per.number;
}
void CreatContact(Contact& L, int n) {//生成一个顺序表
    L.per = (Person*)malloc(n * sizeof(Person));
    L.length = 0;
    L.ContactSize =100;
    for (int i = 1; i <= n; i++) {
        if (L.length >= L.ContactSize) {
            Person* newbase = (Person*)realloc(L.per,
                (L.ContactSize + 10) * sizeof(Person));
            if (!newbase) {
                cout << "储存分配失败。" << endl;
                return;
            }
            L.per = newbase;
            L.ContactSize += 10;
        }
        Person* temp = &(L.per[i - 1]);
        CreatPerson(*temp);
        ++L.length;
    }
}

void InsertPer(Contact& L, Person x, int i) {//在第i个位置插入值为x的元素
    if (i<1 || i>L.length + 1) {
        cout << "i值不合法" << endl;
        return;
    }
    if (L.length >= L.ContactSize) {
        Contact NewBase;
        NewBase.per = (Person*)realloc(L.per,
            (L.ContactSize + i) * sizeof(Person));
        if (!NewBase.per) {
            cout << "储存分配失败" << endl;
            return;
        }
        L.per = NewBase.per;
        L.ContactSize += i;
    }
    cout << "正在查找插入位置······" << endl;
    Person* q = &(L.per[i - 1]);
    for (Person* p = &(L.per[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = x;
    ++L.length;
    cout << "正在新建联系人······" << endl;
    cout << "联系人已保存。" << endl;
}
void DeletePer(Contact& L, int i) {//删除顺序表中第i个元素
    if (i<1 || i>L.length + 1) {
        cout << "i值不合法" << endl;
        return;
    }
    cout << "正在查找删除位置······" << endl;
    Person* p = &(L.per[i - 1]);
    Person e = *p;
    Person* q = L.per + L.length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L.length;

    cout << "正在删除联系人······" << endl;

    cout << "联系人已删除。" << endl;
}
void LocatePer(Contact& L, Person e) {//定位元素e
    int i = 1;
    Person* p = L.per;
    cout << "正在查找联系人位置······" << endl;
while (i <= L.length && !(e.number==p->number)) {
        ++i;
        ++p;
    }
    if (i > L.length)
        cout << "查找失败" << endl;
    else {
        cout << "查找成功" << endl;
        cout << "数据e位于第" << i << "处" << endl;
    }
}
void DisplayPer(Contact& L) {//打印通讯录
    Person* p = L.per;
    cout << "联系人" << "  " << "电话号码" << endl;
    for (int i = 1; i <= L.length; i++) {
        cout << p->name << " " << p->number << endl;
        p++;
    }
}
int main() {//主函数
    Contact a;
    int n;
    cout << "请输入联系人的数量：";
    cin >> n;
    CreatContact(a, n);
    DisplayPer(a);
    Person x = {
            "范宣明",
            123131,
    };
    int i;
    cout << "请输入联系人插入位置：";
    cin >> i;
    InsertPer(a, x, i);
    cout << "插入后的联系人列表为：" << endl;
    DisplayPer(a);
    cout << "请输入删除位置：";
    cin >> i;
    DeletePer(a, i);
    cout << "删除后的联系人列表为：" << endl;
    DisplayPer(a);
    Person e;
    cout << "请输入所查找的联系人信息：" << endl;
    CreatPerson(e);
    cout << "查找联系人e······" << endl;
    LocatePer(a, e);
    cout << "使用愉快" << endl;
    return 0;
}


