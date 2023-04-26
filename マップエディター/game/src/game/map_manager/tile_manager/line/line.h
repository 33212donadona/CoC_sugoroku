#pragma once
#include "aqua.h"

class CLine :
	public aqua::IGameObject
{
public:

	CLine(aqua::IGameObject* parent);
	~CLine() = default;

	/*
	 * @brief 初期化
	 */
	void Initialize(aqua::CVector2* first_pos);

	/*
	 * @brief 更新
	 */
	void Update()override;

	/*
	 * @brief 描画
	 */
	void Draw()override;

	/*
	 * @brief 解放
	 */
	void Finalize()override;

	aqua::CVector2* m_TergetPosition;

private:
	static const float m_LineThick;

	aqua::CVector2* m_FirstPosition;
	aqua::CVector2  m_PrevFirstPosition;

};