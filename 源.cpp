#include<iostream>
#include<string>
using namespace std;

struct Person{//������ϵ�˽ṹ��
    char name[30];
    int number;
};
typedef struct {//����ͨѶ¼���ݽṹ
    Person* per;
    int length;
    int ContactSize;
}Contact;
bool Compare(Person a, Person b) {//�Ƚ��������Ƿ���ͬ
    if (a.name == b.name && a.number == b.number)
        return true;
    else
        return false;
}
void CreatPerson(Person& per) {//������ϵ�������͵绰
    cout << "�������û�������";
    cin >> per.name;
    cout << "�������û����룺";
    cin >> per.number;
}
void CreatContact(Contact& L, int n) {//����һ��˳���
    L.per = (Person*)malloc(n * sizeof(Person));
    L.length = 0;
    L.ContactSize =100;
    for (int i = 1; i <= n; i++) {
        if (L.length >= L.ContactSize) {
            Person* newbase = (Person*)realloc(L.per,
                (L.ContactSize + 10) * sizeof(Person));
            if (!newbase) {
                cout << "�������ʧ�ܡ�" << endl;
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

void InsertPer(Contact& L, Person x, int i) {//�ڵ�i��λ�ò���ֵΪx��Ԫ��
    if (i<1 || i>L.length + 1) {
        cout << "iֵ���Ϸ�" << endl;
        return;
    }
    if (L.length >= L.ContactSize) {
        Contact NewBase;
        NewBase.per = (Person*)realloc(L.per,
            (L.ContactSize + i) * sizeof(Person));
        if (!NewBase.per) {
            cout << "�������ʧ��" << endl;
            return;
        }
        L.per = NewBase.per;
        L.ContactSize += i;
    }
    cout << "���ڲ��Ҳ���λ�á�����������" << endl;
    Person* q = &(L.per[i - 1]);
    for (Person* p = &(L.per[L.length - 1]); p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = x;
    ++L.length;
    cout << "�����½���ϵ�ˡ�����������" << endl;
    cout << "��ϵ���ѱ��档" << endl;
}
void DeletePer(Contact& L, int i) {//ɾ��˳����е�i��Ԫ��
    if (i<1 || i>L.length + 1) {
        cout << "iֵ���Ϸ�" << endl;
        return;
    }
    cout << "���ڲ���ɾ��λ�á�����������" << endl;
    Person* p = &(L.per[i - 1]);
    Person e = *p;
    Person* q = L.per + L.length - 1;
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    --L.length;

    cout << "����ɾ����ϵ�ˡ�����������" << endl;

    cout << "��ϵ����ɾ����" << endl;
}
void LocatePer(Contact& L, Person e) {//��λԪ��e
    int i = 1;
    Person* p = L.per;
    cout << "���ڲ�����ϵ��λ�á�����������" << endl;
while (i <= L.length && !(e.number==p->number)) {
        ++i;
        ++p;
    }
    if (i > L.length)
        cout << "����ʧ��" << endl;
    else {
        cout << "���ҳɹ�" << endl;
        cout << "����eλ�ڵ�" << i << "��" << endl;
    }
}
void DisplayPer(Contact& L) {//��ӡͨѶ¼
    Person* p = L.per;
    cout << "��ϵ��" << "  " << "�绰����" << endl;
    for (int i = 1; i <= L.length; i++) {
        cout << p->name << " " << p->number << endl;
        p++;
    }
}
int main() {//������
    Contact a;
    int n;
    cout << "��������ϵ�˵�������";
    cin >> n;
    CreatContact(a, n);
    DisplayPer(a);
    Person x = {
            "������",
            123131,
    };
    int i;
    cout << "��������ϵ�˲���λ�ã�";
    cin >> i;
    InsertPer(a, x, i);
    cout << "��������ϵ���б�Ϊ��" << endl;
    DisplayPer(a);
    cout << "������ɾ��λ�ã�";
    cin >> i;
    DeletePer(a, i);
    cout << "ɾ�������ϵ���б�Ϊ��" << endl;
    DisplayPer(a);
    Person e;
    cout << "�����������ҵ���ϵ����Ϣ��" << endl;
    CreatPerson(e);
    cout << "������ϵ��e������������" << endl;
    LocatePer(a, e);
    cout << "ʹ�����" << endl;
    return 0;
}


