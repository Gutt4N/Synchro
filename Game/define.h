//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   define.h
//!
//! @brief  define関連のヘッダファイル
//!
//! @date   
//!
//! @author GF3_01_安藤 祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				        define	                   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//移動速度
#define MOVESPEED (5)
//マップのサイズ
#define MAP_W (GAME_W/BLOCK_W)
#define MAP_H (GAME_H/BLOCK_H)
//マップに表示するブロックのサイズ
#define BLOCK_W (32)
#define BLOCK_H (32)
#define BLOCK_CHIP (32)
//画面サイズ
#define GAME_W (1280)
#define GAME_H (960)
//ジャンプ
//3マス分ジャンプ
#define JUMPPOWER (17)
//残像処理
#define ZANZO (27)
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				        extern	                   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//

//グローバル変数
#ifndef EXTERN
#define EXTERN extern
#endif

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				      構造体宣言                   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
typedef struct
{
	//座標
	int x;
	int y;
	//前の座標保存用
	int before_x;
	int before_y;
}Pos;

typedef struct
{
	//グラフィック x,y,w,h
	int x;
	int y;
	int w;
	int h;
	//画像を入れる変数
	HGRP Handle;
	//画像を入れる配列変数
	HGRP Handles[3];
}Grp;

typedef struct
{
	//スピード縦軸、横軸
	int x;
	int y;
}Spd;

typedef struct
{
	//ジャンプフラグ、ジャンプしたしてないを判断
	int JumpFlag;
}Jump;

typedef struct
{
	//構造体を構造体にまとめる
	Pos pos;
	Grp grp;
	Spd spd;
	Jump jump;
	//歩いているかどうかを判断する変数
	int Move;
	//プレイヤーを存在しているかどうかを判断
	int Flag;
	//残像処理
	int Kiseki;
	//復活回数のカウント
	int Down;
}Object;

/////グローバルで構造体を定義/////
//プレイヤーの構造体
EXTERN Object Player;
EXTERN Object Player2;
//ゴールチップの構造体
EXTERN Object Goal1;
EXTERN Object Goal2;
EXTERN Object Goal3;
EXTERN Object Goal4;
EXTERN Object Goal;
//
EXTERN Object CheckPoint;

//GetHitKeyStateAll関数に使う変数
EXTERN char Key[256];
//Map切り替え
EXTERN int MapChange;

//残像処理に使うグローバル変数
EXTERN int PlayerX[ZANZO];
EXTERN int PlayerY[ZANZO];
EXTERN int PlayerXX[ZANZO];
EXTERN int PlayerYY[ZANZO];
//ここまで。


//シーンの切り替え
EXTERN int Scene;
//ゲームシーンの中の切り替え
EXTERN int GameScene;
//操作用変数
EXTERN int KeyCode;
EXTERN int KeyCodeOld;

//時間を格納する変数
EXTERN float Time;
EXTERN int SSSTime;
EXTERN int SSTime;
EXTERN int STime;
EXTERN int DTime;
EXTERN int TTime;
EXTERN int FTime;
//ここまで
//格納した時間をリザルトで表示する変数///
EXTERN int DrawSTime;
EXTERN int DrawDTime;
EXTERN int DrawTTime;
EXTERN int DrawFTime;
/////////////////////////////////////////
EXTERN int count;
//Soundを初期化する変数
EXTERN int muinit;
EXTERN int g_mCnt;
//マップの切り替えをするための変数
EXTERN int MapFlagNumber;
//スタート表示するための変数
EXTERN int S_init;
//チュートリアルでの文字を表示する変数
EXTERN int FontInit;
EXTERN int FontInit2;
//ゲームシーンにつかうenum
enum Game
{
	Title,
	Game,
	Exit
};
//マップ切り替えのenum
enum Map
{
	SELECT,
	TUTORIAL,
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6,
	STAGE7,
	STAGE8,
	STAGE9,
	STAGE10,
	STAGE11,
	STAGE12,
	STAGE13,
	STAGE14,
	STAGE15,
	RESULT
};