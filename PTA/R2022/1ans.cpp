/*
˼·��
1.�����̻���Ϊ4��������  ��ĳ�������������ⷽ�񣬶�����3��������û�����ⷽ��
2.������û�����ⷽ��������̵Ľ��㴦��L�͵����ⷽ����и���
3.ֱ������size == 1 Ϊֹ 

*/ 

#include<bits/stdc++.h>
using namespace std;

int cover[100][100];
int title = 1; 

//tr��tc:��ʾ�������Ͻǵĳ�ʼλ�õ����к� ��dr dc ��ʾ���ⷽ������к� size = 2^k;  
void board_cover(int tr,int tc,int dr,int dc,int size){
	
	if(size == 1){
		return ;
	} 
	
	int num = title++;
	size = size / 2;//���̻���
	
	//1.���̵����Ͻ� 
	//������ⷽ�������Ͻǵ������� 
	if(dr < tr + size && dc < tc + size)
		board_cover(tr,tc,dr,dc,size);
	else{//������������Ͻǵ��������У���ô�Ļ��������̵������½� ����һ������ 
		cover[tr + size - 1][tc + size - 1] = num;
		board_cover(tr,tc,tr + size - 1,tc + size -1,size); //tr + size - 1,tc + size -1 ���ⷽ������� 
	}
	
	//2.���̵����Ͻ�
	//������ⷽ�������̵������̵����Ͻ� 
	if(dr < tr + size && dc >= tc + size)
		board_cover(tr,tc + size,dr,dc,size);
	else{//������������Ͻǵ��������У���ô�Ļ��������̵������½� ����һ������
		
		cover[tr + size - 1][tc + size] = num;
		board_cover(tr,tc + size,tr + size - 1,tc + size,size); 
	}
	
	//3.���̵����½�
	if(dr >= tr + size && dc >= tc + size)
		board_cover(tr + size,tc + size,dr,dc,size);
	else{
		cover[tr + size][tc + size] = num;
		board_cover(tr + size,tc + size,tr + size,tc + size,size);
	}
	
	//4.���̵����½�
	if(dr >= tr + size && dc < tc + size)
		board_cover(tr + size,tc,dr,dc,size);
	else{
		cover[tr + size][tc + size - 1] = num;
		board_cover(tr + size,tc,tr + size,tc + size -1,size);	
	}
	
} 

int main(){
		freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	int dr,dc,length;
	cin >> dr >> dc >> length;
	
	cover[dr][dc] = 0;	
	
	board_cover(1,1,dr,dc,length);
	
	for(int i = 1; i <= length; i++){	
		for(int j = 1; j <= length; j++){
			//cout << ' ' << ' '  << ' ' << cover[i][j];
			//����������ʽ��Ϊ4���ֽ�  ������ǰ��3���� 
			printf("%4d",cover[i][j]);
		}
		cout << endl;
	}
	
} 

