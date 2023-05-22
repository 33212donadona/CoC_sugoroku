#include "main_game_work.h"
#include "../../../../../../common_data/common_data.h"
#include "../../../../../../select_charactor/charactor/charactor_info.h"

CMainGameWork::CMainGameWork(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"MainGameWork")
{
}

void CMainGameWork::Initialize()
{
	m_TextBoxSprite.Create("data\\game_main\\UI\\text_box.png");
	m_CommonData = (CCommonData*)aqua::FindGameObject("CommonData");
	
}

void CMainGameWork::Update()
{
}

void CMainGameWork::Draw()
{
	m_TextBoxSprite.Draw();

	if (m_CommonData)
	{
		for (int i = (int)PLAYER_ID::PL1; i < (int)PLAYER_ID::DUMMY; ++i)
		{
			m_CommonData->RefarenceChara((PLAYER_ID)i).Draw();
		}
	}
}

void CMainGameWork::Finalize()
{
	m_TextBoxSprite.Delete();
}
