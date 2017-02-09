//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Map.h
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


// 関数の定義 ==============================================================

//Mapの表示
void MapLoad1(void);
void MapLoad2(void);
void MapLoad3(void);
void TitleLoad(void);
void SelectMap(void);


//ステージ チュートリアル、Stage1の初期化
void Tutorial();
void Stage1();


void ResultLoad();

//タイトル当たり判定
void TitleAtari();
void TitleAtari2();
void ResultAtari();
void ResultAtari2();

//当たり判定（Mapの）
void AtariUpdate(void);
void AtariUpdate2(void);

void Counter(int x, int y, int n);