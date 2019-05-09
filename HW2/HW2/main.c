// Student ID: B10615043
// Date: April 6, 2019
// Last Update: April 7, 2019
// Problem statement: This C program to solve Longest palindrome subsequence problem.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �x�s��r��
char str[1000 + 1];
// �x�s�j����ת��
int len[1000][1000];
// �x�s�j���X�I
int rec[1000][1000];

int palindromeLength(int i, int j);
void palindromePrint(int i, int j);
int main()
{
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		gets(str);
		// �N���ת���l�Ƭ�-1
		memset(len, -1, sizeof(len));
		int length = strlen(str);
		printf("%d\n", palindromeLength(0, length - 1));
		palindromePrint(0, length - 1);
		printf("\n");
		//getchar();
	}
	return 0;
}

int palindromeLength(int i, int j)
{
	// �P��m�^��1
	if (i == j) 
		return 1;
	// �A�ˤ��p��
	if (i > j) 
		return 0;
	// �Ȥw�g�p��L
	if (len[i][j] != -1) 
		return len[i][j];

	// ��ݬ۵�
	if (str[i] == str[j])
	{
		len[i][j] = palindromeLength(i + 1, j - 1) + 2;
		rec[i][j] = 0;
	}
	// ��ݤ��۵�
	else
	{
		int left = palindromeLength(i + 1, j);
		int right = palindromeLength(i, j - 1);

		// �����R����
		if (left > right)
		{
			len[i][j] = left;
			rec[i][j] = 1;
		}

		// �����R�k��
		else
		{
			len[i][j] = right;
			rec[i][j] = 2;
		}
	}
	return len[i][j];
}

void palindromePrint(int i, int j)
{
	// �A�ˮɻ��j����
	if (i > j) return;

	// ���׬��_�Ʈɤ������r���C
	if (i == j)
	{
		printf("%c", str[i]);
	}
	// �r���@�ˮɿ�X
	else if (rec[i][j] == 0)
	{
		printf("%c", str[i]);
		palindromePrint(i + 1, j - 1);
		printf("%c", str[i]);
	}
	// ����X����
	else if (rec[i][j] == 1)
	{
		palindromePrint(i + 1, j);
	}
	// ����X�k��
	else
	{
		palindromePrint(i, j - 1);
	}
}