//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   define.h
//!
//! @brief  define�֘A�̃w�b�_�t�@�C��
//!
//! @date   
//!
//! @author GF3_01_���� �ˑ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				        define	                   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//�ړ����x
#define MOVESPEED (5)
//�}�b�v�̃T�C�Y
#define MAP_W (GAME_W/BLOCK_W)
#define MAP_H (GAME_H/BLOCK_H)
//�}�b�v�ɕ\������u���b�N�̃T�C�Y
#define BLOCK_W (32)
#define BLOCK_H (32)
#define BLOCK_CHIP (32)
//��ʃT�C�Y
#define GAME_W (1280)
#define GAME_H (960)
//�W�����v
//3�}�X���W�����v
#define JUMPPOWER (17)
//�c������
#define ZANZO (27)
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				        extern	                   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//

//�O���[�o���ϐ�
#ifndef EXTERN
#define EXTERN extern
#endif

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				      �\���̐錾                   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
typedef struct
{
	//���W
	int x;
	int y;
	//�O�̍��W�ۑ��p
	int before_x;
	int before_y;
}Pos;

typedef struct
{
	//�O���t�B�b�N x,y,w,h
	int x;
	int y;
	int w;
	int h;
	//�摜������ϐ�
	HGRP Handle;
	//�摜������z��ϐ�
	HGRP Handles[3];
}Grp;

typedef struct
{
	//�X�s�[�h�c���A����
	int x;
	int y;
}Spd;

typedef struct
{
	//�W�����v�t���O�A�W�����v�������ĂȂ��𔻒f
	int JumpFlag;
}Jump;

typedef struct
{
	//�\���̂��\���̂ɂ܂Ƃ߂�
	Pos pos;
	Grp grp;
	Spd spd;
	Jump jump;
	//�����Ă��邩�ǂ����𔻒f����ϐ�
	int Move;
	//�v���C���[�𑶍݂��Ă��邩�ǂ����𔻒f
	int Flag;
	//�c������
	int Kiseki;
	//�����񐔂̃J�E���g
	int Down;
}Object;

/////�O���[�o���ō\���̂��`/////
//�v���C���[�̍\����
EXTERN Object Player;
EXTERN Object Player2;
//�S�[���`�b�v�̍\����
EXTERN Object Goal1;
EXTERN Object Goal2;
EXTERN Object Goal3;
EXTERN Object Goal4;
EXTERN Object Goal;
//
EXTERN Object CheckPoint;

//GetHitKeyStateAll�֐��Ɏg���ϐ�
EXTERN char Key[256];
//Map�؂�ւ�
EXTERN int MapChange;

//�c�������Ɏg���O���[�o���ϐ�
EXTERN int PlayerX[ZANZO];
EXTERN int PlayerY[ZANZO];
EXTERN int PlayerXX[ZANZO];
EXTERN int PlayerYY[ZANZO];
//�����܂ŁB


//�V�[���̐؂�ւ�
EXTERN int Scene;
//�Q�[���V�[���̒��̐؂�ւ�
EXTERN int GameScene;
//����p�ϐ�
EXTERN int KeyCode;
EXTERN int KeyCodeOld;

//���Ԃ��i�[����ϐ�
EXTERN float Time;
EXTERN int SSSTime;
EXTERN int SSTime;
EXTERN int STime;
EXTERN int DTime;
EXTERN int TTime;
EXTERN int FTime;
//�����܂�
//�i�[�������Ԃ����U���g�ŕ\������ϐ�///
EXTERN int DrawSTime;
EXTERN int DrawDTime;
EXTERN int DrawTTime;
EXTERN int DrawFTime;
/////////////////////////////////////////
EXTERN int count;
//Sound������������ϐ�
EXTERN int muinit;
EXTERN int g_mCnt;
//�}�b�v�̐؂�ւ������邽�߂̕ϐ�
EXTERN int MapFlagNumber;
//�X�^�[�g�\�����邽�߂̕ϐ�
EXTERN int S_init;
//�`���[�g���A���ł̕�����\������ϐ�
EXTERN int FontInit;
EXTERN int FontInit2;
//�Q�[���V�[���ɂ���enum
enum Game
{
	Title,
	Game,
	Exit
};
//�}�b�v�؂�ւ���enum
enum Map
{
	SELECT,
	TUTORIAL,
	STAGE1,
	STAGE2,
	STAGE3,
	STAGE4,
	STAGE5,
	STAGE6,
	STAGE7,
	STAGE8,
	STAGE9,
	STAGE10,
	STAGE11,
	STAGE12,
	STAGE13,
	STAGE14,
	STAGE15,
	RESULT
};