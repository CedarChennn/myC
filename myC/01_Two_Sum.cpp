/*
�����ⷨ
*/
#include <vector>
#include <map>
using namespace std;

//
//class Solution {
//public:
//	vector<int> twoSum(vector<int>& nums, int target)
//	{
//		int i, j;
//		for (i = 0; i < nums.size() - 1; i++)
//		{
//			for (j = i + 1; j < nums.size(); j++)
//			{
//				if (nums[i] + nums[j] == target)
//				{
//					return { i,j };
//				}
//
//			}
//		}
//		return { i,j };
//	}
//};

/*
�����ϣ��
*/
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//����hash��������Ԫ��
		vector<int> b(2, -1);//��Ž��, ����һ����ʼ��СΪ2�ҳ�ʼֵ��Ϊ-1������
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
};
/*
һ���ϣ��
*/
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> a;//����hash��������Ԫ��
		vector<int> b(2, -1);//��Ž��, ����һ����ʼ��СΪ2�ҳ�ʼֵ��Ϊ-1������
		for (int i = 0; i < nums.size(); i++)
		{
			if (a.count(target - nums[i]) > 0)
			{
				b[0] = a[target - nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;
		}
		return b;
	};
};
