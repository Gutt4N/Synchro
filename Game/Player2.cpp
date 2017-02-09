//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Player.cpp
//!
//! @brief  Player�֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author GF3_01_�����ˑ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "Player2.h"
#include "define.h"
// �O���[�o���ϐ��̒�` ====================================================
HGRP zanzo2;
//�A�j���[�V����
int PuniPuniPlayer2;
// �֐��̒�` ==============================================================
//�v���C���[�̏�����
void InitializePlayer2(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag);
//�c������
void PlayerFootPrints2();
//�v�j�v�j�A�j���[�V����
void AnimesionPlayer2();
//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializePlayer2(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag)
{
	Player->pos.x = x;
	Player->pos.y = y;
	Player->grp.x = gx;
	Player->grp.y = gy;
	Player->grp.w = gw;
	Player->grp.h = gh;
	Player->spd.x = sx;
	Player->spd.y = sy;
	Player->Flag = flag;
	Player->grp.Handle = LoadGraph("Resources\\Images\\Player2.png");
	Player->grp.Handles[0] = LoadGraph("Resources\\Images\\Player2.png");
	Player->grp.Handles[1] = LoadGraph("Resources\\Images\\Player2.2.png");
	Player->grp.Handles[2] = LoadGraph("Resources\\Images\\Player2.png");
}
//�c������
void InitZanzo2()
{
	int i;
	static int g_init = 0;
	if (g_init == 0)
	{
		zanzo2 = LoadGraph("Resources\\Images\\Player2Ki.png");
		g_init = 1;
	}
	//�c���ʒu
	for (i = 0; i < ZANZO; i++)
	{
		PlayerXX[i] = Player2.pos.x;
		PlayerYY[i] = Player2.pos.y;
	}
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FFirstMapPlayer2             //
//				�T�v  �F�v���C���[�\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void FirstMapPlayer2()
{
	//�v���C���[������
	InitializePlayer2(&Player2, 64, 600, 0, 0, 32, 32, 0, 0, 1);
	//�c��������
	InitZanzo2();
}

void TitleMapPlayer2()
{
	//�v���C���[������
	InitializePlayer2(&Player2, 640, 600, 0, 0, 32, 32, 0, 0, 1);
	//�c��������
	InitZanzo2();
}

void RePlayer2()
{
	//�v���C���[������
	InitializePlayer2(&Player2, 800, 560, 0, 0, 32, 32, 0, 0, 1);
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawPlayer                 //
//				�T�v  �F�v���C���[�\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawPlayer2()
{
	if (KeyCode & PAD_INPUT_RIGHT)
	{
		PlayerFootPrints2();
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_LEFT)
	{
		PlayerFootPrints2();
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_10)
	{
		DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (Player2.jump.JumpFlag == 1)
	{
		PlayerFootPrints2();
	}
	if (KeyCode == 0)
	{
		AnimesionPlayer2();
	}
	
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FMovePlayer                 //
//				�T�v  �F�v���C���[�ړ�			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void MovePlayer2()
{
	//Flag���P�łȂ��ƕ\������Ȃ�
	if (Player2.Flag == 1)
	{
		//Move���P�łȂ��Ƒ�����󂯕t���Ȃ�
		if (Player2.Move == 1)
		{
			//�E�ړ� ���x5.0f
			if (Key[KEY_INPUT_RIGHT] == 1)
			{
				Player2.pos.x = Player2.pos.x + (Player2.spd.x + MOVESPEED);
				PlayerXX[0] = Player2.pos.x;
			}
			//���ړ� ���x5.0f
			else if (Key[KEY_INPUT_LEFT] == 1)
			{
				Player2.pos.x = Player2.pos.x + (Player2.spd.x - MOVESPEED);
				PlayerXX[0] = Player2.pos.x;

			}
		}
	}
	
	int i;
	// �c���f�[�^����Â��炷
	for (i = ZANZO - 1; i > 0; i--)
	{
		PlayerXX[i] = PlayerXX[i - 1];
		PlayerYY[i] = PlayerYY[i - 1];
	}
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FJumpPlayer                 //
//				�T�v  �F�v���C���[��Jump		   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void JumpPlayer2()
{
	static HSND JumpMu2;
	static int init = 0;
	if (init == 0)
	{
		JumpMu2 = LoadSoundMem("Resources\\Sounds\\jump.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, JumpMu2);
		init = 1;
	}
	
	if (Key[KEY_INPUT_SPACE] == 1 && Player2.jump.JumpFlag == 0&&Player2.Move==1)
	{
		PlaySoundMem(JumpMu2, DX_PLAYTYPE_BACK);
		Player2.spd.y = -JUMPPOWER;
		//��񂾂�t���O�𗧂Ă�
		Player2.jump.JumpFlag = 1;
	}
	//�������x����
	if (Player2.spd.y < 9)
	{
		Player2.spd.y++;
	}
	Player2.pos.y -= Player2.spd.y;
	PlayerYY[0] = Player2.pos.y;
}

//�c��
void PlayerFootPrints2()
{
	int i;
	Player2.Kiseki = 1;
	//�c������
	if (Player2.Kiseki == 1)
	{
		for (i = 0; i < ZANZO; i++)
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200 - 255 * i / ZANZO);
			DrawGraph(PlayerXX[i] + 7, PlayerYY[i] + 8, zanzo2, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

//�v�j�v�j�A�j���[�V��������
void AnimesionPlayer2()
{
	static int AnimesionCount = 0;
	AnimesionCount++;
	if (AnimesionCount >= 10 && PuniPuniPlayer2 != 2)
	{
		PuniPuniPlayer2++;
		AnimesionCount = 0;
	}
	if (AnimesionCount >= 10 && PuniPuniPlayer2 == 2)
	{
		PuniPuniPlayer2 = 0;
		AnimesionCount = 0;
	}
	DrawRectGraph(Player2.pos.x, Player2.pos.y, Player2.grp.x, Player2.grp.y, Player2.grp.w, Player2.grp.h, Player2.grp.Handles[PuniPuniPlayer2], TRUE, FALSE);

}