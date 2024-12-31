#include "Hooks/Fixes.h"

namespace Fixes::FrustumCheck
{
	void Install()
	{
		const REL::Relocation NiFrustrumPlanes__Set{ REL::Offset(0xCB2760) };

		// mov rdx, [rdx+180h] (48 8B 92 80 01 00 00)
		//                         v  v  v
		// add rdx, 1CCh       (48 81 C2 CC 01 00 00)

		REL::safe_fill(NiFrustrumPlanes__Set.address() + 0x5, 0x81, 1);
		REL::safe_fill(NiFrustrumPlanes__Set.address() + 0x6, 0xC2, 1);
		REL::safe_fill(NiFrustrumPlanes__Set.address() + 0x7, 0xCC, 1);
		logger::info("Patched NiFrustrumPlanes::Set");
	}
}
