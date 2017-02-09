//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Stage9.cpp
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


void Stage9();
// �O���[�o�� ================================================

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FMapFirstInit               //
//				�T�v  �F�}�b�v�f�[�^�ǂݍ���       //
//				����  �F�ȗ�					   //
//				�߂�l�F�ȗ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage9Init(void)
{
	FILE *fp = NULL;
	char buf[512];
	char *tok;
	char *next_token = NULL;
	int i, j;
	switch (MapFlagNumber)
	{
	case 9:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			fopen_s(&fp, "Map\\MapNinth\\Map.csv", "r");
			break;
		case 1:
			fopen_s(&fp, "Map\\MapNinth\\Map2.csv", "r");
			break;
		}
		break;
	}
	//�}�b�v�̓ǂݍ���
	for (i = 0; i < MAP_H; i++)
	{
		fgets(buf, sizeof(buf), fp);
		for (j = 0; j < MAP_W; j++)
		{

			if (j == 0)
			{
				tok = strtok_s(buf, ",", &next_token);
			}
			else
			{
				tok = strtok_s(NULL, ",", &next_token);

			}
			StageMap[i][j] = atoi(tok);
		}
	}
	fclose(fp);
}


///////////////////////////////////////Stage9�̏�����
void Stage9()
{
	if (Scene == Game &&  MapFlagNumber == 9)
	{
		S_init = 0;
		//���Ԃ̏�����
		Time = 0;
		STime = 0;
		DTime = 0;
		TTime = 0;
		FTime = 0;
		//�\���̏�����
		DrawSTime = 0;
		DrawDTime = 0;
		DrawTTime = 0;
		DrawFTime = 0;
		Player.Down = 0;
		//�J�E���^�[�n�̏�����
		MapChange = 0;
		count = 0;
		muinit = 0;
		g_mCnt = 0;
		//�v���C���[�̏�����
		FirstMapPlayer();
		FirstMapPlayer2();
		//�S�[���A�p�[�c�̏�����
		InitGoalStage2First();
		InitGoalStage2Second();
		InitGoalStage2Third();
		InitGoalStage2();
		InitZanzo1();
		//�f�o�b�O
		GameScene = STAGE9;
	}
}


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FMapLoad1		           //
//				�T�v  �F�}�b�v�f�[�^�ǂݍ���       //
//				����  �F�ȗ�					   //
//				�߂�l�F�ȗ�        		       //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void Stage9Load()
{
	//map�ǂݍ���
	Stage9Init();
	//�}�b�v�\��
	DrawStageMap();
}

