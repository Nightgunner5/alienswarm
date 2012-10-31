#ifndef _IASW_PLAYER_CONTROLLED_CHARACTER_H
#define _IASW_PLAYER_CONTROLLED_CHARACTER_H

class CASW_Player;

abstract_class IASW_Player_Controlled_Character
{
public:
	// Commander/Inhabiting	
	virtual void SetCommander( CASW_Player *player ) = 0;
	virtual CASW_Player* GetCommander( void ) const = 0;

	virtual bool IsInhabited( void ) const = 0;
	virtual void SetInhabited( bool bInhabited ) = 0;

	virtual void InhabitedBy( CASW_Player *player ) = 0;
	virtual void UninhabitedBy( CASW_Player *player ) = 0;

};

#endif // _IASW_PLAYER_CONTROLLED_CHARACTER_H