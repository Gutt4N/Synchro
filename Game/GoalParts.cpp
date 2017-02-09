//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Goal.cpp
//!
//! @brief  ItemやGoalの関連のソースファイル
//!
//! @date   日付
//!
//! @author GF3_01_安藤祥大
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/_
// ヘッダファイルの読み込み ================================================
#include "Object.h"
#include "define.h"
#include "GameMain.h"

void InitObject(Object *obj, int posx, int posy, int grpw, int grph, int grpx, int grpy);

//ゴールのアニメーション
int AnimesionGoal = 0;

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：InitObject                 //
//				概要  ：初期化するための関数       //
//				引数  ：省略					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void InitObject(Object *obj, int posx, int posy, int grpx, int grpy, int grpw, int grph)
{
	//座標変更
	obj->pos.x = posx;
	obj->pos.y = posy;
	//グラフィック画像切抜き
	obj->grp.x = grpx;
	obj->grp.y = grpy;
	//座標サイズ
	obj->grp.w = grpw;
	obj->grp.h = grph;
}

///////////////////////////////////////////////////////////////////

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				チュートリアルイニシャライズ	   //
//				概要  ：画像初期化                 //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//

void InitGoalTutorialFirst()
{
	//一度だけ読み込み
	static int init = 0;
	Goal1.Flag = 1;
	//初期化
	InitObject(&Goal1, 1097, 430, 0, 0, 64, 32);
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//二個目
void InitGoalTutorialSecond()
{
	//一度だけ読み込み
	static int init = 0;
	Goal2.Flag = 1;
	//初期化
	InitObject(&Goal2, 1097, 600, 0, 32, 64, 32);
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalTutorial()
{
	//一度だけ読み込み
	static int init = 0;
	Goal.Flag = 0;
	//初期化
	InitObject(&Goal, 800, 500, 0, 0, 64, 64);
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

//////////////////////パーツ２個とゴール１個///////////////
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//					Stageイニシャライズ		       //
//				概要  ：画像初期化                 //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//

void InitGoalStage1First()
{
	//一度だけ読み込み
	static int init = 0;
	Goal1.Flag = 1;
	//初期化	
	switch (MapFlagNumber)
	{
	case 1:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 480, 576, 0, 0, 64, 32);
			break;
		}
		break;
	case 2:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 545, 500, 0, 0, 64, 32);
			break;
		}
		break;
	case 3:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 612, 576, 0, 0, 64, 32);
			break;
		}
		break;
	case 7:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 920, 380, 0, 32, 64, 32);
			break;
		}
		break;
	}
	
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//二個目
void InitGoalStage1Second()
{
	//一度だけ読み込み
	static int init = 0;
	Goal2.Flag = 1;
	//初期化
	switch (MapFlagNumber)
	{
	case 1:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 480, 448, 0, 32, 64, 32);
			break;
		}
		break;
	case 2:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 780, 640, 0, 32, 64, 32);
			break;
		}
		break;
	case 3:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 353, 380, 0, 32, 64, 32);
			break;
		}
		break;
	case 7:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 560, 320, 0, 32, 64, 32);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalStage1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal.Flag = 0;
	//初期化
	switch (MapFlagNumber)
	{
	case 1:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal, 1010, 500, 0, 0, 64, 64);
			break;
		}
		break;
	case 2:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal, 1150, 520, 0, 0, 64, 64);
			break;
		}
		break;
	case 3:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal, 1150, 490, 0, 0, 64, 64);
			break;
		}
		break;
	case 7:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal, 1170, 520, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

///////////////////////////////////////////////////////////////////////



//////////////////////パーツ3個とゴール１個///////////////
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//					Stageイニシャライズ		       //
//				概要  ：画像初期化                 //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//

void InitGoalStage2First()
{
	//一度だけ読み込み
	static int init = 0;
	Goal1.Flag = 1;
	//初期化	
	switch (MapFlagNumber)
	{
	case 4:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 384, 480, 32, 32, 32, 32);
			break;
		}
		break;
	case 9:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 630, 420, 32, 32, 32, 32);
			break;
		}
		break;
	case 10:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 213, 700, 32, 32, 32, 32);
			break;
		}
		break;
	}

	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//二個目
void InitGoalStage2Second()
{
	//一度だけ読み込み
	static int init = 0;
	Goal2.Flag = 1;
	//初期化
	switch (MapFlagNumber)
	{
	case 4:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 600, 544, 0, 32, 64, 32);
			break;
		}
		break;
	case 9:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 557, 350, 0, 32, 64, 32);
			break;
		}
		break;
	case 10:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 213,310, 32, 0, 32, 32);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

//３個目
void InitGoalStage2Third()
{
	//一度だけ読み込み
	static int init = 0;
	Goal3.Flag = 1;
	//初期化	
	switch (MapFlagNumber)
	{
	case 4:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 1175, 480, 32, 0, 32, 32);
			break;
		}
		break;
	case 9:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 560, 680, 32, 0, 32, 32);
			break;
		}
		break;
	case 10:
		//マップファイいるをオープンする
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3,885, 535, 0, 32, 64, 32);
			break;
		}
		break;
	}

	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal3.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalStage2()
{
	//一度だけ読み込み
	static int init = 0;
	Goal.Flag = 0;
	//初期化
	switch (MapFlagNumber)
	{
	case 4:
		switch (MapChange)
		{
		case 0:
			//Goal初期化
			InitObject(&Goal, 235, 500, 0, 0, 64, 64);
			break;
		}
		break;
	case 9:
		switch (MapChange)
		{
		case 0:
			//Goal初期化
			InitObject(&Goal, 1150, 850, 0, 0, 64, 64);
			break;
		}
		break;
	case 10:
		switch (MapChange)
		{
		case 0:
			//Goal初期化
			InitObject(&Goal, 350, 500, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////Render/////////////////////////////


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawObject                 //
//				概要  ：Objectを簡単表示	       //
//				引数  ：Object					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawObject(Object *obj)
{
	DrawRectGraph(obj->pos.x, obj->pos.y, obj->grp.x, obj->grp.y, obj->grp.w, obj->grp.h, obj->grp.Handle, TRUE, FALSE);
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawObjectAnime            //
//				概要  ：Objectを簡単表示	       //
//				引数  ：Object					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawObjectAnime(Object *obj)
{
	DrawRectGraph(obj->pos.x, obj->pos.y, obj->grp.x, obj->grp.y, obj->grp.w, obj->grp.h, obj->grp.Handles[AnimesionGoal], TRUE, FALSE);
}


//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：DrawGoalParts              //
//				概要  ：Goalを表示			       //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void DrawGoalParts()
{
	//ゴールのアニメーション
	static int GoalCount = 0;

	//ゴールパーツの表示
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal4.Flag == 1)
	{
		DrawObject(&Goal4);
	}
	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 && Goal4.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 || Goal4.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

void DrawGoalPartsTurorial()
{
	//ゴールのアニメーション
	static int GoalCount = 0;

	//ゴールパーツの表示
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}


void DrawGoalPartsTurorial1()
{
	//ゴールのアニメーション
	static int GoalCount = 0;

	//ゴールパーツの表示
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
		DrawString(1100, 380, "カケラ", GetColor(255, 255, 255));
		DrawString(1120, 400, "↓", GetColor(255, 255, 255));
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
		DrawString(1120, 630, "↑", GetColor(255, 255, 255));
		DrawString(1100, 650, "カケラ", GetColor(255, 255, 255));
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0)
	{
		Goal.Flag = 1;
		DrawString(500, 300, "ゴールが出現しました。ゴールに触れればクリア！", GetColor(255, 255, 255));
		DrawString(710, 520, "ゴール→", GetColor(255, 255, 255));
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

//Stage4

void DrawStage4Parts1()
{
	//ゴールパーツの表示
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}
}
void DrawStage4Parts()
{
	static int GoalCount = 0;

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

//Stage5の当たり判定
void DrawStage5Parts1()
{
	//ゴールパーツの表示
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}
	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}
}
void DrawStage5Parts2()
{
	//ゴールのアニメーション
	static int GoalCount = 0;
	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal4.Flag == 1)
	{
		DrawObject(&Goal4);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 && Goal4.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 || Goal4.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

void DrawStage5Parts3()
{
	//ゴールのアニメーション
	static int GoalCount = 0;
	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 )
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 )
	{
		Goal.Flag = 0;
	}
	//ゴールのアニメーション処理
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}




//下里MAP
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：InitGoalPartsFirst  ...etc //
//				概要  ：画像初期化                 //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void InitGoalPartsFirst1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal1.Flag = 1;
	//初期化
	//InitObject(&Goal1, 416, 480, 32, 32, 32, 32);
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 240, 320, 32, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 240, 440, 32, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 850, 215, 32, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal1, 1145, 550, 32, 32, 32, 32);
			break;
		}
		break;

	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//二個目
void InitGoalPartsSecond1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal2.Flag = 1;
	//初期化
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 240, 705, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 570, 480, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 850, 800, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal2, 1140, 220, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//三個目
void InitGoalPartsThird1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal3.Flag = 1;
	//初期化
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 1184, 480, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 1170, 550, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 190, 675, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal3, 506, 800, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal3.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//四個目
void InitGoalPartsFourth1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal4.Flag = 1;
	//初期化
	//InitObject(&Goal4, 1120, 544, 0, 0, 32, 32);
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal4, 1184, 545, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal4, 465, 160, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal4, 810, 735, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goalパーツの初期化
			InitObject(&Goal4, 1043, 736, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal4.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}
}
//ゴール本体
void InitGoal1()
{
	//一度だけ読み込み
	static int init = 0;
	Goal.Flag = 0;
	//初期化
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goalの初期化
			InitObject(&Goal, 936, 710, 0, 0, 64, 64);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goalの初期化
			InitObject(&Goal, 1000, 840, 0, 0, 64, 64);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goalの初期化
			InitObject(&Goal, 550, 721, 0, 0, 64, 64);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goalの初期化
			InitObject(&Goal, 300, 500, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//画像読み込み
	if (init == 0)
	{
		//ゴール画像
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}