#include<bits/stdc++.h> 
using namespace std;
int a[73];
bool check()
{
	for(int i = 0;i < 8;i++)
	{
		int u = a[i * 9 + 1]; 
		for(int j = 1;j < 9;j++)
		{
			if( a[i * 9 + j + 1] != u){
				return false;
			}
		}	
	}
	return true; 
 } 
 void op1()//ok
 {
 	int tmp;
 	tmp = a[1]; a[1] = a[5]; a[5] = a[9]; a[9] = tmp;
 	tmp = a[3]; a[3] = a[6]; a[6] = a[8]; a[8] = tmp;
 	tmp = a[2]; a[2] = a[7]; a[7] = a[4]; a[4] = tmp;
	
	tmp = a[19]; a[19] = a[68]; a[68] = a[54]; a[54] = tmp;
	
	tmp = a[10]; a[10] = a[36]; a[36] = a[41]; a[41] = tmp;
	tmp = a[12]; a[12] = a[35]; a[35] = a[42]; a[42] = tmp;
	tmp = a[11]; a[11] = a[31]; a[31] = a[43]; a[43] = tmp;
	tmp = a[15]; a[15] = a[30]; a[30] = a[44]; a[44] = tmp;
	tmp = a[14]; a[14] = a[28]; a[28] = a[45]; a[45] = tmp;
 
 }
 void exop1() //ok
 {
 	int tmp;
 	tmp = a[9]; a[9] = a[5]; a[5] = a[1]; a[1] = tmp;
 	tmp = a[8]; a[8] = a[6]; a[6] = a[3]; a[3] = tmp;
 	tmp = a[4]; a[4] = a[7]; a[7] = a[2]; a[2] = tmp;
	
	tmp = a[54]; a[54] = a[68]; a[68] = a[19]; a[19] = tmp;
	
	tmp = a[41]; a[41] = a[36]; a[36] = a[10]; a[10] = tmp;
	tmp = a[42]; a[42] = a[35]; a[35] = a[12]; a[12] = tmp;
	tmp = a[43]; a[43] = a[31]; a[31] = a[11]; a[11] = tmp;
	tmp = a[44]; a[44] = a[30]; a[30] = a[15]; a[15] = tmp;
	tmp = a[45]; a[45] = a[28]; a[28] = a[14]; a[14] = tmp;
 }
void op2()//ok
{
	int tmp;
	tmp = a[10]; a[10] = a[14]; a[14] = a[18]; a[18] = tmp;
	tmp = a[12]; a[12] = a[15]; a[15] = a[17]; a[17] = tmp;
	tmp = a[11]; a[11] = a[16]; a[16] = a[13]; a[13] = tmp;
	
	tmp = a[28]; a[28] = a[41]; a[41] = a[63]; a[63] = tmp;
	
	tmp = a[19]; a[19] = a[9]; a[9] = a[50]; a[50] = tmp;
	tmp = a[21]; a[21] = a[8]; a[8] = a[51]; a[51] = tmp;
	tmp = a[20]; a[20] = a[4]; a[4] = a[52]; a[52] = tmp;
	tmp = a[24]; a[24] = a[3]; a[3] = a[53]; a[53] = tmp;
	tmp = a[23]; a[23] = a[1]; a[1] = a[54]; a[54] = tmp;
}

void exop2()//ok
{
	int tmp;
	tmp = a[18]; a[18] = a[14]; a[14] = a[10]; a[10] = tmp;
	tmp = a[17]; a[17] = a[15]; a[15] = a[12]; a[12] = tmp;
	tmp = a[13]; a[13] = a[16]; a[16] = a[11]; a[11] = tmp;
	
	tmp = a[63]; a[63] = a[41]; a[41] = a[28]; a[28] = tmp;
	
	tmp = a[50]; a[50] = a[9]; a[9] = a[19]; a[19] = tmp;
	tmp = a[51]; a[51] = a[8]; a[8] = a[21]; a[21] = tmp;
	tmp = a[52]; a[52] = a[4]; a[4] = a[20]; a[20] = tmp;
	tmp = a[53]; a[53] = a[3]; a[3] = a[24]; a[24] = tmp;
	tmp = a[54]; a[54] = a[1]; a[1] = a[23]; a[23] = tmp;	
}
void op3()//ok
{
	int tmp;
	tmp = a[27]; a[27] = a[19]; a[19] = a[23]; a[23] = tmp;
	tmp = a[26]; a[26] = a[21]; a[21] = a[24]; a[24] = tmp;
	tmp = a[22]; a[22] = a[20]; a[20] = a[25]; a[25] = tmp;
	
	tmp = a[72]; a[72] = a[1]; a[1] = a[50]; a[50] = tmp;
	
	tmp = a[59]; a[59] = a[28]; a[28] = a[18]; a[18] = tmp;
	tmp = a[60]; a[60] = a[30]; a[30] = a[17]; a[17] = tmp;
	tmp = a[61]; a[61] = a[29]; a[29] = a[13]; a[13] = tmp;
	tmp = a[62]; a[62] = a[33]; a[33] = a[12]; a[12] = tmp;
	tmp = a[63]; a[63] = a[32]; a[32] = a[10]; a[10] = tmp;
}
void exop3()//ok
{
	int tmp; 
	tmp = a[23]; a[23] = a[19]; a[19] = a[27]; a[27] = tmp;
	tmp = a[24]; a[24] = a[21]; a[21] = a[26]; a[26] = tmp;
	tmp = a[25]; a[25] = a[20]; a[20] = a[22]; a[22] = tmp;
	
	tmp = a[50]; a[50] = a[1]; a[1] = a[72]; a[72] = tmp;
	
	tmp = a[18]; a[18] = a[28]; a[28] = a[59]; a[59] = tmp;
	tmp = a[17]; a[17] = a[30]; a[30] = a[60]; a[60] = tmp;
	tmp = a[13]; a[13] = a[29]; a[29] = a[61]; a[61] = tmp;
	tmp = a[12]; a[12] = a[33]; a[33] = a[62]; a[62] = tmp;
	tmp = a[10]; a[10] = a[32]; a[32] = a[63]; a[63] = tmp;
}

void op4()//ok
{
	int tmp;
	tmp = a[36]; a[36] = a[28]; a[28] = a[32]; a[32] = tmp;
	tmp = a[35]; a[35] = a[30]; a[30] = a[33]; a[33] = tmp;
	tmp = a[31]; a[31] = a[29]; a[29] = a[34]; a[34] = tmp;
	
	tmp = a[45]; a[45] = a[10]; a[10] = a[59]; a[59] = tmp;
	
	tmp = a[68]; a[68] = a[1]; a[1] = a[27]; a[27] = tmp;
	tmp = a[69]; a[69] = a[3]; a[3] = a[26]; a[26] = tmp;
	tmp = a[70]; a[70] = a[2]; a[2] = a[22]; a[22] = tmp;
	tmp = a[71]; a[71] = a[6]; a[6] = a[21]; a[21] = tmp;
	tmp = a[72]; a[72] = a[5]; a[5] = a[19]; a[19] = tmp;
}
void exop4()//ok
{
	int tmp;
	tmp = a[32]; a[32] = a[28]; a[28] = a[36]; a[36] = tmp;
	tmp = a[33]; a[33] = a[30]; a[30] = a[35]; a[35] = tmp;
	tmp = a[34]; a[34] = a[29]; a[29] = a[31]; a[31] = tmp;
	
	tmp = a[59]; a[59] = a[10]; a[10] = a[45]; a[45] = tmp;
	
	tmp = a[27]; a[27] = a[1]; a[1] = a[68]; a[68] = tmp;
	tmp = a[26]; a[26] = a[3]; a[3] = a[69]; a[69] = tmp;
	tmp = a[22]; a[22] = a[2]; a[2] = a[70]; a[70] = tmp;
	tmp = a[21]; a[21] = a[6]; a[6] = a[71]; a[71] = tmp;
	tmp = a[19]; a[19] = a[5]; a[5] = a[72]; a[72] = tmp;
}
void op5()//ok
{
	int tmp;
	tmp = a[45]; a[45] = a[37]; a[37] = a[41]; a[41] = tmp;
	tmp = a[44]; a[44] = a[39]; a[39] = a[42]; a[42] = tmp;
	tmp = a[40]; a[40] = a[38]; a[38] = a[43]; a[43] = tmp;
	
	tmp = a[36]; a[36] = a[55]; a[55] = a[14]; a[14] = tmp;
	
	tmp = a[5]; a[5] = a[64]; a[64] = a[54]; a[54] = tmp;
	tmp = a[6]; a[6] = a[66]; a[66] = a[53]; a[53] = tmp;
	tmp = a[7]; a[7] = a[65]; a[65] = a[49]; a[49] = tmp;
	tmp = a[8]; a[8] = a[69]; a[69] = a[48]; a[48] = tmp;
	tmp = a[9]; a[9] = a[68]; a[68] = a[46]; a[46] = tmp;
}
void exop5()//ok
{
	int tmp;
	tmp = a[41]; a[41] = a[37]; a[37] = a[45]; a[45] = tmp;
	tmp = a[42]; a[42] = a[39]; a[39] = a[44]; a[44] = tmp;
	tmp = a[43]; a[43] = a[38]; a[38] = a[40]; a[40] = tmp;
	
	tmp = a[14]; a[14] = a[55]; a[55] = a[36]; a[36] = tmp;
	
	tmp = a[54]; a[54] = a[64]; a[64] = a[5]; a[5] = tmp;
	tmp = a[53]; a[53] = a[66]; a[66] = a[6]; a[6] = tmp;
	tmp = a[49]; a[49] = a[65]; a[65] = a[7]; a[7] = tmp;
	tmp = a[48]; a[48] = a[69]; a[69] = a[8]; a[8] = tmp;
	tmp = a[46]; a[46] = a[68]; a[68] = a[9]; a[9] = tmp;
}
void op6()//ok
{
	int tmp;
	tmp = a[54]; a[54] = a[46]; a[46] = a[50]; a[50] = tmp;
	tmp = a[53]; a[53] = a[48]; a[48] = a[51]; a[51] = tmp;
	tmp = a[49]; a[49] = a[47]; a[47] = a[52]; a[52] = tmp;
	
	tmp = a[9]; a[9] = a[64]; a[64] = a[23]; a[23] = tmp;
	
	tmp = a[14]; a[14] = a[37]; a[37] = a[63]; a[63] = tmp;
	tmp = a[15]; a[15] = a[39]; a[39] = a[62]; a[62] = tmp;
	tmp = a[16]; a[16] = a[38]; a[38] = a[58]; a[58] = tmp;
	tmp = a[17]; a[17] = a[42]; a[42] = a[57]; a[57] = tmp;
	tmp = a[18]; a[18] = a[41]; a[41] = a[55]; a[55] = tmp;
}
void exop6()//ok
{
	int tmp;
	tmp = a[50]; a[50] = a[46]; a[46] = a[54]; a[54] = tmp;
	tmp = a[51]; a[51] = a[48]; a[48] = a[53]; a[53] = tmp;
	tmp = a[52]; a[52] = a[47]; a[47] = a[49]; a[49] = tmp;
	
	tmp = a[23]; a[23] = a[64]; a[64] = a[9]; a[9] = tmp;
	
	tmp = a[63]; a[63] = a[37]; a[37] = a[14]; a[14] = tmp;
	tmp = a[62]; a[62] = a[39]; a[39] = a[15]; a[15] = tmp;
	tmp = a[58]; a[58] = a[38]; a[38] = a[16]; a[16] = tmp;
	tmp = a[57]; a[57] = a[42]; a[42] = a[17]; a[17] = tmp;
	tmp = a[55]; a[55] = a[41]; a[41] = a[18]; a[18] = tmp;
}
void op7()//ok
{
	int tmp;
	tmp = a[55]; a[55] = a[59]; a[59] = a[63]; a[63] = tmp;
	tmp = a[57]; a[57] = a[60]; a[60] = a[62]; a[62] = tmp;
	tmp = a[56]; a[56] = a[61]; a[61] = a[58]; a[58] = tmp;
	
	tmp = a[37]; a[37] = a[32]; a[32] = a[18]; a[18] = tmp;
	
	tmp = a[46]; a[46] = a[72]; a[72] = a[23]; a[23] = tmp;
	tmp = a[48]; a[48] = a[71]; a[71] = a[24]; a[24] = tmp;
	tmp = a[47]; a[47] = a[67]; a[67] = a[25]; a[25] = tmp;
	tmp = a[51]; a[51] = a[66]; a[66] = a[26]; a[26] = tmp;
	tmp = a[50]; a[50] = a[64]; a[64] = a[27]; a[27] = tmp;
}
void exop7()//ok
{
	int tmp;
	tmp = a[63]; a[63] = a[59]; a[59] = a[55]; a[55] = tmp;
	tmp = a[62]; a[62] = a[60]; a[60] = a[57]; a[57] = tmp;
	tmp = a[58]; a[58] = a[61]; a[61] = a[56]; a[56] = tmp;
	
	tmp = a[18]; a[18] = a[32]; a[32] = a[37]; a[37] = tmp;
	
	tmp = a[23]; a[23] = a[72]; a[72] = a[46]; a[46] = tmp;
	tmp = a[24]; a[24] = a[71]; a[71] = a[48]; a[48] = tmp;
	tmp = a[25]; a[25] = a[67]; a[67] = a[47]; a[47] = tmp;
	tmp = a[26]; a[26] = a[66]; a[66] = a[51]; a[51] = tmp;
	tmp = a[27]; a[27] = a[64]; a[64] = a[50]; a[50] = tmp;
}
void op8()//ok
{
	int tmp;
	tmp = a[64]; a[64] = a[68]; a[68] = a[72]; a[72] = tmp;
	tmp = a[66]; a[66] = a[69]; a[69] = a[71]; a[71] = tmp;
	tmp = a[65]; a[65] = a[70]; a[70] = a[67]; a[67] = tmp;
	
	tmp = a[46]; a[46] = a[5]; a[5] = a[27]; a[27] = tmp;
	
	tmp = a[55]; a[55] = a[45]; a[45] = a[32]; a[32] = tmp;
	tmp = a[57]; a[57] = a[44]; a[44] = a[33]; a[33] = tmp;
	tmp = a[56]; a[56] = a[40]; a[40] = a[34]; a[34] = tmp;
	tmp = a[60]; a[60] = a[39]; a[39] = a[35]; a[35] = tmp;
	tmp = a[59]; a[59] = a[37]; a[37] = a[36]; a[36] = tmp;
}
void exop8()//ok
{
	int tmp;
	tmp = a[72]; a[72] = a[68]; a[68] = a[64]; a[64] = tmp;
	tmp = a[71]; a[71] = a[69]; a[69] = a[66]; a[66] = tmp;
	tmp = a[67]; a[67] = a[70]; a[70] = a[65]; a[65] = tmp;
	
	tmp = a[27]; a[27] = a[5]; a[5] = a[46]; a[46] = tmp;
	
	tmp = a[32]; a[32] = a[45]; a[45] = a[55]; a[55] = tmp;
	tmp = a[33]; a[33] = a[44]; a[44] = a[57]; a[57] = tmp;
	tmp = a[34]; a[34] = a[40]; a[40] = a[56]; a[56] = tmp;
	tmp = a[35]; a[35] = a[39]; a[39] = a[60]; a[60] = tmp;
	tmp = a[36]; a[36] = a[37]; a[37] = a[59]; a[59] = tmp;
}
void op9()//ok
{
	int tmp;
	tmp = a[65]; a[65] = a[22]; a[22] = a[52]; a[52] = tmp;
	tmp = a[69]; a[69] = a[21]; a[21] = a[53]; a[53] = tmp;
	tmp = a[70]; a[70] = a[20]; a[20] = a[49]; a[49] = tmp;
	
	tmp = a[34]; a[34] = a[13]; a[13] = a[38]; a[38] = tmp;
	tmp = a[33]; a[33] = a[17]; a[17] = a[39]; a[39] = tmp;
	tmp = a[29]; a[29] = a[16]; a[16] = a[40]; a[40] = tmp;
}
void exop9()//ok
{
	int tmp;
	tmp = a[52]; a[52] = a[22]; a[22] = a[65]; a[65] = tmp;
	tmp = a[53]; a[53] = a[21]; a[21] = a[69]; a[69] = tmp;
	tmp = a[49]; a[49] = a[20]; a[20] = a[70]; a[70] = tmp;
	
	tmp = a[38]; a[38] = a[13]; a[13] = a[34]; a[34] = tmp;
	tmp = a[39]; a[39] = a[17]; a[17] = a[33]; a[33] = tmp;
	tmp = a[40]; a[40] = a[16]; a[16] = a[29]; a[29] = tmp;
}
void op10()//ok
{
	int tmp;
	tmp = a[2]; a[2] = a[49]; a[49] = a[25]; a[25] = tmp;
	tmp = a[6]; a[6] = a[48]; a[48] = a[26]; a[26] = tmp;
	tmp = a[7]; a[7] = a[47]; a[47] = a[22]; a[22] = tmp;
	
	tmp = a[43]; a[43] = a[58]; a[58] = a[29]; a[29] = tmp;
	tmp = a[42]; a[42] = a[62]; a[62] = a[30]; a[30] = tmp;
	tmp = a[38]; a[38] = a[61]; a[61] = a[31]; a[31] = tmp;
}
void exop10()//ok
{
	int tmp;
	tmp = a[25]; a[25] = a[49]; a[49] = a[2]; a[2] = tmp;
	tmp = a[26]; a[26] = a[48]; a[48] = a[6]; a[6] = tmp;
	tmp = a[22]; a[22] = a[47]; a[47] = a[7]; a[7] = tmp;
	
	tmp = a[29]; a[29] = a[58]; a[58] = a[43]; a[43] = tmp;
	tmp = a[30]; a[30] = a[62]; a[62] = a[42]; a[42] = tmp;
	tmp = a[31]; a[31] = a[61]; a[61] = a[38]; a[38] = tmp;
}
void op11()//ok
{
	int tmp;
	tmp = a[67]; a[67] = a[2]; a[2] = a[52]; a[52] = tmp;
	tmp = a[71]; a[71] = a[3]; a[3] = a[51]; a[51] = tmp;
	tmp = a[70]; a[70] = a[4]; a[4] = a[47]; a[47] = tmp;
	
	tmp = a[34]; a[34] = a[11]; a[11] = a[58]; a[58] = tmp;
	tmp = a[35]; a[35] = a[15]; a[15] = a[57]; a[57] = tmp;
	tmp = a[31]; a[31] = a[16]; a[16] = a[56]; a[56] = tmp;
}
void exop11()//ok
{
	int tmp;
	tmp = a[52]; a[52] = a[2]; a[2] = a[67]; a[67] = tmp;
	tmp = a[51]; a[51] = a[3]; a[3] = a[71]; a[71] = tmp;
	tmp = a[47]; a[47] = a[4]; a[4] = a[70]; a[70] = tmp;
	
	tmp = a[58]; a[58] = a[11]; a[11] = a[34]; a[34] = tmp;
	tmp = a[57]; a[57] = a[15]; a[15] = a[35]; a[35] = tmp;
	tmp = a[56]; a[56] = a[16]; a[16] = a[31]; a[31] = tmp;
}
void op12() //ok
{
	int tmp;
	tmp = a[4]; a[4] = a[65]; a[65] = a[25]; a[25] = tmp;
	tmp = a[8]; a[8] = a[66]; a[66] = a[24]; a[24] = tmp;
	tmp = a[7]; a[7] = a[67]; a[67] = a[20]; a[20] = tmp;
	
	tmp = a[43]; a[43] = a[56]; a[56] = a[13]; a[13] = tmp;
	tmp = a[44]; a[44] = a[60]; a[60] = a[12]; a[12] = tmp;
	tmp = a[40]; a[40] = a[61]; a[61] = a[11]; a[11] = tmp;
}
void exop12()//ok
{
	int tmp;
	tmp = a[25]; a[25] = a[65]; a[65] = a[4]; a[4] = tmp;
	tmp = a[24]; a[24] = a[66]; a[66] = a[8]; a[8] = tmp;
	tmp = a[20]; a[20] = a[67]; a[67] = a[7]; a[7] = tmp;
	
	tmp = a[13]; a[13] = a[56]; a[56] = a[43]; a[43] = tmp;
	tmp = a[12]; a[12] = a[60]; a[60] = a[44]; a[44] = tmp;
	tmp = a[11]; a[11] = a[61]; a[61] = a[40]; a[40] = tmp;
}
bool dfs(int cur)
{
	if(cur >= 3) return false;
	op1();if(check()) return true; if(dfs(cur + 1)) return true;exop1();
	op2();if(check()) return true; if(dfs(cur + 1)) return true;exop2();
	op3();if(check()) return true; if(dfs(cur + 1)) return true;exop3();
	op4();if(check()) return true; if(dfs(cur + 1)) return true;exop4();
	op5();if(check()) return true; if(dfs(cur + 1)) return true;exop5();
	op6();if(check()) return true; if(dfs(cur + 1)) return true;exop6();
	op7();if(check()) return true; if(dfs(cur + 1)) return true;exop7();
	op8();if(check()) return true; if(dfs(cur + 1)) return true;exop8();
	op9();if(check()) return true; if(dfs(cur + 1)) return true;exop9();
	op10();if(check()) return true; if(dfs(cur + 1)) return true;exop10();
	op11();if(check()) return true; if(dfs(cur + 1)) return true;exop11();
	op12();if(check()) return true; if(dfs(cur + 1)) return true;exop12();
	
	exop1();if(check()) return true; if(dfs(cur + 1)) return true;op1();
	exop2();if(check()) return true; if(dfs(cur + 1)) return true;op2();
	exop3();if(check()) return true; if(dfs(cur + 1)) return true;op3();
	exop4();if(check()) return true; if(dfs(cur + 1)) return true;op4();
	exop5();if(check()) return true; if(dfs(cur + 1)) return true;op5();
	exop6();if(check()) return true; if(dfs(cur + 1)) return true;op6();
	exop7();if(check()) return true; if(dfs(cur + 1)) return true;op7();
	exop8();if(check()) return true; if(dfs(cur + 1)) return true;op8();
	exop9();if(check()) return true; if(dfs(cur + 1)) return true;op9();
	exop10();if(check()) return true; if(dfs(cur + 1)) return true;op10();
	exop11();if(check()) return true; if(dfs(cur + 1)) return true;op11();
	exop12();if(check()) return true; if(dfs(cur + 1)) return true;op12();
	
	return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=72;i++)
		{
			scanf("%d",&a[i]);
		}
		if(check())
		{
			puts("YES");
			continue;
		}
	
		dfs(0)? puts("YES"):puts("NO");
		
	}
	return 0;
 } 