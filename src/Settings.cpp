#include "Settings.h"

void Settings::Load()
{
	constexpr auto path = L"Data/SKSE/Plugins/flayan_Tweaks.ini";

	CSimpleIniA ini;
	ini.SetUnicode();

	ini.LoadFile(path);

	fixes.Load(ini);

	ini.SaveFile(path);
}

const Settings::Fixes& Settings::GetFixes() const
{
	return fixes;
}

void Settings::Fixes::Load(CSimpleIniA& a_ini)
{
	static const char* section = "Fixes";
	logger::info("Settings - Loading [{}]", section);

	get_value(a_ini, frustumCheck, section, "Frustum Check", ";Fixes faulty frustum check in VR");
}
