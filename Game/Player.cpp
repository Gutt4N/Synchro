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
#include "Player.h"
#include "define.h"
// グローバル変数の定義 ====================================================

//残像の画像をいれる変数
HGRP zanzo;
//アニメーション
int PuniPuniPlayer;

//メモ
// マップを一つ一つに区切って ゴールまでいったら次のマップへ
// アイテムなどをいっぱいおいてみたり、ギミックなどをいっぱいつくる。

// 関数の定義 ==============================================================
//プレイヤーの初期化
void InitializePlayer(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag);
//残像処理
void PlayerFootPrints();
//プニプニアニメーション
void AnimesionPlayer();

//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializePlayer(Object *Player,int x,int y,int gx,int gy,int gw,int gh,int sx,int sy,int flag)
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
	Player->grp.Handle = LoadGraph("Resources\\Images\\Player1.png");
	Player->grp.Handles[0] = LoadGraph("Resources\\Images\\Player1.png");
	Player->grp.Handles[1] = LoadGraph("Resources\\Images\\Player1.1.png");
	Player->grp.Handles[2] = LoadGraph("Resources\\Images\\Player1.png");
}
//残像処理
void InitZanzo1()
{
	int i;
	static int g_init = 0;
	if (g_init == 0)
	{
		zanzo = LoadGraph("Resources\\Images\\Player1Ki.png");
		g_init = 1;
	}
	//残像表示位置
	for (i = 0; i < ZANZO; i++)
	{
		PlayerX[i] = Player.pos.x;
		PlayerY[i] = Player.pos.y;
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：FirstMapPlayer             //
//				概要  ：プレイヤー表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void FirstMapPlayer()
{
	//初期化
	InitializePlayer(&Player, 64, 416, 0, 0, 32, 32, 0, 0, 1);
	//残像をつけてあげる
	InitZanzo1();
}

//タイトル プレイヤー位置の初期化
void TitleMapPlayer()
{
	//初期化
	InitializePlayer(&Player, 640, 78, 0, 0, 32,32, 0, 0, 1);
	//残像をつけてあげる
	InitZanzo1();
}

void RePlayer1()
{
	//初期化
	InitializePlayer(&Player, 800, 600, 0, 0, 32, 32, 0, 0, 1);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawPlayer                 //
//				概要  ：プレイヤー表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawPlayer()
{
	if (KeyCode & PAD_INPUT_RIGHT)
	{
		PlayerFootPrints();
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_LEFT)
	{
		PlayerFootPrints();
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_10)
	{
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (Player.jump.JumpFlag == 1)
	{
		PlayerFootPrints();
	}
	if (KeyCode == 0)
	{
		AnimesionPlayer();
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：MovePlayer                 //
//				概要  ：プレイヤー移動			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void MovePlayer()
{
	//Flagが1でないとプレイヤーは表示されない
	if (Player.Flag == 1)
	{
		//Moveが1でないと操作を受け付けない
		if (Player.Move == 1)
		{
			//右移動 速度5.0f(同時移動）
			if (KeyCode & PAD_INPUT_RIGHT)
			{
				Player.pos.x += (Player.spd.x + MOVESPEED);
				PlayerX[0] = Player.pos.x;
			}
			//左移動 速度5.0f（同時移動）
			else if (KeyCode & PAD_INPUT_LEFT)
			{
				Player.pos.x += (Player.spd.x - MOVESPEED);
				PlayerX[0] = Player.pos.x;
			}
		}
	}
	int i;
	// 残像データを一つづつずらす
	for (i = ZANZO - 1; i > 0; i--)
	{
		PlayerX[i] = PlayerX[i - 1];
		PlayerY[i] = PlayerY[i - 1];
	}
	
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：JumpPlayer                 //
//				概要  ：プレイヤーがJump		   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void JumpPlayer()
{
	static HSND JumpMu;
	static int init = 0;
	if (init == 0)
	{
		JumpMu = LoadSoundMem("Resources\\Sounds\\jump.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, JumpMu);
		init = 1;
	}
	if ((KeyCode & PAD_INPUT_10) && Player.jump.JumpFlag == 0&&Player.Move==1)
	{
		//ジャンプサウンド
		PlaySoundMem(JumpMu, DX_PLAYTYPE_BACK);
		Player.spd.y = -JUMPPOWER;
		//飛んだらフラグを立てる
		Player.jump.JumpFlag = 1;
	}
	//落下速度制限
	if (Player.spd.y < 9)
	{
		Player.spd.y++;
	}
	//重力をあげる
	Player.pos.y += Player.spd.y;
	PlayerY[0] = Player.pos.y;
}


//残像
void PlayerFootPrints()
{
	int i;
	Player.Kiseki = 1;
	//残像処理
	if (Player.Kiseki == 1)
	{
		for (i = 0; i < ZANZO; i++)
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200 - 255 * i / ZANZO);
			DrawGraph(PlayerX[i]+7, PlayerY[i]+8, zanzo, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}
//プニプニ処理
void AnimesionPlayer()
{
	static int AnimesionCount = 0;
	AnimesionCount++;
	if (AnimesionCount >= 10 && PuniPuniPlayer != 2)
	{
		PuniPuniPlayer++;
		AnimesionCount = 0;
	}
	if (AnimesionCount >= 10 && PuniPuniPlayer == 2)
	{
		PuniPuniPlayer = 0;
		AnimesionCount = 0;
	}
	DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handles[PuniPuniPlayer], TRUE, FALSE);

}