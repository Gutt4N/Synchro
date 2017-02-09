//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Object.h
//!
//! @brief  ItemやGoalの関連のhファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/


// 多重インクルードの防止 ==================================================
#pragma once

void DrawGoalParts();
void DrawGoalPartsTurorial();
void DrawGoalPartsTurorial1();
//Stage4ゲート表示//
void DrawStage4Parts();
void DrawStage4Parts1();
//Stage5ゲート表示//
void DrawStage5Parts1();
void DrawStage5Parts2();
void DrawStage5Parts3();
//ゴールパーツの当たり判定/////
//Stage T 1 2 3の当たり判定//
void StageTUTORIAL();	
void Stage1HITParts();	
//Stage4の当たり判定二つの関数を用意
//Mapに一つだけのオブジェクト
void Stage4HitParts1();
//Mapに二つのオブジェクトとゴール
void Stage4HitParts2();

//Stage5のパーツ当たり判定
void Stage5HitParts1();
void Stage5HitParts2();
//Stage9のパーツ当たり判定
void Stage9HitParts1();
void Stage9HitParts2();
//////////////////////////////

void InitFirstMapPoint();
//パーツ４つとゴール１の初期化処理
void InitGoalPartsFirst();
void InitGoalPartsSecond();
void InitGoalPartsThird();
void InitGoalPartsFourth();
void InitGoal();

//チュートリアルのゲート
void InitGoalTutorialFirst();
void InitGoalTutorialSecond();
void InitGoalTutorial();

//1thゲート
//2thゲート
//ゴール
void InitGoalStage1First();
void InitGoalStage1Second();
void InitGoalStage1();

//1thゲート
//2thゲート
//3thゲート
//ゴール
void InitGoalStage2First();
void InitGoalStage2Second();
void InitGoalStage2Third();
void InitGoalStage2();

//下里ゲート
void InitGoalPartsFirst1();
void InitGoalPartsSecond1();
void InitGoalPartsThird1();
void InitGoalPartsFourth1();
void InitGoal1();