#ifndef _I_ASW_PLAYER_CONTROLLED_CHARACTER_H
#define _I_ASW_PLAYER_CONTROLLED_CHARACTER_H

class C_ASW_Player;

abstract_class I_ASW_Player_Controlled_Character
{
public:
	// Commander/Inhabiting	
	virtual C_ASW_Player* GetCommander( void ) const = 0;

	virtual bool IsInhabited( void ) const = 0;

};

#endif // _I_ASW_PLAYER_CONTROLLED_CHARACTER_H