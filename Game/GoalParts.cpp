//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   Goal.cpp
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

void InitObject(Object *obj, int posx, int posy, int grpw, int grph, int grpx, int grpy);

//�S�[���̃A�j���[�V����
int AnimesionGoal = 0;

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FInitObject                 //
//				�T�v  �F���������邽�߂̊֐�       //
//				����  �F�ȗ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void InitObject(Object *obj, int posx, int posy, int grpx, int grpy, int grpw, int grph)
{
	//���W�ύX
	obj->pos.x = posx;
	obj->pos.y = posy;
	//�O���t�B�b�N�摜�ؔ���
	obj->grp.x = grpx;
	obj->grp.y = grpy;
	//���W�T�C�Y
	obj->grp.w = grpw;
	obj->grp.h = grph;
}

///////////////////////////////////////////////////////////////////

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�`���[�g���A���C�j�V�����C�Y	   //
//				�T�v  �F�摜������                 //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//

void InitGoalTutorialFirst()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal1.Flag = 1;
	//������
	InitObject(&Goal1, 1097, 430, 0, 0, 64, 32);
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//���
void InitGoalTutorialSecond()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal2.Flag = 1;
	//������
	InitObject(&Goal2, 1097, 600, 0, 32, 64, 32);
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalTutorial()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal.Flag = 0;
	//������
	InitObject(&Goal, 800, 500, 0, 0, 64, 64);
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

//////////////////////�p�[�c�Q�ƃS�[���P��///////////////
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//					Stage�C�j�V�����C�Y		       //
//				�T�v  �F�摜������                 //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//

void InitGoalStage1First()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal1.Flag = 1;
	//������	
	switch (MapFlagNumber)
	{
	case 1:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 480, 576, 0, 0, 64, 32);
			break;
		}
		break;
	case 2:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 545, 500, 0, 0, 64, 32);
			break;
		}
		break;
	case 3:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 612, 576, 0, 0, 64, 32);
			break;
		}
		break;
	case 7:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 920, 380, 0, 32, 64, 32);
			break;
		}
		break;
	}
	
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//���
void InitGoalStage1Second()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal2.Flag = 1;
	//������
	switch (MapFlagNumber)
	{
	case 1:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 480, 448, 0, 32, 64, 32);
			break;
		}
		break;
	case 2:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 780, 640, 0, 32, 64, 32);
			break;
		}
		break;
	case 3:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 353, 380, 0, 32, 64, 32);
			break;
		}
		break;
	case 7:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 560, 320, 0, 32, 64, 32);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalStage1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal.Flag = 0;
	//������
	switch (MapFlagNumber)
	{
	case 1:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal, 1010, 500, 0, 0, 64, 64);
			break;
		}
		break;
	case 2:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal, 1150, 520, 0, 0, 64, 64);
			break;
		}
		break;
	case 3:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal, 1150, 490, 0, 0, 64, 64);
			break;
		}
		break;
	case 7:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal, 1170, 520, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

///////////////////////////////////////////////////////////////////////



//////////////////////�p�[�c3�ƃS�[���P��///////////////
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//					Stage�C�j�V�����C�Y		       //
//				�T�v  �F�摜������                 //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//

void InitGoalStage2First()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal1.Flag = 1;
	//������	
	switch (MapFlagNumber)
	{
	case 4:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 384, 480, 32, 32, 32, 32);
			break;
		}
		break;
	case 9:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 630, 420, 32, 32, 32, 32);
			break;
		}
		break;
	case 10:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 213, 700, 32, 32, 32, 32);
			break;
		}
		break;
	}

	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//���
void InitGoalStage2Second()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal2.Flag = 1;
	//������
	switch (MapFlagNumber)
	{
	case 4:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 600, 544, 0, 32, 64, 32);
			break;
		}
		break;
	case 9:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 557, 350, 0, 32, 64, 32);
			break;
		}
		break;
	case 10:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 213,310, 32, 0, 32, 32);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

//�R��
void InitGoalStage2Third()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal3.Flag = 1;
	//������	
	switch (MapFlagNumber)
	{
	case 4:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 1175, 480, 32, 0, 32, 32);
			break;
		}
		break;
	case 9:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 560, 680, 32, 0, 32, 32);
			break;
		}
		break;
	case 10:
		//�}�b�v�t�@�C������I�[�v������
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3,885, 535, 0, 32, 64, 32);
			break;
		}
		break;
	}

	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal3.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}

void InitGoalStage2()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal.Flag = 0;
	//������
	switch (MapFlagNumber)
	{
	case 4:
		switch (MapChange)
		{
		case 0:
			//Goal������
			InitObject(&Goal, 235, 500, 0, 0, 64, 64);
			break;
		}
		break;
	case 9:
		switch (MapChange)
		{
		case 0:
			//Goal������
			InitObject(&Goal, 1150, 850, 0, 0, 64, 64);
			break;
		}
		break;
	case 10:
		switch (MapChange)
		{
		case 0:
			//Goal������
			InitObject(&Goal, 350, 500, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////Render/////////////////////////////


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawObject                 //
//				�T�v  �FObject���ȒP�\��	       //
//				����  �FObject					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawObject(Object *obj)
{
	DrawRectGraph(obj->pos.x, obj->pos.y, obj->grp.x, obj->grp.y, obj->grp.w, obj->grp.h, obj->grp.Handle, TRUE, FALSE);
}

//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawObjectAnime            //
//				�T�v  �FObject���ȒP�\��	       //
//				����  �FObject					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawObjectAnime(Object *obj)
{
	DrawRectGraph(obj->pos.x, obj->pos.y, obj->grp.x, obj->grp.y, obj->grp.w, obj->grp.h, obj->grp.Handles[AnimesionGoal], TRUE, FALSE);
}


//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FDrawGoalParts              //
//				�T�v  �FGoal��\��			       //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void DrawGoalParts()
{
	//�S�[���̃A�j���[�V����
	static int GoalCount = 0;

	//�S�[���p�[�c�̕\��
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal4.Flag == 1)
	{
		DrawObject(&Goal4);
	}
	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 && Goal4.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 || Goal4.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

void DrawGoalPartsTurorial()
{
	//�S�[���̃A�j���[�V����
	static int GoalCount = 0;

	//�S�[���p�[�c�̕\��
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}


void DrawGoalPartsTurorial1()
{
	//�S�[���̃A�j���[�V����
	static int GoalCount = 0;

	//�S�[���p�[�c�̕\��
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
		DrawString(1100, 380, "�J�P��", GetColor(255, 255, 255));
		DrawString(1120, 400, "��", GetColor(255, 255, 255));
	}

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
		DrawString(1120, 630, "��", GetColor(255, 255, 255));
		DrawString(1100, 650, "�J�P��", GetColor(255, 255, 255));
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0)
	{
		Goal.Flag = 1;
		DrawString(500, 300, "�S�[�����o�����܂����B�S�[���ɐG���΃N���A�I", GetColor(255, 255, 255));
		DrawString(710, 520, "�S�[����", GetColor(255, 255, 255));
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

//Stage4

void DrawStage4Parts1()
{
	//�S�[���p�[�c�̕\��
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}
}
void DrawStage4Parts()
{
	static int GoalCount = 0;

	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}

	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

//Stage5�̓����蔻��
void DrawStage5Parts1()
{
	//�S�[���p�[�c�̕\��
	if (Goal1.Flag == 1)
	{
		DrawObject(&Goal1);
	}
	if (Goal2.Flag == 1)
	{
		DrawObject(&Goal2);
	}
}
void DrawStage5Parts2()
{
	//�S�[���̃A�j���[�V����
	static int GoalCount = 0;
	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal4.Flag == 1)
	{
		DrawObject(&Goal4);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 && Goal4.Flag == 0)
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 || Goal4.Flag == 1)
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}

void DrawStage5Parts3()
{
	//�S�[���̃A�j���[�V����
	static int GoalCount = 0;
	if (Goal3.Flag == 1)
	{
		DrawObject(&Goal3);
	}

	if (Goal1.Flag == 0 && Goal2.Flag == 0 && Goal3.Flag == 0 )
	{
		Goal.Flag = 1;
	}
	if (Goal1.Flag == 1 || Goal2.Flag == 1 || Goal3.Flag == 1 )
	{
		Goal.Flag = 0;
	}
	//�S�[���̃A�j���[�V��������
	if (Goal.Flag == 1)
	{
		GoalCount++;
		if (GoalCount >= 15 && AnimesionGoal != 2)
		{
			AnimesionGoal++;
			GoalCount = 0;
		}
		if (GoalCount >= 15 && AnimesionGoal == 2)
		{
			AnimesionGoal = 0;
			GoalCount = 0;
		}
		DrawObjectAnime(&Goal);
	}
}




//����MAP
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
//				�֐����FInitGoalPartsFirst  ...etc //
//				�T�v  �F�摜������                 //
//				����  �F�Ȃ�					   //
//				�߂�l�F�Ȃ�         			   //
//*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*:;;;:*��*//
void InitGoalPartsFirst1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal1.Flag = 1;
	//������
	//InitObject(&Goal1, 416, 480, 32, 32, 32, 32);
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 240, 320, 32, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 240, 440, 32, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 850, 215, 32, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal1, 1145, 550, 32, 32, 32, 32);
			break;
		}
		break;

	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal1.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//���
void InitGoalPartsSecond1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal2.Flag = 1;
	//������
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 240, 705, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 570, 480, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 850, 800, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal2, 1140, 220, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal2.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//�O��
void InitGoalPartsThird1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal3.Flag = 1;
	//������
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 1184, 480, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 1170, 550, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 190, 675, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal3, 506, 800, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal3.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}

}
//�l��
void InitGoalPartsFourth1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal4.Flag = 1;
	//������
	//InitObject(&Goal4, 1120, 544, 0, 0, 32, 32);
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal4, 1184, 545, 0, 32, 32, 32);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal4, 465, 160, 0, 32, 32, 32);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal4, 810, 735, 0, 32, 32, 32);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goal�p�[�c�̏�����
			InitObject(&Goal4, 1043, 736, 0, 32, 32, 32);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal4.grp.Handle = LoadGraph("Resources\\Images\\Item\\Goal.png");
		init = 1;
	}
}
//�S�[���{��
void InitGoal1()
{
	//��x�����ǂݍ���
	static int init = 0;
	Goal.Flag = 0;
	//������
	switch (MapFlagNumber)
	{
	case 5:
		switch (MapChange)
		{
		case 0:
			//Goal�̏�����
			InitObject(&Goal, 936, 710, 0, 0, 64, 64);
			break;
		}
		break;
	case 6:
		switch (MapChange)
		{
		case 0:
			//Goal�̏�����
			InitObject(&Goal, 1000, 840, 0, 0, 64, 64);
			break;
		}
		break;
	case 8:
		switch (MapChange)
		{
		case 0:
			//Goal�̏�����
			InitObject(&Goal, 550, 721, 0, 0, 64, 64);
			break;
		}
		break;
	case 11:
		switch (MapChange)
		{
		case 0:
			//Goal�̏�����
			InitObject(&Goal, 300, 500, 0, 0, 64, 64);
			break;
		}
		break;
	}
	//�摜�ǂݍ���
	if (init == 0)
	{
		//�S�[���摜
		Goal.grp.Handles[0] = LoadGraph("Resources\\Images\\Item\\Goal.png");
		Goal.grp.Handles[1] = LoadGraph("Resources\\Images\\Item\\Goal2.png");
		Goal.grp.Handles[2] = LoadGraph("Resources\\Images\\Item\\Goal3.png");
		init = 1;
	}

}