#include <iostream>
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
	int tmp = sqrt(num);
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
	while (num1 != num2)
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
* @fn       isMutualPrime
*
* @brief    判断输入的两个数是否互为素数
*
* @data    需要判断的数
*
* @return  1-是，0-不是
*/
int main()
{
	int num1 = 0, num2 = 0;
	cout << "请输入两个素数。"<<endl;
	cin >> num1 >> num2;
	cout<<isPrime(num1)<<endl;
	cout << isPrime(num1) << endl;
	cout << isMutualPrime(num1,num2) << endl;
	system("PAUSE ");
	return 0;
}