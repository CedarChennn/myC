#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include<queue>
using namespace std;

vector<int> twoSum_001(vector<int>& nums, int target) 
{
  map<int, int> a;  //����hash��������Ԫ��
  vector<int> b(2, -1);  //��Ž��, ����һ����ʼ��СΪ2�ҳ�ʼֵ��Ϊ-1������
  for (int i = 0; i < nums.size(); i++)
    a.insert(map<int, int>::value_type(nums[i], i));
  for (int i = 0; i < nums.size(); i++) 
  {
    if (a.count(target - nums[i]) > 0 && (a[target - nums[i]] != i))
    //�ж��Ƿ��ҵ�Ŀ��Ԫ����Ŀ��Ԫ�ز����Ǳ���,count()��������ֵ��һ��������1��ʾ�����Ԫ�أ�0��ʾû�����Ԫ�ء�
    {
      b[0] = i;
      b[1] = a[target - nums[i]];
      break;
    }
  }
  return b;
};
vector<int> twoSum2_001(vector<int>& nums, int target) {
  map<int, int> a;  //����hash��������Ԫ��
  vector<int> b(2, -1);  //��Ž��, ����һ����ʼ��СΪ2�ҳ�ʼֵ��Ϊ-1������
  for (int i = 0; i < nums.size(); i++) {
    if (a.count(target - nums[i]) > 0) {
      b[0] = a[target - nums[i]];
      b[1] = i;
      break;
    }
    a[nums[i]] = i;
  }
  return b;
};
int reverse_007(int x) {
  int rev = 0;
  while (x != 0) {
    int pop = x % 10;
    x /= 10;
    if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
    if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
    rev = rev * 10 + pop;
  }
  return rev;
}
bool isPalindrome2_009(int x) {
  int midrev = 0;  //�洢��벿�����ֵķ�ת���
  if (x < 0 || (x % 10 == 0 && x != 0))
    return false;  //�ų����������һλ����Ϊ0������
  while (x > midrev) {
    midrev = midrev * 10 + x % 10;
    x /= 10;
  }
  return midrev == x || midrev / 10 == x;  //���ָ���Ϊż�����������������
}
int numIslands_200(vector<vector<char>>& grid)
{
	int h = grid.size();
	if (!h) return 0;
	int w = grid[0].size();
	int num_islands = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (grid[i][j] == '1')
			{
				grid[i][j] = '0';
				num_islands++;
				queue < pair<int, int>> q;
				q.push({ i,j });
				while (!q.empty())
				{
					auto new_center = q.front();
					q.pop();
					int nh = new_center.first;
					int nw = new_center.second;
					if ((nh > 0) && (grid[nh - 1][nw] == '1')) { q.push({ nh - 1,nw }); grid[nh - 1][nw] = '0'; }
					if ((nw > 0) && (grid[nh][nw - 1] == '1')) { q.push({ nh,nw - 1 }); grid[nh][nw - 1] = '0'; }
					if ((nh < h - 1) && (grid[nh + 1][nw] == '1')) { q.push({ nh + 1,nw }); grid[nh + 1][nw] = '0'; }
					if ((nw < w - 1) && (grid[nh][nw + 1] == '1')) { q.push({ nh,nw + 1 }); grid[nh][nw + 1] = '0'; }
				}
			}
		}
	}
	return num_islands;
}
vector<int> dailyTemperatures_739(vector<int>& T)
{
	int n = T.size();
	vector<int> result(n);
	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j += result[j])
		{
			if (T[j] > T[i])
			{
				result[i] = j - i;
				break;
			}
			else
			{
				if (result[j] == 0)
				{
					result[i] = 0;
					break;
				}
			}
		}
	}
	return result;
}

string decodeString(string s) {
	string res = "";
	stack <int> nums;
	stack <string> strs;
	int num = 0;
	int len = s.size();
	for (int i = 0; i < len; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + s[i] - '0';
		}
		else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			res = res + s[i];
		}
		else if (s[i] == '[') //����[��ǰ������ѹ��numsջ�ڣ� ��ĸ�ַ���ѹ��strsջ��
		{
			nums.push(num);
			num = 0;
			strs.push(res);
			res = "";
		}
		else //������]��ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
		{
			int times = nums.top(); 
			nums.pop();
			for (int j = 0; j < times; ++j)
				strs.top() += res;
			res = strs.top(); //֮����������ĸ���ͻ�ֱ�Ӽӵ�res֮����Ϊ������ͬһ��������
							  //���������ţ�res�ᱻѹ��strsջ����Ϊ��һ�������
			strs.pop();
		}
	}
	return res;
}
