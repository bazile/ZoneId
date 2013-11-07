// zoneid.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2) return 0;

	CCoInitialize init;
	HRESULT hr;

	CComPtr<IZoneIdentifier> spzi;
	spzi.CoCreateInstance(CLSID_PersistentZoneIdentifier);
	
	hr = CComQIPtr<IPersistFile>(spzi)->Load(argv[1], STGM_READ);
	if (SUCCEEDED(hr))
	{
		DWORD dwZone;
		hr = spzi->GetId(&dwZone);
		if (SUCCEEDED(hr))
		{
			//printf("Zone identifier is %d\n", dwZone);
			//printf("Zone identifier is %s\n", ZoneIdToString(dwZone));
			//_wprintf_p(TEXT("Zone identifier is %s\n"), ZoneIdToString(dwZone).c_str());
			switch (dwZone)
			{
			case URLZONE::URLZONE_INTERNET:
				printf("Zone identifier is Internet (3)\n", dwZone);
				break;

			default:
				printf("Zone identifier is %d\n", dwZone);
				break;
			}
		}
	}
	else
	{
		printf("Couldn't get zone identifier (perhaps there isn't one)\n");
	}

	return 0;
}

