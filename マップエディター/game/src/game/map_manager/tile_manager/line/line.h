#pragma once
#include "aqua.h"

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief ‰Šú‰»
	 */
	void Initialize(aqua::CVector2* first_pos);

	/*
	 * @brief XV
	 */
	void Update()override;

	/*
	 * @brief •`‰æ
	 */
	void Draw()override;

	/*
	 * @brief ‰ğ•ú
	 */
	void Finalize()override;

	aqua::CVector2* m_TergetPosition;

private:
	static const float m_LineThick;

	aqua::CVector2* m_FirstPosition;
	aqua::CVector2  m_PrevFirstPosition;

};