//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Object.cpp
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
// グローバル変数の定義 ====================================================
int g_se = 0;

//関数の定義 ====================================================

//ゴールやパーツの当たり判定関数
int CollisionObj(float x1, float y1, float r1, float x2, float y2, float r2);
//ゴールやパーツの表示
void DrawObject(Object *obj);
//パーツの当たり判定
void CollisionGoalParts(Object *obj1, Object *obj2);
//ゴールの当たり判定
void CollisionGoal(Object *obj1, Object *obj2);


//ゴールパーツの当たり判定
//Playerとパーツ番号
void CollisionGoalParts(Object *obj1, Object *obj2)
{
	static HSND Hit;
	static int init = 0;
	if (init == 0)
	{
		Hit = LoadSoundMem("Resources\\Sounds\\hit.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, Hit);
		init = 1;
	}

	float x1, y1, r1, x2, y2, r2; //中心座標と半径

	//ｘ方向の中心座標
	x1 = obj1->pos.x + obj1->grp.w / 2;
	x2 = obj2->pos.x + obj2->grp.w / 2;
	//ｙ方向の中心座標
	y1 = obj1->pos.y + obj1->grp.h / 2;
	y2 = obj2->pos.y + obj2->grp.h / 2;
	//半径
	r1 = obj1->grp.w / 2;
	r2 = obj2->grp.w / 2;

	if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r2 + r1) * (r2 + r1))
	{
		if (obj2->Flag == 1)
		{
			g_se = 0;
		}
		if (g_se == 0)
		{
			PlaySoundMem(Hit, DX_PLAYTYPE_BACK);
			obj2->Flag = 0;
			g_se=1;
		}
	}
}

//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名： CollisionGoalParts        //
//				概要  ：Goalの処理			       //
//				引数  ：省略					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void CollisionGoal(Object *obj1,Object *obj2)
{
	float x1, y1, r1, x2, y2, r2; //中心座標と半径

	//ｘ方向の中心座標
	x1 = obj1->pos.x + obj1->grp.w / 2;
	x2 = obj2->pos.x + obj2->grp.w / 2;
	//ｙ方向の中心座標
	y1 = obj1->pos.y + obj1->grp.h / 2;
	y2 = obj2->pos.y + obj2->grp.h / 2;
	//半径
	r1 = obj1->grp.w / 2;
	r2 = obj2->grp.w / 2;

	if (obj2->Flag == 1)
	{
		if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r2 + r1) * (r2 + r1))
		{
			GameSelectmanuInit();
			GameScene=RESULT;
		}
	}
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：GoalUp		               //
//				概要  ：Goalの処理			       //
//				引数  ：なし					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
void StageTUTORIAL()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player,  &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player, &Goal4);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player2, &Goal2);
	CollisionGoalParts(&Player2, &Goal3);
	CollisionGoalParts(&Player2, &Goal4);

	//プレイヤーとゴールの当たり判定
	CollisionGoal(&Player,&Goal);
	CollisionGoal(&Player2,&Goal);
}

//１MAPに二つのゲートと一つのゲート
void Stage1HITParts()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player2, &Goal2);
	//プレイヤーとゴールの当たり判定
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}


void Stage4HitParts1()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
}
void Stage4HitParts2()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	//プレイヤーとゴールの当たり判定
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}

//Stage5
//パーツ１とパーツ２の当たり判定
void Stage5HitParts1()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
}
void Stage5HitParts2()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	CollisionGoalParts(&Player, &Goal4);
	CollisionGoalParts(&Player2, &Goal4);
	//プレイヤーとゴールの当たり判定
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}
//Stage5
//パーツ１とパーツ２の当たり判定
void Stage9HitParts1()
{
	//プレイヤーとパーツの当たり判定
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
}
void Stage9HitParts2()
{
	//パーツ３の当たり判定
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	//ゴールの当たり判定
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
//				関数名：CollisionObj               //
//				概要  ：アイテムの当たり判定（円） //
//				引数  ：省略					   //
//				戻り値：なし         			   //
//*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*:;;;:*†*//
int CollisionObj(float x1, float y1, float r1, float x2, float y2, float r2)
{

	if ((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= (r2 + r1)*(r2 + r1))
	{
		return 1;
		
	}
	else
	{
		return 0;
	}
}