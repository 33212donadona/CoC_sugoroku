#pragma once
#include "aqua.h"
#include "../charactor/charactor_id.h"

using ParamVector = std::vector<aqua::CBoxPrimitive>;

class CParameter :
	public aqua::IGameObject
{
public:

	/*!
	 *  @brief コンストラクタ
	 */
	CParameter(aqua::IGameObject* parent);

	/*!
	 *  @brief デストラクタ
	 */
	~CParameter() = default;

	/*!
	 *  @brief 初期化
	 */
	void Initialize
	(
		STATUS& parameter,
		aqua::CVector2 position = aqua::CVector2::ZERO,
		aqua::CVector2 size = aqua::CVector2(aqua::GetWindowSize().x, aqua::GetWindowSize().y / 2)
	);

	/*!
	 *  @brief 更新
	 */
	void Update()override;

	/*!
	 *  @brief 描画
	 */
	void Draw()override;

	/*!
	 *  @brief 解放
	 */
	void Finalize()override;

private:

	void ParamSetUp(ParamVector* param_box, int parameter, int max_parameter,aqua::CVector2 position);

private:
	static const aqua::CPoint m_division;
	static const aqua::CPoint m_param_start_division;
	static const aqua::CVector2 m_param_box_size;
	static const unsigned int m_param_color;
	static const unsigned int m_param_color_overe;

	STATUS m_Parameter;        // パラメーター
	aqua::CVector2 m_Position; // 座標
	aqua::CVector2 m_Size;	   // 大きさ
	aqua::CVector2 m_Scale;	   // 大きさ

	ParamVector m_ParamBoxHp;  // HPのパラメーターメモリ
	ParamVector m_ParamBoxStr; // STRのパラメーターメモリ
	ParamVector m_ParamBoxDex; // DEXのパラメーターメモリ


};