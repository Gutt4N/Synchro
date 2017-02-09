//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Object.cpp
//!
//! @brief  Item��Goal�̊֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author GF3_01_�����ˑ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/_
// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Object.h"
#include "define.h"
#include "GameMain.h"
// �O���[�o���ϐ��̒�` ====================================================
int g_se = 0;

//�֐��̒�` ====================================================

//�S�[����p�[�c�̓����蔻��֐�
int CollisionObj(float x1, float y1, float r1, float x2, float y2, float r2);
//�S�[����p�[�c�̕\��
void DrawObject(Object *obj);
//�p�[�c�̓����蔻��
void CollisionGoalParts(Object *obj1, Object *obj2);
//�S�[���̓����蔻��
void CollisionGoal(Object *obj1, Object *obj2);


//�S�[���p�[�c�̓����蔻��
//Player�ƃp�[�c�ԍ�
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

	float x1, y1, r1, x2, y2, r2; //���S���W�Ɣ��a

	//�������̒��S���W
	x1 = obj1->pos.x + obj1->grp.w / 2;
	x2 = obj2->pos.x + obj2->grp.w / 2;
	//�������̒��S���W
	y1 = obj1->pos.y + obj1->grp.h / 2;
	y2 = obj2->pos.y + obj2->grp.h / 2;
	//���a
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

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����F CollisionGoalParts        //
//				�T�v  �FGoal�̏���			       //
//				����  �F�ȗ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void CollisionGoal(Object *obj1,Object *obj2)
{
	float x1, y1, r1, x2, y2, r2; //���S���W�Ɣ��a

	//�������̒��S���W
	x1 = obj1->pos.x + obj1->grp.w / 2;
	x2 = obj2->pos.x + obj2->grp.w / 2;
	//�������̒��S���W
	y1 = obj1->pos.y + obj1->grp.h / 2;
	y2 = obj2->pos.y + obj2->grp.h / 2;
	//���a
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
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FGoalUp		               //
//				�T�v  �FGoal�̏���			       //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void StageTUTORIAL()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player,  &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player, &Goal4);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player2, &Goal2);
	CollisionGoalParts(&Player2, &Goal3);
	CollisionGoalParts(&Player2, &Goal4);

	//�v���C���[�ƃS�[���̓����蔻��
	CollisionGoal(&Player,&Goal);
	CollisionGoal(&Player2,&Goal);
}

//�PMAP�ɓ�̃Q�[�g�ƈ�̃Q�[�g
void Stage1HITParts()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player2, &Goal2);
	//�v���C���[�ƃS�[���̓����蔻��
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}


void Stage4HitParts1()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
}
void Stage4HitParts2()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	//�v���C���[�ƃS�[���̓����蔻��
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}

//Stage5
//�p�[�c�P�ƃp�[�c�Q�̓����蔻��
void Stage5HitParts1()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
}
void Stage5HitParts2()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	CollisionGoalParts(&Player, &Goal4);
	CollisionGoalParts(&Player2, &Goal4);
	//�v���C���[�ƃS�[���̓����蔻��
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}
//Stage5
//�p�[�c�P�ƃp�[�c�Q�̓����蔻��
void Stage9HitParts1()
{
	//�v���C���[�ƃp�[�c�̓����蔻��
	CollisionGoalParts(&Player, &Goal1);
	CollisionGoalParts(&Player2, &Goal1);
	CollisionGoalParts(&Player, &Goal2);
	CollisionGoalParts(&Player2, &Goal2);
}
void Stage9HitParts2()
{
	//�p�[�c�R�̓����蔻��
	CollisionGoalParts(&Player, &Goal3);
	CollisionGoalParts(&Player2, &Goal3);
	//�S�[���̓����蔻��
	CollisionGoal(&Player, &Goal);
	CollisionGoal(&Player2, &Goal);
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FCollisionObj               //
//				�T�v  �F�A�C�e���̓����蔻��i�~�j //
//				����  �F�ȗ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
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