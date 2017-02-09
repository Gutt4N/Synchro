//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   AllStage.cpp
//!
//! @brief  Map�֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author GF3_01_���� �ˑ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "AllStage.h"
#include "define.h"
#include "Player.h"
#include "Player2.h"
#include "Object.h"
#include <math.h>

#define PI 3.1415926f

//�}�b�v�\��for���i�g���܂킵�p�j
void DrawStageMap();
//�}�b�v�ړ�����
void Stage1Scroll1(int x1, int y1, int x2, int y2, Object *Play);
void Stage1Scroll2(int x1, int y1, int x2, int y2, Object *Play);
//�Е������̃}�b�v�Ɉړ����Ă����݂����}�b�v�ړ����Ȃ��ƈӖ����Ȃ��̂ł�����\�ɂ���֐�
void Stage1PlayerNext(Object *Play, Object *Play2);
void Stage1PlayerPrevious(Object *Play, Object *Play2);

//_/_/_/_/_/_/_/_/_/_/_/_/_/_/�v���C���[���}�b�v�ړ��������̃C�j�V�����C�Y_/_/_/_/_/_/_/_/_/_/_/_/_//
void MapChangePlayerNextPos(Object *Player, int Any);
void MapChangePlayerPreviousPos(Object *Player, int Any);
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/�v���C���[���}�b�v���痎�����Ƃ��̏���_/_/_/_/_/_/_/_/_/_/_/_/_//
void Stage1ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Player, Object *Player2, int x, int y, int xx, int yy, int num);

// �O���[�o�� ================================================
////�}�b�v�`�b�v
int StageMap[MAP_H][MAP_W];


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FAtariUpdate                //
//				�T�v  �F�}�b�v�����蔻��           //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void StageAtariUpdate()
{
	int x1, y1, x2, y2;
	//�v���C���[�ړ�
	MovePlayer();

	//�����蔻�菉����
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//������ 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67))
	{
		Player.pos.x = x2*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//�E���� 
	if ((StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player.pos.x = x1*BLOCK_CHIP;
		Player.spd.x = 0;
	}
	//�}�b�v�X�N���[������
	Stage1Scroll1(x1, y1, x2, y2, &Player);
	Stage1Scroll2(x1, y1, x2, y2, &Player);

	//�W�����v����
	JumpPlayer();

	//�����蔻�菉����
	x1 = Player.pos.x / BLOCK_CHIP;
	y1 = Player.pos.y / BLOCK_CHIP;
	x2 = (Player.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//�㔻�� 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67))
	{
		Player.pos.y = y2*BLOCK_CHIP;
		Player.spd.y = 0;
	}
	//������ 
	if ((StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player.pos.y = y1*BLOCK_CHIP;
		Player.spd.y = 0;
		Player.jump.JumpFlag = 0;
	}
	//�}�b�v���痎�����Ƃ����X�|�[������
	Stage1ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
}


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FAtariUpdate                //
//				�T�v  �F�}�b�v�����蔻��           //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void StageAtariUpdate2()
{

	int x1, y1, x2, y2;

	//�v���C���[�ړ�
	MovePlayer2();
	//�����蔻�菉����
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;


	//������ 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67))
	{
		Player2.pos.x = x2*BLOCK_CHIP;
		Player2.spd.x = 0;
	}
	//�E���� 
	if ((StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player2.pos.x = x1*BLOCK_CHIP;
		Player2.spd.x = 0;
	}

	//�}�b�v�X�N���[������
	Stage1Scroll1(x1, y1, x2, y2, &Player2);
	Stage1Scroll2(x1, y1, x2, y2, &Player2);
	//�W�����v����
	JumpPlayer2();

	//�����蔻�菉����
	x1 = Player2.pos.x / BLOCK_CHIP;
	y1 = Player2.pos.y / BLOCK_CHIP;
	x2 = (Player2.pos.x + BLOCK_CHIP - 1) / BLOCK_CHIP;
	y2 = (Player2.pos.y + BLOCK_CHIP - 1) / BLOCK_CHIP;

	//�㔻�� 
	if ((StageMap[y1][x1] == 66 || StageMap[y1][x1] == 67) || (StageMap[y1][x2] == 66 || StageMap[y1][x2] == 67))
	{
		Player2.pos.y = y2*BLOCK_CHIP;
		Player2.spd.y = 0;
		Player2.jump.JumpFlag = 0;
	}
	//������ 
	if ((StageMap[y2][x1] == 66 || StageMap[y2][x1] == 67) || (StageMap[y2][x2] == 66 || StageMap[y2][x2] == 67))
	{
		Player2.pos.y = y1*BLOCK_CHIP;
		Player2.spd.y = 0;
	}

	//�}�b�v���痎�����Ƃ����X�|�[������
	Stage1ResPawnPlayer(x1, y1, x2, y2, &Player, &Player2, 64, 416, 64, 600, 1);
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1Scroll1              //
//				�T�v  �F�}�b�v�`�b�v�ړ�	       //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1Scroll1(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;

	�ړ������Ƃ��̍��W��
	���̃}�b�v�Ɉړ����Ă��
	X��32Y�͑O�̃}�b�v�̍��W�̈ʒu
	*/

	//�E���� 
	if (StageMap[y1][x2] == 3 || StageMap[y2][x2] == 3)
	{
		Play->Flag = 0;
		Stage1PlayerNext(&Player, &Player2);
	}
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1Scroll2              //
//				�T�v  �F�}�b�v�`�b�v�ړ�	       //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1Scroll2(int x1, int y1, int x2, int y2, Object *Play)
{
	/*
	Player->pos.before_y = Player->pos.y;
	�ړ������Ƃ��̍��W��
	�O�̃}�b�v�ɖ߂��
	X��1216Y�͑O�̃}�b�v�̍��W�̈ʒu
	*/

	//������ 
	if (StageMap[y1][x1] == 2 || StageMap[y2][x1] == 2)
	{
		Play->Flag = 0;
		Stage1PlayerPrevious(&Player, &Player2);
	}
}


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1ChangePlayerNextPos  //
//				�T�v  �F�v���C���[���}�b�v���ړ�   //
//					�������̍��W				   //
//				����  �FObject  *Player			   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1ChangePlayerNextPos(Object *Player, int Any)
{
	Player->pos.before_y = Player->pos.y;
	Player->pos.x = Any;
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1ChangePlayerPreviousPos //
//				�T�v  �F�v���C���[���}�b�v���ړ�   //
//					�������̍��W				   //
//				����  �FObject  *Player			   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1ChangePlayerPreviousPos(Object *Player, int Any)
{
	Player->pos.before_y = Player->pos.y;
	Player->pos.x = Any;
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FWaitPlayerNext   		   //
//				�T�v  �F�v���C���[���}�b�v���ړ�   //
//				����  �FObject  *Player			   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1PlayerNext(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		//�}�b�v���`�F���W�����炘�̍��W���R�Q�ɂ��Ă�����
		MapChangePlayerNextPos(&Player, 32);
		MapChangePlayerNextPos(&Player2, 32);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			//�}�b�v���`�F���W
			MapChange++;
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
		}
	}
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1PlayerPrevious	   //
//				�T�v  �F�v���C���[���}�b�v���ړ�   //
//				����  �FObject  *Player			   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1PlayerPrevious(Object *Play, Object *Play2)
{
	if (Play->Flag == 0 && Play2->Flag == 0)
	{
		//�}�b�v���`�F���W�����炘�̍��W��1216�ɂ��Ă�����
		MapChangePlayerPreviousPos(&Player, 1216);
		MapChangePlayerPreviousPos(&Player2, 1216);
		Play->Flag = 1;
		Play2->Flag = 1;
		if (Play->Flag == 1 && Play2->Flag == 1)
		{
			PlayerX[0] = Play->pos.x;
			PlayerXX[0] = Play2->pos.x;
			//�}�b�v���`�F���W
			MapChange--;
		}
	}
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FStage1ResPawnPlayer  	   //
//				�T�v  �F��������				   //
//				����  �F�ȗ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage1ResPawnPlayer(int x1, int y1, int x2, int y2, Object *Playe, Object *Playe2, int x, int y, int xx, int yy, int num)
{
	//�㔻�� 
	if (StageMap[y1][x1] == num || StageMap[y1][x2] == num)
	{
		//�������񐔂������Ő����Ă���
		Playe->Down++;
		Playe2->Down++;
		//potision�������Ŏw��
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		//�c���̓v���C���[�̎w�肵���|�W�V�����Ɉړ�
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//��������S�[���̃p�[�c������
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0 ||
			Playe->Flag == 0 && Playe2->Flag == 1)
		{
			Playe->Flag = 1;
			Playe2->Flag = 1;
			Playe->pos.x = x;
			Playe->pos.y = y;
			Playe2->pos.x = xx;
			Playe2->pos.y = yy;
			PlayerX[0] = Player.pos.x;
			PlayerXX[0] = Player2.pos.x;
		}
	}
	//������ 
	if (StageMap[y2][x1] == num || StageMap[y2][x2] == num)
	{
		//�������񐔂������Ő����Ă���
		Playe->Down++;
		Playe2->Down++;
		//potision�������Ŏw��
		Playe->pos.x = x;
		Playe->pos.y = y;
		Playe2->pos.x = xx;
		Playe2->pos.y = yy;
		//�c���̓v���C���[�̎w�肵���|�W�V�����Ɉړ�
		PlayerX[0] = Player.pos.x;
		PlayerXX[0] = Player2.pos.x;
		//��������S�[���̃p�[�c������
		Goal1.Flag = 1;
		Goal2.Flag = 1;
		Goal3.Flag = 1;
		Goal4.Flag = 1;
		if (Playe->Flag == 1 && Playe2->Flag == 0 ||
			Playe->Flag == 0 && Playe2->Flag == 1)
		{
			Playe->Flag = 1;
			Playe2->Flag = 1;
			Playe->pos.x = x;
			Playe->pos.y = y;
			Playe2->pos.x = xx;
			Playe2->pos.y = yy;
			PlayerX[0] = Player.pos.x;
			PlayerXX[0] = Player2.pos.x;
		}
	}
}



//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawMap                    //
//				�T�v  �F�}�b�v�\���g���܂킵       //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawStageMap()
{
	//��x�����ǂݍ���
	static int init = 0;
	static int Count = 0;
	static HGRP map[2];
	static HGRP next;
	static HGRP back;
	if (init == 0)
	{
		//�}�b�v�摜
		map[0] = LoadGraph("Resources\\Images\\Map\\groundY.png");
		map[1] = LoadGraph("Resources\\Images\\Map\\groundT.png");
		next = LoadGraph("Resources\\Images\\Map\\next.png");
		back = LoadGraph("Resources\\Images\\Map\\back.png");
		//�ǂݍ��񂾂̂ŗp�ς�
		init = 1;
	}
	//for���Ŏg�p
	int i, j;
	//�\��
	for (i = 0; i < MAP_H; i++)
	{
		for (j = 0; j < MAP_W; j++)
		{
			switch (StageMap[i][j])
			{
				//cos�Ł��O���t�B�b�N�𓮂���
			case 2:
				DrawGraph((j * BLOCK_CHIP) - cos(PI * 2 / 120 * Count) * 5, i * BLOCK_CHIP, back, TRUE);
				break;
				//cos�Ł��O���t�B�b�N�𓮂���
			case 3:
				DrawGraph((j * BLOCK_CHIP) + cos(PI * 2 / 120 * Count) * 5, i * BLOCK_CHIP, next, TRUE);
				break;
			case 66:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[0], TRUE);
				break;
			case 67:
				DrawGraph(j * BLOCK_CHIP, i * BLOCK_CHIP, map[1], TRUE);
				break;
			}
		}
	}
	Count++;
}