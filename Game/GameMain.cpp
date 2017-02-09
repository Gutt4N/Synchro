//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#define EXTERN
// ヘッダファイルの読み込み ================================================
#include "GameMain.h"
#include "define.h"
#include "Player.h"
#include "AllStage.h"
#include "Map.h"
#include "Player2.h"
#include "Object.h"
// 列挙体の定義 ====================================================

// グローバル変数の定義 ====================================================

//タイトルで使う初期化変数
int TitleInit = 0;
//メニュー画面の画像
HGRP menu;
//タイトルテキストの画像
HGRP nexttitle;
//BGMを入れる変数
HSND bgm;
//BGMをシーン切り替えごとに流しなおす
int MusicInit;
// 関数の定義 ==============================================================
//Enterキー処理
void UpEcs();
//ESCキー処理
void ReEcs();
//ESCキー処理
void ReTitle();
//BGM処理
void BGM1();
void BGM2();
//スタート処理
void StartString(int Num);
void StartString1(int Num);
//落下回数表示するための関数
void DrawPlayerDownCounter();
//経過時間表示
void StartTimer();
//リザルトで経過時間を表示
void DrawTimer();
//キャラクターを表示する関数
void DrawPlayers(Object *Player, Object *Player2);
//Titleシーン
void TitlE();
//Titleシーンの初期化
void titleinit();

//リザルト画面の処理
void Result();

//Ecsキーでタイトルへを点滅
void DrawEcsFlash();
//チュートリアルでの制御
void TutorialControl();
void TutorialControl2();


//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Initialize(void)
{
	//ゲームシーンの初期化
	Scene = Title;
	switch (Scene)
	{
	//Titleシーンなら
	case Title:
		//TitleInitが０なら
		if (TitleInit == 0)
		{
			//Titleの初期化
			titleinit();
			//プレイヤー１，２の位置を初期化
			TitleMapPlayer();
			TitleMapPlayer2();
		}
		break;
	case Game:
		switch (GameScene)
		{
		case SELECT:
			break;
		case TUTORIAL:
			break;
		case STAGE1:
			break;
		case STAGE2:
			break;
		case STAGE3:
			break;
		case STAGE4:
			break;
		case STAGE5:
			break;
		case STAGE6:
			break;
		case STAGE7:
			break;
		case STAGE8:
			break;
		case STAGE9:
			break;
		case STAGE10:
			break;
		case STAGE11:
			break;
		case RESULT:
			break;
		}
		break;
	case Exit:
		break;
	}

}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Update(void)
{
	//キー入力取得
	GetHitKeyStateAll(Key);
	// キー入力取得
	KeyCode = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	switch (Scene)
	{
	//Titleシーンなら
	case Title:
		//Titleで行う処理
		TitlE();
		//BGMをならす処理
		BGM1();
		//プレイヤー１，２のマップ当たり判定
		TitleAtari();
		TitleAtari2();
		break;
		//caseゲームで
	case Game:
		//かつゲームシーンで
		switch (GameScene)
		{
			//マップセレクト画面だったら
		case SELECT:
			//BGMを鳴らす処理
			BGM2();
			if (MapChange == 0)
			{
				//マップの当たり判定
				AtariUpdate();
				AtariUpdate2();
				//ステージに入ったときの処理
				Tutorial();
				//ステージ12345の処理
				Stage1();
				Stage2();
				Stage3();
				Stage4();
				Stage5();
				//Titleにもどったときの処理
				ReTitle();
			}
			else if(MapChange == 1)
			{
				//マップの当たり判定
				AtariUpdate();
				AtariUpdate2();
				//ステージ6789 10 11の処理
				Stage6();
				Stage7();
				Stage8();
				Stage9();
				Stage10();
				Stage11();
				//タイトルに戻ったときの処理
				ReTitle();
			}
			break;
			
		case TUTORIAL:  //チュートリアルシーンなら
			//BGMをならす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				AtariUpdate();
				AtariUpdate2();
			}
			else
			{
				//マップの当たり判定
				AtariUpdate();
				AtariUpdate2();
				//チュートリアルでのゴール、パーツの当たり判定
				StageTUTORIAL();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE1:	//ステージ１なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//ステージ１でのゴール、パーツの処理
				Stage1HITParts();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE2:	//Stage2なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage2のゴール、パーツの処理
				Stage1HITParts();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE3:
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage3でのゴール、パーツの処理
				Stage1HITParts();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE4:
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage4でのゴール、パーツの処理
				Stage4HitParts1();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//ゲートの当たり判定
				Stage4HitParts2();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE5:	//Stage5なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage5でのゴール、パーツの処理
				Stage5HitParts1();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage5でのゴール、パーツの処理
				Stage5HitParts2();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE6:		//Stage6なら
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage6のゴール、パーツの処理
				StageTUTORIAL();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE7:		//Stage7なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage7のゴール、パーツの当たり判定
				Stage1HITParts();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE8:	//Stage8なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage8のゴール、パーツの処理
				Stage5HitParts1();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage8のゴール、パーツの処理
				Stage5HitParts2();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE9:		//Stage9なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage9のゴール、パーツの処理
				Stage9HitParts1();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage9のゴール、パーツの処理
				Stage9HitParts2();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE10:		//Stage10なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage10のゴール、パーツの処理２つ
				Stage9HitParts1();
				Stage9HitParts2();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case STAGE11:		//Stage11なら
			//BGMを鳴らす処理
			BGM1();
			if (MapChange == 0)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage11のゴール、パーツの処理
				Stage5HitParts2();
			}
			else if (MapChange == 1)
			{
				//マップの当たり判定
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage11のゴール、パーツの処理
				Stage5HitParts1();
			}
			//ゲーム中にEcsキーを押したときの処理
			ReEcs();
			break;
		case RESULT:	//リザルトなら
			//BGMを鳴らす処理
			BGM2();
			/*リザルト結果を表示するために
			カウンターを動かす*/
			count++;
			//マップの当たり判定
			ResultAtari();
			ResultAtari2();
			//リザルト結果
			Result();
			//Enterキーを押したときの処理
			UpEcs();
			break;
		}
		break;
	case Exit:
		break;
	}

	KeyCodeOld = KeyCode;			//入力情報保存

}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Render(void)
{
	switch (Scene)
	{
	case Title:	//Titleシーンなら
		//プレイヤー１，２の描画
		DrawPlayers(&Player, &Player2);
		TitleLoad();
		break;
	case Game:
			switch (GameScene)
			{
			case SELECT:
				
				if (MapChange == 0)
				{
					DrawString(20, 250, "チュートリアル", GetColor(255, 255, 255));
					DrawString(20, 680, "チュートリアル", GetColor(255, 255, 255));
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//Selectマップの読み込み
					SelectMap();
				}
				else if (MapChange==1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//Selectマップの読み込み
					SelectMap();
				}
				break;
			case TUTORIAL:
				//Ready Goを表示、から時間計算
				StartString1(0);
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//チュートリアルのマップ読み込み
					MapLoad1();
					//チュートリアルの処理
					TutorialControl();
					
				}
				else if(MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//チュートリアルのマップ読み込み
					MapLoad2();
					//ゴール、パーツの表示
				    DrawGoalPartsTurorial1();
					//説明
					TutorialControl2();
				}
				
				break;
			case STAGE1:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップの読み込み
					Stage1Load1();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップの読み込み
					Stage1Load1();
					//ゴール、パーツの表示
					DrawGoalPartsTurorial();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE2:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップの読み込み
					Stage2Load1();
					//下里
					//DrawGoalParts();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップの読み込み
					Stage2Load1();
					//ゴール、パーツの表示
					DrawGoalPartsTurorial();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE3:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage3Load();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage3Load();
					////パーツ表示////
					DrawGoalPartsTurorial();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE4:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage4Load();
					//ゴール、パーツの表示
					DrawStage4Parts1();
				}
				else if (MapChange == 1)
				{
					//プレイヤー表示
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage4Load();
					//ゴール、パーツの表示
					DrawStage4Parts();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE5:	
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage5Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップロード
					Stage5Load();
					//ゴール、パーツの表示
					DrawStage5Parts2();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE6:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage6Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
					DrawStage5Parts2();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE7:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage7Load();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage7Load();
					//ゴール、パーツの表示
					DrawGoalPartsTurorial();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE8:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage8Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage8Load();
					//ゴール、パーツの表示
					DrawStage5Parts2();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE9:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage9Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage9Load();
					//ゴール、パーツの表示
					DrawStage5Parts3();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE10:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage10Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
					//ゴール、パーツの表示
					DrawStage5Parts3();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case STAGE11:
				if (MapChange == 0)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage11Load();
					//ゴール、パーツの表示
					DrawStage5Parts2();
				}
				else if (MapChange == 1)
				{
					//プレイヤー１，２の描画
					DrawPlayers(&Player, &Player2);
					//マップ読み込み
					Stage11Load();
					//ゴール、パーツの表示
					DrawStage5Parts1();
				}
				//Ready Goを表示、から時間計算
				StartString(1);
				break;
			case RESULT:
				//プレイヤー１，２の描画
				DrawPlayers(&Player, &Player2);
				//マップの表示
				ResultLoad();
				//時間、ランク、等の表示
				Result();
				break;
			}
			break;
	case Exit:
		break;
	}


}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Finalize(void)
{

}



//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawPlayer                 //
//				概要  ：プレイヤー表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawPlayers(Object *Player,Object *Player2)
{
	//フラグが１だったら表示するぜー！
	if (Player->Flag == 1)
	{
		//プレイヤー1表示
		DrawPlayer();
	}
	//フラグが１だったら表示するぜー！
	if (Player2->Flag == 1)
	{
		//プレイヤー2表示
		DrawPlayer2();
	}

}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：TitlE	                   //
//				概要  ：タイトル表示			   //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void TitlE()
{
	static int nextcount=0;
	//Ｓｔａｒｔ end 表示
	//DrawRectGraph(550, 700, 0, 0, 512, 512, menu, TRUE, FALSE);
	//var1.00表示
	DrawString(1150, 50, "Ver 1.00", GetColor(255, 255, 255));
	DrawString(50, 900, "タイトルでもキャラクターが動くよ！", GetColor(255, 255, 255));
	DrawString(1190, 650, "Start", GetColor(255, 255, 255));
	DrawString(1190, 580, "Start", GetColor(255, 255, 255));
	DrawString(50, 270, "End", GetColor(255, 255, 255));
	DrawString(50, 330, "End", GetColor(255, 255, 255));
	static HSND EnterMu;
	static HSND sentaku;
	static int init = 0;
	if (init == 0)
	{
		//サウンドエフェクトの初期化
		EnterMu = LoadSoundMem("Resources\\Sounds\\kettei.mp3");
		sentaku = LoadSoundMem("Resources\\Sounds\\cursor2.mp3");
		ChangeVolumeSoundMem(255 * 50 / 100, EnterMu);
		ChangeVolumeSoundMem(255 * 50 / 100, sentaku);
		init = 1;

	}
	//キーボード入力状態を取得
	GetHitKeyStateAll(Key);
	/*
	//上キーの処理
	if (Key[KEY_INPUT_UP] == 1)
	{
		//→を上へ。
		nextcount = 0;
		PlaySoundMem(sentaku, DX_PLAYTYPE_BACK);
	}
	//下キーの処理
	if (Key[KEY_INPUT_DOWN] == 1)
	{
		//→を下へ
		nextcount = 1;
		PlaySoundMem(sentaku, DX_PLAYTYPE_BACK);
	}

	if (nextcount == 0)
	{
		//→の表示
		DrawGraph(500, 750, nexttitle, TRUE);
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			PlaySoundMem(EnterMu, DX_PLAYTYPE_BACK);
			//１にする
			TitleInit = 1;
			//セレクト画面の初期化
			GameSelectmanuInit();
			////マップChangeを０にしておく
			MapChange = 0;
			//シーンをゲームに切り替える
			Scene = Game;
			
		}
	}
	else
	{
		//→の表示
		DrawGraph(500, 815, nexttitle, TRUE);
		//→がEndにあれば正常終了
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			DxLib_End();
		}
	}
	*/
	if (Key[KEY_INPUT_R] == 1)
	{
		Player.pos.x = 640;
		Player.pos.y = 78;
		Player2.pos.x = 640;
		Player2.pos.y = 600;
	}
	
}

void titleinit()
{
	//プレイヤーを動けるようにしておく
	Player.Move = 1;
	Player2.Move = 1;
	//画像を初期化
	menu = LoadGraph("Resources\\Images\\Titlemenu.png");
	nexttitle = LoadGraph("Resources\\Images\\Map\\next.png");
	//音楽を初期化
	bgm = LoadSoundMem("Resources\\Sounds\\bgm_maoudamashii_cyber01.mp3");
}

void GameSelectmanuInit()
{
	//プレイヤーを動けるようにしておく
	Player.Move = 1;
	Player2.Move = 1;
	//マップチェンジを0にしておく
	MapChange = 0;
	//マップチェンジカウンターを戻す
	MapFlagNumber = 0;
	//プレイヤーの初期化
	FirstMapPlayer();
	FirstMapPlayer2();
}

//復活回数をカウントする関数
void DrawPlayerDownCounter()
{
	static int init = 0;
	if (init == 0)
	{
		Player.Down = 0;
		init = 1;
	}
	static HGRP Down = LoadGraph("Resources\\Images\\Item\\Number.png");
	//復活回数＝ を描画
	DrawRectGraph(780, 30, 0, 40, 200, 50, Down, TRUE, FALSE);
	//数字を描画
	Counter(960, 55, Player.Down);
	
}
//経過時間を描画するカウント
void StartTimer()
{
	static HGRP Down = LoadGraph("Resources\\Images\\Item\\Number.png");
	//経過時間 を描画
	DrawRectGraph(250, 50, 0, 95, 400, 50, Down, TRUE, FALSE);
	DrawString(420, 55, " :", GetColor(255, 255, 255));
	//時間を数えるカウンターを動かす
	Time++;
	//60フレームになったら
	if(Time>=60)
	{
		Time = 0;
		//00:01秒追加する
		STime++;
		//更新ごとに表示変数に代入
		DrawSTime = STime;
	}
	//9秒になったら
	if (STime>9)
	{
		//00:10秒にする
		DTime++;
		//00:00にもどす
		STime = 0;
		//更新ごとに表示変数に代入
		DrawDTime = DTime;
		
	}
	//59秒以上になったら
	if (DTime > 5)
	{
		//01:00にする
		TTime++;
		//59秒を00秒に戻す
		DTime = 0;
		//更新ごとに表示変数に代入
		DrawTTime = TTime;

	}
	//09分59秒になったら
	if (TTime > 9)
	{
		//10分にする
		FTime++;
		//10分にして0分00秒にもどす
		TTime = 0;
		//更新ごとに表示変数に代入
		DrawFTime = FTime;
	}

	//計算した時間を表示
	Counter(460, 55, STime);
	Counter(440, 55, DTime);
	Counter(410, 55, TTime);
	Counter(390, 55, FTime);
}
//リザルト画面の処理
void Result()
{
	static HGRP Result;
	static HGRP Down; 
	static HSND ResultMus;
	
	DrawString(1150, 50, "Select画面", GetColor(255, 255, 255));
	DrawString(1150, 900, "Select画面", GetColor(255, 255, 255));

	/*DrawRectGraph(200, 50, 0, 95, 400, 50, Down, TRUE, FALSE);*/
	//DrawString(370, 55, " :", GetColor(255, 255, 255));
	static int init = 0;
	
	static int Draw = 0;
	if (init == 0)
	{
		//プレイヤー１２の初期化
		RePlayer1();
		RePlayer2();
		Result = LoadGraph("Resources\\Images\\Item\\Score.png");
		Down = LoadGraph("Resources\\Images\\Item\\Number.png");
		ResultMus = LoadSoundMem("Resources\\Sounds\\drum-japanese1.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, ResultMus);
		init = 1;
	}
	//CLEARを表示
	DrawRectGraph(400, 40, 0, 0, 500, 110, Result, TRUE, FALSE);
	if (count > 60)
	{
		if (muinit == 0)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 1;
		}
		//経過時間の描画
		DrawRectGraph(500, 250, 0, 95, 400, 50, Down, TRUE, FALSE);
		DrawString(670, 250, " :", GetColor(255, 255, 255));
		Counter(710, 250, DrawSTime);
		Counter(690, 250, DrawDTime);
		Counter(660, 250, DrawTTime);
		Counter(640, 250, DrawFTime);
		//ここまで
		
	}
	if (count > 120)
	{
		if (muinit == 1)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 2;
		}
		//復活回数を描画
		Counter(670, 400, Player.Down);
		DrawRectGraph(500, 380, 0, 40, 200, 50, Down, TRUE, FALSE);
		//ここまで
	}
	//ランクSABCを判断する条件判断文
	if (count > 180)
	{
	
		DrawRectGraph(400, 520, 0, 130, 500, 110, Result, TRUE, FALSE);
		if (TTime  <=0 &&DTime<=5&&STime<=9)
		{
			DrawRectGraph(900, 510, 0, 370, 110, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 2 && DTime <= 3)
		{
			DrawRectGraph(900, 510, 120, 370, 150, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 3 && DTime <= 3)
		{
			DrawRectGraph(900, 510, 280, 370, 100, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 6 && DTime <= 6)
		{
			DrawRectGraph(900, 510, 400, 370, 80, 110, Result, TRUE, FALSE);
		}
		if (muinit == 2)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 3;
		}
	}

	/*
	//Enter Keyを押してもらうように催促する
	if (count > 210)
	{
		g_mCnt++;
		if (g_mCnt % 60 >= 30)
		{
			DrawString(600, 700, "Push Enter Key", GetColor(255, 255, 255));
		}
	}
	
	UpEcs();
	*/
}

//Enterキーの処理
void UpEcs()
{
	if (Key[KEY_INPUT_RETURN] == 1)
	{
		GameSelectmanuInit();
		GameScene = SELECT;
	}
}
//Ecsキーの処理
void ReEcs()
{
	if ((KeyCode&PAD_INPUT_9) && !(KeyCodeOld&PAD_INPUT_9))
	{
		GameSelectmanuInit();
		GameScene = SELECT;
		FontInit = 0;
		FontInit2 = 0;
	}
}
//Ecsキーの処理
void ReTitle()
{
	if ((KeyCode&PAD_INPUT_9) && !(KeyCodeOld&PAD_INPUT_9))
	{
		TitleMapPlayer();
		TitleMapPlayer2();
		Scene = Title;
	}
}


//BGM処理
void BGM1()
{
	if (MusicInit == 0)
	{
		StopSoundMem(bgm);
		ChangeVolumeSoundMem(255 * 40 / 100, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
		MusicInit = 1;
	}
}
//BGM処理
void BGM2()
{
	if (MusicInit == 1)
	{
		ChangeVolumeSoundMem(255 * 40 / 100, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
		MusicInit = 0;
	}
}
//スタートするときにReadyGoを流す
void StartString(int Num)
{
	//画像を入れる変数
	static HGRP Ready;
	static HGRP Go;
	//ReadyとGoの初期位置
	static int Ready_x = 1280;
	static int Go_x = 1280;
	static int DrawSpeed = 20;
	//１秒だけまつカウンタ
	static int TimeCount = 0;
	if (S_init == 0)
	{
		//Ready Goの初期化
		Ready_x = 1280;
		Go_x = 1280;
		DrawSpeed = 20;
		TimeCount = 0;
		Ready = LoadGraph("Resources\\Images\\string\\Ready.png");
		Go = LoadGraph("Resources\\Images\\string\\Go.png");
		//読み込んだらinitを１にする
		S_init = 1;
	}
	//initが１になったらReadyを流す
	if (S_init == 1)
	{
		//Goになるまでプレイヤーの入力を受け付けない
		Player.Move = 0;
		Player2.Move = 0;
		DrawGraph(Ready_x -= DrawSpeed, 300, Ready, TRUE);
	}
	//座標の真ん中付近にきたら画像を１秒とめる
	if (Ready_x == 520)
	{
		TimeCount++;
		DrawSpeed = 0;
	}
	if (TimeCount == 60)
	{
		//Goを表示する速度
		DrawSpeed = 20;
		//次回の為に初期化をしておく
		TimeCount = 0;
	}
	//Readyがｘ座標０未満になったらGoを流す
	if (Ready_x < -300)
	{
		DrawSpeed = 15;
		DrawGraph(Go_x -= DrawSpeed, 300, Go, TRUE);
		//Goになったのでプレイヤーの入力受付をok or No
		Player.Move = Num;
		Player2.Move = Num;
		//復活回数と経過時間を表示と計算
		StartTimer();
		DrawPlayerDownCounter();
		DrawEcsFlash();
	}
}


//スタートするときにReadyGoを流す
void StartString1(int Num)
{
	//画像を入れる変数
	static HGRP Ready;
	static HGRP Go;
	//ReadyとGoの初期位置
	static int Ready_x = 1280;
	static int Go_x = 1280;
	static int DrawSpeed = 20;
	//１秒だけまつカウンタ
	static int TimeCount = 0;
	if (S_init == 0)
	{
		//Ready Goの初期化
		Ready_x = 1280;
		Go_x = 1280;
		DrawSpeed = 20;
		TimeCount = 0;
		Ready = LoadGraph("Resources\\Images\\string\\Ready.png");
		Go = LoadGraph("Resources\\Images\\string\\Go.png");
		//読み込んだらinitを１にする
		S_init = 1;
	}
	//initが１になったらReadyを流す
	if (S_init == 1)
	{
		//Goになるまでプレイヤーの入力を受け付けない
		Player.Move = 0;
		Player2.Move = 0;
		DrawGraph(Ready_x -= DrawSpeed, 300, Ready, TRUE);
	}
	//座標の真ん中付近にきたら画像を１秒とめる
	if (Ready_x == 520)
	{
		TimeCount++;
		DrawSpeed = 0;
	}
	if (TimeCount == 60)
	{
		//Goを表示する速度
		DrawSpeed = 20;
		//次回の為に初期化をしておく
		TimeCount = 0;
	}
	//Readyがｘ座標０未満になったらGoを流す
	if (Ready_x < -300)
	{
		DrawSpeed = 15;
		DrawGraph(Go_x -= DrawSpeed, 300, Go, TRUE);
		//Goになったのでプレイヤーの入力受付をok or No
		Player.Move = Num;
		Player2.Move = Num;
		DrawEcsFlash();
	}
}

//Ecsキーの表示を点滅させておく
void DrawEcsFlash()
{
	g_mCnt++;
	if (g_mCnt % 300 >= 30)
	{
		DrawString(1050, 80, "ESCキーでセレクト画面へ", GetColor(255, 255, 255));
	}
}

//チュートリアルでの行動制御文
void TutorialControl()
{
	//表示するためのカウント
	static int DrawCount = 0;
	static int FontSpeed = 10;
	//ようこそ
	static int FontType1X = 1300;
	//重力説明
	static int FontType11X = 1300;
	static int FontType12X = 1300;
	//これから
	static int FontType2X = 1300;
	//左右の方向 スペースジャンプ
	static int FontType3X = 1300;
	//では実際に
	static int FontType4X = 1300;
	//次にジャンプをしてみましょう
	static int FontType5X = 1300;
	//ではここまで目指してください
	static int FontType6X = 1300;
	//黄色の↑
	static int FontType7X = 1300;
	//黄色の矢印説明
	static int FontType8X = 1300;

	//左右に操作するためのカウント
	static int PlayKeyCountL = 0;
	static int PlayKeyCountR = 0;
	//okを一度しかださないようにする
	static int OKFlag = 0;
	static int OKFlag1 = 0;
	static int OKFlag2 = 0;
	//左右の操作、ジャンプのうけつけ
	static int PlayKeyFlag = 0;
	//一秒間は動けるようにしておく
	static int PlayerWait = 0;
	static int PlayerWait1 = 0;
	if (FontInit == 0)
	{
		//初期化
		DrawCount = 0;
		//Fontの初期値
		FontType1X = 1300;
		FontType11X = 1300;
		FontType12X = 1300;
		FontType2X = 1300;
		FontType3X = 1300;
		FontType4X = 1300;
		FontType5X = 1300;
		FontType6X = 1300;
		FontType7X = 1300;
		FontType8X = 1300;
		//FontScrollSpeed
		FontSpeed = 10;
		//各プレイヤーを動けないようにしておく
		Player.Move = 0;
		Player2.Move = 0;
		//左右に操作するためのカウント
		PlayKeyCountL = 0;
		PlayKeyCountR = 0;
		//OKFlagを一度だけしか表示しない
		OKFlag = 0;
		OKFlag1 = 0;
		OKFlag2 = 0;
		//左右の操作だけをうけつけジャンプはうけつけない1 ジャンプもOKにする2
		PlayKeyFlag = 0;
		FontInit = 1;
		//一秒間は動けるようにしておく
		PlayerWait = 0;
		PlayerWait1 = 0;
	}

	if (FontInit == 1)
	{
		DrawCount++;
		//ようこそ
		if (DrawCount > 240)
		{
			DrawString(FontType1X -= FontSpeed, 300, "ようこそ Synchro へ", GetColor(255, 255, 255));
			if (FontType1X < 810 && FontType1X>500)
			{
				FontSpeed = 2;
			}
			if (FontType1X < 500 && FontType1X>-30)
			{
				FontSpeed = 10;
			}
		}
		//重力説明
		if (FontType1X < -30)
		{
			DrawString(FontType11X -= FontSpeed, 300, "キャラクターには重力が発生しております", GetColor(255, 255, 255));

			if (FontType11X < 780 && FontType11X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType11X < 400 && FontType11X>-50)
			{
				FontSpeed = 10;
			}
		}
		if (FontType11X < -30)
		{
			DrawString(FontType12X -= FontSpeed, 300, "キャラクターの頭上にはそれぞれの重量の方向が示されています", GetColor(255, 255, 255));

			if (FontType12X < 780 && FontType12X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType12X < 400 && FontType12X>-50)
			{
				FontSpeed = 10;
			}
		}
		//操作説明
		if (FontType12X < -30)
		{
			DrawString(FontType2X -= FontSpeed, 300, "では、操作説明をさせていただきます", GetColor(255, 255, 255));

			if (FontType2X < 780 && FontType2X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType2X < 400 && FontType2X>-50)
			{
				FontSpeed = 10;
			}
		}
		//方向キー
		if (FontType2X < -50)
		{
			DrawString(FontType3X -= FontSpeed, 300, "左右の方向キー（←）（→）で移動になってます", GetColor(255, 255, 255));
			if (FontType3X < 780 && FontType3X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType3X < 400 && FontType3X>-50)
			{
				FontSpeed = 10;
			}
		}
		//方向キー
		if (FontType3X < -50)
		{
			DrawString(FontType4X -= FontSpeed, 300, "では実際に動かしてみましょう", GetColor(255, 255, 255));
			if (FontType4X < 780 && FontType4X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType4X < 400 && FontType4X>-50)
			{
				FontSpeed = 10;
			}
		}
		//実際に操作
		if (FontType4X < -50)
		{
			PlayKeyFlag = 1;
			if (PlayKeyFlag == 1)
			{

				//各プレイヤーを動けるようにする
				Player.Move = 1;
				Player2.Move = 1;
				//矢印の表示
				if (KeyCode & PAD_INPUT_RIGHT)
				{
					DrawString(Player.pos.x + 32, Player.pos.y + 5, "→", GetColor(255, 255, 255));
					DrawString(Player2.pos.x + 32, Player2.pos.y + 5, "→", GetColor(255, 255, 255));
					PlayKeyCountR = 1;
					OKFlag = 1;
				}
				//矢印の表示
				else if (KeyCode & PAD_INPUT_LEFT)
				{
					DrawString(Player.pos.x - 32, Player.pos.y + 5, "←", GetColor(255, 255, 255));
					DrawString(Player2.pos.x - 32, Player2.pos.y + 5, "←", GetColor(255, 255, 255));
					PlayKeyCountL = 1;
					OKFlag = 1;
				}
				//左右にうごかしてください
				if (PlayKeyCountL == 0 || PlayKeyCountR == 0)
				{
					DrawString(610, 300, "左右に動かしてください", GetColor(255, 255, 255));
				}
				//CountLRが１でOKFLagが立てば OKを表示
				else if (PlayKeyCountL == 1 && PlayKeyCountR == 1 && OKFlag == 1 && OKFlag1 == 0)
				{
					DrawString(640, 300, "OK", GetColor(255, 255, 255));
					PlayerWait++;
				}
				//0.5秒たてば操作ができなくなる
				if (PlayerWait > 30)
				{
					OKFlag = 0;
					OKFlag1 = 1;
					Player.Move = 0;
					Player2.Move = 0;
					PlayKeyCountL = 1;
					PlayKeyCountR = 1;
					//ジャンプ
					DrawString(FontType5X -= FontSpeed, 300, "では次にジャンプをしてみましょう", GetColor(255, 255, 255));
					if (FontType5X < 780 && FontType5X > 400)
					{
						FontSpeed = 2;
					}
					if (FontType5X < 400 && FontType5X>-50)
					{
						FontSpeed = 10;
					}
				}
				if (FontType5X < -50)
				{
					
					//ジャンプできるようにする
					Player.Move = 1;
					Player2.Move = 1;
					if (Player.pos.x<320 || Player.pos.x<515)
					{
						DrawString(320, 450, "ここから", GetColor(255, 255, 255));
						DrawString(320, 480, "↓", GetColor(255, 255, 255));
						DrawString(320, 550, "↑", GetColor(255, 255, 255));
						DrawString(320, 570, "ここから", GetColor(255, 255, 255));

						DrawString(514, 450, "ここまで", GetColor(255, 255, 255));
						DrawString(514, 480, "↓", GetColor(255, 255, 255));
						DrawString(514, 550, "↑", GetColor(255, 255, 255));
						DrawString(514, 570, "ここまで", GetColor(255, 255, 255));
					}
					if (Player.pos.x > 514)
					{
						//ジャンプできるようにする
						Player.Move = 0;
						Player2.Move = 0;
						OKFlag2 = 1;
						
					}
					if (OKFlag2 == 1)
					{
						PlayerWait1 = 1;
					}
					
					if (PlayerWait1==1)
					{
						//ジャンプできるようにする
						Player.Move = 1;
						Player2.Move = 1;
						OKFlag2 = 2;
						DrawString(FontType6X -= FontSpeed, 300, "ではMAPの右端にある、黄色の矢印までいきましょう", GetColor(255, 255, 255));
						DrawString(1150, 450, "ここまで", GetColor(255, 255, 255));
						DrawString(1150, 480, "↓", GetColor(255, 255, 255));
						DrawString(1150, 550, "↑", GetColor(255, 255, 255));
						DrawString(1150, 570, "ここまで", GetColor(255, 255, 255));
						if (FontType6X < 780 && FontType6X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType6X < 400 && FontType6X>-50)
						{
							FontSpeed = 10;
						}
					}
					if (Player.pos.x > 1140)
					{
						PlayerWait1 = 2;
						
					}
					if (PlayerWait1 == 2)
					{
						//うごけないようにする
						Player.Move = 0;
						Player2.Move = 0;
						DrawString(FontType7X -= FontSpeed, 300, "黄色の矢印にふたつのキャラクターが触れるとMapが切り替わります", GetColor(255, 255, 255));
						if (FontType7X < 780 && FontType7X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType7X < 400 && FontType7X>-50)
						{
							FontSpeed = 10;
						}
					}
					if (FontType7X<-50)
					{
						
						DrawString(FontType8X -= FontSpeed, 300, "ではMAPの移動をしてみましょう", GetColor(255, 255, 255));
						if (FontType8X < 780 && FontType8X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType8X < 400 && FontType8X>-50)
						{
							FontSpeed = 10;
						}
						if (FontType8X < -50)
						{
							//うごけるようにする
							Player.Move = 1;
							Player2.Move = 1;
						}
					}

				}
			}
		}
	}
}
//チュートリアル制御文
void TutorialControl2()
{
	//
	static int FontType1X = 1300;
	//
	static int FontType2X = 1300;
	static int FontSpeed = 10;

	static int DrawCount = 0;
	if (FontInit2 == 0)
	{
		FontType1X = 1300;
		FontType2X = 1300;
		//FontScrollSpeed
		FontSpeed = 10;

		DrawCount = 0;
		FontInit2 = 1;
	}

	if (FontInit2 == 1)
	{
		DrawCount++;
		//ようこそ
		if (DrawCount > 30)
		{
			DrawString(FontType1X -= FontSpeed, 300, "各ステージにはゴールを出現させるためのカケラが存在しています", GetColor(255, 255, 255));
			if (FontType1X < 810 && FontType1X>500)
			{
				FontSpeed = 2;
			}
			if (FontType1X < 500 && FontType1X>-30)
			{
				FontSpeed = 10;
			}
		}
		//重力説明
		if (FontType1X < -30)
		{
			DrawString(FontType2X -= FontSpeed, 300, "これらをすべてとってみましょう", GetColor(255, 255, 255));

			if (FontType2X < 780 && FontType2X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType2X < 400 && FontType2X>-50)
			{
				FontSpeed = 10;
			}
		}
		if (FontType2X < -50)
		{
			Player.Move = 1;
			Player2.Move = 1;
			/*DrawString(1144, 380, "カケラ", GetColor(255, 255, 255));
			DrawString(1144, 400, "↓", GetColor(255, 255, 255));
			DrawString(1144, 630, "↑", GetColor(255, 255, 255));
			DrawString(1144, 650, "カケラ", GetColor(255, 255, 255));*/
		}
	}
}
