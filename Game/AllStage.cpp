//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   AllStage.cpp
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
#include <math.h>

#define PI 3.1415926f

//マップ表示for文（使いまわし用）
void DrawStageMap();
//マップ移動処理
void Stage1Scroll1(int x1, int y1, int x2, int y2, Object *Play);
void Stage1Scroll2(int x1, int y1, int x2, int y2, Object *Play);
//片方が次のマップに移動してもお互いがマップ移動しないと意味がないのでそれを可能にする関数
void Stage1PlayerNext(Object *Play, Object *Play2);
void Stage1PlayerPrevious(Object *Play, Object *Play2);

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/プレイヤーがマップ移動した時のイニシャライズ_/_/_/_/_/_/_/_/_/_/_/_/_//
void MapChangePlayerNextPos(Object *Player, int Any);
void MapChangePlayerPreviousPos(Object *Player, int Any);
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/プレイヤーがマップから落ちたときの処理_/_/_/_/_/_/_/_/_/_/_/_/_//
void Stage1ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Player, Object *Player2, int x, int y, int xx, int yy, int num);

// グローバル ================================================
////マップチップ
int StageMap[MAP_H][MAP_W];


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：AtariUpdate                //
//				概要  ：マップ当たり判定           //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void StageAtariUpdate()
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
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67))
	{
		Player.pos.x = x2*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//右判定 
	if ((StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player.pos.x = x1*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//マップスクロール判定
	Stage1Scroll1(x1, y1, x2, y2, &Player);
	Stage1Scroll2(x1, y1, x2, y2, &Player);

	//ジャンプ処理
	JumpPlayer();

	//当たり判定初期化
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67))
	{
		Player.pos.y = y2*BLOCK_CHIP;
		Player.spd.y = 0;
	}
	//下判定 
	if ((StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player.pos.y = y1*BLOCK_CHIP;
		Player.spd.y = 0;
		Player.jump.JumpFlag = 0;
	}
	//マップから落ちたときリスポーンする
	Stage1ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：AtariUpdate                //
//				概要  ：マップ当たり判定           //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void StageAtariUpdate2()
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
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67))
	{
		Player2.pos.x = x2*BLOCK_CHIP;
		Player2.spd.x = 0;
	}
	//右判定 
	if ((StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player2.pos.x = x1*BLOCK_CHIP;
		Player2.spd.x = 0;
	}

	//マップスクロール判定
	Stage1Scroll1(x1, y1, x2, y2, &Player2);
	Stage1Scroll2(x1, y1, x2, y2, &Player2);
	//ジャンプ処理
	JumpPlayer2();

	//当たり判定初期化
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//上判定 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67))
	{
		Player2.pos.y = y2*BLOCK_CHIP;
		Player2.spd.y = 0;
		Player2.jump.JumpFlag = 0;
	}
	//下判定 
	if ((StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player2.pos.y = y1*BLOCK_CHIP;
		Player2.spd.y = 0;
	}

	//マップから落ちたときリスポーンする
	Stage1ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1Scroll1              //
//				概要  ：マップチップ移動	       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1Scroll1(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;

	移動したときの座標は
	次のマップに移動してれば
	Xは32Yは前のマップの座標の位置
	*/

	//右判定 
	if (StageMap[y1][x2] == 3 || StageMap[y2][x2] == 3)
	{
		Play->Flag = 0;
		Stage1PlayerNext(&Player, &Player2);
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1Scroll2              //
//				概要  ：マップチップ移動	       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1Scroll2(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;
	移動したときの座標は
	前のマップに戻れば
	Xは1216Yは前のマップの座標の位置
	*/

	//左判定 
	if (StageMap[y1][x1] == 2 || StageMap[y2][x1] == 2)
	{
		Play->Flag = 0;
		Stage1PlayerPrevious(&Player, &Player2);
	}
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1ChangePlayerNextPos  //
//				概要  ：プレイヤーがマップを移動   //
//					した時の座標				   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1ChangePlayerNextPos(Object *Player, int Any)
{
	Player->pos.before_y = Player->pos.y;
	Player->pos.x = Any;
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1ChangePlayerPreviousPos //
//				概要  ：プレイヤーがマップを移動   //
//					した時の座標				   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1ChangePlayerPreviousPos(Object *Player, int Any)
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
void Stage1PlayerNext(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
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
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1PlayerPrevious	   //
//				概要  ：プレイヤーがマップを移動   //
//				引数  ：Object  *Player			   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1PlayerPrevious(Object *Play, Object *Play2)
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
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：Stage1ResPawnPlayer  	   //
//				概要  ：復活処理				   //
//				引数  ：省略					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void Stage1ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Playe, Object *Playe2, int x, int y, int xx, int yy, int num)
{
	//上判定 
	if (StageMap[y1][x1] == num || StageMap[y1][x2] == num)
	{
		//落ちた回数をここで数えている
		Playe->Down++;
		Playe2->Down++;
		//potisionをここで指定
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		//残像はプレイヤーの指定したポジションに移動
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//落ちたらゴールのパーツが復活
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0 ||
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
	if (StageMap[y2][x1] == num || StageMap[y2][x2] == num)
	{
		//落ちた回数をここで数えている
		Playe->Down++;
		Playe2->Down++;
		//potisionをここで指定
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		//残像はプレイヤーの指定したポジションに移動
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//落ちたらゴールのパーツが復活
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0 ||
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



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawMap                    //
//				概要  ：マップ表示使いまわし       //
//				引数  ：なし					   //
//				戻り値：なし        		       //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawStageMap()
{
	//一度だけ読み込み
	static int init = 0;
	static int Count = 0;
	static HGRP map[2];
	static HGRP next;
	static HGRP back;
	if (init == 0)
	{
		//マップ画像
		map[0] = LoadGraph("Resources\\Images\\Map\\groundY.png");
		map[1] = LoadGraph("Resources\\Images\\Map\\groundT.png");
		next = LoadGraph("Resources\\Images\\Map\\next.png");
		back = LoadGraph("Resources\\Images\\Map\\back.png");
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
			switch (StageMap[i][j])
			{
				//cosで→グラフィックを動かす
			case 2:
				DrawGraph((j * BLOCK_CHIP) - cos(PI * 2 / 120 * Count) * 5, i * BLOCK_CHIP, back, TRUE);
				break;
				//cosで→グラフィックを動かす
			case 3:
				DrawGraph((j * BLOCK_CHIP) + cos(PI * 2 / 120 * Count) * 5, i * BLOCK_CHIP, next, TRUE);
				break;
			case 66:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[0], TRUE);
				break;
			case 67:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[1], TRUE);
				break;
			}
		}
	}
	Count++;
}