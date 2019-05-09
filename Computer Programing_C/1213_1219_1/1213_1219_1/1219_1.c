#define _CRT_SECURE_NO_WARNINGS
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#include <stdio.h>

int main() {

	int a,b;
	while (scanf("%d %d", &a,&b) != EOF) {
		int room[256][256] = { 0 };
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				scanf("%d", &room[i][j]);
			}
		}
		int wl[256] = {0};   // �C�@����������i����������
		int wr[256] = { 0 };   // �C�@��������k�i����������
		int h[256] = { 0 };    // �x�Ω��W�i����������
		int l[256] = { 0 };    // �x�Ω��W�����쩳��A�����i�������Z���C
		int r[256] = { 0 };    // �x�Ω��W�����쩳��A���k�i�������Z���C
		int max_area = 0;// �̤j�x�έ��n�A��l�Ƭ��̤p��

		// �H�C�@�Ӿ����@����Ω���
		for (int i = 1; i <=a; i++){
			// �����i����������
			for (int j = 1; j <b; j++) {
				if (room[i][j]) wl[j] = wl[j - 1] + 1;
				else wl[j] = 0;
			}
			// ���k�i����������
			for (int j = b; j >= 1; j--) {
				if (room[i][j]) wr[j] = wr[j + 1] + 1;
				else wr[j] = 0;
			}
			// �x�Ω��W�i����������
			for (int j = 1; j <=a; j++) {
				if (room[i][j])	h[j] = h[j] + 1;
				else h[j] = 0;
			}
			// �x�Ω��W�����쩳�A�����i�������Z���C
			for (int j = 1; j <=a; j++) {
				if (l[j] == 0) l[j] = wl[j];
				else l[j] = min(wl[j], l[j]);
			}
			// �x�Ω��W�����쩳��A���k�i�������Z���C
			for (int j = 1; j <=a; j++) {
				if (r[j] == 0) r[j] = wr[j];
				else r[j] = min(wr[j], r[j]);
			}
			// �O�� Largest Empty Rectangle
			for (int j = 1; j <=a; j++)
				max_area = max(max_area, (l[j] + r[j] - 1) * h[j]);
		}
		printf("%d\n", max_area);
	}
	return 0;
}
