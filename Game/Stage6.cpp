//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Stage6.cpp
//!
//! @brief  Map関連のソースファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤 祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "AllStage.h"
#include "define.h"
#include "Player.h"
#include "Player2.h"
#include "Object.h"


void Stage6();
// グローバル ================================================

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapFirstInit               //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage6Init(void)
{
	FILE *fp = NULL;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	switch (MapFlagNumber)
	{
	case 6:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			fopen_s(&fp, "Map\\MapSixth\\Map.csv", "r");
			break;
		}
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
			StageMap[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}


///////////////////////////////////////Stage6の初期化
void Stage6()
{
	if (Scene == Game &&  MapFlagNumber == 6)
	{
		S_init = 0;
		//時間の初期化
		Time = 0;
		STime = 0;
		DTime = 0;
		TTime = 0;
		FTime = 0;
		//表示の初期化
		DrawSTime = 0;
		DrawDTime = 0;
		DrawTTime = 0;
		DrawFTime = 0;
		Player.Down = 0;
		//カウンター系の初期化
		MapChange = 0;
		count = 0;
		muinit = 0;
		g_mCnt = 0;
		//プレイヤーの初期化
		FirstMapPlayer();
		FirstMapPlayer2();
		//ゴール、パーツの初期化
		InitGoalPartsFirst1();
		InitGoalPartsSecond1();
		InitGoalPartsThird1();
		InitGoalPartsFourth1();
		InitGoal1();
		InitZanzo1();
		//デバッグ
		GameScene = STAGE6;
	}
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MapLoad1		           //
//				概要  ：マップデータ読み込み       //
//				引数  ：省略					   //
//				戻り値：省略        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage6Load()
{
	//map読み込み
	Stage6Init();
	//マップ表示
	DrawStageMap();
}

