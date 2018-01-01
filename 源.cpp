#include <iostream>
#include <vector>  
#include <string>  
#include <fstream>  
#include<time.h>
using namespace std;
/*************************************************************
* @fn       isPrime  
*
* @brief    判断输入数是否为素数 
*
* @data    需要判断的数   
*
* @return  1-是素数，0-不是素数 
*/
bool isPrime(int num)
{
	int tmp = sqrt(num);  //这里是利用数的开根号若不满足质数的条件，则本身必不满足的定理来缩短判断质数的时间
	for (int i = 2; i <= tmp; i++)
	if (num %i == 0)
		return 0;
	return 1;
}
/*************************************************************
* @fn       isMutualPrime
*
* @brief    判断输入的两个数是否互为素数
*
* @data    需要判断的数
*
* @return  1-是，0-不是
*/
bool isMutualPrime(int num1,int num2)
{
	while (num1 != num2)//这是利用两个数若互为质数，则他们的公倍数为1的定理
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
* @brief    生成公钥和私钥
*
* @data    两个质数，公钥和私钥的参数
*
* @return  1-生成成功，0-生成失败
*/
bool calculateKey(int &d,int &e,int &n,int num1,int num2)
{
	int t = 0;
	n = num1*num2;
	t = (num1 - 1)*(num2 - 1);
	cout << "enter ‘e’" << endl;
	cin >> e;//e满足1<e<t
	if (e<1 || e>t){
		cout << "e is error,please input again:";
		cin >> e;
	}
	d = 1;
	while (((e*d) % t) != 1)//d是e在与n有关模下的乘法逆元
		d++;
	cout << "the public_key is (" << e << "," << n <<")"<< endl;
	cout << "the private_key is (" << d << "," << n << ")" << endl;
	return 1;
}
/*************************************************************
* @fn       encryption
*
* @brief    加密
*
* @data    要加密的明文数字，加密后的数字，参数e，n，r
*
* @return  1-生成成功，0-生成失败
*/
bool encryption(int &r, int &e, int n)
{
	int m = 0;
	r = 1;
	cout << "请输入要加密的明文数字" << endl;
	cin >> m;
	e = e + 1;
	while (e != 1){
		r = r*m;
		r = r%n;
		e--;
	}
	cout << "加密后的数字为" << r << endl;
	return 1;
}
/*************************************************************
* @fn       decrypt
*
* @brief    解密
*
* @data    要解密的数字，解密后的数字，参数d，n，r
*
* @return  1-生成成功，0-生成失败
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
	cout << "解密后的数字为" << o << endl;
	return 1;
}
/*************************************************************
* @fn       encryptionFile
*
* @brief    加密文档
*
* @data    参数e，n，r
*
* @return  1-生成成功，0-生成失败
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
		cout << "未成功打开文件" << endl;
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
	cout << "\n加密文档所需时间为" << totaltime << "秒！" << endl;
	return 1;
}
/*************************************************************
* @fn       decryptFile
*
* @brief    加密文档
*
* @data    参数d，n，r
*
* @return  1-生成成功，0-生成失败
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
		cout << "未成功打开文件" << endl;
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
	cout << "\n解密文档所需时间为" << totaltime << "秒！" << endl;
	return 1;
}
int main()
{
	int num1 = 0, num2 = 0,n = 0,e = 0,d = 0,r=0;
	cout << "请输入两个素数。"<<endl;
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
