//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Map.h
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


// �֐��̒�` ==============================================================

//Map�̕\��
void MapLoad1(void);
void MapLoad2(void);
void MapLoad3(void);
void TitleLoad(void);
void SelectMap(void);


//�X�e�[�W �`���[�g���A���AStage1�̏�����
void Tutorial();
void Stage1();


void ResultLoad();

//�^�C�g�������蔻��
void TitleAtari();
void TitleAtari2();
void ResultAtari();
void ResultAtari2();

//�����蔻��iMap�́j
void AtariUpdate(void);
void AtariUpdate2(void);

void Counter(int x, int y, int n);