#include <iostream>
#include <vector>  
#include <string>  
#include <fstream>  
#include<time.h>
using namespace std;
/*************************************************************
* @fn       isPrime  
*
* @brief    �ж��������Ƿ�Ϊ���� 
*
* @data    ��Ҫ�жϵ���   
*
* @return  1-��������0-�������� 
*/
bool isPrime(int num)
{
	int tmp = sqrt(num);  //�������������Ŀ�����������������������������ز�����Ķ����������ж�������ʱ��
	for (int i = 2; i <= tmp; i++)
	if (num %i == 0)
		return 0;
	return 1;
}
/*************************************************************
* @fn       isMutualPrime
*
* @brief    �ж�������������Ƿ�Ϊ����
*
* @data    ��Ҫ�жϵ���
*
* @return  1-�ǣ�0-����
*/
bool isMutualPrime(int num1,int num2)
{
	while (num1 != num2)//������������������Ϊ�����������ǵĹ�����Ϊ1�Ķ���
	{
		if (num1>num2)num1 = num1 - num2;
		if (num1<num2)num2 = num2 - num1;
	}
	if (num1 == 1)
		return 1;
	else
		return 0;
}
/*************************************************************
* @fn       calculateKey
*
* @brief    ���ɹ�Կ��˽Կ
*
* @data    ������������Կ��˽Կ�Ĳ���
*
* @return  1-���ɳɹ���0-����ʧ��
*/
bool calculateKey(int &d,int &e,int &n,int num1,int num2)
{
	int t = 0;
	n = num1*num2;
	t = (num1 - 1)*(num2 - 1);
	cout << "enter ��e��" << endl;
	cin >> e;//e����1<e<t
	if (e<1 || e>t){
		cout << "e is error,please input again:";
		cin >> e;
	}
	d = 1;
	while (((e*d) % t) != 1)//d��e����n�й�ģ�µĳ˷���Ԫ
		d++;
	cout << "the public_key is (" << e << "," << n <<")"<< endl;
	cout << "the private_key is (" << d << "," << n << ")" << endl;
	return 1;
}
/*************************************************************
* @fn       encryption
*
* @brief    ����
*
* @data    Ҫ���ܵ��������֣����ܺ�����֣�����e��n��r
*
* @return  1-���ɳɹ���0-����ʧ��
*/
bool encryption(int &r, int &e, int n)
{
	int m = 0;
	r = 1;
	cout << "������Ҫ���ܵ���������" << endl;
	cin >> m;
	e = e + 1;
	while (e != 1){
		r = r*m;
		r = r%n;
		e--;
	}
	cout << "���ܺ������Ϊ" << r << endl;
	return 1;
}
/*************************************************************
* @fn       decrypt
*
* @brief    ����
*
* @data    Ҫ���ܵ����֣����ܺ�����֣�����d��n��r
*
* @return  1-���ɳɹ���0-����ʧ��
*/
bool decrypt(int&r, int &d, int n)
{
	int o = 1;
	d = d + 1;
	while (d != 1)
	{
		o = o*r;
		o = o%n;
		d --;
	}
	cout << "���ܺ������Ϊ" << o << endl;
	return 1;
}
/*************************************************************
* @fn       encryptionFile
*
* @brief    �����ĵ�
*
* @data    ����e��n��r
*
* @return  1-���ɳɹ���0-����ʧ��
*/
bool encryptionFile(int &r, int &e, int n){
	clock_t start, finish;
	double totaltime;
	start = clock();
	ifstream myfile("E:\\text1.txt");
	ofstream outfile("E:\\text2.txt", ofstream::app);
	string temp;

	if (!myfile.is_open())
	{
		cout << "δ�ɹ����ļ�" << endl;
	}
	while (getline(myfile, temp))
	{
		int i = stoi(temp);
		r = 1;
		e = e + 1;
		while (e != 1){
			r = r*i;
			r = r%n;
			e--;
		}
		outfile << r;
	}
	myfile.close();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n�����ĵ�����ʱ��Ϊ" << totaltime << "�룡" << endl;
	return 1;
}
/*************************************************************
* @fn       decryptFile
*
* @brief    �����ĵ�
*
* @data    ����d��n��r
*
* @return  1-���ɳɹ���0-����ʧ��
*/
bool decryptFile(int &r, int &d, int n){
	clock_t start, finish;
	double totaltime;
	start = clock();
	ifstream myfile("E:\\text2.txt");
	ofstream outfile("E:\\text3.txt", ofstream::app);
	string temp;

	if (!myfile.is_open())
	{
		cout << "δ�ɹ����ļ�" << endl;
	}
	while (getline(myfile, temp))
	{
		int i = stoi(temp);
		int o = 1;
		d = d + 1;
		while (d != 1)
		{
			o = o*i;
			o = o%n;
			d--;
		}
		outfile << o;
	}
	myfile.close();
	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n�����ĵ�����ʱ��Ϊ" << totaltime << "�룡" << endl;
	return 1;
}
int main()
{
	int num1 = 0, num2 = 0,n = 0,e = 0,d = 0,r=0;
	cout << "����������������"<<endl;
	cin >> num1 >> num2;
	cout<<isPrime(num1)<<endl;
	cout << isPrime(num1) << endl;
	cout << isMutualPrime(num1,num2) << endl;
	cout<<calculateKey(d,e,n,num1,num2)<<endl;
	//cout << encryption(r,e,n) << endl;
	//cout << decrypt(r,d,n) << endl;
	cout << encryptionFile(r, e, n) << endl;
	cout << decryptFile(r, d, n) << endl;
	system("PAUSE ");
	return 0;
}
