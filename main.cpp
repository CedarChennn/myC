#include <iostream>
#include<cmath>
#include<vector>
#include<stack>
#include <algorithm>
#include<map>
#include<string>
#include<fstream>
#include<queue>
using namespace std;







int main()
{
	vector<vector<int>> obj(3,vector<int>(3,0));//Ĭ��ֵΪ0,Ĭ��sizeΪ0
	obj[1][1] = 1;
	for (unsigned int i  = 0; i < obj.size(); i++)//size()������ʵ�����ݸ��� 
	{
		cout << obj.size() << ","<<endl;
	}
	auto a = '11' ;
	cout << typeid('1'-'0').name()<<endl;
	cout << typeid('1' - '0').name();
	cout << __cplusplus << endl;
	updateMatrix(obj);

	cout << 1;
	return 0;

}