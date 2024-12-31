#include "Fixes.h"
#include "Settings.h"

void Fixes::PostLoad::Install()
{
	const auto& fixes = Settings::GetSingleton()->GetFixes();
	if (fixes.frustumCheck && REL::Module::IsVR()) {
		FrustumCheck::Install();
	}
}
