//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Map.cpp
//!
//! @brief  Map関連のソースファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤 祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "Map.h"
#include "define.h"
#include "Player.h"
#include "Player2.h"
#include "Object.h"
#include <math.h>

#define PI 3.1415926f


//マップ移動処理
void Mapidou(Object *map);
//マップ表示for文（使いまわし用）
void DrawMap();
//スペア
void DrawMapSpare();
//マップチップ移動処理
void MapScroll1(int x1, int y1, int x2, int y2, Object *Play);
void MapScroll2(int x1, int y1, int x2, int y2, Object *Play);
void MapScroll3(int x1, int y1, int x2, int y2, Object *Play);
void MapScroll4(int x1, int y1, int x2, int y2, Object *Play);
void MapScroll5(int x1, int y1, int x2, int y2, Object *Play);
//片方が次のマップに移動してもお互いがマップ移動しないと意味がないのでそれを可能にする関数
void WaitPlayerNext(Object *Play,Object *Play2);
void WaitPlayerNext1(Object *Play, Object *Play2);
void WaitPlayerNext2(Object *Play, Object *Play2);
void WaitPlayerPrevious(Object *Play, Object *Play2);
void WaitPlayerPrevious1(Object *Play, Object *Play2);

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/プレイヤーがマップ移動した時のイニシャライズ_/_/_/_/_/_/_/_/_/_/_/_/_//
void MapChangePlayerNextPos(Object *Player,int Any);
void MapChangePlayerNextPos1(Object *Player, int Any);
void MapChangePlayerNextPos2(Object *Player, int Any);
void MapChangePlayerPreviousPos(Object *Player,int Any);
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/プレイヤーがマップから落ちたときの処理_/_/_/_/_/_/_/_/_/_/_/_/_//
void ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Player, Object *Player2, int x, int y, int xx, int yy,int num);
void MapChangeCollisionLR(int x1, int y1, int x2, int y2, Object *Player, int num);
void MapChangeCollisionUD1(int x1, int y1, int x2, int y2, Object *Player, int num);
void MapChangeCollisionUD2(int x1, int y1, int x2, int y2, Object *Player, int num);
//
void MapSelectCollisionLR(int x1, int y1, int x2, int y2, Object *Player2, int num,int flag);
void MapSelectCollisionUD1(int x1, int y1, int x2, int y2, Object *Player2, int num,int flag);
void MapSelectCollisionUD2(int x1, int y1, int x2, int y2, Object *Player2, int num, int flag);
//チュートリアルに入った処理
void Tutorial();
// グローバル ================================================
//マップチップ
int Map[MAP_H][MAP_W];



void Counter(int x, int y, int n)
{
	static HGRP Number = LoadGraph("Resources\\Images\\Item\\Number.png");
	int w = n;	//描画用数字 wという変数に入れている
	int i = 0;	//文字数

	if (w == 0)
	{
		DrawRectGraph(x, y, 0, 0, 25, 32, Number, TRUE, FALSE);
	}
	else
	{
		while (w)
		{
			DrawRectGraph(x - i * 25, y, (w % 10) * 25, 0, 25, 32, Number, TRUE, FALSE);
			w /= 10;
			i++;
		}
	}
}



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：TitleInit                   //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void TitleInit()
{
	FILE *fp;
	errno_t err;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	//マップファイいるをオープンする
	err = fopen_s(&fp, "Map\\title\\title.csv", "r");
	//マップの読み込み
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			Map[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：SelectMapInit              //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void SelectMapInit()
{
	FILE *fp = NULL;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	switch (MapChange)
	{
	case 0:
		//マップファイいるをオープンする
		fopen_s(&fp, "Map\\title\\select.csv", "r");
		break;
	case 1:
		//マップファイいるをオープンする
		fopen_s(&fp, "Map\\title\\select2.csv", "r");
		break;
	}
	
	//マップの読み込み
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			Map[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapFirstInit               //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapFirstInit(void)
{
	FILE *fp;
	errno_t err;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	//マップファイいるをオープンする
	err = fopen_s(&fp, "Map\\MapTutorial\\Map.csv", "r");
	//マップの読み込み
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			Map[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapSecondInit               //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapSecondInit(void)
{
	FILE *fp;
	errno_t err;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	//マップファイいるをオープンする
	err = fopen_s(&fp, "Map\\MapTutorial\\Map2.csv", "r");
	//マップChangeを０にしておく
	//マップの読み込み
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			Map[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：ResultInit                 //
//				概要  ：マップデータ		       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void ResultInit()
{
	FILE *fp;
	errno_t err;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	//マップファイいるをオープンする
	err = fopen_s(&fp, "Map\\result\\result.csv", "r");
	//マップの読み込み
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			Map[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：TitleLoad		           //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void TitleLoad()
{
	TitleInit();
	DrawMap();
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：SelectLoad		           //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void SelectMap()
{
	SelectMapInit();
	DrawMap();
	DrawString(440, 370, "プレイヤーを動かして、マップを選ぼう！", GetColor(255, 255, 255));
	DrawString(440, 400, "矢印キーで左右に動かし、SPACEキーでジャンプ！", GetColor(255, 255, 255));

	DrawString(40, 915, "ESCキーでタイトルへ", GetColor(255, 255, 255));
}

///////////////////////////////////////チュートリアルの初期化
void Tutorial()
{
	if (Scene == Game && MapFlagNumber==99)
	{
		S_init = 0;
		//時間
		Time = 0;
		STime = 0;
	    DTime = 0;
		TTime = 0;
		FTime = 0;
		//表示
		DrawSTime = 0;
		DrawDTime = 0;
		DrawTTime = 0;
		DrawFTime = 0;
		Player.Down = 0;
		MapChange = 0;
		count = 0;
		muinit = 0;
		g_mCnt = 0;
		//チュートリアルの初期化
		FirstMapPlayer();
		FirstMapPlayer2();
		InitGoalTutorialFirst();
		InitGoalTutorialSecond();
		InitGoalTutorial();
		InitZanzo1();
		//デバッグ
		GameScene = TUTORIAL;
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapLoad1		           //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapLoad1()
{
	static HGRP GravityP1;
	static HGRP GravityP2;
	static int GP = 0;
	static int init = 0;
	if (init == 0)
	{
		GravityP1 = LoadGraph("Resources\\Images\\Map\\Gravity1.png");
		GravityP2 = LoadGraph("Resources\\Images\\Map\\Gravity2.png");
		init = 1;
	}
	DrawGraph(Player.pos.x, (Player.pos.y - 32) - sin(PI * 2 / 60 * GP) * 3, GravityP1, TRUE);
	DrawGraph(Player2.pos.x, (Player2.pos.y + 32) + sin(PI * 2 / 60 * GP) * 3, GravityP2, TRUE);
	GP++;
	//map読み込み
	MapFirstInit();
	//マップ表示
	DrawMap();
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapLoad2		           //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapLoad2()
{
	static HGRP GravityP1;
	static HGRP GravityP2;
	static int GP = 0;
	static int init = 0;
	if (init == 0)
	{
		GravityP1 = LoadGraph("Resources\\Images\\Map\\Gravity1.png");
		GravityP2 = LoadGraph("Resources\\Images\\Map\\Gravity2.png");
		init = 1;
	}
	DrawGraph(Player.pos.x, (Player.pos.y - 32) - sin(PI * 2 / 60 * GP) * 3, GravityP1, TRUE);
	DrawGraph(Player2.pos.x, (Player2.pos.y + 32) + sin(PI * 2 / 60 * GP) * 3, GravityP2, TRUE);
	GP++;
	//map読み込み
	MapSecondInit();
	//マップ表示
	DrawMap();
}


void ResultLoad()
{
	ResultInit();
	//マップ表示
	DrawMap();
}


void TitleAtari()
{

	int x1, y1, x2, y2;
	//プレイヤー移動
	MovePlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player.pos.x = x2*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.x = x1*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//マップスクロール判定
	MapScroll3(x1, y1, x2, y2, &Player);
	MapScroll4(x1, y1, x2, y2, &Player);

	//48,64当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 64);
	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 121, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 122, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 123, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////

	//ジャンプ処理
	JumpPlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player.pos.y = y2*BLOCK_CHIP;
		Player.spd.y = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.y = y1*BLOCK_CHIP;
		Player.spd.y = 0;

		Player.jump.JumpFlag = 0;
	}

	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 64);

	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 121, 99);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 122, 1);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 123, 2);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////


	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);
}

void TitleAtari2()
{

	int x1, y1, x2, y2;

	//プレイヤー移動
	MovePlayer2();
	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;


	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player2.pos.x = x2*BLOCK_CHIP;
		Player2.spd.x = 0;
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.x = x1*BLOCK_CHIP;
		Player2.spd.x = 0;
	}

	//8,64の当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 64);
	//////////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 105, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 106, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////

	//マップスクロール判定
	MapScroll3(x1, y1, x2, y2, &Player2);
	MapScroll4(x1, y1, x2, y2, &Player2);
	//ジャンプ処理
	JumpPlayer2();

	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player2.pos.y = y2*BLOCK_CHIP;
		Player2.spd.y = 0;
		Player2.jump.JumpFlag = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.y = y1*BLOCK_CHIP;
		Player2.spd.y = 0;
	}

	MapChangeCollisionUD2(x1, y1, x2, y2, &Player2, 48);
	MapChangeCollisionUD2(x1, y1, x2, y2, &Player2, 64);

	//////////////////////////////////////////////////////
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 105, 99);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 106, 1);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////


	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);

}


void ResultAtari()
{

	int x1, y1, x2, y2;
	//プレイヤー移動
	MovePlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player.pos.x = x2*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.x = x1*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//マップスクロール判定
	MapScroll5(x1, y1, x2, y2, &Player);

	//48,64当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 64);
	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 121, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 122, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 123, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////

	//ジャンプ処理
	JumpPlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player.pos.y = y2*BLOCK_CHIP;
		Player.spd.y = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.y = y1*BLOCK_CHIP;
		Player.spd.y = 0;

		Player.jump.JumpFlag = 0;
	}

	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 64);

	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 121, 99);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 122, 1);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 123, 2);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////


	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);
}

void ResultAtari2()
{


	int x1, y1, x2, y2;

	//プレイヤー移動
	MovePlayer2();
	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;


	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player2.pos.x = x2*BLOCK_CHIP;
		Player2.spd.x = 0;
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.x = x1*BLOCK_CHIP;
		Player2.spd.x = 0;
	}

	//8,64の当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 64);
	//////////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 105, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 106, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////

	//マップスクロール判定
	MapScroll5(x1, y1, x2, y2, &Player2);
	//ジャンプ処理
	JumpPlayer2();

	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player2.pos.y = y2*BLOCK_CHIP;
		Player2.spd.y = 0;
		Player2.jump.JumpFlag = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.y = y1*BLOCK_CHIP;
		Player2.spd.y = 0;
	}

	MapChangeCollisionUD2(x1, y1, x2, y2, &Player2, 48);
	MapChangeCollisionUD2(x1, y1, x2, y2, &Player2, 64);

	//////////////////////////////////////////////////////
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 105, 99);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 106, 1);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////


	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：AtariUpdate                //
//				概要  ：マップ当たり判定           //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void AtariUpdate()
{
	int x1, y1, x2, y2;
	//プレイヤー移動
	MovePlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player.pos.x = x2*BLOCK_CHIP;
		Player.spd.x = 0;	
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.x = x1*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//マップスクロール判定
	MapScroll1(x1, y1, x2, y2,&Player);
	MapScroll2(x1, y1, x2, y2, &Player);

	//48,64当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player, 64);
	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 121, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 122, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 123, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////

	//ジャンプ処理
	JumpPlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player.pos.y = y2*BLOCK_CHIP;
		Player.spd.y = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player.pos.y = y1*BLOCK_CHIP;
		Player.spd.y = 0;

		Player.jump.JumpFlag = 0;
	}

	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 48);
	MapChangeCollisionUD1(x1, y1, x2, y2, &Player, 64);

	//セレクト画面の当たり判定
	//////////////////////////////////////////////////
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 121,99);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 122,1);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 123,2);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 124, 3);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 125, 4);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 126, 5);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 128, 6);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 129, 7);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 130, 8);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 131, 9);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 132, 10);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 133, 11);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 134, 12);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 135, 13);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 136, 14);
	MapSelectCollisionUD1(x1, y1, x2, y2, &Player, 137, 15);
	///////////////////////////////////////////////////////
	

	ResPawnPlayer(x1, y1, x2, y2, &Player,&Player2, 64, 416, 64, 600,1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：AtariUpdate                //
//				概要  ：マップ当たり判定           //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void AtariUpdate2()
{

	int x1, y1, x2, y2;

	//プレイヤー移動
	MovePlayer2();
	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	
	//左判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y2][x1] == 66 || Map[y2][x1] == 67))
	{
		Player2.pos.x = x2*BLOCK_CHIP;
		Player2.spd.x = 0;
	}
	//右判定 
	if ((Map[y1][x2] == 66 || Map[y1][x2] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.x = x1*BLOCK_CHIP;
		Player2.spd.x = 0;
	}

	//8,64の当たり判定
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 48);
	MapChangeCollisionLR(x1, y1, x2, y2, &Player2, 64);
	//////////////////////////////////////////////////////
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 105, 99);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 106, 1);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionLR(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////

	//マップスクロール判定
	MapScroll1(x1, y1, x2, y2,&Player2);
	MapScroll2(x1, y1, x2, y2,&Player2);
	//ジャンプ処理
	JumpPlayer2();

	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((Map[y1][x1] == 66 || Map[y1][x1] == 67) || (Map[y1][x2] == 66 || Map[y1][x2] == 67))
	{
		Player2.pos.y = y2*BLOCK_CHIP;
		Player2.spd.y = 0;
		Player2.jump.JumpFlag = 0;
	}
	//下判定 
	if ((Map[y2][x1] == 66 || Map[y2][x1] == 67) || (Map[y2][x2] == 66 || Map[y2][x2] == 67))
	{
		Player2.pos.y = y1*BLOCK_CHIP;
		Player2.spd.y = 0;
	}

	MapChangeCollisionUD2(x1, y1, x2, y2,  &Player2, 48);
	MapChangeCollisionUD2(x1, y1, x2, y2,  &Player2, 64);

	//////////////////////////////////////////////////////
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 105,99);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 106,1);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 107, 2);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 108, 3);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 109, 4);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 110, 5);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 160, 6);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 161, 7);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 162, 8);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 163, 9);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 164, 10);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 166, 11);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 167, 12);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 168, 13);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 169, 14);
	MapSelectCollisionUD2(x1, y1, x2, y2, &Player2, 170, 15);
	//////////////////////////////////////////////////////
	

	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600,1);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 25);
	ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 8);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapScroll1                  //
//				概要  ：マップチップ移動	       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapScroll1(int x1,int y1,int x2,int y2,Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;
	
	移動したときの座標は
	次のマップに移動してれば
	Xは32Yは前のマップの座標の位置
	*/

	//右判定 
	if (Map[y1][x2] == 3 || Map[y2][x2] == 3)
	{
		Play->Flag = 0;
		WaitPlayerNext(&Player, &Player2);
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapScroll2                  //
//				概要  ：マップチップ移動	       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapScroll2(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;
	移動したときの座標は
	前のマップに戻れば
	Xは1216Yは前のマップの座標の位置
	*/

	//左判定 
	if (Map[y1][x1] == 2 || Map[y2][x1] == 2)
	{
		Play->Flag = 0;
		WaitPlayerPrevious(&Player, &Player2);
	}
}

void MapScroll3(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;

	移動したときの座標は
	次のマップに移動してれば
	Xは32Yは前のマップの座標の位置
	*/

	//右判定 
	if (Map[y1][x2] == 3 || Map[y2][x2] == 3)
	{
		Play->Flag = 0;
		WaitPlayerNext1(&Player, &Player2);
	}
}

void MapScroll4(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;

	移動したときの座標は
	次のマップに移動してれば
	Xは32Yは前のマップの座標の位置
	*/

	//右判定 
	if (Map[y1][x2] == 2 || Map[y2][x2] == 2)
	{
		Play->Flag = 0;
		WaitPlayerPrevious1(&Player, &Player2);
	}
}

void MapScroll5(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;

	移動したときの座標は
	次のマップに移動してれば
	Xは32Yは前のマップの座標の位置
	*/

	//右判定 
	if (Map[y1][x2] == 3 || Map[y2][x2] == 3)
	{
		Play->Flag = 0;
		WaitPlayerNext2(&Player, &Player2);
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawMap                    //
//				概要  ：マップ表示使いまわし       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawMap()
{
	//一度だけ読み込み
	static int init = 0;
	static int Count = 0;
	static HGRP map[2];
	static HGRP next;
	static HGRP back;
	static HGRP yari;
	static HGRP yariR;
	static HGRP red;
	static HGRP blue;
	static HGRP tutorial;
	static HGRP tutorialRe;
	static HGRP stage[15];
	
	if (init == 0)
	{
		//マップ画像
		map[0] = LoadGraph("Resources\\Images\\Map\\groundY.png");
		map[1] = LoadGraph("Resources\\Images\\Map\\groundT.png");
		next = LoadGraph("Resources\\Images\\Map\\next.png");
		back = LoadGraph("Resources\\Images\\Map\\back.png");
		yari = LoadGraph("Resources\\Images\\Map\\yari.png");
		yariR = LoadGraph("Resources\\Images\\Map\\yariR.png");
		red = LoadGraph("Resources\\Images\\Map\\red.png");
		blue = LoadGraph("Resources\\Images\\Map\\blue.png");
		tutorial = LoadGraph("Resources\\Images\\Map\\tutorial.png");
		tutorialRe = LoadGraph("Resources\\Images\\Map\\tutorialRe.png");
		stage[0] = LoadGraph("Resources\\Images\\Map\\stage1.png");
		stage[1] = LoadGraph("Resources\\Images\\Map\\stage2.png");
		stage[2] = LoadGraph("Resources\\Images\\Map\\stage3.png");
		stage[3] = LoadGraph("Resources\\Images\\Map\\stage4.png");
		stage[4] = LoadGraph("Resources\\Images\\Map\\stage5.png");
		stage[5] = LoadGraph("Resources\\Images\\Map\\stage6.png");
		stage[6] = LoadGraph("Resources\\Images\\Map\\stage7.png");
		stage[7] = LoadGraph("Resources\\Images\\Map\\stage8.png");
		stage[8] = LoadGraph("Resources\\Images\\Map\\stage9.png");
		stage[9] = LoadGraph("Resources\\Images\\Map\\stage10.png");
		stage[10] = LoadGraph("Resources\\Images\\Map\\stage11.png");
		stage[11] = LoadGraph("Resources\\Images\\Map\\stage12.png");
		stage[12] = LoadGraph("Resources\\Images\\Map\\stage13.png");
		stage[13] = LoadGraph("Resources\\Images\\Map\\stage14.png");
		stage[14] = LoadGraph("Resources\\Images\\Map\\stage15.png");
		//読み込んだので用済み
		init = 1;
	}
	//for文で使用
	int i, j;
	//表示
	for (i = 0; i < MAP_H; i++)
	{
		for (j = 0; j < MAP_W; j++)
		{
			switch (Map[i][j])
			{
				//cosで矢印をうごかす
			case 2:
				DrawGraph((j * BLOCK_CHIP) - cos(PI * 2 / 120 * Count) * 5, i * BLOCK_CHIP, back, TRUE);
				break;
				//cosで矢印をうごかす
			case 3:
				DrawGraph((j * BLOCK_CHIP) + cos(PI * 2 / 120 * Count)*5, i * BLOCK_CHIP, next, TRUE);
				break;
			case 48:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, blue, TRUE);
				break;
			case 64:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, red, TRUE);
				break;
			case 66:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[0], TRUE);
				break;
			case 67:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[1], TRUE);
				break;
				//画像を反転させる
			case 105:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP,30,30,1.0f,PI, tutorial, TRUE);
				break;
			case 106:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[0], TRUE);
				break;
			case 107:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[1], TRUE);
				break;
			case 108:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[2], TRUE);
				break;
			case 109:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[3], TRUE);
				break;
			case 110:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[4], TRUE);
				break;
			case 121:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, tutorial, TRUE);
				break;
			case 122:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[0], TRUE);
				break;
			case 123:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[1], TRUE);
				break;
			case 124:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[2], TRUE);
				break;
			case 125:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[3], TRUE);
				break;
			case 126:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[4], TRUE);
				break;
			case 128:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[5], TRUE);
				break;
			case 129:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[6], TRUE);
				break;
			case 130:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[7], TRUE);
				break;
			case 131:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[8], TRUE);
				break;
			case 132:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[9], TRUE);
				break;
			case 133:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, stage[10], TRUE);
				break;
				//画像を反転させる
			case 160:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[5], TRUE);
				break;
			case 161:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[6], TRUE);
				break;
			case 162:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[7], TRUE);
				break;
			case 163:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[8], TRUE);
				break;
			case 164:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[9], TRUE);
				break;
			case 165:
				DrawRotaGraph2(j * BLOCK_CHIP, i * BLOCK_CHIP, 30, 30, 1.0f, PI, stage[10], TRUE);
				break;
			}
			
		}
	}
	Count++;
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名： MapChangePlayerNextPos   //
//				概要  ：プレイヤーがマップを移動   //
//					した時の座標				   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapChangePlayerNextPos(Object *Player,int Any)
{
	Player->pos.before_y = Player->pos.y;
	Player->pos.x = Any;
}

void MapChangePlayerNextPos1(Object *Player, int Any)
{
	Player->pos.x = 64;
	Player->pos.y = 416;
}
void MapChangePlayerNextPos2(Object *Player, int Any)
{
	Player->pos.x = 64;
	Player->pos.y = 600;
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapChangePlayerPreviousPos //
//				概要  ：プレイヤーがマップを移動   //
//					した時の座標				   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MapChangePlayerPreviousPos(Object *Player,int Any)
{
	Player->pos.before_y = Player->pos.y;
	Player->pos.x = Any;
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：WaitPlayerNext   		   //
//				概要  ：プレイヤーがマップを移動   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void WaitPlayerNext(Object *Play,Object *Play2)
{
	if (Play->Flag == 0&&Play2->Flag==0)
	{
		//マップをチェンジしたらｘの座標を３２にしてあげる
		MapChangePlayerNextPos(&Player, 32);
		MapChangePlayerNextPos(&Player2, 32);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			//マップをチェンジ
			MapChange++;
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
		}
	}
}


void WaitPlayerNext1(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		//マップをチェンジしたらｘの座標を３２にしてあげる
		MapChangePlayerNextPos1(&Player, 32);
		MapChangePlayerNextPos2(&Player2, 32);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			//マップをチェンジ
			Scene = Game;
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
		}
	}
}

void WaitPlayerNext2(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		//マップをチェンジしたらｘの座標を３２にしてあげる
		MapChangePlayerNextPos1(&Player, 32);
		MapChangePlayerNextPos2(&Player2, 32);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			//マップをチェンジ
			GameScene = SELECT;
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
		}
	}
}



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：WaitPlayer				   //
//				概要  ：プレイヤーがマップを移動   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void WaitPlayerPrevious(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		//マップをチェンジしたらｘの座標を1216にしてあげる
		MapChangePlayerPreviousPos(&Player, 1216);
		MapChangePlayerPreviousPos(&Player2, 1216);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
			//マップをチェンジ
			MapChange--;
		}
	}
}

void WaitPlayerPrevious1(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			DxLib_End();
		}
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：ResPawnPlayer			   //
//				概要  ：復活処理				   //
//				引数  ：省略					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Playe,Object *Playe2,int x,int y,int xx,int yy,int num)
{
	//上判定 
	if (Map[y1][x1] == num || Map[y1][x2] == num)
	{
		//落ちた回数をここで数えている
		Playe->Down++;
		Playe2->Down++;
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//落ちたらやりなおしー
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0||
			Playe->Flag == 0 && Playe2->Flag == 1)
		{
			Playe->Flag = 1;
			Playe2->Flag = 1;
			Playe->pos.x = x;
			Playe->pos.y = y;
			Playe2->pos.x = xx;
			Playe2->pos.y = yy;
			PlayerX[0] = Player.pos.x;
			PlayerXX[0] = Player2.pos.x;
		}
	}
	//下判定 
	if (Map[y2][x1] == num || Map[y2][x2] == num)
	{
		//落ちた回数をここで数えている
		Playe->Down++;
		Playe2->Down++;
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//落ちたらやりなおしー
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0||
			Playe->Flag == 0 && Playe2->Flag == 1)
		{
			Playe->Flag = 1;
			Playe2->Flag = 1;
			Playe->pos.x = x;
			Playe->pos.y = y;
			Playe2->pos.x = xx;
			Playe2->pos.y = yy;
			PlayerX[0] = Player.pos.x;
			PlayerXX[0] = Player2.pos.x;
		}
	}
}


///////////////ここから///////////////セレクト画面での当たり判定/////////////
void MapChangeCollisionLR(int x1, int y1, int x2, int y2, Object *Player,int num)
{
	//初期化
	x1 = Player->pos.x / BLOCK_CHIP;
	y1 = Player->pos.y / BLOCK_CHIP;
	x2 = (Player->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;


	//左判定 
	if (Map[y1][x1] == num || Map[y2][x1] == num)
	{
		Player->pos.x = x2*BLOCK_CHIP;
		Player->spd.x = 0;
	}
	//右判定 
	if (Map[y1][x2] == num || Map[y2][x2] == num)
	{
		Player->pos.x = x1*BLOCK_CHIP;
		Player->spd.x = 0;
	}
}

void MapChangeCollisionUD1(int x1, int y1, int x2, int y2, Object *Player,int num)
{
	//初期化
	x1 = Player->pos.x / BLOCK_CHIP;
	y1 = Player->pos.y / BLOCK_CHIP;
	x2 = (Player->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if (Map[y1][x1] == num || Map[y1][x2] == num)
	{
		Player->pos.y = y2*BLOCK_CHIP;
		Player->spd.y = 0;
	}
	//下判定 
	if (Map[y2][x1] == num || Map[y2][x2] == num)
	{
		Player->pos.y = y1*BLOCK_CHIP;
		Player->spd.y = 0;
		Player->jump.JumpFlag = 0;
	}
}

void MapChangeCollisionUD2(int x1, int y1, int x2, int y2, Object *Player, int num)
{
	//初期化
	x1 = Player->pos.x / BLOCK_CHIP;
	y1 = Player->pos.y / BLOCK_CHIP;
	x2 = (Player->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if (Map[y1][x1] == num || Map[y1][x2] == num)
	{
		Player->pos.y = y2*BLOCK_CHIP;
		Player->spd.y = 0;
		Player->jump.JumpFlag = 0;
	}
	//下判定 
	if (Map[y2][x1] == num || Map[y2][x2] == num)
	{
		Player->pos.y = y1*BLOCK_CHIP;
		Player->spd.y = 0;
		
	}
}

void MapSelectCollisionLR(int x1, int y1, int x2, int y2, Object *Player2, int num,int flag)
{
	//初期化
	x1 = Player2->pos.x / BLOCK_CHIP;
	y1 = Player2->pos.y / BLOCK_CHIP;
	x2 = (Player2->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;


	//左判定 
	if (Map[y1][x1] == num || Map[y2][x1] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.x = 0;
	}
	//右判定 
	if (Map[y1][x2] == num || Map[y2][x2] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.x = 0;
	}
}

void MapSelectCollisionUD1(int x1, int y1, int x2, int y2, Object *Player2, int num,int flag)
{
	//初期化
	x1 = Player2->pos.x / BLOCK_CHIP;
	y1 = Player2->pos.y / BLOCK_CHIP;
	x2 = (Player2->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if (Map[y1][x1] == num || Map[y1][x2] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.y = 0;
	}
	//下判定 
	if (Map[y2][x1] == num || Map[y2][x2] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.y = 0;
		Player2->jump.JumpFlag = 0;
	}
}

void MapSelectCollisionUD2(int x1, int y1, int x2, int y2, Object *Player2, int num,int flag)
{
	//初期化
	x1 = Player2->pos.x / BLOCK_CHIP;
	y1 = Player2->pos.y / BLOCK_CHIP;
	x2 = (Player2->pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2->pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if (Map[y1][x1] == num || Map[y1][x2] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.y = 0;
		Player2->jump.JumpFlag = 0;
	}
	//下判定 
	if (Map[y2][x1] == num || Map[y2][x2] == num)
	{
		MapFlagNumber = flag;
		Player2->spd.y = 0;
	}
}
///////////////ここまで///////////////セレクト画面での当たり判定/////////////