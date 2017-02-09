//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  Player関連のソースファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
// ヘッダファイルの読み込み ================================================
#include "Player2.h"
#include "define.h"
// グローバル変数の定義 ====================================================
HGRP zanzo2;
//アニメーション
int PuniPuniPlayer2;
// 関数の定義 ==============================================================
//プレイヤーの初期化
void InitializePlayer2(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag);
//残像処理
void PlayerFootPrints2();
//プニプニアニメーション
void AnimesionPlayer2();
//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializePlayer2(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag)
{
	Player->pos.x = x;
	Player->pos.y = y;
	Player->grp.x = gx;
	Player->grp.y = gy;
	Player->grp.w = gw;
	Player->grp.h = gh;
	Player->spd.x = sx;
	Player->spd.y = sy;
	Player->Flag = flag;
	Player->grp.Handle = LoadGraph("Resources\\Images\\Player2.png");
	Player->grp.Handles[0] = LoadGraph("Resources\\Images\\Player2.png");
	Player->grp.Handles[1] = LoadGraph("Resources\\Images\\Player2.2.png");
	Player->grp.Handles[2] = LoadGraph("Resources\\Images\\Player2.png");
}
//残像処理
void InitZanzo2()
{
	int i;
	static int g_init = 0;
	if (g_init == 0)
	{
		zanzo2 = LoadGraph("Resources\\Images\\Player2Ki.png");
		g_init = 1;
	}
	//残像位置
	for (i = 0; i < ZANZO; i++)
	{
		PlayerXX[i] = Player2.pos.x;
		PlayerYY[i] = Player2.pos.y;
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：FirstMapPlayer2             //
//				概要  ：プレイヤー表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void FirstMapPlayer2()
{
	//プレイヤー初期化
	InitializePlayer2(&Player2, 64, 600, 0, 0, 32, 32, 0, 0, 1);
	//残像初期化
	InitZanzo2();
}

void TitleMapPlayer2()
{
	//プレイヤー初期化
	InitializePlayer2(&Player2, 640, 600, 0, 0, 32, 32, 0, 0, 1);
	//残像初期化
	InitZanzo2();
}

void RePlayer2()
{
	//プレイヤー初期化
	InitializePlayer2(&Player2, 800, 560, 0, 0, 32, 32, 0, 0, 1);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawPlayer                 //
//				概要  ：プレイヤー表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawPlayer2()
{
	if (KeyCode & PAD_INPUT_RIGHT)
	{
		PlayerFootPrints2();
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_LEFT)
	{
		PlayerFootPrints2();
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_10)
	{
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (Player2.jump.JumpFlag == 1)
	{
		PlayerFootPrints2();
	}
	if (KeyCode == 0)
	{
		AnimesionPlayer2();
	}
	
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MovePlayer                 //
//				概要  ：プレイヤー移動			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MovePlayer2()
{
	//Flagが１でないと表示されない
	if (Player2.Flag == 1)
	{
		//Moveが１でないと操作を受け付けない
		if (Player2.Move == 1)
		{
			//右移動 速度5.0f
			if (Key[KEY_INPUT_RIGHT] == 1)
			{
				Player2.pos.x = Player2.pos.x + (Player2.spd.x + MOVESPEED);
				PlayerXX[0] = Player2.pos.x;
			}
			//左移動 速度5.0f
			else if (Key[KEY_INPUT_LEFT] == 1)
			{
				Player2.pos.x = Player2.pos.x + (Player2.spd.x - MOVESPEED);
				PlayerXX[0] = Player2.pos.x;

			}
		}
	}
	
	int i;
	// 残像データを一つづつずらす
	for (i = ZANZO - 1; i > 0; i--)
	{
		PlayerXX[i] = PlayerXX[i - 1];
		PlayerYY[i] = PlayerYY[i - 1];
	}
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：JumpPlayer                 //
//				概要  ：プレイヤーがJump		   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void JumpPlayer2()
{
	static HSND JumpMu2;
	static int init = 0;
	if (init == 0)
	{
		JumpMu2 = LoadSoundMem("Resources\\Sounds\\jump.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, JumpMu2);
		init = 1;
	}
	
	if (Key[KEY_INPUT_SPACE] == 1 && Player2.jump.JumpFlag == 0&&Player2.Move==1)
	{
		PlaySoundMem(JumpMu2, DX_PLAYTYPE_BACK);
		Player2.spd.y = -JUMPPOWER;
		//飛んだらフラグを立てる
		Player2.jump.JumpFlag = 1;
	}
	//落下速度制限
	if (Player2.spd.y < 9)
	{
		Player2.spd.y++;
	}
	Player2.pos.y -= Player2.spd.y;
	PlayerYY[0] = Player2.pos.y;
}

//残像
void PlayerFootPrints2()
{
	int i;
	Player2.Kiseki = 1;
	//残像処理
	if (Player2.Kiseki == 1)
	{
		for (i = 0; i < ZANZO; i++)
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200 - 255 * i / ZANZO);
			DrawGraph(PlayerXX[i] + 7, PlayerYY[i] + 8, zanzo2, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

//プニプニアニメーション処理
void AnimesionPlayer2()
{
	static int AnimesionCount = 0;
	AnimesionCount++;
	if (AnimesionCount >= 10 && PuniPuniPlayer2 != 2)
	{
		PuniPuniPlayer2++;
		AnimesionCount = 0;
	}
	if (AnimesionCount >= 10 && PuniPuniPlayer2 == 2)
	{
		PuniPuniPlayer2 = 0;
		AnimesionCount = 0;
	}
	DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);

}