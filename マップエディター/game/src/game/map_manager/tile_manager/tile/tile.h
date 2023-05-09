#pragma once
#include "aqua.h"

class ITile :
	public aqua::IGameObject
{
public:
	ITile(aqua::IGameObject* parent,std::string name);
	~ITile() = default;

	/*!
	 *   @brief  ������
	 * 
	 *   @param[in] position ���W
	 */
	virtual void Initialize(aqua::CVector2 position);

	/*!
	 *   @brief  ������
	 * 
	 *   @param[in] block_name �摜��
	 *   @param[in] position   ���W
	 */
	virtual void Initialize(std::string block_name,aqua::CVector2 position);

	/*!
	 *   @brief  �X�V
	 */
	virtual void Update()override;

	/*!
	 *   @brief  �`��
	 */
	virtual void Draw()override;

	/*!
	 *   @brief  ���
	 */
	virtual void Finalize()override;

	/*!
	 *   @brief  �^�C�����W�̉���
	 */
	void SetPosition(aqua::CVector2& move);

	/*!
	 *   @brief  �^�C�����W�̎擾
	 * 
	 *   @return �^�C�����W
	 */
	aqua::CVector2 GetPosition();

	/*!
	 *   @brief  �^�C�����S���W�̎擾
	 *
	 *   @return �^�C�����S���W
	 */
	aqua::CVector2* GetCenterPosition();

	/*!
	 *   @brief  �i�߂�^�C���ԍ���ݒ�
	 * 
	 *   @param[in] vector_num       �z��ԍ�
	 *   @param[in] next_tile_number �^�C���ԍ�
	 */
	void SetNextTileID(int vector_num,ITile* next_tile_number);

	/*!
	 *   @brief  �^�C���ԍ���ݒ�
	 * 
	 *   @param[in] tile_number �^�C���ԍ�
	 */
	void SetTileID(int tile_number);

	/*!
	 *   @brief  �����̃^�C���ԍ����擾
	 * 
	 *   @return �^�C���ԍ�
	 */
	int* GetNowTileID();

	/*!
	 *   @brief  �i�߂�^�C���̍ő�l���擾
	 * 
	 *   @return �i�߂�^�C���̍ő�l
	 */
	int GetMaxNextTileSize();

	/*!
	 *   @brief  ���ɐi�߂�^�C���ԍ�
	 * 
	 *   @param[in] vector_num �z��ԍ�
	 * 
	 *   @return ���ɐi�߂�^�C���ԍ�
	 */
	int* GetNextTileID(int vector_num);

	/*!
	 *   @brief  �������ꂽ�^�C���ԍ�
	 */
	static int m_tile_num;

	/*!
	 *   @brief  �����Ƃ̏Փ˔���
	 * 
	 *   @param[in] position ���W
	 * 
	 *   @return �����Ƃ̏Փ˔���
	 *   @retval true  �����Ă���
	 *   @retval false �����Ă��Ȃ�
	 */
	bool CheckOnTile(aqua::CVector2& position);

	/*!
	 *   @brief  �摜�̑傫�����擾
	 * 
	 *   @return �摜�̑傫��
	 */
	aqua::CVector2 GetTileSize();

private:

	static const float m_out_of_range;   //! �Փ˔���̋��e�͈�

	int m_NowID;                         //! �����̃^�C���ԍ�

	std::vector<ITile*> m_NextTile;      //! ���ɐi�߂�^�C���ԍ�

	aqua::CSprite m_TileSprite;          //! �^�C���̉摜

	aqua::CVector2 m_TileHalfSize;       //! �^�C���̔����̑傫��

	aqua::CVector2 m_CenterPosition;     //! �^�C���̒��S���W

};