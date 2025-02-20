#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include <stdbool.h>

#include "../include/lib_func.h"

// 2つの数字が等しいですか？
bool is_same(int val1, int val2)
{
	return val1 == val2;
}

// val1 から val3 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_3(int sum, int val1, int val2, int val3)
{
	int num = 0;
	
	if(sum == val1) num++;
	if(sum == val2) num++;
	if(sum == val3) num++;
	if(sum == val1 + val2) num++;
	if(sum == val1 + val3) num++;
	if(sum == val2 + val3) num++;
	if(sum == val1 + val2 + val3) num++;
	
	return num;
}

// val1 から val4 の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations_4(int sum, int val1, int val2, int val3, int val4)
{
	//変数定義
	int num = 0;

	if (sum == val1) num++;
	if (sum == val2) num++;
	if (sum == val3) num++;
	if (sum == val4) num++;
	if (sum == val1 + val2) num++;
	if (sum == val1 + val3) num++;
	if (sum == val1 + val4) num++;
	if (sum == val2 + val3) num++;
	if (sum == val2 + val4) num++;
	if (sum == val3 + val4) num++;
	if (sum == val1 + val2 + val3) num++;
	if (sum == val1 + val2 + val4) num++;
	if (sum == val1 + val3 + val4) num++;
	if (sum == val2 + val3 + val4) num++;
	if (sum == val1 + val2 + val3 + val4) num++;

	return num;
}

// val_array の配列に格納されたarray_sizeの数字の任意の組み合わせで値の和がsumになる組み合わせは何個ありますか？
int calc_combinations(int sum, const int* val_array, int array_size)
{
	//変数定義
	int i, j;
	int all = 0;

	int  num = 0;
	float  num_1 = 1;
	float  num_2 = 1;

	for (i = 0; i < array_size; i++)
	{
		all += val_array[i];

		if (sum == all)
		{
			for (j = 0; j < i + 1; j++)
			{
				num_1 *= ((float)(i + 1) - j);
			}
			for (j = 0; j < i + 1; j++)
			{
				num_2 *= ((float)array_size - j);
			}
			num = (int)(num_2 / num_1);
			break;
		}
	}

	return num;
}
