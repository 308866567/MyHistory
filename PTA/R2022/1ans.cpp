/*
思路：
1.将棋盘划分为4个子棋盘  在某个棋盘中有特殊方格，而其他3个子棋盘没有特殊方格
2.在其他没有特殊方格的子棋盘的交汇处用L型的特殊方格进行覆盖
3.直到最后的size == 1 为止 

*/ 

#include<bits/stdc++.h>
using namespace std;

int cover[100][100];
int title = 1; 

//tr，tc:表示棋盘左上角的初始位置的行列号 ，dr dc 表示特殊方格的行列号 size = 2^k;  
void board_cover(int tr,int tc,int dr,int dc,int size){
	
	if(size == 1){
		return ;
	} 
	
	int num = title++;
	size = size / 2;//棋盘划分
	
	//1.棋盘的左上角 
	//如果特殊方格在左上角的棋盘中 
	if(dr < tr + size && dc < tc + size)
		board_cover(tr,tc,dr,dc,size);
	else{//如果方格不在左上角的子棋盘中，那么的话在子棋盘的最右下角 覆盖一个方格 
		cover[tr + size - 1][tc + size - 1] = num;
		board_cover(tr,tc,tr + size - 1,tc + size -1,size); //tr + size - 1,tc + size -1 特殊方格的坐标 
	}
	
	//2.棋盘的右上角
	//如果特殊方格在棋盘的子棋盘的右上角 
	if(dr < tr + size && dc >= tc + size)
		board_cover(tr,tc + size,dr,dc,size);
	else{//如果方格不在右上角的子棋盘中，那么的话在子棋盘的最左下角 覆盖一个方格
		
		cover[tr + size - 1][tc + size] = num;
		board_cover(tr,tc + size,tr + size - 1,tc + size,size); 
	}
	
	//3.棋盘的右下角
	if(dr >= tr + size && dc >= tc + size)
		board_cover(tr + size,tc + size,dr,dc,size);
	else{
		cover[tr + size][tc + size] = num;
		board_cover(tr + size,tc + size,tr + size,tc + size,size);
	}
	
	//4.棋盘的左下角
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
			//这里的输出格式是为4个字节  不能是前面3个空 
			printf("%4d",cover[i][j]);
		}
		cout << endl;
	}
	
} 

