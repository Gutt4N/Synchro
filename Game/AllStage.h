//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   AllStage.h
//!
//! @brief  Map関連のヘッダファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤 祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================

// 多重インクルードの防止 ==================================================
#pragma once

//マップチップ
extern int StageMap[30][40];

// 関数の定義 ==============================================================

////Map表示////
void Stage1Load1();
void Stage1Load2();
void Stage2Load1();
void Stage3Load();
void Stage4Load();
void Stage5Load();
void Stage6Load();
void Stage7Load();
void Stage8Load();
void Stage9Load();
void Stage10Load();
void Stage11Load();

//ステージの初期化
void Stage1();
void Stage2();
void Stage3();
void Stage4();
void Stage5();
void Stage6();
void Stage7();
void Stage8();
void Stage9();
void Stage10();
void Stage11();

void InitStage1();

//当たり判定（Mapの）
void StageAtariUpdate(void);
void StageAtariUpdate2(void);
//使いまわしMap表示
void DrawStageMap();




