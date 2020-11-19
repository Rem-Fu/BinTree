#pragma once
#include <iostream>
#include <string>
#include<queue>
#include<graphics.h>
#define r 30
#define width 1000
#define heigh 600
using namespace std;
template <class T>
struct BinTreeNode
{	      //����������ඨ��
    T data;	 		      //������
    BinTreeNode<T>* leftChild, * rightChild, * parent;
    int x0, y0;
    //����Ů������Ů����
    BinTreeNode(BinTreeNode<T>* p)                //���캯��
    {
        data = '@'; leftChild = NULL;  rightChild = NULL; parent = p;

    }
    BinTreeNode()
    {
        data = '@'; leftChild = NULL;  rightChild = NULL; parent = NULL;
    }
};

template <class T>
class BinaryTree 
{			//�������ඨ��
public:
    BinaryTree() { root = new BinTreeNode<T>; root->parent = NULL; }	  		//���캯��
    ~BinaryTree() { destroy(root); }	  		//��������
    BinTreeNode<T>* Parent(BinTreeNode <T>* t)
    {	//����˫�׽��
        return t.parent;
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* t) {	//��������Ů
        return (t != NULL)?t->leftChild : NULL;
    }
    BinTreeNode<T>* RightChild(BinTreeNode<T>* t) { 	//��������Ů
        return (t != NULL)?t->rightChild : NULL;
    }
    BinTreeNode<T>* getRoot() const { return root; }	 //ȡ��
    BinTreeNode<T>* CoParent(BinTreeNode<T>* p, BinTreeNode<T>* q);

    void levelOrder(BinTreeNode<T>* t);			//��������

     void Create(); //�˵�
     bool Num(string s, string t);
     void Error();
     bool Examine_1(string str1, string str2);
     bool Examine_2(string str1, string str2);
     void Find(BinTreeNode<T>* d);
protected:
    BinTreeNode<T>* root; 		//�������ĸ�ָ��
    T RefValue;	 		//��������ֹͣ��־
    void CreateBinTree1(BinTreeNode<T>* t, string str1, string str2);//ǰ+���������������
    void CreateBinTree2(BinTreeNode<T>* t, string str1, string str2);//��+���������������
    void destroy(BinTreeNode<T>*& subTree); 		//ɾ��

private:
    string str1; //������̶�ȡ������
    string str2; //������̶�ȡ������

};

template<class T>
inline BinTreeNode<T>* BinaryTree<T>::CoParent(BinTreeNode<T>* p, BinTreeNode<T>* q)
{
    string str;
    char s;
    int i = 0;
    int n;
    BinTreeNode<T>* ch = new BinTreeNode<T>;
    ch = p;
    while (p->parent != NULL)
    {
        str += p->parent->data;
        p = p->parent;
    }
    while (q->parent != NULL)
    {
        s = q->parent->data;
        n = str.find(s);
        if (n != -1) break;
        else q=q->parent;
    }
        for (int i = 0; i <= n; i++)
        {
            ch = ch->parent;
        }
    return ch;
}

template<class T>
inline void BinaryTree<T>::levelOrder(BinTreeNode<T>* t)
{
    queue<BinTreeNode<T>*>  q;
    q.push(t);
    int x = width / 2;
    int dy = 120;
    int dx = 200;
    int n = 0;
    int y;
    q.front()->x0 = x;
    q.front()->y0 = 40;
    circle(q.front()->x0, q.front()->y0, r);
    xyprintf(q.front()->x0 - 2, q.front()->y0 - 7, "%c", q.front()->data);
    int temp[2] = { -1,1 };
    x /= 2;
    while (!q.empty())
    {
        if (q.front()->leftChild != NULL)
            q.push(q.front()->leftChild);
        if(q.front()->rightChild!=NULL)
            q.push(q.front()->rightChild);
        y = q.front()->y0;
        q.pop();
        if (!q.empty())
        {
            q.front()->y0 = q.front()->parent->y0 + dy;
            if (y != q.front()->y0)
                x /= 2;
            if (n%2 == 0)
                q.front()->x0 = q.front()->parent->x0 - x;
            else 
                q.front()->x0 = q.front()->parent->x0 + x;
            
            if (!q.empty() && q.front()->data != '@')
            {
                Sleep(500);
                ege_line(q.front()->parent->x0+(r)* temp[n % 2], q.front()->parent->y0+r-10 , q.front()->x0, q.front()->y0-r);
                circle(q.front()->x0, q.front()->y0, r);
                xyprintf(q.front()->x0 - 2, q.front()->y0 - 7, "%c", q.front()->data);
            }
            n++;
        }
    }
}

template<class T>
inline void BinaryTree<T>::Create()
{
    cout << "-----------------------------------" << endl;
    cout << "��1�� ǰ+�������������������" << endl;
    cout << "��2�� ��+�������������������" << endl;
    cout << "��ѡ��";
    int ch;
    bool p;
    while (cin >> ch)
    {
        if (ch == 1)
        {
            cout << "������ǰ�������";
            cin >> str1;
            cout << "���������������";
            cin >> str2;
            p=Num(str1, str2);
            if (p)
            {
                p=Examine_1(str1,str2);
                if (p)
                {
                    CreateBinTree1(root, str1, str2);
                    initgraph(width, heigh, 0);
                    setbkcolor(WHITE);
                    setcolor(BLACK);
                    ege_enable_aa(true);
                    levelOrder(root);
                    getch();
                    closegraph();
                    cout << endl;
                    cout << "�Ƿ�������Ȳ�ѯ��";
                    cout << "��1�� ��" << '\t' << "��2����" << endl;
                    cout << "��ѡ��";
                    int x;
                    cin >> x;
                    if(x==1)
                        Find(root);
                }
                else 
                    Error();
            }
            else
                Error();
        }
        else if (ch == 2)
        {
            cout << "���������������";
            cin >> str1;
            cout << "��������������";
            cin >> str2;
            p = Num(str1, str2);
            if (p)
            {
                p = Examine_2(str1,str2);
                if (p)
                {
                    CreateBinTree2(root, str1, str2);
                    initgraph(width, heigh, 0);
                    setbkcolor(WHITE);
                    setcolor(BLACK);
                    ege_enable_aa(true);
                    levelOrder(root);
                    getch();
                    closegraph();
                    clearviewport();
                    cout << endl;
                    cout << "�Ƿ�������Ȳ�ѯ��";
                    cout << "��1�� ��" << '\t' << "��2����" << endl;
                    cout << "��ѡ��";
                    int x;
                    cin >> x;
                    if (x == 1)
                        Find(root);
                }
                else 
                    Error();
            }
            else
                Error();
        }
        else
            cout << "����Ƿ������������룺" << endl;
        cout << "��1�� ǰ+�������������������" << endl;
        cout << "��2�� ��+�������������������" << endl;
        cout << "��ѡ��";
    }
}

template<class T>
inline bool BinaryTree<T>::Num(string s, string t)
{
    int x = s.length();
    int y = t.length();
    if (x == y) return true;
    else 
        return false;
}

template<class T>
inline void BinaryTree<T>::Error()
{
    cout << "�������޷�����������,���������룺" << endl;
}

template<class T>
inline bool BinaryTree<T>::Examine_1(string str1, string str2)
{
    if (str1[0] != NULL && str2[0] != NULL)//�ж������Ƿ�������		
    {
        int i = 0, j = 0;
        char rootNode = str1[0];//��
        int p = str2.find(rootNode);//�������������е�λ��
        if (p == -1) return false;//���δ�ҵ����ڵ㣬GetP��������-1������ֹ��麯��������0�����ܹ���Ϊ������

        if (p >= 0)
        {
            i = Examine_1(str1.substr(1, p), str2.substr(0, p));//�ҵ��˸��ڵ㣬��ֱ��ȡ��������ڵ����Ԫ��
                                                              //�ӵ�һ��Ԫ�ؿ�ʼ��ȡ����ȡp��Ԫ��
        }//ͬʱ��ȡǰ��������ȳ���p��Ԫ�����У��ӵڶ���Ԫ�ؿ�ʼ�������µ�ǰ�����У����еݹ����

         //��ȡ�������е���������ǰ�����е�ʣ�²���
        if (p < str1.size())
        {
            j = Examine_1(str1.substr(p + 1, (str1.size() - 1 - p)), str2.substr(p + 1, (str2.size() - 1 - p)));
        }
        //�����߶���ⲻ������ʱ����󷵻�1����ʾ���Դ�ӡ��������
        return (i + j == 2) ? true : false;//����i=j=1,�ű�ʾ�ܹ�����Ϊ������
    }
    //���������ϣ��򷵻�1,����������û�����⣬
    else return true;
}

template<class T>
inline bool BinaryTree<T>::Examine_2(string str1, string str2)
{
    if (str1[0] != NULL && str2[0] != NULL)
    {
        int i = 0, j = 0;
        char rootNode = str2[str2.length() - 1];//��
        int p = str1.find(rootNode);//�������������е�λ��
        if (p == -1) return false;

        if (p >= 0)
        {
            i = Examine_2(str1.substr(0, p), str2.substr(0, p));
        }
        if (p < str1.size())
        {
            j = Examine_2(str1.substr(p + 1, (str1.size() - 1 - p)), str2.substr(p, (str2.size() - 1 - p)));
        }
        return (i + j == 2) ? true : false;
    }
    else return true;
}

template<class T>
inline void BinaryTree<T>::Find(BinTreeNode<T>* d)
{
    BinTreeNode<T>* p = new BinTreeNode<T>;
    BinTreeNode<T>* q = new BinTreeNode<T>;
    BinTreeNode<T>* s = new BinTreeNode<T>;
    queue<BinTreeNode<T>*>  t;
    cout << "��ֱ���������data��";
    char ch1, ch2;
    cin >> ch1 >> ch2;
    int n = str1.find(ch1);
    int m = str1.find(ch2);
    if (ch1 != -1 && ch2 != -1)
    {     
        t.push(d);       
        while (!t.empty())
        {
            if (t.front()->data == ch1) p = t.front();
            else if (t.front()->data == ch2) q = t.front();
            if (t.front()->leftChild != NULL)
                t.push(t.front()->leftChild);
            if (t.front()->rightChild != NULL)
                t.push(t.front()->rightChild);
            t.pop();
        }
        s=CoParent(p, q);
        cout << "�乲ͬ���ȵ�dataΪ��" << s->data << endl;
    }
    else
    {
        if (ch1 == -1 && ch2 == -1)
            cout << "����data����������" << endl;
        else if (ch1 == -1)
            cout << "��һ��data��������" << endl;
        else 
            cout << "�ڶ���data��������" << endl;
        return;
    }
}

template<class T>
void BinaryTree<T>::CreateBinTree1(BinTreeNode<T>* t, string str1, string str2)
{
    //ǰ+�����������������
    BinTreeNode<T>* NextL = new BinTreeNode<T>(t);  //����
    BinTreeNode<T>* NextR = new BinTreeNode<T>(t);    //�Һ���
    if (str1.length() == 0)
    {
        t = NULL;
        delete NextL;
        delete NextR;
        return;
    }
    t->leftChild= NextL;
    t->rightChild=NextR;
    char rootNode = str1[0];//��
    int index = str2.find(rootNode);//�������������е�λ��
    string lchild_str2 = str2.substr(0, index);//���ӵ���������
    string rchild_str2 = str2.substr(index + 1);//�Һ��ӵ���������
    int lchild_length = lchild_str2.length();//���ӵĳ���
    int rchild_length = rchild_str2.length();//�Һ��ӵĳ���
    string lchild_str1 = str1.substr(1, lchild_length);//���ӵ�ǰ������
    string rchild_str1 = str1.substr(1 + lchild_length);//�Һ��ӵ�ǰ������
    if (t != NULL)
    {
        t->data = rootNode;
        CreateBinTree1(NextL, lchild_str1, lchild_str2);//�ݹ鴴������
        CreateBinTree1(NextR, rchild_str1, rchild_str2);//�ݹ鴴���Һ���
    }
}

template<class T>
inline void BinaryTree<T>::CreateBinTree2(BinTreeNode<T>*  t, string str1, string str2)
{
    BinTreeNode<T>* NextL = new BinTreeNode<T>(t);  //����
    BinTreeNode<T>* NextR = new BinTreeNode<T>(t);    //�Һ���
    if (str1.length() == 0)
    {
        t = NULL;
        delete NextL;
        delete NextR;
        return;
    }
    t->leftChild = NextL;
    t->rightChild = NextR;
    char rootNode = str2[str2.length()-1];//��
    int index = str1.find(rootNode);//�������������е�λ��
    string lchild_str1 = str1.substr(0, index);//���ӵ���������
    string rchild_str1 = str1.substr(index+1);//�Һ��ӵ���������
    int lchild_length = lchild_str1.length();//���ӵĳ���
    int rchild_length = rchild_str1.length();//�Һ��ӵĳ���
    string lchild_str2 = str2.substr(0, lchild_length);//���ӵĺ�������
    string rchild_str2 = str2.substr(lchild_length,rchild_length);//�Һ��ӵĺ�������
    if (t != NULL)
    {
        t->data = rootNode;  
        CreateBinTree2(NextR, rchild_str1, rchild_str2);//�ݹ鴴���Һ���
        CreateBinTree2(NextL, lchild_str1, lchild_str2);//�ݹ鴴������
    }
}

template<class T>
inline void BinaryTree<T>::destroy(BinTreeNode<T>*& subTree)
{
    //˽�к���: ɾ����ΪsubTree������
    if (subTree != NULL) {
        destroy(subTree->leftChild);     //ɾ��������
        destroy(subTree->rightChild);   //ɾ��������
        delete subTree; 			 //ɾ�������
    }
}


