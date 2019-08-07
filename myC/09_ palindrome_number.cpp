/*
ת�����ַ������в���
*/
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		long rev;
		if (x < 0) return false;//�ų�����
		string str_x = to_string(x);//ת�����ַ���
		std::reverse(str_x.begin(), str_x.end());//���з�ת
		stringstream out(str_x);
		out >> rev;//���д��rev
		return x == rev;//�Ƚϵó����
	}
};


/*

*/


class Solution {
public:
	bool isPalindrome(int x) {
		int midrev = 0;//�洢��벿�����ֵķ�ת���
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;//�ų����������һλ����Ϊ0������
		while (x > midrev)
		{
			midrev = midrev * 10 + x % 10;
			x /= 10;
		}
		return midrev == x || midrev / 10 == x;//���ָ���Ϊż�����������������
	}
};

/*
��������������ջ�����ԣ������ֵĺ�벿��ѹ��ջ�ڣ���һһ�����Աȣ�Ϊ��������Ҫ��ȡ������λ��������һ��ջ���ر���Ҫע���������λ��ż��λ�����Ĳ��
*/
class Solution {
public:
    int get_length(int x){//��ȡ����λ��
     int leng=0;
     while(x)
        {
            x/=10;
            leng++;
        }
        return leng;
    }
    bool isPalindrome(int x) {
        if(x<0 ||(x%10==0&&x!=0)) return false;
        stack<int> mystack;//����һ��ջ
        int l=get_length(x);//�������λ��
        int p=0;//��ŵ���������
        if(l%2==0)//ż��λ����
        {
            for(int i=0;i<l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            for(int j=l/2;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
        else//����λ����
        {
            for(int i=0;i<=l/2;i++)
            {
                p=x%10;
                x/=10;
                mystack.push(p);
            }
            mystack.pop();
            for(int j=l/2+1;j<l;j++)
            {
                p=x%10;
                x/=10;
                if(p==mystack.top())
                {
                    mystack.pop();
                    continue;
                }
                else return false;
            }
            return true;
        }
    }
};