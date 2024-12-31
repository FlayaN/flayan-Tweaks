#include "Hooks.h"

#include "Hooks/Fixes.h"
#include "Settings.h"

namespace Hooks
{
	void PostLoad::Install()
	{
		Settings::GetSingleton()->Load();

		logger::info("{:*^50}", "HOOKS PostLoad");

		Fixes::PostLoad::Install();
	}
}
