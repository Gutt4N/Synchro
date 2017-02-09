//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#define EXTERN
// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"
#include "define.h"
#include "Player.h"
#include "AllStage.h"
#include "Map.h"
#include "Player2.h"
#include "Object.h"
// �񋓑̂̒�` ====================================================

// �O���[�o���ϐ��̒�` ====================================================

//�^�C�g���Ŏg���������ϐ�
int TitleInit = 0;
//���j���[��ʂ̉摜
HGRP menu;
//�^�C�g���e�L�X�g�̉摜
HGRP nexttitle;
//BGM������ϐ�
HSND bgm;
//BGM���V�[���؂�ւ����Ƃɗ����Ȃ���
int MusicInit;
// �֐��̒�` ==============================================================
//Enter�L�[����
void UpEcs();
//ESC�L�[����
void ReEcs();
//ESC�L�[����
void ReTitle();
//BGM����
void BGM1();
void BGM2();
//�X�^�[�g����
void StartString(int Num);
void StartString1(int Num);
//�����񐔕\�����邽�߂̊֐�
void DrawPlayerDownCounter();
//�o�ߎ��ԕ\��
void StartTimer();
//���U���g�Ōo�ߎ��Ԃ�\��
void DrawTimer();
//�L�����N�^�[��\������֐�
void DrawPlayers(Object *Player, Object *Player2);
//Title�V�[��
void TitlE();
//Title�V�[���̏�����
void titleinit();

//���U���g��ʂ̏���
void Result();

//Ecs�L�[�Ń^�C�g���ւ�_��
void DrawEcsFlash();
//�`���[�g���A���ł̐���
void TutorialControl();
void TutorialControl2();


//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Initialize(void)
{
	//�Q�[���V�[���̏�����
	Scene = Title;
	switch (Scene)
	{
	//Title�V�[���Ȃ�
	case Title:
		//TitleInit���O�Ȃ�
		if (TitleInit == 0)
		{
			//Title�̏�����
			titleinit();
			//�v���C���[�P�C�Q�̈ʒu��������
			TitleMapPlayer();
			TitleMapPlayer2();
		}
		break;
	case Game:
		switch (GameScene)
		{
		case SELECT:
			break;
		case TUTORIAL:
			break;
		case STAGE1:
			break;
		case STAGE2:
			break;
		case STAGE3:
			break;
		case STAGE4:
			break;
		case STAGE5:
			break;
		case STAGE6:
			break;
		case STAGE7:
			break;
		case STAGE8:
			break;
		case STAGE9:
			break;
		case STAGE10:
			break;
		case STAGE11:
			break;
		case RESULT:
			break;
		}
		break;
	case Exit:
		break;
	}

}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Update(void)
{
	//�L�[���͎擾
	GetHitKeyStateAll(Key);
	// �L�[���͎擾
	KeyCode = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	switch (Scene)
	{
	//Title�V�[���Ȃ�
	case Title:
		//Title�ōs������
		TitlE();
		//BGM���Ȃ炷����
		BGM1();
		//�v���C���[�P�C�Q�̃}�b�v�����蔻��
		TitleAtari();
		TitleAtari2();
		break;
		//case�Q�[����
	case Game:
		//���Q�[���V�[����
		switch (GameScene)
		{
			//�}�b�v�Z���N�g��ʂ�������
		case SELECT:
			//BGM��炷����
			BGM2();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				AtariUpdate();
				AtariUpdate2();
				//�X�e�[�W�ɓ������Ƃ��̏���
				Tutorial();
				//�X�e�[�W12345�̏���
				Stage1();
				Stage2();
				Stage3();
				Stage4();
				Stage5();
				//Title�ɂ��ǂ����Ƃ��̏���
				ReTitle();
			}
			else if(MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				AtariUpdate();
				AtariUpdate2();
				//�X�e�[�W6789 10 11�̏���
				Stage6();
				Stage7();
				Stage8();
				Stage9();
				Stage10();
				Stage11();
				//�^�C�g���ɖ߂����Ƃ��̏���
				ReTitle();
			}
			break;
			
		case TUTORIAL:  //�`���[�g���A���V�[���Ȃ�
			//BGM���Ȃ炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				AtariUpdate();
				AtariUpdate2();
			}
			else
			{
				//�}�b�v�̓����蔻��
				AtariUpdate();
				AtariUpdate2();
				//�`���[�g���A���ł̃S�[���A�p�[�c�̓����蔻��
				StageTUTORIAL();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE1:	//�X�e�[�W�P�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//�X�e�[�W�P�ł̃S�[���A�p�[�c�̏���
				Stage1HITParts();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE2:	//Stage2�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage2�̃S�[���A�p�[�c�̏���
				Stage1HITParts();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE3:
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage3�ł̃S�[���A�p�[�c�̏���
				Stage1HITParts();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE4:
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage4�ł̃S�[���A�p�[�c�̏���
				Stage4HitParts1();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//�Q�[�g�̓����蔻��
				Stage4HitParts2();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE5:	//Stage5�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage5�ł̃S�[���A�p�[�c�̏���
				Stage5HitParts1();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage5�ł̃S�[���A�p�[�c�̏���
				Stage5HitParts2();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE6:		//Stage6�Ȃ�
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage6�̃S�[���A�p�[�c�̏���
				StageTUTORIAL();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE7:		//Stage7�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage7�̃S�[���A�p�[�c�̓����蔻��
				Stage1HITParts();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE8:	//Stage8�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage8�̃S�[���A�p�[�c�̏���
				Stage5HitParts1();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage8�̃S�[���A�p�[�c�̏���
				Stage5HitParts2();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE9:		//Stage9�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage9�̃S�[���A�p�[�c�̏���
				Stage9HitParts1();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage9�̃S�[���A�p�[�c�̏���
				Stage9HitParts2();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE10:		//Stage10�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage10�̃S�[���A�p�[�c�̏����Q��
				Stage9HitParts1();
				Stage9HitParts2();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case STAGE11:		//Stage11�Ȃ�
			//BGM��炷����
			BGM1();
			if (MapChange == 0)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage11�̃S�[���A�p�[�c�̏���
				Stage5HitParts2();
			}
			else if (MapChange == 1)
			{
				//�}�b�v�̓����蔻��
				StageAtariUpdate();
				StageAtariUpdate2();
				//Stage11�̃S�[���A�p�[�c�̏���
				Stage5HitParts1();
			}
			//�Q�[������Ecs�L�[���������Ƃ��̏���
			ReEcs();
			break;
		case RESULT:	//���U���g�Ȃ�
			//BGM��炷����
			BGM2();
			/*���U���g���ʂ�\�����邽�߂�
			�J�E���^�[�𓮂���*/
			count++;
			//�}�b�v�̓����蔻��
			ResultAtari();
			ResultAtari2();
			//���U���g����
			Result();
			//Enter�L�[���������Ƃ��̏���
			UpEcs();
			break;
		}
		break;
	case Exit:
		break;
	}

	KeyCodeOld = KeyCode;			//���͏��ۑ�

}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Render(void)
{
	switch (Scene)
	{
	case Title:	//Title�V�[���Ȃ�
		//�v���C���[�P�C�Q�̕`��
		DrawPlayers(&Player, &Player2);
		TitleLoad();
		break;
	case Game:
			switch (GameScene)
			{
			case SELECT:
				
				if (MapChange == 0)
				{
					DrawString(20, 250, "�`���[�g���A��", GetColor(255, 255, 255));
					DrawString(20, 680, "�`���[�g���A��", GetColor(255, 255, 255));
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//Select�}�b�v�̓ǂݍ���
					SelectMap();
				}
				else if (MapChange==1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//Select�}�b�v�̓ǂݍ���
					SelectMap();
				}
				break;
			case TUTORIAL:
				//Ready Go��\���A���玞�Ԍv�Z
				StartString1(0);
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�`���[�g���A���̃}�b�v�ǂݍ���
					MapLoad1();
					//�`���[�g���A���̏���
					TutorialControl();
					
				}
				else if(MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�`���[�g���A���̃}�b�v�ǂݍ���
					MapLoad2();
					//�S�[���A�p�[�c�̕\��
				    DrawGoalPartsTurorial1();
					//����
					TutorialControl2();
				}
				
				break;
			case STAGE1:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�̓ǂݍ���
					Stage1Load1();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�̓ǂݍ���
					Stage1Load1();
					//�S�[���A�p�[�c�̕\��
					DrawGoalPartsTurorial();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE2:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�̓ǂݍ���
					Stage2Load1();
					//����
					//DrawGoalParts();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�̓ǂݍ���
					Stage2Load1();
					//�S�[���A�p�[�c�̕\��
					DrawGoalPartsTurorial();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE3:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage3Load();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage3Load();
					////�p�[�c�\��////
					DrawGoalPartsTurorial();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE4:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage4Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage4Parts1();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�\��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage4Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage4Parts();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE5:	
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage5Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v���[�h
					Stage5Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts2();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE6:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage6Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
					DrawStage5Parts2();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE7:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage7Load();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage7Load();
					//�S�[���A�p�[�c�̕\��
					DrawGoalPartsTurorial();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE8:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage8Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage8Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts2();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE9:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage9Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage9Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts3();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE10:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage10Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts3();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case STAGE11:
				if (MapChange == 0)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage11Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts2();
				}
				else if (MapChange == 1)
				{
					//�v���C���[�P�C�Q�̕`��
					DrawPlayers(&Player, &Player2);
					//�}�b�v�ǂݍ���
					Stage11Load();
					//�S�[���A�p�[�c�̕\��
					DrawStage5Parts1();
				}
				//Ready Go��\���A���玞�Ԍv�Z
				StartString(1);
				break;
			case RESULT:
				//�v���C���[�P�C�Q�̕`��
				DrawPlayers(&Player, &Player2);
				//�}�b�v�̕\��
				ResultLoad();
				//���ԁA�����N�A���̕\��
				Result();
				break;
			}
			break;
	case Exit:
		break;
	}


}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Finalize(void)
{

}



//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawPlayer                 //
//				�T�v  �F�v���C���[�\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawPlayers(Object *Player,Object *Player2)
{
	//�t���O���P��������\�����邺�[�I
	if (Player->Flag == 1)
	{
		//�v���C���[1�\��
		DrawPlayer();
	}
	//�t���O���P��������\�����邺�[�I
	if (Player2->Flag == 1)
	{
		//�v���C���[2�\��
		DrawPlayer2();
	}

}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FTitlE	                   //
//				�T�v  �F�^�C�g���\��			   //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void TitlE()
{
	static int nextcount=0;
	//�r�������� end �\��
	//DrawRectGraph(550, 700, 0, 0, 512, 512, menu, TRUE, FALSE);
	//var1.00�\��
	DrawString(1150, 50, "Ver 1.00", GetColor(255, 255, 255));
	DrawString(50, 900, "�^�C�g���ł��L�����N�^�[��������I", GetColor(255, 255, 255));
	DrawString(1190, 650, "Start", GetColor(255, 255, 255));
	DrawString(1190, 580, "Start", GetColor(255, 255, 255));
	DrawString(50, 270, "End", GetColor(255, 255, 255));
	DrawString(50, 330, "End", GetColor(255, 255, 255));
	static HSND EnterMu;
	static HSND sentaku;
	static int init = 0;
	if (init == 0)
	{
		//�T�E���h�G�t�F�N�g�̏�����
		EnterMu = LoadSoundMem("Resources\\Sounds\\kettei.mp3");
		sentaku = LoadSoundMem("Resources\\Sounds\\cursor2.mp3");
		ChangeVolumeSoundMem(255 * 50 / 100, EnterMu);
		ChangeVolumeSoundMem(255 * 50 / 100, sentaku);
		init = 1;

	}
	//�L�[�{�[�h���͏�Ԃ��擾
	GetHitKeyStateAll(Key);
	/*
	//��L�[�̏���
	if (Key[KEY_INPUT_UP] == 1)
	{
		//������ցB
		nextcount = 0;
		PlaySoundMem(sentaku, DX_PLAYTYPE_BACK);
	}
	//���L�[�̏���
	if (Key[KEY_INPUT_DOWN] == 1)
	{
		//��������
		nextcount = 1;
		PlaySoundMem(sentaku, DX_PLAYTYPE_BACK);
	}

	if (nextcount == 0)
	{
		//���̕\��
		DrawGraph(500, 750, nexttitle, TRUE);
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			PlaySoundMem(EnterMu, DX_PLAYTYPE_BACK);
			//�P�ɂ���
			TitleInit = 1;
			//�Z���N�g��ʂ̏�����
			GameSelectmanuInit();
			////�}�b�vChange���O�ɂ��Ă���
			MapChange = 0;
			//�V�[�����Q�[���ɐ؂�ւ���
			Scene = Game;
			
		}
	}
	else
	{
		//���̕\��
		DrawGraph(500, 815, nexttitle, TRUE);
		//����End�ɂ���ΐ���I��
		if (Key[KEY_INPUT_RETURN] == 1)
		{
			DxLib_End();
		}
	}
	*/
	if (Key[KEY_INPUT_R] == 1)
	{
		Player.pos.x = 640;
		Player.pos.y = 78;
		Player2.pos.x = 640;
		Player2.pos.y = 600;
	}
	
}

void titleinit()
{
	//�v���C���[�𓮂���悤�ɂ��Ă���
	Player.Move = 1;
	Player2.Move = 1;
	//�摜��������
	menu = LoadGraph("Resources\\Images\\Titlemenu.png");
	nexttitle = LoadGraph("Resources\\Images\\Map\\next.png");
	//���y��������
	bgm = LoadSoundMem("Resources\\Sounds\\bgm_maoudamashii_cyber01.mp3");
}

void GameSelectmanuInit()
{
	//�v���C���[�𓮂���悤�ɂ��Ă���
	Player.Move = 1;
	Player2.Move = 1;
	//�}�b�v�`�F���W��0�ɂ��Ă���
	MapChange = 0;
	//�}�b�v�`�F���W�J�E���^�[��߂�
	MapFlagNumber = 0;
	//�v���C���[�̏�����
	FirstMapPlayer();
	FirstMapPlayer2();
}

//�����񐔂��J�E���g����֐�
void DrawPlayerDownCounter()
{
	static int init = 0;
	if (init == 0)
	{
		Player.Down = 0;
		init = 1;
	}
	static HGRP Down = LoadGraph("Resources\\Images\\Item\\Number.png");
	//�����񐔁� ��`��
	DrawRectGraph(780, 30, 0, 40, 200, 50, Down, TRUE, FALSE);
	//������`��
	Counter(960, 55, Player.Down);
	
}
//�o�ߎ��Ԃ�`�悷��J�E���g
void StartTimer()
{
	static HGRP Down = LoadGraph("Resources\\Images\\Item\\Number.png");
	//�o�ߎ��� ��`��
	DrawRectGraph(250, 50, 0, 95, 400, 50, Down, TRUE, FALSE);
	DrawString(420, 55, " :", GetColor(255, 255, 255));
	//���Ԃ𐔂���J�E���^�[�𓮂���
	Time++;
	//60�t���[���ɂȂ�����
	if(Time>=60)
	{
		Time = 0;
		//00:01�b�ǉ�����
		STime++;
		//�X�V���Ƃɕ\���ϐ��ɑ��
		DrawSTime = STime;
	}
	//9�b�ɂȂ�����
	if (STime>9)
	{
		//00:10�b�ɂ���
		DTime++;
		//00:00�ɂ��ǂ�
		STime = 0;
		//�X�V���Ƃɕ\���ϐ��ɑ��
		DrawDTime = DTime;
		
	}
	//59�b�ȏ�ɂȂ�����
	if (DTime > 5)
	{
		//01:00�ɂ���
		TTime++;
		//59�b��00�b�ɖ߂�
		DTime = 0;
		//�X�V���Ƃɕ\���ϐ��ɑ��
		DrawTTime = TTime;

	}
	//09��59�b�ɂȂ�����
	if (TTime > 9)
	{
		//10���ɂ���
		FTime++;
		//10���ɂ���0��00�b�ɂ��ǂ�
		TTime = 0;
		//�X�V���Ƃɕ\���ϐ��ɑ��
		DrawFTime = FTime;
	}

	//�v�Z�������Ԃ�\��
	Counter(460, 55, STime);
	Counter(440, 55, DTime);
	Counter(410, 55, TTime);
	Counter(390, 55, FTime);
}
//���U���g��ʂ̏���
void Result()
{
	static HGRP Result;
	static HGRP Down; 
	static HSND ResultMus;
	
	DrawString(1150, 50, "Select���", GetColor(255, 255, 255));
	DrawString(1150, 900, "Select���", GetColor(255, 255, 255));

	/*DrawRectGraph(200, 50, 0, 95, 400, 50, Down, TRUE, FALSE);*/
	//DrawString(370, 55, " :", GetColor(255, 255, 255));
	static int init = 0;
	
	static int Draw = 0;
	if (init == 0)
	{
		//�v���C���[�P�Q�̏�����
		RePlayer1();
		RePlayer2();
		Result = LoadGraph("Resources\\Images\\Item\\Score.png");
		Down = LoadGraph("Resources\\Images\\Item\\Number.png");
		ResultMus = LoadSoundMem("Resources\\Sounds\\drum-japanese1.mp3");
		ChangeVolumeSoundMem(255 * 40 / 100, ResultMus);
		init = 1;
	}
	//CLEAR��\��
	DrawRectGraph(400, 40, 0, 0, 500, 110, Result, TRUE, FALSE);
	if (count > 60)
	{
		if (muinit == 0)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 1;
		}
		//�o�ߎ��Ԃ̕`��
		DrawRectGraph(500, 250, 0, 95, 400, 50, Down, TRUE, FALSE);
		DrawString(670, 250, " :", GetColor(255, 255, 255));
		Counter(710, 250, DrawSTime);
		Counter(690, 250, DrawDTime);
		Counter(660, 250, DrawTTime);
		Counter(640, 250, DrawFTime);
		//�����܂�
		
	}
	if (count > 120)
	{
		if (muinit == 1)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 2;
		}
		//�����񐔂�`��
		Counter(670, 400, Player.Down);
		DrawRectGraph(500, 380, 0, 40, 200, 50, Down, TRUE, FALSE);
		//�����܂�
	}
	//�����NSABC�𔻒f����������f��
	if (count > 180)
	{
	
		DrawRectGraph(400, 520, 0, 130, 500, 110, Result, TRUE, FALSE);
		if (TTime  <=0 &&DTime<=5&&STime<=9)
		{
			DrawRectGraph(900, 510, 0, 370, 110, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 2 && DTime <= 3)
		{
			DrawRectGraph(900, 510, 120, 370, 150, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 3 && DTime <= 3)
		{
			DrawRectGraph(900, 510, 280, 370, 100, 110, Result, TRUE, FALSE);
		}
		else if (TTime <= 6 && DTime <= 6)
		{
			DrawRectGraph(900, 510, 400, 370, 80, 110, Result, TRUE, FALSE);
		}
		if (muinit == 2)
		{
			PlaySoundMem(ResultMus, DX_PLAYTYPE_BACK);
			muinit = 3;
		}
	}

	/*
	//Enter Key�������Ă��炤�悤�ɍÑ�����
	if (count > 210)
	{
		g_mCnt++;
		if (g_mCnt % 60 >= 30)
		{
			DrawString(600, 700, "Push Enter Key", GetColor(255, 255, 255));
		}
	}
	
	UpEcs();
	*/
}

//Enter�L�[�̏���
void UpEcs()
{
	if (Key[KEY_INPUT_RETURN] == 1)
	{
		GameSelectmanuInit();
		GameScene = SELECT;
	}
}
//Ecs�L�[�̏���
void ReEcs()
{
	if ((KeyCode&PAD_INPUT_9) && !(KeyCodeOld&PAD_INPUT_9))
	{
		GameSelectmanuInit();
		GameScene = SELECT;
		FontInit = 0;
		FontInit2 = 0;
	}
}
//Ecs�L�[�̏���
void ReTitle()
{
	if ((KeyCode&PAD_INPUT_9) && !(KeyCodeOld&PAD_INPUT_9))
	{
		TitleMapPlayer();
		TitleMapPlayer2();
		Scene = Title;
	}
}


//BGM����
void BGM1()
{
	if (MusicInit == 0)
	{
		StopSoundMem(bgm);
		ChangeVolumeSoundMem(255 * 40 / 100, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
		MusicInit = 1;
	}
}
//BGM����
void BGM2()
{
	if (MusicInit == 1)
	{
		ChangeVolumeSoundMem(255 * 40 / 100, bgm);
		PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
		MusicInit = 0;
	}
}
//�X�^�[�g����Ƃ���ReadyGo�𗬂�
void StartString(int Num)
{
	//�摜������ϐ�
	static HGRP Ready;
	static HGRP Go;
	//Ready��Go�̏����ʒu
	static int Ready_x = 1280;
	static int Go_x = 1280;
	static int DrawSpeed = 20;
	//�P�b�����܂J�E���^
	static int TimeCount = 0;
	if (S_init == 0)
	{
		//Ready Go�̏�����
		Ready_x = 1280;
		Go_x = 1280;
		DrawSpeed = 20;
		TimeCount = 0;
		Ready = LoadGraph("Resources\\Images\\string\\Ready.png");
		Go = LoadGraph("Resources\\Images\\string\\Go.png");
		//�ǂݍ��񂾂�init���P�ɂ���
		S_init = 1;
	}
	//init���P�ɂȂ�����Ready�𗬂�
	if (S_init == 1)
	{
		//Go�ɂȂ�܂Ńv���C���[�̓��͂��󂯕t���Ȃ�
		Player.Move = 0;
		Player2.Move = 0;
		DrawGraph(Ready_x -= DrawSpeed, 300, Ready, TRUE);
	}
	//���W�̐^�񒆕t�߂ɂ�����摜���P�b�Ƃ߂�
	if (Ready_x == 520)
	{
		TimeCount++;
		DrawSpeed = 0;
	}
	if (TimeCount == 60)
	{
		//Go��\�����鑬�x
		DrawSpeed = 20;
		//����ׂ̈ɏ����������Ă���
		TimeCount = 0;
	}
	//Ready�������W�O�����ɂȂ�����Go�𗬂�
	if (Ready_x < -300)
	{
		DrawSpeed = 15;
		DrawGraph(Go_x -= DrawSpeed, 300, Go, TRUE);
		//Go�ɂȂ����̂Ńv���C���[�̓��͎�t��ok or No
		Player.Move = Num;
		Player2.Move = Num;
		//�����񐔂ƌo�ߎ��Ԃ�\���ƌv�Z
		StartTimer();
		DrawPlayerDownCounter();
		DrawEcsFlash();
	}
}


//�X�^�[�g����Ƃ���ReadyGo�𗬂�
void StartString1(int Num)
{
	//�摜������ϐ�
	static HGRP Ready;
	static HGRP Go;
	//Ready��Go�̏����ʒu
	static int Ready_x = 1280;
	static int Go_x = 1280;
	static int DrawSpeed = 20;
	//�P�b�����܂J�E���^
	static int TimeCount = 0;
	if (S_init == 0)
	{
		//Ready Go�̏�����
		Ready_x = 1280;
		Go_x = 1280;
		DrawSpeed = 20;
		TimeCount = 0;
		Ready = LoadGraph("Resources\\Images\\string\\Ready.png");
		Go = LoadGraph("Resources\\Images\\string\\Go.png");
		//�ǂݍ��񂾂�init���P�ɂ���
		S_init = 1;
	}
	//init���P�ɂȂ�����Ready�𗬂�
	if (S_init == 1)
	{
		//Go�ɂȂ�܂Ńv���C���[�̓��͂��󂯕t���Ȃ�
		Player.Move = 0;
		Player2.Move = 0;
		DrawGraph(Ready_x -= DrawSpeed, 300, Ready, TRUE);
	}
	//���W�̐^�񒆕t�߂ɂ�����摜���P�b�Ƃ߂�
	if (Ready_x == 520)
	{
		TimeCount++;
		DrawSpeed = 0;
	}
	if (TimeCount == 60)
	{
		//Go��\�����鑬�x
		DrawSpeed = 20;
		//����ׂ̈ɏ����������Ă���
		TimeCount = 0;
	}
	//Ready�������W�O�����ɂȂ�����Go�𗬂�
	if (Ready_x < -300)
	{
		DrawSpeed = 15;
		DrawGraph(Go_x -= DrawSpeed, 300, Go, TRUE);
		//Go�ɂȂ����̂Ńv���C���[�̓��͎�t��ok or No
		Player.Move = Num;
		Player2.Move = Num;
		DrawEcsFlash();
	}
}

//Ecs�L�[�̕\����_�ł����Ă���
void DrawEcsFlash()
{
	g_mCnt++;
	if (g_mCnt % 300 >= 30)
	{
		DrawString(1050, 80, "ESC�L�[�ŃZ���N�g��ʂ�", GetColor(255, 255, 255));
	}
}

//�`���[�g���A���ł̍s�����䕶
void TutorialControl()
{
	//�\�����邽�߂̃J�E���g
	static int DrawCount = 0;
	static int FontSpeed = 10;
	//�悤����
	static int FontType1X = 1300;
	//�d�͐���
	static int FontType11X = 1300;
	static int FontType12X = 1300;
	//���ꂩ��
	static int FontType2X = 1300;
	//���E�̕��� �X�y�[�X�W�����v
	static int FontType3X = 1300;
	//�ł͎��ۂ�
	static int FontType4X = 1300;
	//���ɃW�����v�����Ă݂܂��傤
	static int FontType5X = 1300;
	//�ł͂����܂Ŗڎw���Ă�������
	static int FontType6X = 1300;
	//���F�́�
	static int FontType7X = 1300;
	//���F�̖�����
	static int FontType8X = 1300;

	//���E�ɑ��삷�邽�߂̃J�E���g
	static int PlayKeyCountL = 0;
	static int PlayKeyCountR = 0;
	//ok����x���������Ȃ��悤�ɂ���
	static int OKFlag = 0;
	static int OKFlag1 = 0;
	static int OKFlag2 = 0;
	//���E�̑���A�W�����v�̂�����
	static int PlayKeyFlag = 0;
	//��b�Ԃ͓�����悤�ɂ��Ă���
	static int PlayerWait = 0;
	static int PlayerWait1 = 0;
	if (FontInit == 0)
	{
		//������
		DrawCount = 0;
		//Font�̏����l
		FontType1X = 1300;
		FontType11X = 1300;
		FontType12X = 1300;
		FontType2X = 1300;
		FontType3X = 1300;
		FontType4X = 1300;
		FontType5X = 1300;
		FontType6X = 1300;
		FontType7X = 1300;
		FontType8X = 1300;
		//FontScrollSpeed
		FontSpeed = 10;
		//�e�v���C���[�𓮂��Ȃ��悤�ɂ��Ă���
		Player.Move = 0;
		Player2.Move = 0;
		//���E�ɑ��삷�邽�߂̃J�E���g
		PlayKeyCountL = 0;
		PlayKeyCountR = 0;
		//OKFlag����x���������\�����Ȃ�
		OKFlag = 0;
		OKFlag1 = 0;
		OKFlag2 = 0;
		//���E�̑��삾�����������W�����v�͂������Ȃ�1 �W�����v��OK�ɂ���2
		PlayKeyFlag = 0;
		FontInit = 1;
		//��b�Ԃ͓�����悤�ɂ��Ă���
		PlayerWait = 0;
		PlayerWait1 = 0;
	}

	if (FontInit == 1)
	{
		DrawCount++;
		//�悤����
		if (DrawCount > 240)
		{
			DrawString(FontType1X -= FontSpeed, 300, "�悤���� Synchro ��", GetColor(255, 255, 255));
			if (FontType1X < 810 && FontType1X>500)
			{
				FontSpeed = 2;
			}
			if (FontType1X < 500 && FontType1X>-30)
			{
				FontSpeed = 10;
			}
		}
		//�d�͐���
		if (FontType1X < -30)
		{
			DrawString(FontType11X -= FontSpeed, 300, "�L�����N�^�[�ɂ͏d�͂��������Ă���܂�", GetColor(255, 255, 255));

			if (FontType11X < 780 && FontType11X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType11X < 400 && FontType11X>-50)
			{
				FontSpeed = 10;
			}
		}
		if (FontType11X < -30)
		{
			DrawString(FontType12X -= FontSpeed, 300, "�L�����N�^�[�̓���ɂ͂��ꂼ��̏d�ʂ̕�����������Ă��܂�", GetColor(255, 255, 255));

			if (FontType12X < 780 && FontType12X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType12X < 400 && FontType12X>-50)
			{
				FontSpeed = 10;
			}
		}
		//�������
		if (FontType12X < -30)
		{
			DrawString(FontType2X -= FontSpeed, 300, "�ł́A��������������Ă��������܂�", GetColor(255, 255, 255));

			if (FontType2X < 780 && FontType2X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType2X < 400 && FontType2X>-50)
			{
				FontSpeed = 10;
			}
		}
		//�����L�[
		if (FontType2X < -50)
		{
			DrawString(FontType3X -= FontSpeed, 300, "���E�̕����L�[�i���j�i���j�ňړ��ɂȂ��Ă܂�", GetColor(255, 255, 255));
			if (FontType3X < 780 && FontType3X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType3X < 400 && FontType3X>-50)
			{
				FontSpeed = 10;
			}
		}
		//�����L�[
		if (FontType3X < -50)
		{
			DrawString(FontType4X -= FontSpeed, 300, "�ł͎��ۂɓ������Ă݂܂��傤", GetColor(255, 255, 255));
			if (FontType4X < 780 && FontType4X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType4X < 400 && FontType4X>-50)
			{
				FontSpeed = 10;
			}
		}
		//���ۂɑ���
		if (FontType4X < -50)
		{
			PlayKeyFlag = 1;
			if (PlayKeyFlag == 1)
			{

				//�e�v���C���[�𓮂���悤�ɂ���
				Player.Move = 1;
				Player2.Move = 1;
				//���̕\��
				if (KeyCode & PAD_INPUT_RIGHT)
				{
					DrawString(Player.pos.x + 32, Player.pos.y + 5, "��", GetColor(255, 255, 255));
					DrawString(Player2.pos.x + 32, Player2.pos.y + 5, "��", GetColor(255, 255, 255));
					PlayKeyCountR = 1;
					OKFlag = 1;
				}
				//���̕\��
				else if (KeyCode & PAD_INPUT_LEFT)
				{
					DrawString(Player.pos.x - 32, Player.pos.y + 5, "��", GetColor(255, 255, 255));
					DrawString(Player2.pos.x - 32, Player2.pos.y + 5, "��", GetColor(255, 255, 255));
					PlayKeyCountL = 1;
					OKFlag = 1;
				}
				//���E�ɂ��������Ă�������
				if (PlayKeyCountL == 0 || PlayKeyCountR == 0)
				{
					DrawString(610, 300, "���E�ɓ������Ă�������", GetColor(255, 255, 255));
				}
				//CountLR���P��OKFLag�����Ă� OK��\��
				else if (PlayKeyCountL == 1 && PlayKeyCountR == 1 && OKFlag == 1 && OKFlag1 == 0)
				{
					DrawString(640, 300, "OK", GetColor(255, 255, 255));
					PlayerWait++;
				}
				//0.5�b���ĂΑ��삪�ł��Ȃ��Ȃ�
				if (PlayerWait > 30)
				{
					OKFlag = 0;
					OKFlag1 = 1;
					Player.Move = 0;
					Player2.Move = 0;
					PlayKeyCountL = 1;
					PlayKeyCountR = 1;
					//�W�����v
					DrawString(FontType5X -= FontSpeed, 300, "�ł͎��ɃW�����v�����Ă݂܂��傤", GetColor(255, 255, 255));
					if (FontType5X < 780 && FontType5X > 400)
					{
						FontSpeed = 2;
					}
					if (FontType5X < 400 && FontType5X>-50)
					{
						FontSpeed = 10;
					}
				}
				if (FontType5X < -50)
				{
					
					//�W�����v�ł���悤�ɂ���
					Player.Move = 1;
					Player2.Move = 1;
					if (Player.pos.x<320 || Player.pos.x<515)
					{
						DrawString(320, 450, "��������", GetColor(255, 255, 255));
						DrawString(320, 480, "��", GetColor(255, 255, 255));
						DrawString(320, 550, "��", GetColor(255, 255, 255));
						DrawString(320, 570, "��������", GetColor(255, 255, 255));

						DrawString(514, 450, "�����܂�", GetColor(255, 255, 255));
						DrawString(514, 480, "��", GetColor(255, 255, 255));
						DrawString(514, 550, "��", GetColor(255, 255, 255));
						DrawString(514, 570, "�����܂�", GetColor(255, 255, 255));
					}
					if (Player.pos.x > 514)
					{
						//�W�����v�ł���悤�ɂ���
						Player.Move = 0;
						Player2.Move = 0;
						OKFlag2 = 1;
						
					}
					if (OKFlag2 == 1)
					{
						PlayerWait1 = 1;
					}
					
					if (PlayerWait1==1)
					{
						//�W�����v�ł���悤�ɂ���
						Player.Move = 1;
						Player2.Move = 1;
						OKFlag2 = 2;
						DrawString(FontType6X -= FontSpeed, 300, "�ł�MAP�̉E�[�ɂ���A���F�̖��܂ł����܂��傤", GetColor(255, 255, 255));
						DrawString(1150, 450, "�����܂�", GetColor(255, 255, 255));
						DrawString(1150, 480, "��", GetColor(255, 255, 255));
						DrawString(1150, 550, "��", GetColor(255, 255, 255));
						DrawString(1150, 570, "�����܂�", GetColor(255, 255, 255));
						if (FontType6X < 780 && FontType6X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType6X < 400 && FontType6X>-50)
						{
							FontSpeed = 10;
						}
					}
					if (Player.pos.x > 1140)
					{
						PlayerWait1 = 2;
						
					}
					if (PlayerWait1 == 2)
					{
						//�������Ȃ��悤�ɂ���
						Player.Move = 0;
						Player2.Move = 0;
						DrawString(FontType7X -= FontSpeed, 300, "���F�̖��ɂӂ��̃L�����N�^�[���G����Map���؂�ւ��܂�", GetColor(255, 255, 255));
						if (FontType7X < 780 && FontType7X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType7X < 400 && FontType7X>-50)
						{
							FontSpeed = 10;
						}
					}
					if (FontType7X<-50)
					{
						
						DrawString(FontType8X -= FontSpeed, 300, "�ł�MAP�̈ړ������Ă݂܂��傤", GetColor(255, 255, 255));
						if (FontType8X < 780 && FontType8X > 400)
						{
							FontSpeed = 2;
						}
						if (FontType8X < 400 && FontType8X>-50)
						{
							FontSpeed = 10;
						}
						if (FontType8X < -50)
						{
							//��������悤�ɂ���
							Player.Move = 1;
							Player2.Move = 1;
						}
					}

				}
			}
		}
	}
}
//�`���[�g���A�����䕶
void TutorialControl2()
{
	//
	static int FontType1X = 1300;
	//
	static int FontType2X = 1300;
	static int FontSpeed = 10;

	static int DrawCount = 0;
	if (FontInit2 == 0)
	{
		FontType1X = 1300;
		FontType2X = 1300;
		//FontScrollSpeed
		FontSpeed = 10;

		DrawCount = 0;
		FontInit2 = 1;
	}

	if (FontInit2 == 1)
	{
		DrawCount++;
		//�悤����
		if (DrawCount > 30)
		{
			DrawString(FontType1X -= FontSpeed, 300, "�e�X�e�[�W�ɂ̓S�[�����o�������邽�߂̃J�P�������݂��Ă��܂�", GetColor(255, 255, 255));
			if (FontType1X < 810 && FontType1X>500)
			{
				FontSpeed = 2;
			}
			if (FontType1X < 500 && FontType1X>-30)
			{
				FontSpeed = 10;
			}
		}
		//�d�͐���
		if (FontType1X < -30)
		{
			DrawString(FontType2X -= FontSpeed, 300, "���������ׂĂƂ��Ă݂܂��傤", GetColor(255, 255, 255));

			if (FontType2X < 780 && FontType2X > 400)
			{
				FontSpeed = 2;
			}
			if (FontType2X < 400 && FontType2X>-50)
			{
				FontSpeed = 10;
			}
		}
		if (FontType2X < -50)
		{
			Player.Move = 1;
			Player2.Move = 1;
			/*DrawString(1144, 380, "�J�P��", GetColor(255, 255, 255));
			DrawString(1144, 400, "��", GetColor(255, 255, 255));
			DrawString(1144, 630, "��", GetColor(255, 255, 255));
			DrawString(1144, 650, "�J�P��", GetColor(255, 255, 255));*/
		}
	}
}
