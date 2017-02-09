//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   AllStage.h
//!
//! @brief  Map�֘A�̃w�b�_�t�@�C��
//!
//! @date   ���t
//!
//! @author GF3_01_���� �ˑ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once

//�}�b�v�`�b�v
extern int StageMap[30][40];

// �֐��̒�` ==============================================================

////Map�\��////
void Stage1Load1();
void Stage1Load2();
void Stage2Load1();
void Stage3Load();
void Stage4Load();
void Stage5Load();
void Stage6Load();
void Stage7Load();
void Stage8Load();
void Stage9Load();
void Stage10Load();
void Stage11Load();

//�X�e�[�W�̏�����
void Stage1();
void Stage2();
void Stage3();
void Stage4();
void Stage5();
void Stage6();
void Stage7();
void Stage8();
void Stage9();
void Stage10();
void Stage11();

void InitStage1();

//�����蔻��iMap�́j
void StageAtariUpdate(void);
void StageAtariUpdate2(void);
//�g���܂킵Map�\��
void DrawStageMap();




