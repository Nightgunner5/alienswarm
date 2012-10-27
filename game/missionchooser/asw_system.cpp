#include "asw_system.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

const char *Sys_FindFirst (FileFindHandle_t &searchhandle, const char *path, char *basename, int namelength )
{
	if (searchhandle != FILESYSTEM_INVALID_FIND_HANDLE)
	{
		Msg("Sys_FindFirst without close");
		g_pFullFileSystem->FindClose(searchhandle);		
	}

	const char* psz = g_pFullFileSystem->FindFirst(path, &searchhandle);
	if (basename && psz)
	{
		Q_FileBase(psz, basename, namelength );
	}

	return psz;
}

//-----------------------------------------------------------------------------
// Purpose: 
// Input  : *basename - 
// Output : char *Sys_FindNext
//-----------------------------------------------------------------------------
const char* Sys_FindNext (FileFindHandle_t &searchhandle, char *basename, int namelength)
{
	const char *psz = g_pFullFileSystem->FindNext(searchhandle);
	if ( basename && psz )
	{
		Q_FileBase(psz, basename, namelength );
	}

	return psz;
}

//-----------------------------------------------------------------------------
// Purpose: 
// Output : void Sys_FindClose
//-----------------------------------------------------------------------------

void Sys_FindClose (FileFindHandle_t &searchhandle)
{
	if ( FILESYSTEM_INVALID_FIND_HANDLE != searchhandle )
	{
		g_pFullFileSystem->FindClose(searchhandle);
		searchhandle = FILESYSTEM_INVALID_FIND_HANDLE;
	}
}