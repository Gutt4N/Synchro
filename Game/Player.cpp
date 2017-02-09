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
#include "Player.h"
#include "define.h"
// �O���[�o���ϐ��̒�` ====================================================

//�c���̉摜�������ϐ�
HGRP zanzo;
//�A�j���[�V����
int PuniPuniPlayer;

//����
// �}�b�v�����ɋ�؂��� �S�[���܂ł������玟�̃}�b�v��
// �A�C�e���Ȃǂ������ς������Ă݂���A�M�~�b�N�Ȃǂ������ς�����B

// �֐��̒�` ==============================================================
//�v���C���[�̏�����
void InitializePlayer(Object *Player, int x, int y, int gx, int gy, int gw, int gh, int sx, int sy, int flag);
//�c������
void PlayerFootPrints();
//�v�j�v�j�A�j���[�V����
void AnimesionPlayer();

//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializePlayer(Object *Player,int x,int y,int gx,int gy,int gw,int gh,int sx,int sy,int flag)
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
	Player->grp.Handle = LoadGraph("Resources\\Images\\Player1.png");
	Player->grp.Handles[0] = LoadGraph("Resources\\Images\\Player1.png");
	Player->grp.Handles[1] = LoadGraph("Resources\\Images\\Player1.1.png");
	Player->grp.Handles[2] = LoadGraph("Resources\\Images\\Player1.png");
}
//�c������
void InitZanzo1()
{
	int i;
	static int g_init = 0;
	if (g_init == 0)
	{
		zanzo = LoadGraph("Resources\\Images\\Player1Ki.png");
		g_init = 1;
	}
	//�c���\���ʒu
	for (i = 0; i < ZANZO; i++)
	{
		PlayerX[i] = Player.pos.x;
		PlayerY[i] = Player.pos.y;
	}
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FFirstMapPlayer             //
//				�T�v  �F�v���C���[�\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void FirstMapPlayer()
{
	//������
	InitializePlayer(&Player, 64, 416, 0, 0, 32, 32, 0, 0, 1);
	//�c�������Ă�����
	InitZanzo1();
}

//�^�C�g�� �v���C���[�ʒu�̏�����
void TitleMapPlayer()
{
	//������
	InitializePlayer(&Player, 640, 78, 0, 0, 32,32, 0, 0, 1);
	//�c�������Ă�����
	InitZanzo1();
}

void RePlayer1()
{
	//������
	InitializePlayer(&Player, 800, 600, 0, 0, 32, 32, 0, 0, 1);
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawPlayer                 //
//				�T�v  �F�v���C���[�\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawPlayer()
{
	if (KeyCode & PAD_INPUT_RIGHT)
	{
		PlayerFootPrints();
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_LEFT)
	{
		PlayerFootPrints();
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (KeyCode & PAD_INPUT_10)
	{
		DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handle, TRUE, FALSE);
		//AnimesionPlayer();
	}
	if (Player.jump.JumpFlag == 1)
	{
		PlayerFootPrints();
	}
	if (KeyCode == 0)
	{
		AnimesionPlayer();
	}
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FMovePlayer                 //
//				�T�v  �F�v���C���[�ړ�			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void MovePlayer()
{
	//Flag��1�łȂ��ƃv���C���[�͕\������Ȃ�
	if (Player.Flag == 1)
	{
		//Move��1�łȂ��Ƒ�����󂯕t���Ȃ�
		if (Player.Move == 1)
		{
			//�E�ړ� ���x5.0f(�����ړ��j
			if (KeyCode & PAD_INPUT_RIGHT)
			{
				Player.pos.x += (Player.spd.x + MOVESPEED);
				PlayerX[0] = Player.pos.x;
			}
			//���ړ� ���x5.0f�i�����ړ��j
			else if (KeyCode & PAD_INPUT_LEFT)
			{
				Player.pos.x += (Player.spd.x - MOVESPEED);
				PlayerX[0] = Player.pos.x;
			}
		}
	}
	int i;
	// �c���f�[�^����Â��炷
	for (i = ZANZO - 1; i > 0; i--)
	{
		PlayerX[i] = PlayerX[i - 1];
		PlayerY[i] = PlayerY[i - 1];
	}
	
}
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FJumpPlayer                 //
//				�T�v  �F�v���C���[��Jump		   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void JumpPlayer()
{
	static HSND JumpMu;
	static int init = 0;
	if (init == 0)
	{
		JumpMu = LoadSoundMem("Resources\\Sounds\\jump.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, JumpMu);
		init = 1;
	}
	if ((KeyCode & PAD_INPUT_10) && Player.jump.JumpFlag == 0&&Player.Move==1)
	{
		//�W�����v�T�E���h
		PlaySoundMem(JumpMu, DX_PLAYTYPE_BACK);
		Player.spd.y = -JUMPPOWER;
		//��񂾂�t���O�𗧂Ă�
		Player.jump.JumpFlag = 1;
	}
	//�������x����
	if (Player.spd.y < 9)
	{
		Player.spd.y++;
	}
	//�d�͂�������
	Player.pos.y += Player.spd.y;
	PlayerY[0] = Player.pos.y;
}


//�c��
void PlayerFootPrints()
{
	int i;
	Player.Kiseki = 1;
	//�c������
	if (Player.Kiseki == 1)
	{
		for (i = 0; i < ZANZO; i++)
		{
			SetDrawBlendMode(DX_BLENDMODE_ADD, 200 - 255 * i / ZANZO);
			DrawGraph(PlayerX[i]+7, PlayerY[i]+8, zanzo, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}
//�v�j�v�j����
void AnimesionPlayer()
{
	static int AnimesionCount = 0;
	AnimesionCount++;
	if (AnimesionCount >= 10 && PuniPuniPlayer != 2)
	{
		PuniPuniPlayer++;
		AnimesionCount = 0;
	}
	if (AnimesionCount >= 10 && PuniPuniPlayer == 2)
	{
		PuniPuniPlayer = 0;
		AnimesionCount = 0;
	}
	DrawRectGraph(Player.pos.x, Player.pos.y, Player.grp.x, Player.grp.y, Player.grp.w, Player.grp.h, Player.grp.Handles[PuniPuniPlayer], TRUE, FALSE);

}